#include <iostream>

using namespace std;

#include "ATM.H"

#include "COSTOM.H"

#include "MyMenu.h"

int main()
{
	ATM a;
	char c;
	do
	{
		c = Menu("******************\n"
				 "*N - ����    �˻�*\n"
				 "*S - �洢    ����*\n"
				 "*B - �鿴    ���*\n"
				 "*W - ��ȡ    ����*\n"
				 "*M - �޸�    ����*\n"
				 "*Q - ����    ����*\n"
				 "******************\n"
				 "��ѡ��:", "NSBWMQ");
		switch(c)
		{
		case 'N':
			a.Account();
			break;
		case 'S':
			c = a.InSystem();
			if(c == 'C') a.Save();
			break;
		case 'B':
			c = a.InSystem();	
			if(c == 'C') a.Show_Fund();
			break;
		case 'W':
			c = a.InSystem();
			if(c == 'C')a.Withdrawl();
			break;
		case 'M':
			c = a.InSystem();
			if(c == 'C') a.Modify_Code();
			break;
		}
	}
	while(c != 'Q');
	return 0;
}

