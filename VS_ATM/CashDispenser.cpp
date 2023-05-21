#include "CashDispenser.h"

CashDispenser::CashDispenser(int cnt)
{
	count = cnt;
}

bool CashDispenser::isSufficientCashAvailable(double amount)
{
	if (amount <= count * 20.0)
		return true;
	else
		return false;
}

void CashDispenser::dispenseCash(double amount)
{
	Screen screen1;

	count -= amount / 20.0;

	screen1.displayMessage(amount);
	screen1.displayMessage(" have been dispensed.");
}

