//6.	��д����, ����һ���ַ�(�Ի��н���), ͳ����ĸ�����ֺ������ַ����ֵ�Ƶ�ʡ�

#include <iostream>

#include <ctype.h>

#include <string.h>

int Indexletter (const char *p, char letter);

void Inputchar(char *p);

using namespace std;

int main()
{
	char word[10000], letter; 
	int sum;
	cout << "Please input some words:\n";
	Inputchar(word);
	cout << "Please input the letter user searchs:\n";
	cin >> letter;
	if( letter <= 'Z' && letter >= 'A') letter = tolower(letter);
	cout << "Figure the sum of the letter in the passage:\n";
	sum = Indexletter (word, letter);
	cout << " There are " << sum << " \" " << letter << " \" " <<"!\n";
	return 0;
}

void Inputchar(char *p)
{
	cin.getline(p, 10000);
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



