#include <iostream>

using namespace std;

#include "Person.h"

#include "MyDate.h"

#include "MyMenu.h"

void Input(PERSON &x)
{
	cout << "学    号: "; cin >> x.studentnum;
	cout << "班    级: "; cin >> x.group;
	cout << "姓    名: "; cin >> x.name;
	cout << "性    别: "; 'M' == Menu("(M - 男, F - 女)", "MF") ? x.gender = 1 : x.gender = 0;
	cout << "出生日期: "; InputDate(x.birthday);
	cout << "入学日期: "; InputDate(x.entrance);
	cout << "移动电话: "; cin >> x.mobileTel;
	cout << "寝 室 号: "; cin >> x.room;
	cout << "寝室电话: "; cin >> x.roomTel;
	cout << "家庭地址: "; cin >> x.homeAdr;
	cout << "邮政编码: "; cin >> x.postcode;
	cout << "家庭电话: "; cin >> x.homeTel;
	cout << "电子邮箱: "; cin >> x.email;
	cout << "QQ 帐 号: "; cin >> x.qq;
}

void Output(const PERSON &x)
{
	cout << "=========================================\n";
	cout << "学    号: " << x.studentnum << endl;
	cout << "班    级: " << x.group << endl;
	cout << "姓    名: " << x.name << endl;
	cout << "性    别: " << (x.gender ? "男" : "女") << endl; 
	cout << "出生日期: "; OutputDate(x.birthday);
	cout << "入学日期: "; OutputDate(x.entrance);
	cout << "移动电话: " << x.mobileTel << endl;
	cout << "寝 室 号: " << x.room << endl;
	cout << "寝室电话: " << x.roomTel << endl;
	cout << "家庭地址: " << x.homeAdr << endl;
	cout << "邮政编码: " << x.postcode << endl;
	cout << "家庭电话: " << x.homeTel << endl;
	cout << "电子邮箱: " << x.email << endl;
	cout << "QQ 帐 号: " << x.qq << endl;
	cout << "=========================================\n";
	cout << endl;
}


		
		



