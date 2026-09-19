# Bank Management System

A console-based **Bank Management System** developed using **C++ OOP concepts** and **MySQL Database**.  
The project allows users to create accounts, deposit money, withdraw money, check balance, view accounts, and delete accounts.

## Features

- Create new bank account
- Deposit money into account
- Withdraw money from account
- Check account balance
- View all account details
- Delete account
- MySQL database integration

---

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- MySQL
- MySQL Connector/C++
- Visual Studio Code
- Microsoft Visual C++ Compiler (MSVC)

---

## Project Structure

```
BankProject
│
├── main.cpp          # Main program and menu handling
│
├── Bank.h            # Bank class declaration
├── Bank.cpp          # Bank class implementation
│
├── Database.h        # Database connection class declaration
├── Database.cpp      # MySQL connection implementation
│
├── README.md
└── .gitignore
```

---

# Database Setup

## Step 1: Create Database

Open MySQL Command Line or MySQL Workbench.

Run:

```sql
CREATE DATABASE banking_system;

USE banking_system;
```

---

## Step 2: Create Table

Run:

```sql
CREATE TABLE accounts (

    id INT PRIMARY KEY AUTO_INCREMENT,

    name VARCHAR(100),

    account_no VARCHAR(20) UNIQUE,

    pin VARCHAR(10),

    balance DOUBLE

);
```

---

# MySQL Connector Setup

Install:

**MySQL Connector/C++**

The project uses:

```
MySQL Connector C++ 9.7
```

Make sure the connector path exists:

```
C:/Program Files/MySQL/MySQL Connector C++ 9.7/
```

---

# Configuration

Update MySQL credentials in:

```
Database.cpp
```

Example:

```cpp
con = driver->connect(
    "tcp://127.0.0.1:3306",
    "root",
    "admin"
);
```

Change:

```
root     → MySQL username

admin    → MySQL password
```

---

# How to Run the Project

## Step 1: Clone Repository

```bash
git clone https://github.com/your_username/Bank-Management-System.git
```

Go inside project folder:

```bash
cd Bank-Management-System
```

---

## Step 2: Open Project

Open the folder in Visual Studio Code.

---

## Step 3: Build Project

Use **x64 Native Tools Command Prompt for VS 2022**.

Navigate to project folder:

```cmd
cd C:\Users\YourName\Desktop\BankProject
```

Compile:

```cmd
cl.exe /Zi /EHsc /nologo ^
main.cpp Bank.cpp Database.cpp ^
/I "C:/Program Files/MySQL/MySQL Connector C++ 9.7/include" ^
/link ^
/LIBPATH:"C:/Program Files/MySQL/MySQL Connector C++ 9.7/lib64/vs14" ^
mysqlcppconn.lib
```

---

## Step 4: Run Application

After successful compilation:

```cmd
main.exe
```

---

# Application Menu

```
====== BANK MANAGEMENT SYSTEM ======

1. Create Account
2. Deposit Money
3. Withdraw Money
4. Check Balance
5. View All Accounts
6. Delete Account
7. Exit
```

---

# OOP Concepts Used

## Classes and Objects

The project contains:

- Bank class
- Database class

Objects are created to manage banking operations.

---

## Encapsulation

Database connection details are hidden inside the Database class.

---

## Exception Handling

SQL exceptions are handled using:

```cpp
try-catch
```

---

# Database Operations

The project performs:

- INSERT → Create Account
- UPDATE → Deposit/Withdraw Money
- SELECT → View Account Details
- DELETE → Remove Account

---

# Future Improvements

- User login system using PIN
- Transaction history
- Admin panel
- Password encryption
- GUI interface using Qt/Java Swing

---
