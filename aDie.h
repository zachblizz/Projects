#ifndef aDie_H
#define aDie_H

#include "aRandomNumberGenerator.h"

class aDie : public aRandomNumberGenerator
{
public:
	aDie (int low = 1, int high = 6, int iter = 6000);
	int throwDie();

	// from last project...
	/*void setRange(int low, int high);
	int getRangeLow() const;
	int getRangeHigh() const;
	void setIterator(int iter);
	void validateIterations(int iter);
	int getIterations() const;
	int throwDie();
private:
	int lower, upper, iterations;
	aRandomNumberGenerator generateDie;*/
};
#endif // !aDie_H