# Customer Bank Management System

This repository contains a simple Customer Bank Management System implemented in C. The system allows users to perform various banking operations, including opening a new account, viewing account details, and exiting the system. Users must enter a password to access the system.

## Table of Contents

- [Features](#features)
- [Usage](#usage)
- [Author](#author)
- [License](#license)

## Features

### Password Protection
- The system is password-protected to ensure only authorized users can access it. The default password is "login."

### New Account Opening
- Users can create a new bank account by providing details such as account number, name, date of birth, age, phone number, address, and initial deposit amount. The system validates age and requires a minimum initial deposit of Rs. 1000.

### Show Account Details
- Users can view the details of an existing account by entering the account number. The system displays information such as account number, name, date of birth, age, phone number, address, and account balance.

### Error Handling
- The system handles errors gracefully, providing appropriate messages when invalid inputs are provided or when an account is not found.

## Usage

To use this Customer Bank Management System, follow these steps:

1. Clone the repository to your local machine.

2. Compile the code using a C compiler (e.g., GCC):
   ```bash
   gcc -o bank_system bank_system.c
