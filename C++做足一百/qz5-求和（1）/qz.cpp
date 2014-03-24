//5.	求和(一)
//输入正整数n, 计算并输出:
//S = 1 + 2 + 3 + 4 + … + n

#include <iostream>

using namespace std;

/*int main()
{
	int max;
	cout << "There are some integer adding from 1 to max\n";
	cout << "Input max:";
	cin >> max;
	cout << "Output the adding sum from 1 to max:" << endl;
	cout << max * (max + 1) / 2 << endl <<endl;
	return 0;
}
*/

int main()
{
	int max, sum, i;
	cout << "There are some integer adding from 1 to max\n";
	cout << "Input max:";
	cin >> max;
	for(sum = 0, i = 1; i <= max; i ++)
	{
		sum += i;
	}
	cout << "Output the adding sum from 1 to max:" << endl;
	cout << sum << endl <<endl;
	return 0;
}


