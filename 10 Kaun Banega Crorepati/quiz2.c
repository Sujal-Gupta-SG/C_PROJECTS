#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <stdbool.h>
#include <pthread.h> // Include this for threading support

#define MAX_QUES_LEN 300
#define MAX_OPTION_LEN 100

volatile int timeout_happened = 0;
bool *question; 
int money_won = 1000;

const char* COLOR_END = "\033[0m";
const char* RED = "\033[1;31m";
const char* GREEN = "\033[1;32m";
const char* YELLOW = "\033[1;33m";
const char* BLUE = "\033[1;34m";
const char* PINK = "\033[1;35m";
const char* AQUA = "\033[1;36m";

typedef struct {
    char text[MAX_QUES_LEN];
    char options[4][MAX_OPTION_LEN];
    char correct_option;
    int timeout;
} Question;

int read_questions(char* file_name, Question** questions);
void print_formatted_question(Question* question);
void play_game(Question* questions, int no_of_questions);
int use_lifeline(Question* question, int* lifeline);
void* timeout_thread(void* arg); // Function prototype for timeout thread

pthread_t timer_thread; // Global variable for the timer thread

int main() {
    srand(time(NULL));
    printf("\t\t%sChalo Kehlte hain KAUN BANEGA CROREPATI !!!%s", PINK, COLOR_END);
    Question* questions;
    int no_of_questions = read_questions("questions.txt", &questions);
    question = (bool *) malloc(no_of_questions * sizeof(bool));
    play_game(questions, no_of_questions);
    free(question);
    exit(0);
}

void* timeout_thread(void* arg) {
    Question* question = (Question*)arg;
    sleep(question->timeout);
    timeout_happened = 1;
    printf("%s\n\nTime out!!!!!  Press Any Key...%s\n", RED, COLOR_END);
    fflush(stdout);
    return NULL;
}

void play_game(Question* questions, int no_of_questions) {
    int lifeline[] = {1, 1};
    int shuffled_indices[no_of_questions];
    
    // Initialize shuffled indices
    for (int i = 0; i < no_of_questions; i++) {
        shuffled_indices[i] = i;
    }
    
    // Shuffle the indices
    for (int i = no_of_questions - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = shuffled_indices[i];
        shuffled_indices[i] = shuffled_indices[j];
        shuffled_indices[j] = temp;
    }

    for (int i = 0; i < no_of_questions; i++) {
        print_formatted_question(&questions[shuffled_indices[i]]); // Use shuffled indices
        timeout_happened = 0; // Reset timeout flag
        pthread_create(&timer_thread, NULL, timeout_thread, &questions[shuffled_indices[i]]); // Start timer thread
        char ch = getchar();
        pthread_cancel(timer_thread); // Cancel timer thread
        ch = toupper(ch);
        
        // Clear input buffer
        while ((getchar()) != '\n'); // Read and discard characters until newline
        
        if (timeout_happened == 1) {
            break;
        }

        if (ch == 'L') {
            int value = use_lifeline(&questions[shuffled_indices[i]], lifeline);
            if (value != 2) {
                i--;
            }
            continue;
        }

        if (ch == questions[shuffled_indices[i]].correct_option) {
            printf("%s\nCorrect!%s", GREEN, COLOR_END);
            money_won = money_won * 2;
            printf("\n%sYou have won: Rs %d%s", BLUE, money_won, COLOR_END);
        } else {
            printf("%s\nWrong! Correct answer is %c.%s", RED, questions[shuffled_indices[i]].correct_option, COLOR_END);
            break;
        }
    }
    printf("\n\n%sGame Over! Your total winnings are: Rs %d%s\n", BLUE,  money_won, COLOR_END);
}


int use_lifeline(Question* question, int* lifeline) {
    printf("\n\n%sAvailable Lifelines:%s", PINK, COLOR_END);
    if (lifeline[0]) printf("\n%s1. Fifty-Fifty (50/50)%s", PINK, COLOR_END);
    if (lifeline[1]) printf("\n%s2. Skip the Question%s", PINK, COLOR_END);
    printf("\n%sChoose a lifeline or 0 to return: %s", PINK, COLOR_END);

    char ch = getchar();
    printf("%c", ch);
    
    // Clear input buffer
    while ((getchar()) != '\n'); // Read and discard characters until newline

    switch (ch)
    {
        case '1':
            if (lifeline[0]) {
                lifeline[0] = 0;
                int removed = 0;
                while (removed < 2) {
                    int num = rand() % 4;
                    if ((num + 'A') != question->correct_option &&
                        question->options[num][0] != '\0') {
                        question->options[num][0] = '\0';
                        removed++;
                    }
                }
                return 1;
            }
            break;
        case '2':
            if (lifeline[1]) {
                lifeline[1] = 0;
                return 2;
            }
            break;
        default:
            printf("\n%sReturning to the Question.%s", PINK, COLOR_END);
            break;
    }
    return 0;
}

void print_formatted_question(Question* question) {
    printf("\n\n%s%s%s", YELLOW, question->text, COLOR_END);
    for (int i = 0; i < 4; i++) {
        if (question->options[i][0] != '\0') {
            printf("%s%c. %s%s", AQUA, ('A' + i), question->options[i], COLOR_END);
        }
    }
    printf("\n%sHurry!! You have only %d Seconds to answer..%s", YELLOW, question->timeout, COLOR_END);
    printf("\n%sPrize Money: Rs %d%s", YELLOW, money_won * 2, COLOR_END);
    printf("\n%sEnter your answer (A, B, C, or D) or L for lifeline: %s", GREEN, COLOR_END);
}

int read_questions(char* file_name, Question** questions) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("\nUnable to open the questions bank.");
        exit(0);
    }
    char str[MAX_QUES_LEN];
    int no_of_lines = 0;
    while (fgets(str, MAX_QUES_LEN, file)) {
        no_of_lines++;
    }
    int no_of_questions = no_of_lines / 7;
    bool question[no_of_questions];
    *questions = (Question *) malloc(no_of_questions * sizeof(Question));
    rewind(file);
    for (int i = 0; i < no_of_questions; i++) {
        fgets((*questions)[i].text, MAX_QUES_LEN, file);
        for (int j = 0; j < 4; j++) {
            fgets((*questions)[i].options[j], MAX_OPTION_LEN, file);
        }
        char option[10];
        fgets(option, 10, file);
        (*questions)[i].correct_option = option[0];

        char timeout[10];
        fgets(timeout, 10, file);
        (*questions)[i].timeout = atoi(timeout);

        question[i] = false;

    }
    fclose(file);
    return no_of_questions;
}
