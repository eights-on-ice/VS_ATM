#pragma once
#include "Withdrawal.h"
#include "Deposit.h"
#include "BalanceInquiry.h"

class ATM
{
private:
	bool userAuthenticated = false; //permits user into main menue when true
	
	BankDatabase* BDB; //will point to Bankdatabase object in main.cpp
	CashDispenser* CD; //will point to CashDispenser object in main.cpp
	Screen SC;
	Keypad KP;
	DepositSlot DS;

public:
	ATM(BankDatabase* currentBDB, CashDispenser* currentCD); //constructs the ATM

	void displayMenue(); //displays main menue
	void performTransaction(int); 
	void run(); //runs the whole thing
};