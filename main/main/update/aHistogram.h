// basically same stuff as the random source, getRange, Difference
#ifndef aHistogram_H
#define aHistogram_H

#include "aRandomNumberGenerator.h"
#include <vector>

using namespace std;

class aHistogram
{
public :
	aHistogram(int low = 0, int high = 1, int iter = 6000);
	~aHistogram();
	void validateRange(int low, int high);
	void setRange(int low, int high);
	void setIteration(int iter);
	int getRangeLow();
	int getRangeHigh();
	int getIterations();
	int getDifferenceRange();
	void update(int randomNumber);
	void updateNumOfBin();
	void displayResults();  // need to put this somewhere in a seperate file...
private:
	vector <int> numOfBins;
	int rangeLow, rangeHigh, iterator;
};
#endif // !aHistogram_H