#include "ATM.h"

ATM::ATM(BankDatabase* currentBDB, CashDispenser* currentCD)
{
	BDB = currentBDB;
	CD = currentCD;
}

void ATM::displayMenue()
{
	SC.displayMessage("Main menue: ");
	SC.displayMessage("     1 - View my balance");
	SC.displayMessage("     2 - Withdraw cash");
	SC.displayMessage("     3 - Deposit funds");
	SC.displayMessage("     4 - Exit");
	SC.displayMessage("Enter a choice (1-4):");
}

void ATM::performTransaction(int acc_number)
{
	while (true)
	{
		displayMenue();
		int choice = KP.getInput();

		Transaction* t1 = nullptr;

		if (choice != 4)
		{
			if (choice == 1)
			{
				t1 = new BalanceInquiry(acc_number, BDB);
			}
			else if (choice == 2)
			{
				t1 = new Withdrawal(acc_number, BDB, CD);
			}
			else if (choice == 3)
			{
				t1 = new Deposit(acc_number, BDB, CD);
			}
			else
			{
				SC.displayMessage("Error: invalid input");
				continue;
			}

			t1->execute();
			delete t1;
		}
		else
			break;
	}
}

void ATM::run()
{
	SC.displayMessage("Welcome!");

	SC.displayMessage("Please enter your account number: ");
	int accountNumber = KP.getInput();

	SC.displayMessage("Enter your PIN: ");
	int pin = KP.getInput();

	if (BDB->authenticateUser(accountNumber, pin))
	{
		userAuthenticated = true;
	}
	else
	{
		SC.displayMessage("Error: incorrect credentials");
	}

	if (userAuthenticated)
	{
		performTransaction(accountNumber);
	}
}
