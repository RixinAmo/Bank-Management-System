#include "Bank.h"

void Bank::createAccount() {

    string name;
    string accountNo;
    string pin;
    double balance;

    cin.ignore();

    cout << "\nEnter Name: ";
    getline(cin, name);

    cout << "Enter Account Number: ";
    cin >> accountNo;

    cout << "Enter PIN: ";
    cin >> pin;

    cout << "Enter Initial Balance: ";
    cin >> balance;

    try {

        sql::PreparedStatement *pstmt;

        pstmt = db.getConnection()->prepareStatement(
            "INSERT INTO accounts(name, account_no, pin, balance) VALUES(?,?,?,?)"
        );

        pstmt->setString(1, name);
        pstmt->setString(2, accountNo);
        pstmt->setString(3, pin);
        pstmt->setDouble(4, balance);

        pstmt->execute();

        cout << "\nAccount Created Successfully!\n";

        delete pstmt;
    }
    catch(sql::SQLException &e) {

        cout << e.what() << endl;
    }
}

void Bank::depositMoney() {

    string accountNo;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> accountNo;

    cout << "Enter Amount: ";
    cin >> amount;

    try {

        sql::PreparedStatement *pstmt;

        pstmt = db.getConnection()->prepareStatement(
            "UPDATE accounts SET balance = balance + ? WHERE account_no=?"
        );

        pstmt->setDouble(1, amount);
        pstmt->setString(2, accountNo);

        pstmt->execute();

        cout << "\nMoney Deposited Successfully!\n";

        delete pstmt;
    }
    catch(sql::SQLException &e) {

        cout << e.what() << endl;
    }
}

void Bank::withdrawMoney() {

    string accountNo;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> accountNo;

    cout << "Enter Amount: ";
    cin >> amount;

    try {

        sql::PreparedStatement *pstmt;

        pstmt = db.getConnection()->prepareStatement(
            "UPDATE accounts SET balance = balance - ? WHERE account_no=?"
        );

        pstmt->setDouble(1, amount);
        pstmt->setString(2, accountNo);

        pstmt->execute();

        cout << "\nMoney Withdrawn Successfully!\n";

        delete pstmt;
    }
    catch(sql::SQLException &e) {

        cout << e.what() << endl;
    }
}

void Bank::checkBalance() {

    string accountNo;

    cout << "\nEnter Account Number: ";
    cin >> accountNo;

    try {

        sql::PreparedStatement *pstmt;
        sql::ResultSet *res;

        pstmt = db.getConnection()->prepareStatement(
            "SELECT balance FROM accounts WHERE account_no=?"
        );

        pstmt->setString(1, accountNo);

        res = pstmt->executeQuery();

        if(res->next()) {

            cout << "\nCurrent Balance: "
                 << res->getDouble("balance")
                 << endl;
        }
        else {

            cout << "\nAccount Not Found!\n";
        }

        delete pstmt;
        delete res;
    }
    catch(sql::SQLException &e) {

        cout << e.what() << endl;
    }
}

void Bank::viewAccounts() {

    try {

        sql::Statement *stmt;
        sql::ResultSet *res;

        stmt = db.getConnection()->createStatement();

        res = stmt->executeQuery("SELECT * FROM accounts");

        cout << "\n===== ALL ACCOUNTS =====\n";

        while(res->next()) {

            cout << "\nID: "
                 << res->getInt("id")
                 << endl;

            cout << "Name: "
                 << res->getString("name")
                 << endl;

            cout << "Account Number: "
                 << res->getString("account_no")
                 << endl;

            cout << "Balance: "
                 << res->getDouble("balance")
                 << endl;
        }

        delete stmt;
        delete res;
    }
    catch(sql::SQLException &e) {

        cout << e.what() << endl;
    }
}

void Bank::deleteAccount() {

    string accountNo;

    cout << "\nEnter Account Number: ";
    cin >> accountNo;

    try {

        sql::PreparedStatement *pstmt;

        pstmt = db.getConnection()->prepareStatement(
            "DELETE FROM accounts WHERE account_no=?"
        );

        pstmt->setString(1, accountNo);

        pstmt->execute();

        cout << "\nAccount Deleted Successfully!\n";

        delete pstmt;
    }
    catch(sql::SQLException &e) {

        cout << e.what() << endl;
    }
}