#include <iostream>

using namespace std;

#include "SQLIST.H"


SQLIST::SQLIST()
{
	length = 0;
}

void SQLIST::Insert(int x)
{
	int n, i;
	if(IsFull())
	{
		cout << "ÈÝÆ÷ÒÑÂú!" << endl;
		throw 1;
	}
	else
	{
		n = Before_Min(x);
		for(i = length - 1; i >= n; i --)
		{
			data[i + 1] = data[i];
		}
		data[n] = x;
		length ++;
	}
}

int SQLIST::Before_Min(int x)
{
	int i;
	for(i = 0; i < length; i ++)
	{
		if(x <= data[i])
		{
			break;
		}
	}
	return i;
}

bool SQLIST::IsFull()
{
	return length == 20;
}

void SQLIST::Output()
{
	int i = 0;
	for(; i < length; i ++)
	{
		cout << data[i] << ' ';
	}
}