#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "aRandomNumberGenerator.h"
#include "aHistogram.h"
//#include "aHistogram.h"

using namespace std;

// Constructor for the range and iterator, initially set low = 0 high = 1 and iterator = 9000
aRandomNumberGenerator::aRandomNumberGenerator(int low, int high, int iter)
{
	validateRange(low, high);
	validateIterator(iter);
}

// Validates the range to handle some errors.
void aRandomNumberGenerator::validateRange(int lower, int higher)
{
	while(higher < lower || lower < 0)
	{
		system("cls");
		cout << "Uh oh, there's something wrong with your range...\nPlease enter range again: ";
		cin >> lower >> higher;
	}
	setRange(lower, higher);
}

// Validates the iterator to handle some errors.
void aRandomNumberGenerator::validateIterator(int iter)
{
	while(iter <= 0)
	{
		cout << "Uh oh, your iterator isn't correct...\nPlease enter the amount again: ";
		cin >> iter;
	}
	setIterator(iter);
}

// Sets the iterator for the Object
void aRandomNumberGenerator::setIterator(int iter)
{
	iterations = iter;
}

// Sets the low and high range for the object.
void aRandomNumberGenerator::setRange(int lower, int upper)
{
	rangeHigh = upper;
	rangeLow = lower;
}

// Gets the lower end of the range for the object.
int aRandomNumberGenerator::getRangeLow()
{
	return rangeLow;
}

// Gets the iterator for the object
int aRandomNumberGenerator::getIterations()
{
	return iterations;
}

// Gets the upper end of the range for the object.
int aRandomNumberGenerator::getRangeHigh()
{
	return rangeHigh;
}

// Finds the difference of the range and returns it for use
int aRandomNumberGenerator::getDifferenceRange()
{
	return (( getRangeHigh() - getRangeLow() ) + 1);
}

// Generates the numbers doesn't need to count the frequency
void aRandomNumberGenerator::generateNumber()
{
	static int number;
	aHistogram histogram1;

	histogram1.validateRange(getRangeLow(), getRangeHigh());
	histogram1.updateNumOfBinsSize();
	histogram1.setIteration(getIterations());

	for(int i = 0; i < getIterations(); i++)
	{
		number = getRangeLow() + rand() % getDifferenceRange(); // we should just need to do this
		histogram1.updateNumOfBinsFrequency(number);
	}
	histogram1.displayResults();
}