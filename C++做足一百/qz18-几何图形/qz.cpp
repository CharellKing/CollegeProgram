//7.	几何图形
//要求: 编写显示如下几何图形的函数, 并编写主函数显示菜单"1-直线 2-三角形 3-菱形 0-结束", 
//由用户进行选择。若选择1～5, 则输入必要的数据, 然后调用有关函数显示图形; 若选择0, 则结束程序。
//void Line(int n, char c);	// 显示字符c组成的长度为n的直线
//void Square(int n, char c);	// 显示字符c组成的长度为n的正方形
//void Isoceles(int n, char c);	// 显示字符c组成的高为n底为2n-1的等腰三角形
//void Diamond(int n, char c);	// 显示字符c组成的高为n的菱形


#include <iostream>

using namespace std;

class GeometricalPicture
{
public:
void Line(int num, char character);	// 显示字符c组成的长度为n的直线
void Square(int num, char character);	// 显示字符c组成的长度为n的正方形
void Isoceles(int num, char character);	// 显示字符c组成的高为n底为2n-1的等腰三角形
void Diamond(int num, char character);	// 显示字符c组成的高为n的菱形
void Blank(int num);// 显示空格；
};

void GeometricalPicture::Line(int num, char character)
{
	 int i = 1;
	 for(i = 1; i <= num; i ++)
	 {
		 cout << character;
	 }
	 cout << "\n";
}

void GeometricalPicture::Square(int num, char character)
{
	int i;
	for(i = 1; i <= num; i ++)
	{
		Line(num, character);
	}
	cout << "\n";
}

void GeometricalPicture::Isoceles(int num, char character)
{
	int i;
	for(i = 1; i <= num; i ++)
	{
		Blank(num - i);
		Line(2 * i - 1, character);
	}
}

void GeometricalPicture::Diamond(int num, char character)
{
	int i, k = (num + 1) / 2;
	Isoceles((num + 1) / 2, character);
	for(i = k + 1 ; i <= num; i ++)
	{
		Blank(i - k);
		Line(4 * k - 2 * i - 1, character);
	}
	cout << endl;
}





void GeometricalPicture::Blank(int num)
{
	int i;
	for(i = 1; i <= num; i ++)
	cout << " ";
}


void OnOff()
{
	int num;
	char character, a;
	GeometricalPicture Fun;
	cout << " Please choose the menu:\n" ;
	cout << " Choose \" 1 \", show a line.\n";
	cout << " Choose \" 2 \", show square.\n";
	cout << " Choose \" 3 \", show isosceles triangle.\n";
	cout << " Choose \" 4 \", show prismatic.\n";
	cout << " Choode \" 0 \",  put the program to end.\n";
	do
	{
		cin >> a;
		if(a <= '4' && a >= '1')
		{
			cout << " Output the \"num\":\n";
			cin >> num;
			cout << " Output a character:\n";
			cin >> character;
			cout << "Daw the picture:\n";
			switch(a)
			{
				case '1':
				Fun.Line(num, character);
				break;
				case '2':
				Fun.Square(num, character);
				break;
				case '3':
				Fun.Isoceles(num, character);
				break;
				case '4':
				Fun.Diamond(num, character);
				break;
			}
			cout << "\n";
		}
		if(a != '0') cout << "Input switch 'a' again.\n";
	}
	while(a != '0');
}


int main()
{
	OnOff();
	return 0;
}

