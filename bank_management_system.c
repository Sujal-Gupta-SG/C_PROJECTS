// Password :- login

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date
{
    int day, month, year;
};

struct account
{
    char account_n[15];
    char name[60];
    int age;
    struct date dob; // Add struct date for date of birth
    char address[100];
    char phone_number[15];
    float amt;
};

// # Customer Bank Management System

// ![GitHub](https://img.shields.io/github/license/Sujal092004/Repositories) ![GitHub last commit](https://img.shields.io/github/last-commit/Sujal092004/Repositories)

// This repository contains a simple Customer Bank Management System implemented in C. The system allows users to perform various banking operations, including opening a new account, viewing account details, and exiting the system. Users must enter a password to access the system.

// ## Table of Contents

// - [Features](#features)
// - [Usage](#usage)
// - [Author](#author)
// - [License](#license)

// ## Features

// ### Password Protection
// - The system is password-protected to ensure only authorized users can access it. The default password is "login."

// ### New Account Opening
// - Users can create a new bank account by providing details such as account number, name, date of birth, age, phone number, address, and initial deposit amount. The system validates age and requires a minimum initial deposit of Rs. 1000.

// ### Show Account Details
// - Users can view the details of an existing account by entering the account number. The system displays information such as account number, name, date of birth, age, phone number, address, and account balance.

// ### Error Handling
// - The system handles errors gracefully, providing appropriate messages when invalid inputs are provided or when an account is not found.

// ## Usage

// To use this Customer Bank Management System, follow these steps:

// 1. Clone the repository to your local machine:
//    ```bash
//    git clone https://github.com/Sujal092004/Repositories.git
//    ```

// 2. Compile the code using a C compiler (e.g., GCC):
//    ```bash
//    gcc -o bank_system bank_system.c
//    ```

// 3. Run the compiled program:
//    ```bash
//    ./bank_system
//    ```

// 4. You will be prompted to enter the password. The default password is "login."

// 5. Once authenticated, you can choose from the following options:
//    - Option 1: New Account Opening
//    - Option 2: Show Account Details
//    - Option 3: Exit

// ## Author

// This Customer Bank Management System was developed by [SUJAl](https://github.com/Sujal092004).

// ## License

// This project is licensed under the [MIT License](LICENSE).

// **Note:** This system is a basic example and may not be suit

struct account edit(struct account *ad)
{
    struct date dob;
    struct account add;
    int choice_back = 0;

    printf("\nEnter option number you want to edit:");
    printf("\n1) For Mobile/Phone Number");
    printf("\n2) For Address");
    printf("\n3) For date of Birth (DD/MM/YYYY)");
    printf("\n4) For name ");
    printf("\n5) For First Deposit amount");
    printf("\nEnter option number: ");
    scanf("%d", &choice_back);

