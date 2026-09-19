#ifndef BANK_H
#define BANK_H

#include "Database.h"

class Bank {

private:
    Database db;

public:

    void createAccount();

    void depositMoney();

    void withdrawMoney();

    void checkBalance();

    void viewAccounts();

    void deleteAccount();
};

#endif