#ifndef aCoin_H
#define aCoin_H

#include "aRandomNumberGenerator.h"

// aCoin now inheriates the memeber functions from aRandomNumberGenerator,
// because aCoin IS A random number generator either 0 or 1 (heards or tails).
class aCoin : public aRandomNumberGenerator
{
public:
	aCoin (int low = 0, int high = 1, int iter = 6000);
	int flipCoin(); // Just returns the random generated number from aRandomNumberGenerator.
};
#endif