#include <iostream>

using namespace std;

#include <conio.h>

#include <cctype>

#include "COSTOM.H"

#include "MyMenu.H"

COSTOM::COSTOM()
{
	aCostom.account[0] = '\0';
	aCostom.code[0] = '\0';
	aCostom.fund = 0;
	aCostom.id.homeAdr[0] = '\0';
	aCostom.id.id_NO[0] = '\0';
	aCostom.id.name[0] = '\0';
	aCostom.id.gender = true;
	aCostom.id.nation[0] = '\0';
}

void COSTOM::Account()
{
	int i = 0;
	char c;
	cout << "请开设一个账户:(15个字符, 只限数字与字符)" << endl;
	while(c = getch(), i < 15)
	{
		if(isalpha(c) || isdigit(c)) this->aCostom.account[i++] = c,
		cout << aCostom.account[i - 1];
	}
	aCostom.account[i] = '\0';
	cout << endl;
}

void COSTOM::Code()
{
	int i;
	char c;
	char s[7], s1[7];
	bool b;
	do
	{
		i = 0;
		cout << "请设置密码:(6位数字)" << endl;
		while(c = getch(), i < 6)
		{
			if(isdigit(c)) s[i++] = c, cout << '*';
		}
		s[i] = '\0';
		cout << endl;
		cout << "请重新输入以确认:" << endl;
		i = 0;
		while(c = getch(), i < 6)
		{
			if(isdigit(c)) s1[i++] = c, cout << '*';
		}
		s1[i] = '\0';
		cout << endl;
		if(!strcmp(s, s1))
		{
			b = false;
			for(i = 0; i < 7; i ++) aCostom.code[i] = s[i];
			cout << "设密成功!" << endl;
		}
		else b = true, cout << "前后输入不一致，重新输入!" << endl;
	}
	while(b);
}

void COSTOM::PersonInfo()
{
	cout << "请输入姓名:" << endl;
	cin >> aCostom.id.name;
	'M' == Menu("请输入性别: (F - 女 M - 男)", "FM") ? aCostom.id.gender = true : aCostom.id.gender = false;
	cout << "请输入家庭地址:" << endl;
	cin >> aCostom.id.homeAdr;
	cout << "请输入ID号:" << endl;
	cin >> aCostom.id.id_NO;
	cout << "请输入所属民族:" << endl;
	cin >> aCostom.id.nation;
	cout << "请输入出生年月日(1988-10-1):" << endl;
	aCostom.id.birthday.InputDate();
}

const char* COSTOM::GetAccount()const
{
	return aCostom.account;
}

const char* COSTOM::GetCode()const
{
	return aCostom.code;
}

const char* COSTOM::GetName()const
{
	return aCostom.id.name;
}

const char* COSTOM::GetHomeAdr()const
{
	return aCostom.id.homeAdr;
}

const char* COSTOM::GetNation()const
{
	return aCostom.id.nation;
}

const char* COSTOM::GetId_NO()const
{
	return aCostom.id.id_NO;
}

MYDATE COSTOM::GetBirthday()const
{
	return aCostom.id.birthday;
}

bool COSTOM::GetGender()const
{
	return aCostom.id.gender;
}

void COSTOM::OutputBirthday()const
{
	aCostom.id.birthday.OutputDate();
}

double COSTOM::Fund()const
{
	return aCostom.fund;
}

void COSTOM::Save(double fund)
{
	aCostom.fund += fund;
}

void COSTOM::Withdrawl(double fund)
{
	aCostom.fund -= fund;
}