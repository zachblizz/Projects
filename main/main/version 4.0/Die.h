#ifndef aDie_H
#define aDie_H

#include "RandomNumberGenerator.h"

// Die now inheriates the memeber functions from RandomNumberGenerator,
// because Die IS A random number generator with range 1-6.
class Die : public RandomNumberGenerator
{
public:
	Die (int low = 1, int high = 6, int iter = 6000);
	virtual int generateNumber(); // Just returns the random generated number from RandomNumberGenerator.
};
#endif // !aDie_H