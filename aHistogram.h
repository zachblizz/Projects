#ifndef aHistogram_H
#define aHistogram_H

#include "aRandomNumberGenerator.h"
#include <vector>
#include <string>

using namespace std;

class aHistogram
{
public:
	aHistogram(int low = 0, int high = 1, int iter = 6000);
	void validateRange(int low, int high);
	aHistogram &setRange(int low, int high); // returning a reference
	aHistogram &setIteration(int iter); // returning a reference
	void setLabels();
	int getRangeLow() const;
	int getRangeHigh() const;
	int getIterations() const;
	int getDifferenceRange() const;
	aHistogram &updateNumOfBinsSize(); // returning a reference
	void updateNumOfBinsFrequency(int randomNumber);
	~aHistogram(); // destructor
	void displayResults();
private:
	vector <int> numOfBins; // vector for the bins
	vector <string> label;  // vector for the label
	//string usersLabels;
	int rangeLow, rangeHigh, iterator;
};
#endif // !aHistogram_H