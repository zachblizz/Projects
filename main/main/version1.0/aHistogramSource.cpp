#include "stdafx.h"
#include "aHistogram.h"
#include "aRandomNumberGenerator.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

aHistogram::aHistogram(int low, int high, int iter)
{
	validateRange(low, high);
	numOfBins.resize((high - low) + 1);
	setIteration(iter);
}

aHistogram::~aHistogram()
{
	numOfBins.clear();
}

void aHistogram::setIteration(int iter)
{
	iterator = iter;
}

int aHistogram::getIterations()
{
	return iterator;
}

void aHistogram::validateRange(int lower, int higher)
{
	while(higher < lower || lower < 0)
	{
		system("cls");
		cout << "Uh oh, there's something wrong with your range...\nPlease enter range again: ";
		cin >> lower >> higher;
	}
	setRange(lower, higher);
}

void aHistogram::setRange(int lower, int upper)
{
	rangeHigh = upper;
	rangeLow = lower;
}

int aHistogram::getRangeLow()
{
	return rangeLow;
}

int aHistogram::getRangeHigh()
{
	return rangeHigh;
}

int aHistogram::getDifferenceRange()
{
	return (( getRangeHigh() - getRangeLow() ) + 1);
}

// updates the numOfBins vector so it has the correct size.
void aHistogram::updateNumOfBinsSize()
{
	numOfBins.resize( getDifferenceRange() );
}

// updates the numOfBins vector everytime we get a new random number.
void aHistogram::updateNumOfBinsFrequency(int randomNumber)
{
	numOfBins[randomNumber - getRangeLow()]++;
}

void aHistogram::displayResults()
{
	//system("cls");
	double scale = 1.0;
	cout << "\n\t\t\t\tRESULTS:\n" << endl;
	cout << "\t\tRange: [" << getRangeLow() << ", " << getRangeHigh() << "]\t\tHistogram:" << "\n" << endl;

	for(int index = getRangeLow(); index <= getRangeHigh(); index++)
	{
		cout << setw(17) << index << ": " << numOfBins[index - getRangeLow()];
		cout << setw(12) << "\t" << index << ": ";

		if(getIterations() < 10)
			scale = 1.0;
		else scale = getIterations() / getDifferenceRange() / 15;;

		for(; scale <= numOfBins[index - getRangeLow()];)
		{
			cout << "X";
			scale += getIterations() / getDifferenceRange() / 15;
		}
		cout << endl; // hello
	}
	cout << "\t\t\t\t       Scale of X: " << getIterations() / getDifferenceRange() / 15 << endl << endl;
}