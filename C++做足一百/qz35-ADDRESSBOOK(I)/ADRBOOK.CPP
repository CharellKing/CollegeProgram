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
	char c[16], i;
	PERSON x;
	bool b;
	c[0] = '0';
	static const char *column[] = {"退    出", "学    号", "班    级", "姓    名", "性    别", "出生日期", "入学日期", "移动电话",
								   "寝 室 号", "寝室电话", "家庭地址", "邮政编码", "家庭电话", "电子邮箱", "QQ 帐 号"};
	cout << "按栏目设置查询条件:" << endl;
	ShowIndexConditions();
	cout << "请选择:";
	do
	{
		b = false;
		while(cin >> k, (k > 14 || k < 0)) cout << "ERROR!\n";
		cout << column[k];
		cout << (k ?  ": " : "\n");
		SetPersonInformation(k , x);
		for(i = 0; c[i] != '0'; i ++)
		{
			if(c[i] == k) b = true;
		}
		if(!b) c[i ++] = k, c[i] = '0'; 
		if(k) ShowChoosedColumn(c, column), cout << "请选择:";
		m ++;
	}
	while(k);
	//ShowIndexConditions();
	if(1 == m) List(head);
	else Reference(head, x, c);
}

void Modify(LNODE &head, const char *s)
{
	LNODE p = head;
	bool b = false, a;
	while(p = p->next)
	{
		if(!strcmp(p->aPerson.studentnum, s))
		{
			b = true;
			break;
		}
	}
	if(!b) cout << "学号不存在!\n";
	else
	{
		Output(p->aPerson);
		int k; 
		char c[16], i;
		LNODE q;
		PERSON y;
		c[0] = '0';
		static const char *column[] = {"退    出", "学    号", "班    级", "姓    名", "性    别", "出生日期", "入学日期", "移动电话",
									   "寝 室 号", "寝室电话", "家庭地址", "邮政编码", "家庭电话", "电子邮箱", "QQ 帐 号"};
		cout << "选择需要修改的栏目:\n";
		ShowIndexConditions();
		cout << "请选择:";
		do
		{
			a = false;
			b = false;
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
			for(i = 0; c[i] != '0'; i ++)
			{
				if(c[i] == k)
				{
					b = true;
					break;
				}
			}
			if(!b && !a) c[i ++] = k, c[i] = '0'; 
			if(k) ShowChoosedColumn(c, column), cout << "请选择:";
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
	

void Reference(LNODE &head, const PERSON &x, const char *c)
{
	LNODE p = head;
	bool b[14];
	char s, i, k = 0;
	while(p = p->next)
	{
		s = 0;
		b[0] = !strcmp(x.studentnum, p->aPerson.studentnum);
		b[1] = !strcmp(x.group, p->aPerson.group);
		b[2] = !strcmp(x.name, p->aPerson.name);
		b[3] = (x.gender == p->aPerson.gender);
		b[4] = (x.birthday.day == p->aPerson.birthday.day &&
			x.birthday.month == p->aPerson.birthday.month && x.birthday.year == p->aPerson.birthday.year);
		b[5] = (x.entrance.day == p->aPerson.entrance.day &&
			x.entrance.month == p->aPerson.entrance.month && x.entrance.year == p->aPerson.entrance.year);
		b[6] = !strcmp(x.mobileTel, p->aPerson.mobileTel);
		b[7] = !strcmp(x.room, p->aPerson.room);
		b[8] = !strcmp(x.roomTel, p->aPerson.roomTel);
		b[9] = !strcmp(x.homeAdr, p->aPerson.homeAdr);
		b[10] = !strcmp(x.postcode, p->aPerson.postcode);
		b[11] = !strcmp(x.homeTel, p->aPerson.homeTel);
		b[12] = !strcmp(x.email, p->aPerson.email);
		b[13] = !strcmp(x.qq, p->aPerson.qq);
		for(i = 0; c[i]; i ++)
		{
			s += b[c[i] - 1];
		}
		if((s == i) && s) Output(p->aPerson), k ++;
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

void SortNum(char *c)
{
	int i, j, k;
	for(i = 0; c[i] != '0'; i ++)
	{
		k = i;
		for(j = i + 1; c[j] != '0'; j ++)
		{
			if(c[i] > c[j]) j = k;
		}
		Swap(c[i], c[k]);
	}
}

bool NoFind(const char *c, const char x)
{
	bool b = true;
	int i;
	for(i = 0; c[i] != '0'; i ++)
	{
		if(c[i] == x)
		{
			b = false;
			break;
		}
	}
	return b;
}

void ShowColumn(const char *s, const char *column[])
{
	char i, j;
	for(i = 0; s[i] != '0';)
	{
		cout << '*';
		for(; i % 5 != 4 && s[i] != '0'; i ++)
		{
			cout << "  " << setw(2) << (int)s[i] << " - " << column[s[i]];
		}
		if(i % 5 == 4 && s[i] != '0')
		{
			cout << "  " << setw(2) << (int)s[i] << " - " << column[s[i ++]];
		}
		for(j = i; j % 5; j ++)
		{
			cout << "               ";
		}
		cout << "  *" << endl;
	}
}

void ShowChoosedColumn(char *c, const char *column[])
{
	char j, k, s[16];
	SortNum(c);
	cout << "*******************************************************************************" << endl;
	cout << "*                                   已选栏目                                  *" << endl;
	ShowColumn(c, column);
	cout << "*******************************************************************************" << endl;
	cout << "*                                   备选栏目                                  *" << endl;
	for(k = 0, j = 0; k < 15; k ++)
	{
		if(NoFind(c, k)) s[j ++] = k;
	}
	s[j] = '0';
	ShowColumn(s, column);
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