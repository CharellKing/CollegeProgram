//2.	韩信点兵(二)
//任给a, b, c(0 a<3, 0 b<5, 0 c<7), 求除以3余a, 除以5余b, 除以7余c的最小正整数解。
//int Special(int a, int b, int c);
//源自《算术统宗》: "三人同行七十稀, 五树梅花廿一枝, 七子团圆正半月, 除百零五便得知。


#include <iostream>

using namespace std;

int HanXinParade(int a, int b, int c);

int main()
{
	int a, b, c;
	cout << "You should read the detail regulations about the game!\n";
	cout << "First you give three positive integer:a, b, c:\n";
	cout << "(a < 3, b < 5, c < 7)\n";
	cout << "The computer will find a value:\n";
	cout << "The value is divided by 3 left a,\n";
	cout << "The value is divided by 5 left b,\n";
	cout << "The value is divided by 7 left c,\n";
	cout << "\n" << endl;
	cout << "Now it is time for you to input a, b, c;\n";
	cin >> a >> b >> c;
	cout << "The value is " << HanXinParade(a, b, c) << " !\n" << endl;
	return 0;
}

int HanXinParade(int a, int b, int c)
{
	int i = 0;
	do
	{
		i ++;
	}
	while(a != i % 3 || b != i % 5 || c != i % 7);
	return i;
}
		

