//2.	������Ʊ:
//���˿���ߵ���1.2�������, ������ȡ����2Ԫ��

#include <iostream>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double audienceHeight;
	cout << "Input audience's height:" << endl;
	cin >> audienceHeight;
	if(audienceHeight < 1.2)
	{
		cout << "FREE!\n";
		cout << endl;
	}
	else
	cout << "TAKE 1.2 yuan.\n";
	return 0;
}

