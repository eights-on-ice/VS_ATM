#include "Deposit.h"

Deposit::Deposit(int acc_number, BankDatabase* currentBDB, CashDispenser* currentCD) //constructing Withdrawal obj and
	: Transaction(acc_number, currentBDB, currentCD)								 //delegating to base class constructor
{
}

void Deposit::promptForDepositAmount()
{
	SC.displayMessage("Enter deposit amount in cents, or zero to cancel.");
}

void Deposit::execute()
{
	promptForDepositAmount();

	double input = KP.getDouble();

	if (input) //if input !=0 (i.e., transaction isnt cancelled)
	{
		amount = input / 100.0; //get amount in dollars

		SC.displayMessage("Please insert a deposit envelope...");

		if (DS.isEnvelopeReceived()) // always true
		{
			SC.displayMessage("Envelope received.");
			BDB->credit(accountNumber, amount); //completes transaction through bankdatabase
		}
	}
}
