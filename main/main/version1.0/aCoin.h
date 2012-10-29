#ifndef aCoin_H
#define aCoin_H

#include "aRandomNumberGenerator.h"

class aCoin
{
public:
	aCoin (int low = 0, int high = 1, int iter = 6000);
	void setRange(int low, int high);
	void setIterator(int iter);
	void validateIterations(int iter);
	int getRangeLow();
	int getRangeHigh();
	int getIterations();
	void flipCoin();
private:
	const enum {HEADS, TAILS};
	int lower, upper, iterations;
	aRandomNumberGenerator generateCoin;
};
#endif