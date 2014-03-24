//7.	��������
//��һ��: ��ʵ����������Ϊֻ���������ֵ�ʵ����
//double Round0(double x); // ��: Round(4.6) = 5.0, Round0(4.1) = 4.0; Round0(-2.6) = -3.0
//��ʾ: xֵ��/��0.5, ��������floor��ceil����ȡ����
//�ڶ���: ��ʵ���������뵽С������2λ��
//double Round2(double x); // ��: Round2(4.375) = 4.38, Round2(-4.374) = -4.37
//������: ��ʵ���������뵽С������nλ��
//double Round(double x, int n); // ��: Round(3.1548, 0) = 3, Round(-3.1548, 3) = -3.

#include <iostream>

double Round(double realNumber, char afterPoint);

int Ceil(double numer);

using namespace std;

#define absoluteValue(number) (number > 0 ? number : -number)

int main()
{
	double realNumber, reservingNumber; 
	char afterPoint;
	cout << "Please input a real number:\n";
	cin >> realNumber;
	cout << "How many the digit after the real-number's point you will reserve:\n";
	cin >> afterPoint;
	reservingNumber = Round(realNumber, afterPoint);
	cout << "Output the new number that has been reserved:\n" << reservingNumber << endl;
	return 0;
}

double Round(double realNumber, char afterPoint)
{
	double number;
	double k = 10;
	char i = '0';
	for(; i < afterPoint; i ++)
	{
		k *= 10;
	}
	number = realNumber * k;
	return Ceil(number) / k;
}

int Ceil(double number)
{
	int integer, newInteger, m;
	integer = (int)(number);
	m = absoluteValue(integer) + 5;
	newInteger = m - m % 10;
	if(integer < 0) newInteger = - newInteger;
	return newInteger;
}

	


	
