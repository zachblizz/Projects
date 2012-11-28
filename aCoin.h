#ifndef aCoin_H
#define aCoin_H

#include "aRandomNumberGenerator.h"

class aCoin : public aRandomNumberGenerator
{
public:
	aCoin (int low = 0, int high = 1, int iter = 6000);
	int flipCoin();

	// from last project...
	/*void setRange(int low, int high);
	int getRangeLow() const;
	int getRangeHigh() const;
	void setIterator(int iter);
	void validateIterations(int iter);
	int getIterations() const;
	int flipCoin();
private:
	const enum {HEADS, TAILS};
	int lower, upper, iterations;
	aRandomNumberGenerator generateCoin;*/
};
#endif