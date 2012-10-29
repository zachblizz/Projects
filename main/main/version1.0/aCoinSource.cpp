#include "stdafx.h"
#include "aCoin.h"
#include <iostream>

using namespace std;

// constructor for the coin.
aCoin::aCoin(int low, int high, int iter)
{
	setRange(low, high);
	validateIterations(iter);
}

// sets the range for the object
void aCoin::setRange(int low, int high)
{
	lower = low;
	upper = high;
}

// sets the iterator for the object
void aCoin::setIterator(int iters)
{
	iterations = iters;
}

// validates the amount of times the user wants to flip the coin.
void aCoin::validateIterations(int iter)
{
	while(iter <= 0)
	{
		cout << "Uh oh, your iterator isn't correct...\nPlease enter the amount again: ";
		cin >> iter;
	}
	setIterator(iter);
}

// gets the lower boundry of the die for the object
int aCoin::getRangeLow()
{
	return lower;
}

// gets the upper boundry of the die for the object
int aCoin::getRangeHigh()
{
	return upper;
}

// gets the number of times the user wants to flip the coin for the object.
int aCoin::getIterations()
{
	return iterations;
}

// implements throwing the coin the amount of times the user puts in
void aCoin::flipCoin()
{
	generateCoin.validateRange(getRangeLow(), getRangeHigh());
	generateCoin.validateIterator(getIterations());
	generateCoin.generateNumber();
}