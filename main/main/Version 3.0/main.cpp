// Author: Zach Blizzard
// Project 3 aCoin, and aDie: via inheritance.
// Object Oriented Design

#include "stdafx.h"
#include "aCoin.h"
#include "aDie.h"
#include "aHistogram.h"
#include "aRandomNumberGenerator.h"
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

	// Instatiating regular coin and die objects.
	static aCoin aCoin1;								// Instantiating the coin object.
	static aDie aDie1;									// Instantiating the die object.
	static aHistogram dieHistogram, coinHistogram;		// Instantiating the die and coin histogram objects.

	// Instantiating the polymorphed coin and die objects 
	static aCoin aCoin2;								// Instantiating another coin object for polymorpism.
	static aDie aDie2;									// Instantiating another die object for polymorphism.
	static aHistogram dieHistogram2, coinHistogram2;	// Polymorphed coin and die histograms.
	static aRandomNumberGenerator *diePtr = &aDie2;		// Polymorphed die pointer.
	static aHistogram *dieHisPtr = &dieHistogram2;		// Polymorphed die histogram pointer.
	static aRandomNumberGenerator *coinPtr = &aCoin2;	// Polymorphed coin pointer.
	static aHistogram *coinHisPtr = &coinHistogram2;	// Polymorphed coin histogram pointer.
	
	// Variables for the amount of iterations.
	int coinIterations, dieIterations, diePtrIterations, coinPtrIterations;

	cout << "\n\n\t\t    WELCOME TO THE FREQUENCY ANALYST TOOL!" << endl;

	// Gets the iterations for the regular coin.
	cout << "\n\t    How many times would you like to flip the coin?: ";
	cin >> coinIterations;
	aCoin1.validateIterator(coinIterations);

	// Gets iterations for the regular die.
	cout << "\t    How many times would you like to throw the die?: ";
	cin >> dieIterations;
	aDie1.validateIterator(dieIterations);

	system("cls");

	// Does everything for the coin
	// using cascaded member-funciton calls.
	coinHistogram.setRange( aCoin1.getRangeLow(), aCoin1.getRangeHigh() ) .updateNumOfBinsSize() .setIteration( coinIterations );
	for(int iCoin = 0; iCoin < coinIterations; ++iCoin)
	{
		coinHistogram.updateNumOfBinsFrequency( aCoin1.flipCoin() ); // Updates the frequency bins inside the histogram
	}
	coinHistogram.displayResults(); // Displays the results.

	system("pause");
	system("cls");

	// Does everything for the die 
	// using cascaded member-function calls.
	dieHistogram.setRange( aDie1.getRangeLow(), aDie1.getRangeHigh() ) .updateNumOfBinsSize() .setIteration( dieIterations );
	for(int iDie = 0; iDie < dieIterations; ++iDie)
	{
		dieHistogram.updateNumOfBinsFrequency( aDie1.throwDie() ); // Updates the frequency bins inside the histogram
	}
	dieHistogram.displayResults(); // Displays the results.

	system("pause");
	system("cls");

/************************************* Polymorphed code *****************************************/

	cout << "--------------------------------- Polymorphism ---------------------------------\n" << endl;

	// Gets the iterations for the polymorphed die.
	cout << "\t How many times would you like to throw the polymorphed die?: ";
	cin >> diePtrIterations;
	diePtr->validateIterator(diePtrIterations);

	// Gets the iterations for the polymorphed coin.
	cout << "\t How many times would you like to throw the polymorphed coin?: ";
	cin >> coinPtrIterations;
	coinPtr->validateIterator(coinPtrIterations);

	system("cls");

	cout << "This is polymorphed!!\n" << endl;

	// Does everything for the diePtr
	dieHisPtr->setRange( diePtr->getRangeLow(), diePtr->getRangeHigh() ) .updateNumOfBinsSize() .setIteration( diePtrIterations );
	for(int iDiePtr = 0; iDiePtr < diePtrIterations; ++iDiePtr)
	{
		dieHisPtr->updateNumOfBinsFrequency( diePtr->generateNumber() ); // Updates the frequency bins inside the histogramPtr
	}
	dieHisPtr->displayResults(); // Displays the results.

	system("pause");
	system("cls");

	cout << "This is polymorphed!!\n" << endl;

	// Does everything for the coinPtr.
	coinHisPtr->setRange( coinPtr->getRangeLow(), coinPtr->getRangeHigh() ) .updateNumOfBinsSize() .setIteration( coinPtrIterations );
	for(int iCoinPtr = 0; iCoinPtr < coinPtrIterations; ++iCoinPtr)
	{
		coinHisPtr->updateNumOfBinsFrequency( coinPtr->generateNumber() );
	}
	coinHisPtr->displayResults();

	system("pause");
	return 0;
}