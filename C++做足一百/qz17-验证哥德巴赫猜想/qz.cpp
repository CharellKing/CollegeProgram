//6.	判断素数(只能被1和该数本身整除的数称为素数, 1不是素数, 如: 2, 3, 5, 7, …)。
//int IsPrime(int n); // 例: IsPrime(5) = 1, IsPrime(6) = 0
//编写主函数, 输出100以内的全部素数。然后, 修改主函数, 验证哥德巴赫猜想(任何大于2的偶数都是两个素数之和): 
//将100以内任何大于2的偶数都表示为两个素数之和。输出结果如下: 
//4 = 2 + 2
//6 = 3 + 3
//8 = 3 + 5
//10 = 3 + 7
//12 = 5 + 7
//14 = 3 + 11
//……

#include <iostream>

#include <stdlib.h>

int CheckingGoldbachConjecture (int max);

int IsPrime(int n);

using namespace std;

int main()
{
	int max, sum;
	cout << "Please input the range of checking: (4 ~ max);\n";
	cin >> max;
	sum = CheckingGoldbachConjecture(max);
	if(sum == max / 2 - 1) cout << "Goldbach's Conjecture is ture in the range from 4 to " << max << " !\n";
	return 0;
}

int IsPrime(int integer)
{
	int start = 2, BOOL = 1, skiding = 0;
	for(; skiding == 0 && start < integer - 1; start ++)
	{
		if(0 == integer % start)
		{
			BOOL = 0;
			skiding = 1;
		}
	}
	if(integer <= 1) BOOL = 0;
	return BOOL;
}

int CheckingGoldbachConjecture (int max)
{
	int sum = 4, firstgene, secondgene, x = 0, skiding = 0;
	for(; sum <= max; skiding = 0, sum += 2)
	{
		for(firstgene = 2; skiding == 0 && firstgene <= sum / 2; firstgene ++)
		{
			if(IsPrime(firstgene))
			{
				secondgene = sum - firstgene;
				if(IsPrime(secondgene))
				{
					cout << sum << " = " << firstgene << " + " << secondgene << endl;
					x ++;
					skiding = 1;
				}
			}
		}
	}
	return x;
}

