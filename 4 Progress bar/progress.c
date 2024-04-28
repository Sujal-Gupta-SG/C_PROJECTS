#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

const int BAR_LENGTH = 20;
const int MAX_TASKS = 10;

typedef struct {
  int id;
  int progress;
  int step;
} Task;

void print_bar(Task task);
void clear_screen();

int main() {
  Task tasks[MAX_TASKS];
  srand(time(NULL));

  // Initialization
  for (int i = 0; i < MAX_TASKS; i++) {
    tasks[i].id = i + 1;
    tasks[i].progress = 0;
    tasks[i].step = rand() % 5 + 1;
  }

  int tasks_incomplete = 1;
  while (tasks_incomplete) {
    tasks_incomplete = 0;
    clear_screen();
    for (int i = 0; i < MAX_TASKS; i++) {
      tasks[i].progress += tasks[i].step;
      if (tasks[i].progress > 100) {
        tasks[i].progress = 100;
      } else if (tasks[i].progress < 100) {
        tasks_incomplete = 1;
      }
      print_bar(tasks[i]);
    }
#ifdef _WIN32
    Sleep(1000); // Sleep for 1 second (1000 milliseconds)
#else
    usleep(1000000); // Sleep for 1 second (1000000 microseconds)
#endif
  }
  printf("All tasks completed!\n");
  return 0;
}

void clear_screen() {
#ifdef _WIN32 
    system("cls");
#else
    printf("\033[H\033[J"); // ANSI escape sequence to clear screen
#endif
}

void print_bar(Task task) {
  int bars_to_show = (task.progress * BAR_LENGTH) / 100;
  printf("Task %d: [", task.id);
  for (int i = 0; i < BAR_LENGTH; i++) {
    if (i < bars_to_show) {
      printf("=");
    } else {
      printf(" ");
    }
  }
  printf("] %d%%\n", task.progress);
}
