# Progress Bar

This program implements a simple progress bar to visualize the progress of multiple tasks simultaneously.

## Features:

- **Multi-Tasking:** Supports tracking the progress of up to 10 tasks concurrently.
- **Dynamic Progress:** Each task progresses independently at a random rate.
- **Real-time Visualization:** Updates and displays the progress bar every second.
- **Cross-platform Compatibility:** Compatible with both Windows and Unix-based systems.

## How to Use:

1. **Run the Program:**
   - Compile and run the program using a C compiler.
   - The progress bars for each task will be displayed in the console window.

2. **Monitor Progress:**
   - Each task is represented by a progress bar.
   - The length of the bar indicates the task's progress, and the percentage is displayed next to it.

3. **Completion:**
   - Once all tasks reach 100% completion, the program notifies the user that all tasks are completed.

4. **Exit Program:**
   - Terminate the program when done monitoring the progress.

## Compatibility:

- **Windows:**
  - Utilizes the `Sleep` function from the `windows.h` library for timing.
  - Clears the screen using the `cls` command.

- **Unix-based Systems:**
  - Uses `usleep` for timing.
  - Clears the screen using ANSI escape sequences.

## How to Run:

1. **Compile:**
   - Compile the program using a C compiler such as GCC or Clang.

2. **Run:**
   - Run the compiled executable file to start monitoring the progress.

3. **Monitor Progress:**
   - Watch the progress bars update in real-time until all tasks are completed.

Enjoy monitoring your tasks with the progress bar! Feel free to modify the code or provide feedback for improvements.
