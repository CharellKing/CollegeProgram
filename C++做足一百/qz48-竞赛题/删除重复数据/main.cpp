/*2.	ɾ���ظ�����
�Ӽ�������n������a1, a2, ..., an, ɾȥ�����ظ�������, Ȼ�������
����: ����10������: 1, 5, 3, 2, 1, 3, 8, 4, 1, 6, ���: 1, 5, 3, 2, 8, 4, 6��
 	��������
ÿ�������������, ��һ��������n, �ڶ�����n������a1, a2, ..., an����nΪ0ʱ������
 	�������
ÿ���������һ��, ��ɾ���ظ����ݺ������������
 	��������
����	���
3
1 2 1
5
1 2 1 2 1
10
1 5 3 2 1 3 8 4 1 6
0	1 2
1 2
1 5 3 2 8 4 6
*/

#include <iostream>

using namespace std;

const int M = 100;

bool Exist(double *array, int n, double real)
{
	for(-- n; n >= 0; n --)
	{
		if(real == array[n]) return true;
	}
	return false;
}

void Output(double *array, int n)
{
	for(n --; n >= 0; n --)
	{
		cout << ' ' << array[n];
	}
}

int main()
{
	double num, array[M];
	int i = 0;
	while(cin >> num, num)
	{
		if(!Exist(array, i, num)) array[i ++] = num;
	}
	Output(array, i); cout << endl;
	return 0;
}

