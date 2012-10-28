#include "stdafx.h"
#include "aDie.h"
#include <iostream>

using namespace std;

aDie::aDie(int low, int high, int iter)
{
	setRange(low, high);
}

void aDie::setRange(int low, int high)
{
	lower = low;
	upper = high;
}

void aDie::setIterator(int iters)
{
	iterations = iters;
}

void aDie::validateIterations(int iter)
{
	while(iter <= 0)
	{
		cout << "Uh oh, your iterator isn't correct...\nPlease enter the amount again: ";
		cin >> iter;
	}
	setIterator(iter);
}

int aDie::getRangeLow()
{
	return lower;
}

int aDie::getRangeHigh()
{
	return upper;
}

int aDie::getIterations()
{
	return iterations;
}

void aDie::throwDie()
{
	aRandomNumberGenerator generateDie;

	generateDie.validateRange(getRangeLow(), getRangeHigh());
	generateDie.validateIterator(getIterations());
	generateDie.generateNumber();
}