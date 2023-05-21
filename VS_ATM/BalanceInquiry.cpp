#include "BalanceInquiry.h"

BalanceInquiry::BalanceInquiry(int acc_number, BankDatabase* currentBDB) //constructing Withdrawal obj and
	: Transaction(acc_number, currentBDB)								 //delegating to base class constructor
{}

void BalanceInquiry::execute() //prints total and available balance
{
	double availableBalance = BDB->getAvailableBalance(accountNumber); //getting available and total 
	double totalBalance = BDB->getTotalBalance(accountNumber);		   // balances from BankDatabase

	SC.displayMessage("Your available balance is: ");
	SC.displayMessage(availableBalance);
	SC.displayMessage("  ");
	SC.displayMessage("And your total balance is: ");
	SC.displayMessage(totalBalance);
	SC.displayMessage("  ");
	SC.displayMessage("  ");
}
