#pragma once
#include "Transaction.h"

class Withdrawal : public Transaction
{
public:
	Withdrawal(int, BankDatabase* currentBDB, CashDispenser* currentCD);

	void displayMenuOfAmounts();

	void execute();
};