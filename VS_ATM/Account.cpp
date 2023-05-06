#include "Account.h"

Account::Account()
{
    accountNumber = 0;
    pin = 0;
    availableBalance = 0;
    totalBalance = 0;
}

Account::Account(int acc_n, int pn, double avB, double tB)
{
    accountNumber = acc_n;
    pin = pn;
    availableBalance = avB;
    totalBalance = tB;
}

int Account::getAccountNumber()
{
    return accountNumber;
}

void Account::credit(double amount)
{
    totalBalance = totalBalance + amount;
}

void Account::debit(double amount)
{
    totalBalance -= amount;
}

bool Account::validatePIN(int pn)
{
    if (pn == pin)
        return true;
    else
        return false;
}

double Account::getAvailableBalance()
{
    return availableBalance;
}

double Account::getTotalBalance()
{
    return totalBalance;
}