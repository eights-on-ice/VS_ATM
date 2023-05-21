//#include "Withdrawal.h"
//#include "Deposit.h"
//#include "BalanceInquiry.h"
#include "ATM.h"

int main()
{
	BankDatabase bank1;
	BankDatabase* pBank1 = &bank1;

	CashDispenser c1(500);
	CashDispenser* pC1 = &c1;

	ATM atm(pBank1, pC1);

	atm.run();

	//cout << pBank1->getAvailableBalance(1);

	//Transaction* pT1 = new Deposit(1, pBank1, pC1);
	//pT1->execute();

	//delete pT1;

	//pT1 = new BalanceInquiry(1, pBank1);
	//pT1->execute();

	//delete pT1;

	//pT1 = new Withdrawal(1, pBank1, pC1);
	//pT1->execute();

	//delete pT1;

	//pT1 = new BalanceInquiry(1, pBank1);
	//pT1->execute();

	return 0;
}