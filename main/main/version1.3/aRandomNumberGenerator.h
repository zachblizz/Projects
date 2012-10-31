#ifndef aRandomNumberGenerator_H
#define aRandomNumberGenerator_H

#include <vector>
using namespace std;

class aRandomNumberGenerator
{
public:
	aRandomNumberGenerator(int low = 0, int high = 1, int iter = 9000);
	~aRandomNumberGenerator();
	void validateRange(int low, int high);
	void validateIterator(int iter);
	void setRange(int low, int high);
	void setIterator(int iter);
	int getRangeLow();
	int getRangeHigh();
	int getIterations();
	int getDifferenceRange();
	void generateNumber();
	//void displayResults();  // need to put this somewhere in a seperate file...

private:
	vector <int> numFrequency; // Not sure if I need this vector, because
							   // the generator shouldn't keep track of what numbers
							   // it's developed.
	int rangeHigh, rangeLow, iterations;
};
#endif // !aRandomNumberGenerator_H