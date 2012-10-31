#include "stdafx.h"
#include <iostream>
#include <cstdlib>
//#include <iomanip>
#include "aRandomNumberGenerator.h"

using namespace std;

// Constructor for the range and iterator, initially set low = 0 high = 1 and iterator = 9000
aRandomNumberGenerator::aRandomNumberGenerator(int low, int high, int iter)
{
	validateRange(low, high);
	validateIterator(iter);
	numFrequency.resize((high - low) + 1);
}

// Destructor of the vector numFrequency
aRandomNumberGenerator::~aRandomNumberGenerator()
{
	numFrequency.clear();
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

	numFrequency.resize(getDifferenceRange());

	for(int i = 0; i < getIterations(); i++)
	{
		number = getRangeLow() + rand() % getDifferenceRange(); // we should just need to do this
		numFrequency[number - getRangeLow()]++; // this should be in the histogramSource using the numOfBins vector
	}
	//displayResults();
}

// Displays the results done by the Program.
/****** TODO: put this somewhere else ********/
//void aRandomNumberGenerator::displayResults()
//{
//	system("cls");
//	double scale = 1.0;
//	cout << "\n\t\t\t\tRESULTS:\n" << endl;
//	cout << "\t\tRange: [" << getRangeLow() << ", " << getRangeHigh() << "]\t\tHistogram:" << "\n" << endl;
//
//	for(int index = getRangeLow(); index <= getRangeHigh(); index++)
//	{
//		cout << setw(17) << index << ": " << numFrequency[index - getRangeLow()];
//		cout << setw(12) << "\t" << index << ": ";
//
//		if((getIterations() / getDifferenceRange() / 15) > 0)
//			scale = getIterations() / getDifferenceRange() / 15;
//		if(getIterations() < 10)
//			scale = 1.0;
//		for(; scale <= numFrequency[index - getRangeLow()];)
//		{
//			cout << "X";
//			scale += getIterations() / getDifferenceRange() / 15;
//		}
//		cout << endl;
//	}
//	cout << "\t\t\t\t       Scale of X: " << getIterations() / getDifferenceRange() / 15 << endl << endl;
//}