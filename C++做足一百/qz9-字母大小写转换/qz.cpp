//2.	��ϸ�۲�ASCII���, ��д��Сд��ĸת��Ϊ��д, �ͽ���д��ĸת��ΪСд�ĺ�����
//ת��Ϊ��д: char ToUpper(char x);	// ��: ToUpper('P') = 'P', ToUpper('p') = 'P', ToUpper('+') = '+'
//ת��ΪСд: char ToLower(char x);	// ��: ToLower('P') = 'p', ToLower('p') = 'p', ToLower('+') = '+'
//ע: ����ֻ����ϰ��Cϵͳ������toupper��tolower����, ��Ҫʹ��ͷ�ļ�ctype.h��
#include <iostream>

void Input (char *p);

char ToUpper(char x);

char ToLower(char x);

using namespace std;

int main()
{
	char letter;
	cout << "Please input an letter, you will get its capital style and minuscule style!\n";
	Input(&letter);
	cout << "The letter's capital style is " << ToUpper(letter) << "!\n" <<endl;
	cout << "The letter's minuscule syle is " << ToLower(letter) << "!\n" <<endl;
	return 0;
}
	
char ToUpper(char letter)
{
	char upper;
	if(letter >= 65 && letter <= 90) upper = letter;
	if(letter >= 97 && letter <= 122) upper = letter - 32;
	return upper;
}

char ToLower(char letter)
{
	char lower;
	if(letter >= 65 && letter <= 90) lower = letter + 32;
	if(letter >= 97 && letter <= 122) lower = letter;
	return lower;
}

void Input (char *p)
{
	int disputability;
	do
	{
		cin >> *p;
		disputability = 'A' > *p || ('Z' < *p && *p <'a') || *p > 'z';
		if(disputability) cout << "The char is not from the alphabet, please input it again!\n";
	}
	while (disputability); 
}


