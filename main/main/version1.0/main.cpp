// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "aCoin.h"
#include "aDie.h"
#include "aHistogram.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned seed = time(0);
	srand(seed);

	aCoin aCoin1;
	aDie aDie1;
	aHistogram dieHistogram, coinHistogram;
	
	int coinIterations, dieIterations;

	cout << "\n\t\t  WELCOME TO THE FREQUENCY ANALYST TOOL!" << endl;

	cout << "\n\tHow many times would you like to flip the coin?: ";
	cin >> coinIterations;
	aCoin1.validateIterations(coinIterations);

	cout << "\n\tHow many times would you like to throw the die?: ";
	cin >> dieIterations;
	aDie1.validateIterations(dieIterations);
	
	aCoin1.flipCoin();
	
	cout << endl;

	aDie1.throwDie();

	system("pause");
	return 0;
}

