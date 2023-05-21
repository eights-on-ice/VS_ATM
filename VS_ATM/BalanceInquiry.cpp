#include "BalanceInquiry.h"

BalanceInquiry::BalanceInquiry(int acc_number, BankDatabase* currentBDB)
	: Transaction(acc_number, currentBDB)
{}

void BalanceInquiry::execute()
{
	double availableBalance = BDB->getAvailableBalance(accountNumber);
	double totalBalance = BDB->getTotalBalance(accountNumber);

	SC.displayMessage("Your available balance is: ");
	SC.displayMessage(availableBalance);
	SC.displayMessage("  ");
	SC.displayMessage("And your total balance is: ");
	SC.displayMessage(totalBalance);
	SC.displayMessage("  ");
	SC.displayMessage("  ");
}
