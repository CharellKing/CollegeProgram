#include <iostream>

using namespace std;

#include "Person.h"

#include "MyDate.h"

#include "MyMenu.h"

void Input(PERSON &x)
{
	cout << "ѧ    ��: "; cin >> x.studentnum;
	cout << "��    ��: "; cin >> x.group;
	cout << "��    ��: "; cin >> x.name;
	cout << "��    ��: "; 'M' == Menu("(M - ��, F - Ů)", "MF") ? x.gender = 1 : x.gender = 0;
	cout << "��������: "; InputDate(x.birthday);
	cout << "��ѧ����: "; InputDate(x.entrance);
	cout << "�ƶ��绰: "; cin >> x.mobileTel;
	cout << "�� �� ��: "; cin >> x.room;
	cout << "���ҵ绰: "; cin >> x.roomTel;
	cout << "��ͥ��ַ: "; cin >> x.homeAdr;
	cout << "��������: "; cin >> x.postcode;
	cout << "��ͥ�绰: "; cin >> x.homeTel;
	cout << "��������: "; cin >> x.email;
	cout << "QQ �� ��: "; cin >> x.qq;
}

void Output(const PERSON &x)
{
	cout << "=========================================\n";
	cout << "ѧ    ��: " << x.studentnum << endl;
	cout << "��    ��: " << x.group << endl;
	cout << "��    ��: " << x.name << endl;
	cout << "��    ��: " << (x.gender ? "��" : "Ů") << endl; 
	cout << "��������: "; OutputDate(x.birthday);
	cout << "��ѧ����: "; OutputDate(x.entrance);
	cout << "�ƶ��绰: " << x.mobileTel << endl;
	cout << "�� �� ��: " << x.room << endl;
	cout << "���ҵ绰: " << x.roomTel << endl;
	cout << "��ͥ��ַ: " << x.homeAdr << endl;
	cout << "��������: " << x.postcode << endl;
	cout << "��ͥ�绰: " << x.homeTel << endl;
	cout << "��������: " << x.email << endl;
	cout << "QQ �� ��: " << x.qq << endl;
	cout << "=========================================\n";
	cout << endl;
}


		
		



