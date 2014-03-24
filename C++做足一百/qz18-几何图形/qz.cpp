//7.	����ͼ��
//Ҫ��: ��д��ʾ���¼���ͼ�εĺ���, ����д��������ʾ�˵�"1-ֱ�� 2-������ 3-���� 0-����", 
//���û�����ѡ����ѡ��1��5, �������Ҫ������, Ȼ������йغ�����ʾͼ��; ��ѡ��0, ���������
//void Line(int n, char c);	// ��ʾ�ַ�c��ɵĳ���Ϊn��ֱ��
//void Square(int n, char c);	// ��ʾ�ַ�c��ɵĳ���Ϊn��������
//void Isoceles(int n, char c);	// ��ʾ�ַ�c��ɵĸ�Ϊn��Ϊ2n-1�ĵ���������
//void Diamond(int n, char c);	// ��ʾ�ַ�c��ɵĸ�Ϊn������


#include <iostream>

using namespace std;

class GeometricalPicture
{
public:
void Line(int num, char character);	// ��ʾ�ַ�c��ɵĳ���Ϊn��ֱ��
void Square(int num, char character);	// ��ʾ�ַ�c��ɵĳ���Ϊn��������
void Isoceles(int num, char character);	// ��ʾ�ַ�c��ɵĸ�Ϊn��Ϊ2n-1�ĵ���������
void Diamond(int num, char character);	// ��ʾ�ַ�c��ɵĸ�Ϊn������
void Blank(int num);// ��ʾ�ո�
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

