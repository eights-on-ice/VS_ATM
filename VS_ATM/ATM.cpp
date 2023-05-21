#include "ATM.h"

ATM::ATM(BankDatabase* currentBDB, CashDispenser* currentCD) //constructs ATM
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

void ATM::performTransaction(int acc_number) //infinite loop that keeps performing
{											 //user's requested transactions
	while (true)
	{
		displayMenue();
		int choice = KP.getInput(); //getting chioce from user

		Transaction* t1 = nullptr; //initializing t1 

		if (choice != 4) //if user did not choose to exit
		{
			if (choice == 1) //assigning appropriate objects for each transaction to t1
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
				continue; //restart loop and display menue again
			}

			t1->execute(); //depending on choice, executes the specific transaction
			delete t1; //deleting dynamically allocated memory
		}
		else //if user chose to exit,
			break; //exit loop
	}
}

void ATM::run()
{
	int accountNumber = 0; //initializing accountNumber

	while (!userAuthenticated) //infinite loop until user is authenticated
	{
		SC.displayMessage("Welcome!");

		SC.displayMessage("Please enter your account number: ");
		accountNumber = KP.getInput();

		if ((BDB->getAccount(accountNumber)) != nullptr) //if such accountNumber exists in BankDatabase
		{
			SC.displayMessage("Enter your PIN: ");
			int pin = KP.getInput();

			if (!(BDB->authenticateUser(accountNumber, pin))) //if credentials are incorrect according to BankDatabase
			{
				SC.displayMessage("Error: incorrect credentials");
			}
			else
			{
				userAuthenticated = true; //authenticate and exit loop
			}
		}
		else //if there is no account with such number
		{
			SC.displayMessage("Error: there is no account with such number");
		}
		
	}

	if (userAuthenticated)
	{
		performTransaction(accountNumber); //start performing transactions
	}
}
