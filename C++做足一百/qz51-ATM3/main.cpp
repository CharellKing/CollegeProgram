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
				 "*N - 申请    账户*\n"
				 "*S - 存储    货币*\n"
				 "*B - 查看    余额*\n"
				 "*W - 提取    货币*\n"
				 "*M - 修改    密码*\n"
				 "*Q - 结束    程序*\n"
				 "******************\n"
				 "请选择:", "NSBWMQ");
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

