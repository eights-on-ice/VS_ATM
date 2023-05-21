#pragma once
#include "Transaction.h"

class Withdrawal : public Transaction //inheriting from Transactions with public access specifier
{
public:
	Withdrawal(int, BankDatabase* currentBDB, CashDispenser* currentCD); //initializes Withdrawal object

	void displayMenuOfAmounts(); //prints withdrawal menue at runtime

	void execute(); //excute function for Withdrawal
};