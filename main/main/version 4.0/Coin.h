#ifndef aCoin_H
#define aCoin_H

#include "RandomNumberGenerator.h"

// Coin now inheriates the memeber functions from RandomNumberGenerator,
// because Coin IS A random number generator either 0 or 1 (heards or tails).
class Coin : public RandomNumberGenerator
{
public:
	Coin (int low = 0, int high = 1, int iter = 6000);
	virtual int generateNumber(); // Just returns the random generated number from RandomNumberGenerator.
};
#endif