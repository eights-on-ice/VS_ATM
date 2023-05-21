#pragma once
#include "BankDatabase.h"
#include "CashDispenser.h"
#include "Keypad.h"
#include "Screen.h"


class Transaction
{
protected:
	int accountNumber;
	double amount;

	BankDatabase* BDB;
	CashDispenser* CD;
	Keypad KP;
	Screen SC;

public:

	Transaction(int, BankDatabase* currentBDB);
	Transaction(int,  BankDatabase* currentBDB, CashDispenser* currentCD);

	void setBDB(BankDatabase* newBDB);
	void setCD(CashDispenser* newCD);


	virtual void execute();
};