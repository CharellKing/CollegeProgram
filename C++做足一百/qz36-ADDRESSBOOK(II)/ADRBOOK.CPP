#include <iostream>

using namespace std;

#include <cstring>

#include <iomanip>

#include "ADRBOOK.H"

#include "Person.h"

#include "MyMenu.h"

void Init(LNODE &head)
{
	head = new NODE;
	head->next = NULL;
}

void Append(LNODE &head, const PERSON &x)
{
	LNODE p, s = head;
	bool k = true;
	while((s = s->next))
	{
		if(!strcmp(x.studentnum, s->aPerson.studentnum))
		{
			k = false;
			cout  << endl << "学号重复，添加失败!\n";
			break;
		}
	}
	if(k)
	{
		p = new NODE;
		p->next = head->next;
		head->next = p;
		p->aPerson = x;
	}
}

void List(LNODE &head)
{
	LNODE p = head;
	while((p = p->next))
	{
		Output(p->aPerson);
	}
}

void Remove(LNODE &head, const char *s)
{
	char c;
	LNODE p = head->next, q = head;
	bool k = false;
	for(; p; p = p->next, q = q->next)
	{
		if(!strcmp(s, p->aPerson.studentnum))
		{
			k = true;
			break;
		}
	}
	if(k)
	{
		Output(p->aPerson);
		c = Menu("是否真的删去该条联系人信息(Y - yes, N - no)", "YN");
		if(c == 'Y') q->next = p->next, delete p;
	}
	else
	{
		cout << "对不起，没找到此人!\n";
	}
}


void Search(LNODE &head)
{
	int k, m = 0; 
	bool b[15];
	PERSON x;
	for(k = 0; k < 15; k ++) b[k] = false;
	static const char *column[] = {"退    出", "学    号", "班    级", "姓    名", "性    别", "出生日期", "入学日期", "移动电话",
								   "寝 室 号", "寝室电话", "家庭地址", "邮政编码", "家庭电话", "电子邮箱", "QQ 帐 号"};
	cout << "按栏目设置查询条件:" << endl;
	ShowIndexConditions();
	cout << "请选择:";
	do
	{
		while(cin >> k, (k > 14 || k < 0)) cout << "ERROR!\n";
		cout << column[k];
		cout << (k ?  ": " : "\n");
		SetPersonInformation(k , x);
		b[k] = true;
		if(k) ShowChoosedColumn(b, column), cout << "请选择:";
		m ++;
	}
	while(k);
	//ShowIndexConditions();
	if(1 == m) List(head);
	else Reference(head, x, b);
}

void Modify(LNODE &head, const char *s)
{
	LNODE p = head;
	bool b1 = false;
	while(p = p->next)
	{
		if(!strcmp(p->aPerson.studentnum, s))
		{
			b1 = true;
			break;
		}
	}
	if(!b1) cout << "学号不存在!\n";
	else
	{
		Output(p->aPerson);
		int k; 
		char i;
		bool b[15], a;
		LNODE q;
		PERSON y;
		for(i = 0; i < 15; i++) b[i] = false;
		static const char *column[] = {"退    出", "学    号", "班    级", "姓    名", "性    别", "出生日期", "入学日期", "移动电话",
									   "寝 室 号", "寝室电话", "家庭地址", "邮政编码", "家庭电话", "电子邮箱", "QQ 帐 号"};
		cout << "选择需要修改的栏目:\n";
		ShowIndexConditions();
		cout << "请选择:";
		do
		{
			a = false;
			while(cin >> k, (k > 14 || k < 0)) cout << "ERROR!\n";
			OutPersonInformation(k , p->aPerson);
			cout << column[k];
			cout << (k ?  ": " : "\n");
			SetPersonInformation(k , y);
			if(k == 1)
			{
				for(q = head->next; q; q = q->next) 
				{
					if(!strcmp(q->aPerson.studentnum, y.studentnum)) a = true;
				}
				if(a) cout << "学号已存在!\n";
				else Evaluate(p, y, k);
			}
			else Evaluate(p, y, k);
			if(!a) b[k] = true;
			if(k) ShowChoosedColumn(b, column), cout << "请选择:";
		}
		while(k);
		//ShowIndexConditions();
	}
}

