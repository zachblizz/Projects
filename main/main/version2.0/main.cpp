// Author: Zach Blizzard
// Project 2 aCoin, and aDie
// Object Oriented Design

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
	unsigned seed;

	cout << "What should the seed be: ";
	cin >> seed;
	srand(seed);

	// creates the coin, die, and the histograms for both.
	aCoin aCoin1;
	aDie aDie1;
	aHistogram dieHistogram, coinHistogram;
	
	int coinIterations, dieIterations;

	cout << "\n\n\t\t  WELCOME TO THE FREQUENCY ANALYST TOOL!" << endl;

	cout << "\n\tHow many times would you like to flip the coin?: ";
	cin >> coinIterations;
	aCoin1.validateIterations(coinIterations);

	cout << "\tHow many times would you like to throw the die?: ";
	cin >> dieIterations;
	aDie1.validateIterations(dieIterations);

	system("cls");	
	
	// does everything for the coin
	coinHistogram.setRange(aCoin1.getRangeLow(), aCoin1.getRangeHigh());
	coinHistogram.updateNumOfBinsSize();
	for(int i = 0; i <= coinIterations; i++)
	{
		coinHistogram.updateNumOfBinsFrequency(aCoin1.flipCoin());
	}
	coinHistogram.displayResults();

	system("pause");
	system("cls");

	// does everything for the die
	dieHistogram.setRange(aDie1.getRangeLow(), aDie1.getRangeHigh());
	dieHistogram.updateNumOfBinsSize();
	for(int i = 0; i <= coinIterations; i++)
	{
		dieHistogram.updateNumOfBinsFrequency(aDie1.throwDie());
	}
	dieHistogram.displayResults();

	system("pause");
	return 0;
}

