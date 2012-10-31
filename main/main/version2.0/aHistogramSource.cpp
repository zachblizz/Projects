#include "stdafx.h"
#include "aHistogram.h"
#include "aRandomNumberGenerator.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

// constructor
aHistogram::aHistogram(int low, int high, int iter)
{
	validateRange(low, high);
	numOfBins.resize((high - low) + 1);
	label.resize((high - low) + 1);
	setIteration(iter);
}

// destructor
aHistogram::~aHistogram()
{
	label.clear();
	numOfBins.clear();
}

// will allow the user to set what the labels of the histogram bins to be.
void aHistogram::setLabels()
{
	label.resize(getDifferenceRange());

	// if the object is a coin, gives these to the label vector
	if(getDifferenceRange() == 2)
	{
		label[0] = "HEADS";
		label[1] = "TAILS";
	}
	// if the object is a die, it gives these to the label vector
	else
	{
		label[0] = "1";
		label[1] = "2";
		label[2] = "3";
		label[3] = "4";
		label[4] = "5";
		label[5] = "6";
	}
}

// sets the iterations for the histogram
void aHistogram::setIteration(int iter)
{
	iterator = iter;
}

// gets the iterations for the histogram
int aHistogram::getIterations() const
{
	return this->iterator;
}

// validates the range
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

// sets the range
void aHistogram::setRange(int lower, int upper)
{
	rangeHigh = upper;
	rangeLow = lower;
}

// gets the lower range
int aHistogram::getRangeLow() const
{
	return this->rangeLow;
}

// gets the upper range
int aHistogram::getRangeHigh() const
{
	return this->rangeHigh;
}

// calcualtes the difference of the range
int aHistogram::getDifferenceRange() const
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
	double scale = 1.0;

	setLabels();

	if(getDifferenceRange() == 2)
		cout << "\n\t\t\t  RESULTS FOR COIN:\n" << endl;
	else cout << "\n\t\t\t  RESULTS FOR DIE:\n" << endl;

	cout << "\t\tRange: [" << getRangeLow() << ", " << getRangeHigh() << "]\t\tHistogram:" << "\n" << endl;

	for(int index = getRangeLow(); index <= getRangeHigh(); index++)
	{
		cout << setw(17) << label[index - getRangeLow()] << ": " << numOfBins[index - getRangeLow()];
		cout << setw(12) << "\t" << label[index - getRangeLow()] << ": ";

		if(getIterations() < 10)
			scale = 1.0;
		else scale = getIterations() / getDifferenceRange() / 15;

		for(; scale <= numOfBins[index - getRangeLow()];)
		{
			cout << "X";
			scale += getIterations() / getDifferenceRange() / 15;
		}
		cout << endl;
	}
	cout << "\t\t\t\t       Scale of X: " << getIterations() / getDifferenceRange() / 15 << endl << endl;
}