void Sort(LNODE &head)
{
	int k;
	static const char *column[] = {"退    出", "学    号", "班    级", "姓    名", "性    别", 
									"出生日期", "入学日期", "移动电话", "寝 室 号", "寝室电话", "家庭地址", "邮政编码", "家庭电话", "电子邮箱", "QQ 帐 号"};
	cout << "选择显示顺序依据的栏目:\n";
	ShowIndexConditions();
	cout << "请选择:";
	while(cin >> k, (k > 14 || k < 0)) cout << "ERROR!\n";
	if(k)
	{
		LNODE p = head, q, s;
		char c;
		cout << column[k] << endl;
		c = Menu("排序: (A - 升序 D - 降序) ", "AD");
		while(p = p->next)
		{
			q = p;
			s = p;
			while(q = q ->next)
			{
				if(c == 'A') 
				{
					if(-1 == IsMax(q->aPerson , s->aPerson, k)) s = q;
				}
				if(c == 'D')
				{
					if(1 == IsMax(q->aPerson, s->aPerson, k)) s = q;
				}
			}
			SwapPerson(p->aPerson, s->aPerson);
		}
	}
	Show(head);
}

void Show(LNODE &head)
{
	LNODE p = head;
	cout << "学    号   姓    名 性    别 出生日期   移动电话      寝 室 号  QQ 帐 号\n";
	while(p = p->next)
	{
		cout << left;
		cout << setw(10) << p->aPerson.studentnum << ' ';
		cout << setw(8) << p->aPerson.name << ' ';
		cout << setw(8) << (p->aPerson.gender ? "男" : "女") << ' ';
		cout << right;
		cout << setfill('0') << setw(4) << p->aPerson.birthday.year << '-'
							 <<	setw(2) << (int)p->aPerson.birthday.month << '-' 
							 << setw(2) << (int)p->aPerson.birthday.day
			 << ' ' << setfill(' ');
		cout << left;
		cout << setw(13) << p->aPerson.mobileTel << ' ';
		cout << setw(9) << p->aPerson.room << ' ';
		cout << setw(10) << p->aPerson.qq << endl;
	}
}

char IsMax(const PERSON &x , const PERSON &y, const char c)
{
	int k;
	switch(c)
	{
		case 1:
			k = strcmp(x.studentnum, y.studentnum);
			break;
		case 2:
			k = strcmp(x.group, y.group);
			break;
		case 3:
			k = strcmp(x.name, y.name);
			break;
		case 4:
			x.gender > y.gender ? k = 1: k = -1;
			break;
		case 5:
			k = IsDateMax(x.birthday, y.birthday);
			break;
		case 6:
			k = IsDateMax(y.entrance, y.entrance);
			break;
		case 7:
			k = strcmp(x.mobileTel, y.mobileTel);
			break;
		case 8:
			k = strcmp(x.room, y.room);
			break;
		case 9:
			k = strcmp(x.roomTel, y.roomTel);
			break;
		case 10:
			k = strcmp(x.homeAdr, y.homeAdr);
			break;
		case 11:
			k = strcmp(x.postcode, y.postcode);
			break;
		case 12:
			k = strcmp(x.homeTel, y.homeTel);
			break;
		case 13:
			k = strcmp(x.email, y.email);
			break;
		case 14:
			k = strcmp(x.qq, y.qq);
			break;
	}
	return k;
}

void SwapPerson(PERSON &x, PERSON &y)
{
	PERSON z = x;
	x = y;
	y = z;
}

