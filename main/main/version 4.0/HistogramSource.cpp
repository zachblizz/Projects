#include "stdafx.h"
#include "Histogram.h"
#include "RandomNumberGenerator.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

// Constructor
Histogram::Histogram(int low, int high, int iter) : rangeLow(low), rangeHigh(high), iterator(iter)
{
	validateRange(low, high);			// Checks to see if the range is valid.
	numOfBins.resize((high - low) + 1); // Resizes the numOfBins vector to the appropriate size.
	label.resize((high - low) + 1);		// Resizes the label vevtor to the appropriate size.
	setIteration(iter);					// Sets the iterations.
}

// Will allow the user to set what the labels of the histogram bins to be.
void Histogram::setLabels()
{
	label.resize(getDifferenceRange());

	// If the object is a coin, it sets the label vector with these values.
	if(getDifferenceRange() == 2)
	{
		label[0] = "HEADS";
		label[1] = "TAILS";
	}
	// If the object is a die, it sets the label vector with these values.
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

// Sets the iterations for the histogram
Histogram &Histogram::setIteration(int iter)
{
	iterator = iter;

	return *this; // To enable the cascaded member-function call
}

// Gets the iterations for the histogram
int Histogram::getIterations() const
{
	return iterator;
}

// Validates the range
void Histogram::validateRange(int lower, int higher)
{
	while(higher < lower || lower < 0)
	{
		system("cls");
		cout << "Uh oh, there's something wrong with your range...\nPlease enter range again: ";
		cin >> lower >> higher;
	}
	setRange(lower, higher);
}

// Sets the range
Histogram &Histogram::setRange(int lower, int upper)
{
	rangeHigh = upper;
	rangeLow = lower;

	return *this; // To enable the cascaded member-function call
}

// Gets the lower range
int Histogram::getRangeLow() const
{
	return rangeLow;
}

// Gets the upper range
int Histogram::getRangeHigh() const
{
	return rangeHigh;
}

// Calcualtes the difference of the range
int Histogram::getDifferenceRange() const
{
	return (( getRangeHigh() - getRangeLow() ) + 1);
}

// Updates the numOfBins vector so it has the correct size.
Histogram &Histogram::updateNumOfBinsSize()
{
	numOfBins.resize( getDifferenceRange() );
	return *this; // To enable the cascaded member-function calls
}

// Updates the numOfBins vector everytime we get a new random number.
void Histogram::updateNumOfBinsFrequency(int randomNumber)
{
	numOfBins[randomNumber - getRangeLow()]++;
}

// Destructor
Histogram::~Histogram()
{
	label.clear();
	numOfBins.clear();
}

// Displays the results for the histogram.
void Histogram::displayResults()
{
	double scale = 1.0;

	setLabels();

	if(getDifferenceRange() == 2)
		cout << "\n\t\t\t    RESULTS FOR COIN:\n" << endl;
	else cout << "\n\t\t\t    RESULTS FOR DIE:\n" << endl;

	cout << "\t\tRange: [" << getRangeLow() << ", " << getRangeHigh() << "]\t\tHistogram:" << "\n" << endl;

	for(int index = getRangeLow(); index <= getRangeHigh(); index++)
	{
		if(numOfBins[index - getRangeLow()] < 10) // For formating purposes.
			cout << setw(17) << label[index - getRangeLow()] << ": 0" << numOfBins[index - getRangeLow()];
		else 
			cout << setw(17) << label[index - getRangeLow()] << ": " << numOfBins[index - getRangeLow()];

		cout << setw(12) << "\t" << label[index - getRangeLow()] << ": ";

		if(getIterations() < 15)
			scale = 1.0;
		else scale = (getIterations() / getDifferenceRange() / 15.0);

		for(double amount = 1.0; amount <= numOfBins[index - getRangeLow()]; amount += scale)
		{
			cout << "X";
		}
		cout << endl;
	}
	//cout  << endl;
	cout << "\t\t\t\t       Scale of X: " << setprecision(2) << fixed << scale << endl << endl;
}