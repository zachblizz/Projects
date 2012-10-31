#include "stdafx.h"
#include "aCoin.h"
#include <iostream>

using namespace std;

aCoin::aCoin(int low, int high, int iter)
{
	setRange(low, high);
}

void aCoin::setRange(int low, int high)
{
	lower = low;
	upper = high;
}

void aCoin::setIterator(int iters)
{
	iterations = iters;
}

void aCoin::validateIterations(int iter)
{
	while(iter <= 0)
	{
		cout << "Uh oh, your iterator isn't correct...\nPlease enter the amount again: ";
		cin >> iter;
	}
	setIterator(iter);
}

int aCoin::getRangeLow()
{
	return lower;
}

int aCoin::getRangeHigh()
{
	return upper;
}

int aCoin::getIterations()
{
	return iterations;
}

void aCoin::flipCoin()
{
	aRandomNumberGenerator generateCoin;

	generateCoin.validateRange(getRangeLow(), getRangeHigh());
	generateCoin.validateIterator(getIterations());
	generateCoin.generateNumber();
}