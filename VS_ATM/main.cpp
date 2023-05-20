#include "BankDatabase.h"
#include<iostream>
using namespace std;

int main()
{
	BankDatabase bank1;

	cout << bank1.getAvailableBalance(1) << endl;

	bank1.credit(1, 500);
	cout << bank1.getTotalBalance(1) << endl;
	bank1.debit(1, 100);
	cout << bank1.getTotalBalance(1) << endl;

	cout << bank1.authenticateUser(2, 2);

	return 0;
}