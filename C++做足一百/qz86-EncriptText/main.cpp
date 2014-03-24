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
			"*此程序会出错:对非密文进行解密*\n"
			"*会造成程序崩溃！同时,在加密之*\n"
			"*前,选择B,将非二进制文件转化为*\n"
			"*二进制文件,如果想要观察明文，*\n"
			"*请按U，将明文转化为非二进制文*\n"
			"*件!                          *\n"
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
                   "*E---------加密*\n"
                   "*D---------解密*\n"
                   "*Q---------结束*\n"
				   "*B---二进制转化*\n"
				   "*U-----通常转化*\n"
				   "****************\n"
				   "请选择:", "EDBUQ"), c != 'Q')
    {
        try
        {
            switch(c)
            {
            case 'E':
                 cout << "请输入要加密的文件名(扩展名):";
                 cin >> filename; 
                 pEncriptText = new EncriptText;
                 pEncriptText->EnCode(filename);
				 cout << endl;
				 pEncriptText->~EncriptText();
                 pEncriptText = NULL;
				 cout << "加密完成!" << endl;
                 break;
            case 'D':
                 cout << "请输入要解密的文件名:(扩展名):";
                 cin >> filename;
                 pEncriptText = new EncriptText;
                 pEncriptText->DeCode(filename);
				 cout << endl;
                 pEncriptText->~EncriptText();
                 pEncriptText = NULL;
				 cout << "解密完成!" << endl;
                 break;
			case 'B':
				cout << "请输入要转换的非二进制文件:(扩展名):";
				cin >> filename;
				pEncriptText = new EncriptText;
                pEncriptText->Binary(filename);
				cout << endl;
                pEncriptText->~EncriptText();
                pEncriptText = NULL;
				cout << "二进制转化完成!" << endl;
                break;
			case 'U':
				cout << "请输入要转换的二进制文件:(扩展名):";
				cin >> filename;
				pEncriptText = new EncriptText;
                pEncriptText->Usually(filename);
				cout << endl;
                pEncriptText->~EncriptText();
				cout << "非二进制转化完成!" << endl;
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
