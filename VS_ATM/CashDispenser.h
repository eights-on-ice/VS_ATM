#pragma once
#include "Screen.h"
class CashDispenser
{
private:
	int count;

public:
	CashDispenser(int);

	bool isSufficientCashAvailable(double);
	void dispenseCash(double);
};