int IsDateMax(const DATE &x, const DATE &y)
{
	int k;
	if(x.year > y.year) k = 1;
	if(x.year < y.year) k = -1;
	if(x.year == y.year)
	{
		if(x.month > y.month) k = 1;
		if(x.month < y.month) k = -1;
		if(x.month == y.month)
		{
			if(x.day > y.day) k = 1;
			if(x.day < y.day) k = -1;
			if(x.day == y.day) k = 0;
		}
	}
	return k;
}
	

void Evaluate(LNODE &p, const PERSON &x, const char c)
{
	switch(c)
	{
		case 1:
			strcpy(p->aPerson.studentnum, x.studentnum);
			break;
		case 2:
			strcpy(p->aPerson.group, x.group);
			break;
		case 3:
			strcpy(p->aPerson.name, x.name);
			break;
		case 4:
			p->aPerson.gender = x.gender;
			break;
		case 5:
			p->aPerson.birthday.day = x.birthday.day, p->aPerson.birthday.month = x.birthday.month, 
			p->aPerson.birthday.year = x.birthday.year;
			break;
		case 6:
			p->aPerson.entrance.day = x.entrance.day, p->aPerson.entrance.month = x.entrance.month, 
			p->aPerson.entrance.year = x.entrance.year;
			break;
		case 7:
			strcpy(p->aPerson.mobileTel, x.mobileTel);
			break;
		case 8:
			strcpy(p->aPerson.room, x.room);
			break;
		case 9:
			strcpy(p->aPerson.roomTel, x.roomTel);
			break;
		case 10:
			strcpy(p->aPerson.homeAdr, x.homeAdr);
			break;
		case 11:
			strcpy(p->aPerson.postcode, x.postcode);
			break;
		case 12:
			strcpy(p->aPerson.homeTel, x.homeTel);
			break;
		case 13:
			strcpy(p->aPerson.email, x.email);
			break;
		case 14:
			strcpy(p->aPerson.qq, x.qq);
			break;
	}
}
	

void Reference(LNODE &head, const PERSON &x, const bool *b)
{
	LNODE p = head;
	bool b1[14];
	char s, s1 = 0, i, k = 0;
	for(i = 1; i < 15; i ++) s1 += b[i]; 
	while(p = p->next)
	{
		s = 0;
		b1[0] = !strcmp(x.studentnum, p->aPerson.studentnum);
		b1[1] = !strcmp(x.group, p->aPerson.group);
		b1[2] = !strcmp(x.name, p->aPerson.name);
		b1[3] = (x.gender == p->aPerson.gender);
		b1[4] = (x.birthday.day == p->aPerson.birthday.day &&
			x.birthday.month == p->aPerson.birthday.month && x.birthday.year == p->aPerson.birthday.year);
		b1[5] = (x.entrance.day == p->aPerson.entrance.day &&
			x.entrance.month == p->aPerson.entrance.month && x.entrance.year == p->aPerson.entrance.year);
		b1[6] = !strcmp(x.mobileTel, p->aPerson.mobileTel);
		b1[7] = !strcmp(x.room, p->aPerson.room);
		b1[8] = !strcmp(x.roomTel, p->aPerson.roomTel);
		b1[9] = !strcmp(x.homeAdr, p->aPerson.homeAdr);
		b1[10] = !strcmp(x.postcode, p->aPerson.postcode);
		b1[11] = !strcmp(x.homeTel, p->aPerson.homeTel);
		b1[12] = !strcmp(x.email, p->aPerson.email);
		b1[13] = !strcmp(x.qq, p->aPerson.qq);
		for(i = 0; i < 14; i ++)
		{
			s += b1[i];
		}
		if(s == s1) Output(p->aPerson), k ++;
	}
	if(!k) cout << "查无此人!\n";
}

