#pragma once
#include "Transaction.h"

class BalanceInquiry : public Transaction
{
public:
	BalanceInquiry(int, BankDatabase* currentBDB);

	void execute();
};