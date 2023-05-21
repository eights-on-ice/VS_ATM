#include "ATM.h"

int main()
{
	//stores accounts informations and 
	//communicates with/is modified by all associated classes
	BankDatabase bank1;
	BankDatabase* pBank1 = &bank1;

	//stores $20 bill count and 
	//communicates with/is modified by all associated classes
	CashDispenser c1(500);
	CashDispenser* pC1 = &c1;

	ATM atm(pBank1, pC1); //creating the atm object

	atm.run(); //running the system

	return 0;
}