#include "Keypad.h"

Keypad::Keypad()
{
}

int Keypad::getInput()
{
    int input;
    cin >> input;
    cout << '\n';
    return input;
}

double Keypad::getDouble()
{
    double input;
    cin >> input;
    cout << '\n';
    return input;
}
