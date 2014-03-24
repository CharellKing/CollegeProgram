//3.	正整数中的某位数字
//求正整数x的最低位、最高位和第n位(由低位到高位从0开始计数)。
//最低位函数: int LowDigit(int x);	// 例: LowDigit(25173) = 3
//最高位函数: int TopDigit(int x);	// 例: TopDigit(25173) = 2
//任意位函数: int Digit(int x, int n);	// 例: Digit(25173, 0) = 3, Digit(25173, 1) = 7, Digit(25173, 5) = 0
//提示: 25173 mod 10 = 3, C/C++的取模运算符为%, 即25173 % 10 = 3。


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

