#pragma once

class Account
{
private:
    int accountNumber;
    int pin;
    double availableBalance;
    double totalBalance;

public:
    Account();
    Account(int, int, double, double);

    bool validatePIN(int);
    double getAvailableBalance();
    double getTotalBalance();
    int getAccountNumber();

    void credit(double);
    void debit(double);
};
