//3.	�������е�ĳλ����
//��������x�����λ�����λ�͵�nλ(�ɵ�λ����λ��0��ʼ����)��
//���λ����: int LowDigit(int x);	// ��: LowDigit(25173) = 3
//���λ����: int TopDigit(int x);	// ��: TopDigit(25173) = 2
//����λ����: int Digit(int x, int n);	// ��: Digit(25173, 0) = 3, Digit(25173, 1) = 7, Digit(25173, 5) = 0
//��ʾ: 25173 mod 10 = 3, C/C++��ȡģ�����Ϊ%, ��25173 % 10 = 3��


#include <iostream>

int LowDigit(int integer);

int TopDigit(int integer);

int Digit(int integer, int digitnumber);

using namespace std;

int main()
{
	int integer, lowdigit, topdigit, middledigit, digitnumber;
	cout << "Please input a integer:" << endl;
	cin >> integer;
	lowdigit = LowDigit(integer);
	topdigit = TopDigit(integer);
	cout << "The lowdigit is " << lowdigit << "!\n" << endl;
	cout << "The topdigit is " << topdigit << "!\n" << endl;
	cout << "Please input the digitnumber:\n";
	cin >> digitnumber;
	cout << endl;
	middledigit = Digit(integer, digitnumber);
	cout << "The middledigit you need is " << middledigit << "!\n" <<endl;
	return 0;
}

int LowDigit(int integer)
{
	return integer % 10;
}

int TopDigit(int integer)
{
	int k = 1;
	while (k <= integer)
	{
		k *= 10;
	}
	k /= 10;
	return integer / k;
}

int Digit(int integer, int digitnumber)
{
	int k = 1, i = 1;
	for(; i < digitnumber; k *= 10, i ++);
	return (integer / k) % 10;
}

