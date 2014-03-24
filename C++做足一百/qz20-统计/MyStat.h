#ifndef _MyStat_h_

#define _MyStat_h_

#include <iostream>

using namespace std;

#define M 1000

typedef double REAL ;

class STAT
{
public:
	STAT(){min = 1e10; max = -1e10; sum = 0;}
	~STAT() {}
	void Amount(int n);
	void Sum(const double *p);
	void SpecialValue(const double *p);
	void Average(const double *p);
	void Input(double *p);
	double GetAmount() const {return amount;}
	double GetMax() const {return max;}
	double GetMin() const {return min;}
	double GetAverage() const {return average;}
	double GetSum() const { return sum;}
private:
	double amount;
	double max;
	double min;
	double average;
	double sum;
};

#endif