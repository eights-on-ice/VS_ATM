#pragma once
#include "Transaction.h"
#include "DepositSlot.h"

class Deposit : public Transaction //inheriting from Transactions with public access specifier
{
private:
	DepositSlot DS; //to receive envelope later

public:
	Deposit(int, BankDatabase* currentBDB, CashDispenser* currentCD); //initializes Deposit object

	void promptForDepositAmount(); //asks user for amount

	void execute(); //excute function for Withdrawal
};