    switch (choice_back)
    {
    case 1:
        printf("\nEnter Mobile/Phone Number: ");
        scanf("%s", &add.phone_number);

        break;
    case 2:
        printf("\nEnter Address: ");
        scanf("%s", add.address);
        break;
    case 3:
        printf("\nEnter date of Birth (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &dob.day, &dob.month, &dob.year);
        break;
    case 4:
        printf("\nEnter the name: ");
        scanf("%s", add.name);
        break;
    case 5:
        printf("\nEnter First Deposit amount: ");
        scanf("%f", &add.amt);
        break;
    default:
        printf("\nInvalid option. Please try again.\n");
        break;
    }
    system("cls");
    *ad = add; // Update the original structure with the edited details

    return *ad;
}

void account();
void menu();
void showAccountDetails(struct account acc);
int login_page();
struct account getAccountDetails(const char *accountNumber);

void account()
{
    int choice_back, option;
    FILE *ptr;
    struct date new_date, dob;
    struct account check, add;

new_record:
    printf("\n\t\t\t\t\tADD RECORD");
    printf("\n\n\t\t\tEnter Today's Date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &new_date.day, &new_date.month, &new_date.year);

    printf("\nEnter The Account Number: ");
    scanf("%s", check.account_n);
    ptr = fopen("record.data", "r");

    while (fscanf(ptr, "%d %d %d %s %s %d %d %d %d %s %s %f\n", &new_date.day, &new_date.month, &new_date.year, add.account_n, add.name, &dob.day, &dob.month, &dob.year, &add.age, add.address, add.phone_number, &add.amt) != EOF)
    {
        if (strcmp(check.account_n, add.account_n) == 0)
        {
            fclose(ptr);
            printf("\nAccount number already in use!");
        sel_option:
            printf("\nTo start again press 1 and 0 to exit:\t");
            scanf("%d", &choice_back);
            if (choice_back == 1)
            {
                system("cls");
                printf("\nYou can start again:");
                goto new_record;
            }
            else if (choice_back == 0)
            {
                system("cls");
                printf("\nGoing to exit:\n");
                return;
            }
            else
            {
                printf("Invalid choice!\nTaking You back to select correct option \n");
                goto sel_option;
            }
        }
    }

    fclose(ptr);
    choice_back = 0;
    strcpy(add.account_n, check.account_n);

    printf("\nEnter the name: ");
    scanf("%s", add.name);

    printf("\nEnter date of Birth (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &dob.day, &dob.month, &dob.year);

    printf("\nEnter the age: ");
    scanf("%d", &add.age);
    if (add.age >= 18)
    {
    }
    else
    {
    select_opt2:
        printf("\n\t\t\tplease accept terms and condition\n");
        printf("\nyou have taken permission from your parent\nIf yes then type 1\nIf no type 0");
        printf("\nEnter your selected option:\t");
        scanf("%d", &choice_back);
        if (choice_back == 1)
        {
            return;
        }
        else if (choice_back == 0)
        {
            system("cls");
            menu();
        }
        else
        {
            printf("\n Invalid choice \n Please Enter Correct Option \n");
            system("cls");
            goto select_opt2;
        }
    }

    printf("\nEnter Mobile/Phone Number: ");
    scanf("%s", &add.phone_number);

    printf("\nEnter Address: ");
    scanf("%s", add.address);

    printf("\nMinimum balance should be Rs. 1000, so deposit above 1000 Rs.");

    printf("\nEnter First Deposit amount: ");
    scanf("%f", &add.amt);
details:
    printf("Your Details that you have entered:\n");
    printf("Account Opening Date (DD/MM/YYYY): %d/%d/%d\n", new_date.day, new_date.month, new_date.year);
    printf("Entered Account Number: %s\n", add.account_n);
    printf("Entered Name: %s\n", add.name);
    printf("Entered Date of Birth (DD/MM/YYYY): %d/%d/%d\n", dob.day, dob.month, dob.year);
    printf("Entered Age: %d\n", add.age);
    printf("Entered Mobile Number: %s\n", add.phone_number);
    printf("Entered Address: %s\n", add.address);
    printf("\nEntered Details is correct\n Type 1 for YES and 0 for EDIT:");
    scanf("%d", &option);
    if (option == 1)
    {
    }
    else if (option == 0)
    {
        system("cls");
        add = edit(&add); // Call the edit() function and update the add structure
        goto details;
    }
    else
    {
        printf("\nInvalid option.Please try again.");
        goto details;
    }

    ptr = fopen("record.data", "a+");
    fprintf(ptr, "%d %d %d %s %s %d %d %d %d %s %s %f\n",
            new_date.day, new_date.month, new_date.year,
            add.account_n, add.name, dob.day, dob.month, dob.year,
            add.age, add.address, add.phone_number, add.amt);

    fclose(ptr);
    system("cls");

    printf("\nAccount created successfully.\n");
    printf("\nGoing back to menu ::");

    menu();
}

void showAccountDetails(struct account acc)
{
    printf("\nAccount Details:\n");
    printf("Account Number: %s\n", acc.account_n);
    printf("Name: %s\n", acc.name);
    printf("Date of Birth: %d/%d/%d\n", acc.dob.day, acc.dob.month, acc.dob.year);
    printf("Age: %d\n", acc.age);
    printf("Mobile Number: %s\n", acc.phone_number);
    printf("Address: %s\n", acc.address);
    printf("Balance: %.2f\n", acc.amt);
}

struct account getAccountDetails(const char *accountNumber)
{
    FILE *ptr = fopen("record.data", "r");
    struct account acc;
    int found = 0;

    while (fscanf(ptr, "%d %d %d %s %s %d %d %d %d %s %s %f\n",
                  &acc.dob.day, &acc.dob.month, &acc.dob.year,
                  acc.account_n, acc.name, &acc.dob.day,
                  &acc.dob.month, &acc.dob.year, &acc.age,
                  acc.address, acc.phone_number, &acc.amt) != EOF)
    {
        if (strcmp(accountNumber, acc.account_n) == 0)
        {
            found = 1;
            break;
        }
    }

    fclose(ptr);

    if (found)
    {
        return acc;
    }
    else
    {
        // Handle case when account number is not found
        // You can return a default account or indicate an error
        // Here, I'm assuming default values for the account
        strcpy(acc.account_n, "N/A");
        strcpy(acc.name, "N/A");
        acc.dob.day = acc.dob.month = acc.dob.year = 0;
        acc.age = 0;
        strcpy(acc.address, "N/A");
        strcpy(acc.phone_number, "N/A");
        acc.amt = 0.0;
        return acc;
    }
}

void menu()
{
    int choice;
home_page:
    printf("\n\n\n\t\t\t\t\tCustomer Bank Management System");
    printf("\n1. New Account Opening");
    printf("\n2. Show Account Details"); // New option
    printf("\n3. Exit");
    printf("\n\n\t\tEnter Your Choice: ");
    scanf("%d", &choice);
    system("cls");

    switch (choice)
    {
    case 1:
        account();
        break;
    case 2:
    {
        char accountNumber[15];
        printf("\nEnter Account Number: ");
        scanf("%s", accountNumber);
        struct account acc = getAccountDetails(accountNumber);
        showAccountDetails(acc);
        break;
    }

    case 3:
        printf("\nThank you for using the Customer Bank Management System!\n");
        break;
    default:
        printf("\nInvalid choice! Please try again.\n");
        menu();
        break;
    }
}

int login_page()
{
    int main_exit;
    char pass[10], password[10] = "login";

    printf("\n\t\t\tEnter The Password To Login: ");
    scanf("%s", pass);
    system("cls");

    if (strcmp(pass, password) == 0)
    {
        printf("\t\tPassword match\n\nLoading");
        for (int i = 0; i <= 6; i++)
        {
            printf(".");
        }
        printf("\n");
        system("cls");
        menu();
    }
    else
    {
        printf("\n\t\tPassword Mismatch\n\n");
        printf("\tEnter 1 to Retry and 0 to Exit: ");
        scanf("%d", &main_exit);

        if (main_exit == 1)
        {
            login_page();
        }
        else if (main_exit == 0)
        {
            system("cls");
            printf("\nThank you for using the Customer Bank Management System!\n");
        }
        else
        {
            printf("Invalid choice!\nTaking You to Login Page\n");
            login_page();
        }
    }

    return 0;
}

int main()
{
    login_page();
    return 0;
}
