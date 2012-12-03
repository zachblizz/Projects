// Author: Zach Blizzard
// Project 3 Coin, and Die: via inheritance.
// Object Oriented Design

#include "stdafx.h"
#include "Coin.h"
#include "Die.h"
#include "Histogram.h"
#include "RandomNumberGenerator.h" // For polymorphism.
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

/*
	// Instatiating regular coin and die objects.
	static Coin aCoin1;									// Instantiating the coin object.
	static Die aDie1;									// Instantiating the die object.
	static Histogram aDieHistogram, aCoinHistogram;		// Instantiating the die and coin histogram objects.
	
	// Variables for the amount of iterations.
	int coinIterations, dieIterations;
*/

	cout << "\n\t\t     WELCOME TO THE FREQUENCY ANALYSIS TOOL!\n" << endl;

/*
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
	aCoinHistogram.setRange( aCoin1.getRangeLow(), aCoin1.getRangeHigh() ) .updateNumOfBinsSize() .setIteration( coinIterations );
	for(int iCoin = 0; iCoin < coinIterations; ++iCoin)
	{
		aCoinHistogram.updateNumOfBinsFrequency( aCoin1.generateNumber() ); // Updates the frequency bins inside the histogram
	}
	aCoinHistogram.displayResults(); // Displays the results.

	system("pause");
	system("cls");

	// Does everything for the die 
	// using cascaded member-function calls.
	aDieHistogram.setRange( aDie1.getRangeLow(), aDie1.getRangeHigh() ) .updateNumOfBinsSize() .setIteration( dieIterations );
	for(int iDie = 0; iDie < dieIterations; ++iDie)
	{
		aDieHistogram.updateNumOfBinsFrequency( aDie1.generateNumber() ); // Updates the frequency bins inside the histogram
	}
	aDieHistogram.displayResults(); // Displays the results.

	system("pause");
	system("cls");
*/

/************************************************************************ Polymorphed code ************************************************************************/

	// Instantiating the polymorphed coin and die objects 
	static Coin aCoin2;									// Instantiating another coin object for polymorpism.
	static Die aDie2;									// Instantiating another die object for polymorphism.
	static Histogram aDieHistogram2, aCoinHistogram2;	// Instantiating new coin and die histograms.
	static RandomNumberGenerator *aRandomNumberPtr;		// Polymorphed randomNumber pointer.
	static Histogram *aHistogramPtr;					// Polymorphed histogram pointer.
	int diePtrIterations, coinPtrIterations;

	cout << "--------------------------- Polymorphism for the Die ---------------------------\n" << endl;

	// Pointers point to a die.
	aRandomNumberPtr = &aDie2;
	aHistogramPtr = &aDieHistogram2;

	// Gets the iterations for the polymorphed die.
	cout << "How many times would you like to throw the polymorphin Power Ranger die?: ";
	cin >> diePtrIterations;
	aRandomNumberPtr->validateIterator(diePtrIterations);

	system("cls");

	// Does everything for the diePtr
	aHistogramPtr->setRange( aRandomNumberPtr->getRangeLow(), aRandomNumberPtr->getRangeHigh() ) .updateNumOfBinsSize() .setIteration( diePtrIterations );
	for(int iDiePtr = 0; iDiePtr < diePtrIterations; ++iDiePtr)
	{
		aHistogramPtr->updateNumOfBinsFrequency( aRandomNumberPtr->generateNumber() ); // Updates the frequency bins inside the aHistogramPtr
	}
	aHistogramPtr->displayResults(); // Displays the results.

	system("pause");
	system("cls");

	cout << "\n\n-------------------------- Polymorphism for the Coin ---------------------------\n" << endl;

	// Pointers now point to a coin.
	aRandomNumberPtr = &aCoin2;
	aHistogramPtr = &aCoinHistogram2;

	// Gets the iterations for the polymorphed coin.
	cout << "How many times would you like to throw the polymorphin Power Ranger coin?: ";
	cin >> coinPtrIterations;
	aRandomNumberPtr->validateIterator(coinPtrIterations);

	system("cls");

	// Does everything for the coinPtr.
	aHistogramPtr->setRange( aRandomNumberPtr->getRangeLow(), aRandomNumberPtr->getRangeHigh() ) .updateNumOfBinsSize() .setIteration( coinPtrIterations );
	for(int iCoinPtr = 0; iCoinPtr < coinPtrIterations; ++iCoinPtr)
	{
		aHistogramPtr->updateNumOfBinsFrequency( aRandomNumberPtr->generateNumber() );
	}
	aHistogramPtr->displayResults(); // Displays the results

	system("pause");
	return 0;
}