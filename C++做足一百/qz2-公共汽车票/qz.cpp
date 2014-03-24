//2.	公汽车票:
//若乘客身高低于1.2米则免费, 否则收取车费2元。

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

