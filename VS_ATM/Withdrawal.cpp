#include "Withdrawal.h"

Withdrawal::Withdrawal(int acc_number, BankDatabase* currentBDB, CashDispenser* currentCD) //constructing Withdrawal obj and
	: Transaction(acc_number, currentBDB, currentCD)									   //delegating to base class constructor
{
}

void Withdrawal::displayMenuOfAmounts() //withdrawal menue
{
	SC.displayMessage("Withdrawal options: ");
	SC.displayMessage("1 - $20     4 - $100");
	SC.displayMessage("2 - $40     5 - $200");
	SC.displayMessage("3 - $60     6 - Cancel transaction");
	SC.displayMessage("Choose a withdrawal option (1-6):");
}

void Withdrawal::execute()
{
	displayMenuOfAmounts();     //displaying menue 
	int choice = KP.getInput(); //and getting input from user

	switch (choice) //specifying amount to be withdrawn
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
	}
	
	if (choice != 6) //if user didnt choose to cancel transaction
	{
		if (BDB->getTotalBalance(accountNumber) >= amount) //if funds are sufficient
		{
			if (CD->isSufficientCashAvailable(amount)) //if ATM has enough bills
			{
				BDB->debit(accountNumber, amount); //complete transaction through bankdatabase
				CD->dispenseCash(amount);
				SC.displayMessage("  ");
			}
			else
			{
				SC.displayMessage("Error: insufficient bills in ATM.");
				SC.displayMessage("Please enter a smaller amount.");
				execute(); //recursively calling excute again to restart process
			}
		}
		else
		{
			SC.displayMessage("Error: insufficient funds.");
			SC.displayMessage("Please enter a smaller amount.");
			execute(); //recursively calling excute again to restart process
		}
	}
}
