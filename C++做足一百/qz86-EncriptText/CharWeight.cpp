#include <iostream>

using namespace std;

#include "CharWeight.H"

CharWeight::CharWeight(char c, double weight, int num)
{
	this->c = c;
	this->weight = weight;
	this->num = num;
}

int CompareWeight(const CharWeight& one, const CharWeight& other)
{
	int result = 0;
	if(one.c > other.c)
	{
		result = 1;
	}
	else if(one.c < other.c)
	{
		result = -1;
	}
	return result;
}

void CharWeight::Output()const
{
	cout << '(' << (int)c << ',' << weight << ',' << num << ") ";
}