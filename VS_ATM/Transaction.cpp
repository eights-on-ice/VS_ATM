#include "Transaction.h"

Transaction::Transaction(int acc_number, BankDatabase* currentBDB)
{
	BDB = currentBDB;
	accountNumber = acc_number;
}

Transaction::Transaction(int acc_number, BankDatabase* currentBDB, CashDispenser* currentCD)
{
	BDB = currentBDB;
	CD = currentCD;
	accountNumber = acc_number;
	amount = 0;
}

void Transaction::setBDB(BankDatabase* newBDB)
{
	BDB = newBDB;
}

void Transaction::setCD(CashDispenser* newCD)
{
	CD = newCD;
}

void Transaction::execute()
{
	SC.displayMessage("virtual");
}
