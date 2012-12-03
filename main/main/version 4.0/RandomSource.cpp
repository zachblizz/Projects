#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "RandomNumberGenerator.h"
#include "Histogram.h"

using namespace std;

// Constructor for the range and iterator, initially set low = 0 high = 1 and iterator = 9000
RandomNumberGenerator::RandomNumberGenerator(int low, int high, int iter) : rangeLow(low), rangeHigh(high), iterations(iter)
{
	validateRange(low, high);
	validateIterator(iter);
}

// Validates the range to handle some errors.
void RandomNumberGenerator::validateRange(int lower, int higher)
{
	while(higher < lower || lower < 0)
	{
		system("cls");
		cout << "Uh oh, there's something wrong with your range...\nPlease enter range again: ";
		cin >> lower >> higher;
	}
	this->setRange(lower, higher);
}

// Validates the iterator to handle some errors.
void RandomNumberGenerator::validateIterator(int iter)
{
	while(iter <= 0)
	{
		cout << "Uh oh, your iterator isn't correct...\nPlease enter the amount again: ";
		cin >> iter;
	}
	setIterator(iter);
}

// Sets the low and high range for the object.
void RandomNumberGenerator::setRange(int lower, int upper)
{
	rangeHigh = upper;
	rangeLow = lower;
}

// Gets the lower end of the range for the object.
int RandomNumberGenerator::getRangeLow() const
{
	return rangeLow;
}

// Gets the upper end of the range for the object.
int RandomNumberGenerator::getRangeHigh() const
{
	return rangeHigh;
}

// Sets the iterator for the Object
void RandomNumberGenerator::setIterator(int iter)
{
	iterations = iter;
}

// Gets the iterator for the object
int RandomNumberGenerator::getIterations() const
{
	return iterations;
}

// Finds the difference of the range and returns it for use
int RandomNumberGenerator::getDifferenceRange() const
{
	int difference = (( getRangeHigh() - getRangeLow() ) + 1);
	return difference;
}

// Generates the random number.
int RandomNumberGenerator::generateNumber() const
{
	static int number;
	number = getRangeLow() + rand() % getDifferenceRange();
	return number;
}