#include <iostream>

using namespace std;


#include "DRAW_SQUARE.H"

#include <cstring>

DRAW_SQUARE::DRAW_SQUARE()
{
	strcpy(word1, "  ");
	strcpy(word2, "¹ê");
	strcpy(word3, "Í¼");
}

void DRAW_SQUARE::Draw(int m, int n)
{
	int i, j;
	Print1(n);
	for(i = 0; i < m - 1; i ++)
	{
		Print2();
		for(j = 0; j < n; j ++)
		{
			Print(i, j);
			Print2();
		}
		cout << endl;
		Print3(n);
	}
	Print2();
	for(j = 0; j < n; j ++)
	{
		Print(i, j);
		Print2();
	}
	cout << endl;
	Print4(n);
}
	


void DRAW_SQUARE::Print1(int n)
{
	int i;
	//cout << "©³©¥©×©¥©×©¥©·" << endl;
	cout << "©³";
	for(i = 1; i < n; i ++) cout << "©¥©×";
	cout << "©¥©·" << endl;
}

void DRAW_SQUARE::Print2()
{
	cout << "©§";
}

void DRAW_SQUARE::Print3(int n)
{
	int i;
	//cout << "©Ç©¥©ï©¥©ï©¥©Ï" << endl;
	cout << "©Ç©¥";
	for(i = 1; i < n; i ++) cout << "©ï©¥";
	cout << "©Ï" << endl;
}

void DRAW_SQUARE::Print4(int n)
{
	int i;
	//cout << "©»©¥©ß©¥©ß©¥©¿" << endl;
	cout << "©»";
	for(i = 1; i < n; i ++) cout << "©¥©ß";
	cout << "©¥©¿" << endl;
}

void DRAW_SQUARE::Print(int x, int y)
{
	if(x == now_location.x - 1 && y == now_location.y - 1) cout << word2;
	else if(grids[x * M + y]) cout << word3;
	else cout << word1;
}

void DRAW_SQUARE::Grids(const bool *grids)
{
	int i, j, k;
	for(i = 0; i < M; i ++)
	{
		for(j = 0; j < M; j ++)
		{
			k = i * M + j;
			this->grids[k] = grids[k];
		}
	}
}

void DRAW_SQUARE::Now_location(const ORDINATE &now_location)
{
	this->now_location = now_location;
}