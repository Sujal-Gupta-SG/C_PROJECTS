# Number Guessing Game

This program is a simple number guessing game implemented in C. The player needs to guess a randomly generated number between 1 and 100 within a limited number of attempts.

## How to Play:

1. **Welcome Message:**
   - Upon starting the game, the player receives a welcome message.

2. **Generate Random Number:**
   - A random number between 1 and 100 is generated using the `rand()` function from the `stdlib.h` library.

3. **Guessing Loop:**
   - The player is prompted to enter their guess.
   - If the guess is lower than the random number, a message instructs the player to guess a larger number.
   - If the guess is higher than the random number, a message instructs the player to guess a smaller number.
   - If the guess is correct, a congratulatory message is displayed along with the number of attempts taken.

4. **Exit:**
   - The game continues until the player correctly guesses the number.
   - Upon guessing the correct number, a goodbye message is displayed, and the game ends.

## Features:

- Random number generation ensures each game session is different.
- Limited number of attempts adds challenge and excitement to the game.
- Simple and intuitive interface for easy gameplay.

## How to Run:

1. **Compile:**
   - Compile the program using a C compiler such as GCC or Clang.

2. **Run:**
   - Run the compiled executable file to start the game.

3. **Guess:**
   - Follow the prompts to guess the random number within the specified range.

4. **Win:**
   - Keep guessing until you correctly guess the number.

5. **Exit:**
   - After guessing the correct number, the game will end with a goodbye message.

## Developer:

- **Name:** Sujal

Enjoy playing the number guessing game! Feel free to modify the code or provide feedback for improvements.
