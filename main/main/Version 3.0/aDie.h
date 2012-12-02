#ifndef aDie_H
#define aDie_H

#include "aRandomNumberGenerator.h"

// aDie now inheriates the memeber functions from aRandomNumberGenerator,
// because aDie IS A random number generator with range 1-6.
class aDie : public aRandomNumberGenerator
{
public:
	aDie (int low = 1, int high = 6, int iter = 6000);
	int throwDie(); // Just returns the random generated number from aRandomNumberGenerator.
};
#endif // !aDie_H