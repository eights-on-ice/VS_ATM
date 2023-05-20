#pragma once
#include "Account.h"

class BankDatabase
{
private:
    Account accounts[3];

public:
    BankDatabase();

    Account* getAccount(int);

    bool authenticateUser(int, int);
    double getAvailableBalance(int);
    double getTotalBalance(int);

    void credit(int, double);
    void debit(int, double);
};

