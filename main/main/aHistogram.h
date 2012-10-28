// basically same stuff as the random source, getRange, Difference
#ifndef aHistogram_H
#define aHistogram_H

#include "aRandomNumberGenerator.h"
#include <vector>

using namespace std;

class aHistogram
{
public :
	aHistogram(int low = 0, int high = 1);
	~aHistogram();
	void validateRange(int low, int high);
	void setRange(int low, int high);
	int getRangeLow();
	int getRangeHigh();
	int getIterations();
	int getDifferenceRange();
	void displayResults();  // need to put this somewhere in a seperate file...
private:
	vector <int> numOfBins;
	const enum {HEADS, TAILS};
	int rangeLow, rangeHigh;
};
#endif // !aHistogram_H