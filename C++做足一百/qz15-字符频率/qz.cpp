//6.	��д����, ����һ���ַ�(�Ի��н���), ͳ����ĸ�����ֺ������ַ����ֵ�Ƶ�ʡ�

#include <iostream>

#include <ctype.h>

#include <string.h>

void Inputchar(char *p);

int Indexletter (const char *p, char letter);

using namespace std;

int main()
{
	char word[10000], letter; 
	int sum;
	cout << "Please input some words:\n";
	Inputchar(word);
	cout << "Please input the letter user searchs:\n";
	cin >> letter;
	letter = tolower(letter);
	cout << "Figure the sum of the letter in the passage:\n";
	sum = Indexletter (word, letter);
	cout << " There are " << sum << " \" " << letter << " \" " <<"!\n";
	return 0;
}

void Inputchar(char *p)
{
	int i = 0;
	do
	{
		p[i] = cin.get();
		i ++;
	}
	while(p[i - 1] != '\n');
}

int Indexletter (const char *p, char letter)
{
	int i, sum = 0, a;
	for(i = 0; p[i] != 0; i ++)
	{
		a = p[i];
		if(p[i] <= 90 && p[i] >= 65) a = tolower(a);
		if(a == letter) sum ++;
	}
	return sum;
}



