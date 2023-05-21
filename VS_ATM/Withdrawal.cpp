#include "Withdrawal.h"

Withdrawal::Withdrawal(int acc_number, BankDatabase* currentBDB, CashDispenser* currentCD) 
	: Transaction(acc_number, currentBDB, currentCD)
{
}

void Withdrawal::displayMenuOfAmounts()
{
	SC.displayMessage("Withdrawal options: ");
	SC.displayMessage("1 - $20     4 - $100");
	SC.displayMessage("2 - $40     5 - $200");
	SC.displayMessage("3 - $60     6 - Cancel transaction");
	SC.displayMessage("Choose a withdrawal option (1-6):");
}

void Withdrawal::execute()
{
	displayMenuOfAmounts();
	int choice = KP.getInput();

	switch (choice)
	{
	case 1:
		amount = 20;
		break;
	case 2:
		amount = 40;
		break;
	case 3:
		amount = 60;
		break;
	case 4:
		amount = 100;
		break;
	case 5:
		amount = 200;
		break;
	case 6:
		SC.displayMessage("Transaction cancelled.");
		break;
	default:
		SC.displayMessage("Error: invalid input.");
		execute();
	}
	
	if (choice != 6)
	{
		if (BDB->getTotalBalance(accountNumber) >= amount)
		{
			if (CD->isSufficientCashAvailable(amount))
			{
				BDB->getAccount(accountNumber)->debit(amount);
				CD->dispenseCash(amount);
				SC.displayMessage("Please take cash.");
				SC.displayMessage("  ");
			}
			else
			{
				SC.displayMessage("Error: insufficient bills in ATM.");
				SC.displayMessage("Please enter a smaller amount.");
				execute();
			}
		}
		else
		{
			SC.displayMessage("Error: insufficient funds.");
			SC.displayMessage("Please enter a smaller amount.");
			execute();
		}
	}
}
