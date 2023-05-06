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
    Account* acc = new Account;

    for (int i = 0; i < 3; i++)
    {
        if (accounts[i].getAccountNumber() == acc_number)
            acc = &accounts[i];
    }

    return acc;
}

bool BankDatabase::authenticateUser(int acc_number, int pn)
{   
    Account* acc = getAccount(acc_number);

    if ((*acc).validatePIN(pn))
        return true;
    else
        return false;

    delete acc;
}

double BankDatabase::getAvailableBalance(int acc_number)
{
    Account* acc = getAccount(acc_number);

    return (*acc).getAvailableBalance();

    delete acc;
}

double BankDatabase::getTotalBalance(int acc_number)
{
    Account* acc = getAccount(acc_number);

    return (*acc).getTotalBalance();

    delete acc;
}

void BankDatabase::credit(int acc_number, double amount)
{
    Account* acc = getAccount(acc_number);

    (*acc).credit(amount);

    delete acc;
}

void BankDatabase::debit(int acc_number, double amount)
{
    Account* acc = getAccount(acc_number);

    (*acc).debit(amount);
    
    delete acc;
}