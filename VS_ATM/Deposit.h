#pragma once
#include "Transaction.h"
#include "DepositSlot.h"

class Deposit : public Transaction
{
private:
	DepositSlot DS;

public:
	Deposit(int, BankDatabase* currentBDB, CashDispenser* currentCD);

	void promptForDepositAmount();

	void execute();
};