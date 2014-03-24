//4.	������
//��д������������
//int RevNum(int n); // ��: Reverse(1234) = 4321;
//��ʾ: ���Ƚ��ۼ���s����; Ȼ���ۼ���s����10, �ټ���n�ĸ�λ��4, ��n����10��Ϊ123; 
//�ٽ��ۼ�������10����ȡn�ĸ�λ3��43, ��n����10��Ϊ12; ��, ��˼�����ȥ, ��n��Ϊ��ʱ, s��Ϊ4321��
//��������ĺ������жϻ�����(����������һ������)��
//int IsPalNum(int n); // ��: IsPalNum(159743) = 0, IsPalNum(1258521) = 1

#include <iostream>

using namespace std;

#define M 50

void Input(char *p, int *m); 

int RevNum(const char *p, int n);

int main()
{
	char array[M];
	int n;
	cout << "Please input the integer:\n";
	Input(array, &n);
	cout << "The reverse number is " << RevNum(array, n) << " !\n";
	return 0;
}

void Input(char *p, int *m)
{
	int i = 1;
	do
	{
		cin.get(p[i]);
		i ++;
	}
	while(isdigit(p[i - 1]));
	*m = i - 2;
}

int RevNum(const char *p, int n)
{
	int i = 1, reversednumber = 0;
	double k = 0.1;
	for(; i <= n; i ++)
	{
		k *= 10;
		reversednumber += (p[i] - '0') * (int)k;
	}
	return reversednumber;
}



