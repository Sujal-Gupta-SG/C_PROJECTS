# Kaun Banega Crorepati (KBC) Game

## Description
This is a console-based version of the popular Indian television game show "Kaun Banega Crorepati" (Who Wants to Be a Millionaire). Players are presented with a series of multiple-choice questions and can win increasing amounts of virtual money for each correct answer. They also have the option to use lifelines to help them answer questions.

## Features
- Randomly selects questions from a provided question bank file
- Supports two lifelines: Fifty-Fifty and Skip the Question
- Uses threading to implement a timer for each question
- Provides colorful output in the console for a better user experience

## Dependencies
- Standard C libraries: stdio.h, stdlib.h, string.h, ctype.h, unistd.h, time.h, stdbool.h
- POSIX threading library: pthread.h

## Usage
1. Compile the program using a C compiler (e.g., gcc).
2. Run the compiled executable.
3. Answer the questions by entering the corresponding option (A, B, C, or D) or use lifelines by entering 'L'.
4. Enjoy the game and see how much virtual money you can win!

## Files
- `main.c`: Contains the main code for the game.
- `questions.txt`: Question bank file containing multiple-choice questions in the required format.

## How to Run
Compile the program using the following command:
```bash
gcc main.c -o kbc_game -pthread
