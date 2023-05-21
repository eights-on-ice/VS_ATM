#include "Deposit.h"

Deposit::Deposit(int acc_number, BankDatabase* currentBDB, CashDispenser* currentCD)
	: Transaction(acc_number, currentBDB, currentCD)
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

	if (input)
	{
		amount = input / 100.0;

		SC.displayMessage("Please insert a deposit envelope...");

		if (DS.isEnvelopeReceived())
		{
			SC.displayMessage("Envelope received.");
			BDB->getAccount(accountNumber)->credit(amount);
		}
	}
}