void ShowIndexConditions()
{
	cout << "*******************************************************************************\n"
			"*                                   可选栏目                                  *\n"                                  
			"*   1 - 学    号   2 - 班    级   3 - 姓    名   4 - 性    别   5 - 出生日期  *\n"
			"*   6 - 入学日期   7 - 移动电话   8 - 寝 室 号   9 - 寝室电话  10 - 家庭地址  *\n"
			"*  11 - 邮政编码  12 - 家庭电话  13 - 电子邮箱  14 - QQ 帐 号   0 - 退    出  *\n"
			"*******************************************************************************\n";
}

void Swap(char &x, char &y)
{
	char z = x;
	x = y;
	y = z;
}

void ShowColumn(const bool *b, const char *column[], bool b1)
{
	char i, j = 0;
	cout << '*';
	for(i = 1; i < 15; i ++)
	{
		if(b[i] == b1 && j % 5 != 4) j ++, cout << "  " << setw(2) << (int)i << " - " << column[i];
		if(b[i] == b1 && j % 5 == 4) j ++, cout << "  " << setw(2) << (int)i << " - " << column[i] << "  " << '*' << endl << '*';
	}
	while(j % 5 != 4) j ++, cout << "               ";
	if(j % 5 == 4)  cout << "                 *" << endl;
}

void ShowChoosedColumn(const bool *b, const char *column[])
{
	cout << "*******************************************************************************" << endl;
	cout << "*                                   已选栏目                                  *" << endl;
	ShowColumn(b, column, true);
	cout << "*******************************************************************************" << endl;
	cout << "*                                   备选栏目                                  *" << endl;
	ShowColumn(b, column, false);
	cout << "*******************************************************************************" << endl;
}

void SetPersonInformation(int k , PERSON &x)
{
	switch(k)
	{
		case 1:
			cin >> x.studentnum;
			break;
		case 2:
			cin >> x.group;
			break;
		case 3:
			cin >> x.name;
			break;
		case 4:
			'M' == Menu("(M - 男, F - 女)", "MF") ? x.gender = 1 : x.gender = 0;
			break;
		case 5:
			InputDate(x.birthday);
			break;
		case 6:
			InputDate(x.entrance);
			break;
		case 7:
			cin >> x.mobileTel;
			break;
		case 8:
			cin >> x.room;
			break;
		case 9:
			cin >> x.roomTel;
			break;
		case 10:
			cin >> x.homeAdr;
			break;
		case 11:
			cin >> x.postcode;
			break;
		case 12:
			cin >> x.homeTel;
			break;
		case 13:
			cin >> x.email;
			break;
		case 14:
			cin >> x.qq;
			break;
	}
}
	

void OutPersonInformation(int k , PERSON &x)
{	
	switch(k)
	{
		case 1:
			cout << "学    号: " << x.studentnum << endl;
			break;
		case 2:
			cout << "班    级: " << x.group << endl;
			break;
		case 3:
			cout << "姓    名: " << x.name << endl;
			break;
		case 4:
			cout << "性    别: " << (x.gender ? "男" : "女") << endl; 
			break;
		case 5:
			cout << "出生日期: "; OutputDate(x.birthday);
			break;
		case 6:
			cout << "入学日期: "; OutputDate(x.entrance);
			break;
		case 7:
			cout << "移动电话: " << x.mobileTel << endl;
			break;
		case 8:
			cout << "寝 室 号: " << x.room << endl;
			break;
		case 9:
			cout << "寝室电话: " << x.roomTel << endl;
			break;
		case 10:
			cout << "家庭地址: " << x.homeAdr << endl;
			break;
		case 11:
			cout << "邮政编码: " << x.postcode << endl;
			break;
		case 12:
			cout << "家庭电话: " << x.homeTel << endl;
			break;
		case 13:
			cout << "电子邮箱: " << x.email << endl;
			break;
		case 14:
			cout << "QQ 帐 号: " << x.qq << endl;
			break;
	}
}

void Clear(LNODE &h)
{
	LNODE p;
	while(p = h->next)
	{
		h->next = p->next;
		delete p;
	}
}