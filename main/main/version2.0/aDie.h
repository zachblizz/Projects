#ifndef aDie_H
#define aDie_H

#include "aRandomNumberGenerator.h"

class aDie
{
public:
	aDie (int low = 1, int high = 6, int iter = 6000);
	void setRange(int low, int high);
	void setIterator(int iter);
	void validateIterations(int iter);
	int getRangeLow() const;
	int getRangeHigh() const;
	int getIterations() const;
	int throwDie();
private:
	int lower, upper, iterations;
	aRandomNumberGenerator generateDie;
};
#endif // !aDie_H