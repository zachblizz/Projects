#ifndef aRandomNumberGenerator_H
#define aRandomNumberGenerator_H

#include "aHistogram.h"

class aRandomNumberGenerator
{
public:
	aRandomNumberGenerator(int low = 0, int high = 1, int iter = 9000);
	void validateRange(int low, int high);
	void validateIterator(int iter);
	void setRange(int low, int high);
	void setIterator(int iter);
	int getRangeLow();
	int getRangeHigh();
	int getIterations();
	int getDifferenceRange();
	void generateNumber();

private:
	int rangeHigh, rangeLow, iterations;
};
#endif // !aRandomNumberGenerator_H