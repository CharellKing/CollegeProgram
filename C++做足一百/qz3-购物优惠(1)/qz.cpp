//3.	购物优惠活动(一)
//若顾客购物不足100元, 则不优惠; 购物达100元, 按九折优惠。输入购物款总额, 输出付款金额(保留2位小数)。

#include <iostream>

using std::cout;

using std::cin;

using std::endl;

int main()
{
	float shoppingSum;
	cout << "Please input the shoppingSum :";
	cout << endl;
	cin >> shoppingSum;
	if(shoppingSum >= 100)
	{
		cout << "Output the expense after been discounted:" << "\n";
		cout << shoppingSum * 0.9 << endl;
	}
	else
	{
		cout << "Don't discount:" << "\n";
		cout << shoppingSum << endl;
	}
	cout << "THANK YOU!\n";
	return 0;
}


