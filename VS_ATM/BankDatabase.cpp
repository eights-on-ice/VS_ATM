#include "BankDatabase.h"
#include <iostream>
using namespace std;

BankDatabase::BankDatabase()
{
    Account ahmed(1, 1, 1000, 5000);
    Account nasser(2, 2, 500, 5000);
    Account abslam(3, 3, 250, 5000);

    accounts[0] = ahmed;
    accounts[1] = nasser;
    accounts[2] = abslam;
}

Account* BankDatabase::getAccount(int acc_number)
{
    for (int i = 0; i < 3; i++)
    {
        if (accounts[i].getAccountNumber() == acc_number)
            return &accounts[i];
    }
}

bool BankDatabase::authenticateUser(int acc_number, int pn)
{   
    if (getAccount(acc_number)->validatePIN(pn))
        return true;
    else
        return false;
}

double BankDatabase::getAvailableBalance(int acc_number)
{
    return getAccount(acc_number)->getAvailableBalance();
}

double BankDatabase::getTotalBalance(int acc_number)
{
    return getAccount(acc_number)->getTotalBalance();
}

void BankDatabase::credit(int acc_number, double amount)
{
    getAccount(acc_number)->credit(amount);
}

void BankDatabase::debit(int acc_number, double amount)
{
    getAccount(acc_number)->debit(amount);
}