#ifndef aRandomNumberGenerator_H
#define aRandomNumberGenerator_H

class aRandomNumberGenerator
{
public:
	aRandomNumberGenerator(int low = 0, int high = 1, int iter = 9000);
	void validateRange(int low, int high);
	void validateIterator(int iter);
	void setRange(int low, int high);
	int getRangeLow() const;
	int getRangeHigh() const;
	void setIterator(int iter);
	int getIterations() const;
	int getDifferenceRange() const;
	int generateNumber();

private:
	int rangeHigh, rangeLow, iterations;
};
#endif // !aRandomNumberGenerator_H