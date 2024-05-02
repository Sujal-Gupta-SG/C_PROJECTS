# Bank Management System

The Bank Management System is a simple program that allows users to perform basic banking operations such as creating an account, depositing money, withdrawing money, and checking the account balance.

## Features:

- **Account Creation:** Users can create a new bank account by providing their name and account number.
- **Deposit Money:** Account holders can deposit money into their accounts.
- **Withdraw Money:** Account holders can withdraw money from their accounts, provided they have sufficient balance.
- **Check Balance:** Users can check their account balance.
- **Data Persistence:** Account data is stored in a binary file (`account.dat`) for persistence.

## How to Use:

1. **Run the Program:**
   - Compile and run the program using a C compiler.

2. **Menu Options:**
   - **Create Account (Option 1):** Allows users to create a new bank account by providing their name and account number.
   - **Deposit Money (Option 2):** Account holders can deposit money into their accounts by entering their account number and the amount to be deposited.
   - **Withdraw Money (Option 3):** Account holders can withdraw money from their accounts by entering their account number and the amount to be withdrawn.
   - **Check Balance (Option 4):** Users can check their account balance by entering their account number.
   - **Exit (Option 5):** Terminates the program.

3. **Account Creation:**
   - Enter your name and account number to create a new account.

4. **Deposit Money:**
   - Enter your account number and the amount to be deposited.

5. **Withdraw Money:**
   - Enter your account number and the amount to be withdrawn.

6. **Check Balance:**
   - Enter your account number to view your current account balance.

7. **Exiting the Program:**
   - Choose the exit option from the menu to terminate the program.

## Compatibility:

- **Operating System:** Compatible with systems supporting ANSI C.
- **Compiler:** Works with standard C compilers like GCC, Clang, and Microsoft Visual Studio.

## Customization:

- Modify the `ACCOUNT_FILE` constant to change the name of the file where account data is stored.
- Adjust the maximum length of the name field and other parameters as needed.

Enjoy managing your bank accounts with this simple Bank Management System! Feel free to modify the code or provide feedback for improvements.
