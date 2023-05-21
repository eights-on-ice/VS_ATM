#pragma once
#include "Withdrawal.h"
#include "Deposit.h"
#include "BalanceInquiry.h"

class ATM
{
private:
	bool userAuthenticated = false;
	
	BankDatabase* BDB;
	CashDispenser* CD;
	Screen SC;
	Keypad KP;
	DepositSlot DS;

public:
	ATM(BankDatabase* currentBDB, CashDispenser* currentCD);

	void displayMenue();
	void performTransaction(int);
	void run();
};