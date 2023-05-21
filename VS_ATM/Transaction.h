#pragma once
#include "BankDatabase.h"
#include "CashDispenser.h"
#include "Keypad.h"
#include "Screen.h"

//parent of Deposit, Withdrawal,
//and BalanceInquiry

class Transaction
{

//shared data fields for child classes
protected:
	int accountNumber; 
	double amount;

	BankDatabase* BDB; //will point to Bankdatabase object in main.cpp
	CashDispenser* CD; //will point to CashDispenser object in main.cpp
	Keypad KP;
	Screen SC;

public:

	Transaction(int, BankDatabase* currentBDB); //constructor for BalanceInquiry
	Transaction(int,  BankDatabase* currentBDB, CashDispenser* currentCD); //constructor for Deposit and Withdrawal

	virtual void execute(); //will be redefined in each child class and dynamically binded
};