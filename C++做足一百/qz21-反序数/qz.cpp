//4.	������
//��д������������
//int RevNum(int n); // ��: Reverse(1234) = 4321;
//��ʾ: ���Ƚ��ۼ���s����; Ȼ���ۼ���s����10, �ټ���n�ĸ�λ��4, ��n����10��Ϊ123; 
//�ٽ��ۼ�������10����ȡn�ĸ�λ3��43, ��n����10��Ϊ12; ��, ��˼�����ȥ, ��n��Ϊ��ʱ, s��Ϊ4321��
//��������ĺ������жϻ�����(����������һ������)��
//int IsPalNum(int n); // ��: IsPalNum(159743) = 0, IsPalNum(1258521) = 1

#include <iostream>

using namespace std;

int RevNum(int n);


int main()
{
	int integer;
	cout << "Please input a integer:\n";
	cin >> integer;
	cout << "The reverse number is " << RevNum(integer) << " !\n";
	return 0;
}

int RevNum(int n)
{
	int k = 1, z, a, reverseNumber = 0;
	while(k <= n)
	{
		k *= 10;
	}
	k /= 10;
	z = k * 10;
	while(z >= 1)
	{
		z /= 10;
		a = n % 10;
		reverseNumber += a * z;
		n /= 10;
	}
	return reverseNumber;
}
		



