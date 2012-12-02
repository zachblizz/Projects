#ifndef aHistogram_H
#define aHistogram_H

#include "aRandomNumberGenerator.h"
#include <vector>
#include <string>

using namespace std;

class aHistogram
{
public:
	aHistogram(int low = 0, int high = 1, int iter = 6000); // Constructor
	void validateRange(int low, int high);					// Checks the range to see if it's valid
	aHistogram &setRange(int low, int high);				// Returning a reference to enable cascaded member funciton calls
	aHistogram &setIteration(int iter);						// Returning a reference to enable cascaded member funciton calls
	void setLabels();										// Sets the labels for the histogram
	int getRangeLow() const;								// Gets the low end of the range for the object
	int getRangeHigh() const;								// Gets the high end of the range for the object
	int getIterations() const;								// Gets the iterations for the object
	int getDifferenceRange() const;							// Gets the difference of the range for the object
	aHistogram &updateNumOfBinsSize();						// Returning a reference to enable cascaded member funciton calls
	void updateNumOfBinsFrequency(int randomNumber);		// Updates the numOfBinsFrequency vector
	~aHistogram();											// Destructor
	void displayResults();									// Displays the results for the histogram
private:
	vector <int> numOfBins; // Vector for the bins
	vector <string> label;  // Vector for the label
	//string usersLabels;
	int rangeLow, rangeHigh, iterator;
};
#endif // !aHistogram_H