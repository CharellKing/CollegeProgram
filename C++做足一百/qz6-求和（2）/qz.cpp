//6.	求和(二)
//输入正整数n, 计算并输出:1 + 1/2 + 1/3 + 1/4·······
 

#include <iostream>

using namespace std;

int main()
{
	int max, i;
	float sum; 
	cout << "There are some integer adding from 1/1 to 1/max\n";
	cout << "Input max:";
	cin >> max;
	for(sum = 0, i = 1; i <= max; i ++)
	{
		sum += 1.0/i;
	}
	cout << "Output the adding sum from 1/1 to 1/max:" << endl;
	cout << sum << endl <<endl;
	return 0;
}


