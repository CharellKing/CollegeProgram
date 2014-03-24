#include <iostream>

using namespace std;

#include <conio.h>

#include <cstring>

#include "MyMenu.h"

#include "ATM.H"

ATM::ATM()
{
	head = new NODE;
	ReadOut();
	//if(!lock[0])
	//	lock = "恭喜发财!";	
}

ATM::~ATM()
{
	LNODE p;
	WriteIn();
	while(head)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

void ATM::ReadOut()
{
	LNODE p = head, s;
	FILE *fp;
	COSTOM a;
	fp = fopen("BANK_DATABASE.dat", "rb");
	if(fp)
	{
		while(fread(&a, sizeof(COSTOM), 1, fp) == 1)
		{
			s = new NODE;
			s->aCostom = a;
			p->next = s;
			p = s;
		}
		p->next = NULL;
		fclose(fp);
	}
	else head->next = NULL;
}

void ATM::WriteIn()
{
	LNODE p = head;
	FILE *fp; 
	fp = fopen("BANK_DATABASE.dat", "wb");
	if(fp)
	{
		while(p = p->next)
		{
			fwrite(&p->aCostom, sizeof(COSTOM), 1, fp);
		}
		fclose(fp);
	}
}

void ATM::Append(const COSTOM &x)
{
	LNODE p;
	if(!Exist(x.GetAccount()))
	{
		p = new NODE;
		p->aCostom = x;
		p->next = head->next;
		head->next = p;
		cout << "申请账户成功!" << endl;
	}
	else
	{
		cout << "此帐户已存在,请重新申请!" << endl;
	}
}

void ATM::Cover(const COSTOM &x)
{
	LNODE p, s = head, q;
	p = Exist(x.GetAccount());
	while(s->next != p)
	{
		s = s->next;
	}
	s->next = p->next;
	delete p;
	q = new NODE;
	q->next = s->next;
	q->aCostom = x;
	s->next = p;
}

/*void ATM::List()
{
	//string lock;
	//cout << "请输入密码:" << endl;
	//cin >> lock;
	
	LNODE p = head;
	while(p = p->next)
	{
		Output(p->aCostom);
	}
	//else cout << "密码错误!" << endl;
}*/

LNODE ATM::Exist(const char *s)
{
	LNODE p = head;
	while(p = p->next)
	{
		if(!strcmp(p->aCostom.GetAccount(), s)) break;
	}
	return p;
}

void ATM::Output(const COSTOM &x)
{
	cout << "***********************************" << endl;
	cout << "姓    名: " << x.GetName() << endl;
	cout << "性    别: " << (x.GetGender() ? "男" : "女") << endl; 
	cout << "账    户: " << x.GetAccount() << endl;
	cout << "密    码: " << x.GetCode() << endl;
	cout << "出生日期: "; x.OutputBirthday();
	cout << "民    族: " << x.GetNation() << endl;
	cout << "家庭地址: " << x.GetHomeAdr() << endl;
	cout << "身份证号: " << x.GetId_NO() << endl;
	cout << "存储金额: " << x.Fund() << " Y" << endl;
	cout << "***********************************" << endl;
}

void ATM::Save()
{
	double fund;
	cout << "请输入所存储金额:" << endl;
	cin >> fund;
	aCostom.Save(fund);
	Cover(aCostom);
	cout << "存储成功!" << endl;
}

void ATM::Modify_Code()
{
	aCostom.Code();
	Cover(aCostom);
	cout << "修改密码成功!" << endl;
}

void ATM::Show_Fund()
{
	cout << "您的余额为:" << aCostom.Fund() << endl;
}

void ATM::Withdrawl()
{
	double fund;
	cout << "请输入您要提取的金额:" << endl;
	cin >> fund;
	if(fund <= aCostom.Fund()) aCostom.Withdrawl(fund), Cover(aCostom), cout << "提取货币成功!" << endl;
	else cout << "余额不足!" << endl;
}

void ATM::Account()
{
	aCostom.Account();
	aCostom.Code();
	aCostom.PersonInfo();
	Append(aCostom);
}

char ATM::InSystem()
{
	char c, i;
	LNODE p;
	char code[7], account[16];
	bool b = false;
	do
	{
		cout << "请输入账号与密码!" << endl;
		cout << "账号:(15个字符, 只限数字与字母)" << endl;
		i = 0, p = head;
		while(c = getch(), i < 15)
		{
			if(isdigit(c) || isalpha(c)) account[i++] = c,
			cout << account[i - 1];
		}
		account[i] = '\0';
		cout << "\n密码(6个字符, 只限数字:)" << endl;
		i = 0;
		while(c = getch(), i < 6)
		{
			if(isdigit(c)) code[i++] = c, cout << '*';
		};
		code[i] = '\0';
		cout << endl;
		while(!b && p)
		{
			if(!strcmp(p->aCostom.GetAccount(), account) && !strcmp(p->aCostom.GetCode(), code)) b = true;
			else p = p->next;
		}
		if(b) aCostom = p->aCostom, c = 'C';
		else
		{
			cout << "账号或密码错误!" << endl;
			c = Menu("是否取消 (C - 继续 Q - 取消)", "CQ");
			if(c == 'Q') b = true;	
		}
	}
	while(!b);
	return c;
}

