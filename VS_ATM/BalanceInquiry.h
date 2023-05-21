#pragma once
#include "Transaction.h"

class BalanceInquiry : public Transaction //inheriting from Transactions with public access specifier
{
public:
	BalanceInquiry(int, BankDatabase* currentBDB); //initializes BalanceInquiry object

	void execute(); //excute function for Withdrawal
};