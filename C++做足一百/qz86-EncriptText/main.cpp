#include <iostream>

using namespace std;

#include <string>

#include <conio.h>

#include <windows.h>

#include <conio.h>

#include "EncriptText.h"

void Instruction()
{
	cout << "*******************************\n"
		    "*--------INSTRUCTION----------*\n"
			"*�˳�������:�Է����Ľ��н���*\n"
			"*����ɳ��������ͬʱ,�ڼ���֮*\n"
			"*ǰ,ѡ��B,���Ƕ������ļ�ת��Ϊ*\n"
			"*�������ļ�,�����Ҫ�۲����ģ�*\n"
			"*�밴U��������ת��Ϊ�Ƕ�������*\n"
			"*��!                          *\n"
			"*******************************\n";
	system("pause");
}

const char Menu(const char* items, const char* choice)
{
	char c;
	system("cls");
	cout << items;
	while(strchr(choice, c = toupper(getch())) == NULL);
	cout << c << endl;
	return c;
}

int main()
{
    EncriptText *pEncriptText = NULL;
    char c;
    string filename;
	Instruction();
    while(c = Menu("****************\n"
                   "*E---------����*\n"
                   "*D---------����*\n"
                   "*Q---------����*\n"
				   "*B---������ת��*\n"
				   "*U-----ͨ��ת��*\n"
				   "****************\n"
				   "��ѡ��:", "EDBUQ"), c != 'Q')
    {
        try
        {
            switch(c)
            {
            case 'E':
                 cout << "������Ҫ���ܵ��ļ���(��չ��):";
                 cin >> filename; 
                 pEncriptText = new EncriptText;
                 pEncriptText->EnCode(filename);
				 cout << endl;
				 pEncriptText->~EncriptText();
                 pEncriptText = NULL;
				 cout << "�������!" << endl;
                 break;
            case 'D':
                 cout << "������Ҫ���ܵ��ļ���:(��չ��):";
                 cin >> filename;
                 pEncriptText = new EncriptText;
                 pEncriptText->DeCode(filename);
				 cout << endl;
                 pEncriptText->~EncriptText();
                 pEncriptText = NULL;
				 cout << "�������!" << endl;
                 break;
			case 'B':
				cout << "������Ҫת���ķǶ������ļ�:(��չ��):";
				cin >> filename;
				pEncriptText = new EncriptText;
                pEncriptText->Binary(filename);
				cout << endl;
                pEncriptText->~EncriptText();
                pEncriptText = NULL;
				cout << "������ת�����!" << endl;
                break;
			case 'U':
				cout << "������Ҫת���Ķ������ļ�:(��չ��):";
				cin >> filename;
				pEncriptText = new EncriptText;
                pEncriptText->Usually(filename);
				cout << endl;
                pEncriptText->~EncriptText();
				cout << "�Ƕ�����ת�����!" << endl;
                break;
            } 
        }
        catch(string excep)
        {
			cout << endl;
            cout << excep << endl;
            pEncriptText = NULL;
        }
		system("pause");
    }
	return 0;
}
