//3.	�����Żݻ(һ)
//���˿͹��ﲻ��100Ԫ, ���Ż�; �����100Ԫ, �������Żݡ����빺����ܶ�, ���������(����2λС��)��

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


