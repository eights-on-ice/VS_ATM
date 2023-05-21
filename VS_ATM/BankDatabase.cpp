#include "BankDatabase.h"

//BankDatabase::BankDatabase(const Account& acc1, const Account& acc2, const Account& acc3) : accounts()
//{
//    Account ahmed(1, 1, 1000, 1000);
//    Account nasser(2, 2, 500, 500);
//    Account abslam(3, 3, 250, 250);
//
//    accounts[0] = acc1;
//    accounts[1] = acc2;
//    accounts[2] = acc3;
//}

BankDatabase::BankDatabase()
{
    Account ahmed(1, 1, 1000, 1000);
    Account nasser(2, 2, 500, 500);
    Account abslam(3, 3, 250, 250);

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