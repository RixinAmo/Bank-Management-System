#include <iostream>
#include "Bank.h"

using namespace std;

int main() {

    Bank bank;

    int choice;

    do {

        cout << "\n====== BANK MANAGEMENT SYSTEM ======\n";

        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. View All Accounts\n";
        cout << "6. Delete Account\n";
        cout << "7. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

            case 1:
                bank.createAccount();
                break;

            case 2:
                bank.depositMoney();
                break;

            case 3:
                bank.withdrawMoney();
                break;

            case 4:
                bank.checkBalance();
                break;

            case 5:
                bank.viewAccounts();
                break;

            case 6:
                bank.deleteAccount();
                break;

            case 7:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 7);

    return 0;
}