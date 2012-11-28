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
 //#include <stdexcept> // trying it out...

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned seed;
	//srand(time(0));

	cout << "What should the seed be: ";
	cin >> seed;
	srand(seed);

	system("cls");

	// creates the coin, die, and the histograms for both.
	static aCoin aCoin1;
	static aDie aDie1;
	static aHistogram dieHistogram, coinHistogram;
	
	int coinIterations, dieIterations;

	cout << "\n\n\t\t    WELCOME TO THE FREQUENCY ANALYST TOOL!" << endl;

	cout << "\n\t    How many times would you like to flip the coin?: ";
	cin >> coinIterations;
	aCoin1.validateIterator(coinIterations);

	cout << "\t    How many times would you like to throw the die?: ";
	cin >> dieIterations;
	aDie1.validateIterator(dieIterations);

	system("cls");	
	
	// does everything for the coin
	// using cascaded member-funciton calls.
	coinHistogram.setRange( aCoin1.getRangeLow(), aCoin1.getRangeHigh() ).updateNumOfBinsSize().setIteration( coinIterations );
	for(int iCoin = 0; iCoin < coinIterations; ++iCoin)
	{
		coinHistogram.updateNumOfBinsFrequency( aCoin1.flipCoin() );
	}
	coinHistogram.displayResults();

	system("pause");
	system("cls");

	// does everything for the die 
	// using cascaded member-function calls.
	dieHistogram.setRange( aDie1.getRangeLow(), aDie1.getRangeHigh() ).updateNumOfBinsSize().setIteration( dieIterations );
	for(int iDie = 0; iDie < coinIterations; ++iDie)
	{
		dieHistogram.updateNumOfBinsFrequency( aDie1.throwDie() );
	}
	dieHistogram.displayResults();

	system("pause");
	return 0;
}

