#include "stdafx.h"
#include "aDie.h"
#include <iostream>

using namespace std;

// constructor for the die.
aDie::aDie(int low, int high, int iter)
{
	setRange(low, high);
	validateIterations(iter);
}

// sets the range for the object
void aDie::setRange(int low, int high)
{
	lower = low;
	upper = high;
}

// sets the iterator for the object
void aDie::setIterator(int iters)
{
	iterations = iters;
}

// validates the amount of times the user wants to throw the die.
void aDie::validateIterations(int iter)
{
	while(iter <= 0)
	{
		cout << "Uh oh, your iterator isn't correct...\nPlease enter the amount again: ";
		cin >> iter;
	}
	setIterator(iter);
}

// gets the lower boundry of the die for the object
int aDie::getRangeLow() const
{
	return lower;
}

// gets the upper boundry of the die for the object
int aDie::getRangeHigh() const
{
	return upper;
}

// gets the number of times the user wants to throw the die for the object.
int aDie::getIterations() const
{
	return iterations;
}

// implements throwing the die the amount of times the user puts in
int aDie::throwDie()
{
	int face;
	generateDie.validateRange(getRangeLow(), getRangeHigh());
	//generateDie.validateIterator(getIterations());
	face = generateDie.generateNumber();
	return face;
}