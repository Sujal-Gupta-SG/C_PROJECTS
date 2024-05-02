# User Management System

This program allows users to register and login to a user management system. It provides functionalities for user registration, login, and exiting the program.

## Features:

- **Registration:** Users can register with a unique username and password.
- **Login:** Registered users can login with their credentials.
- **Username and Password Handling:** Handles input for usernames and passwords securely.
- **Maximum Users:** Supports a maximum of 10 users for registration.
- **User-Friendly Interface:** Simple menu-based interface for ease of use.
- **Error Handling:** Provides error messages for invalid input and login failures.

## How to Use:

1. **Run the Program:**
   - Compile and run the program using a C compiler.

2. **Menu Options:**
   - **Register (Option 1):** Allows new users to register with a unique username and password.
   - **Login (Option 2):** Registered users can login with their credentials.
   - **Exit (Option 3):** Terminates the program.

3. **Registration:**
   - Enter a unique username and password to register as a new user.

4. **Login:**
   - Enter the registered username and password to login.
   - Password input is masked for security.

5. **Exiting the Program:**
   - Choose the exit option from the menu to terminate the program.

## Compatibility:

- **Operating System:** Compatible with systems supporting ANSI C.
- **Compiler:** Works with standard C compilers like GCC, Clang, and Microsoft Visual Studio.

## Security Note:

- While password masking is enabled during input, remember to handle sensitive user data securely in production environments.

## Customization:

- Modify the `MAX_USERS` constant to change the maximum number of supported users.

Enjoy managing your users with this simple User Management System! Feel free to modify the code or provide feedback for improvements.
