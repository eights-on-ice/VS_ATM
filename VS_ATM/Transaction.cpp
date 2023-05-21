#include "Transaction.h"

Transaction::Transaction(int acc_number, BankDatabase* currentBDB)
{
	//initializing attributes
	BDB = currentBDB;
	accountNumber = acc_number;

	CD = nullptr; //wont be needed for BalanceInquiry()
	amount = 0;
}

Transaction::Transaction(int acc_number, BankDatabase* currentBDB, CashDispenser* currentCD)
{
	//initializing attributes
	BDB = currentBDB;
	CD = currentCD;
	accountNumber = acc_number;
	amount = 0;
}

void Transaction::execute()
{
	SC.displayMessage("virtual");
}
