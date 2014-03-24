#include <iostream>

using namespace std;

#include "MyMenu.h"

#include "ADRBOOK.H"

#include "Person.h"

#include "MyFile.h"

int main()
{
	char c, s[15];
	PERSON x;
	ADDRESSBOOK a;
	Init(a.head);
	cout << "�����ļ���:";
	cin >> a.filename;
	if(ReadOut(a)) cout << "�ļ��Ѵ���!" << endl;
	do
	{
		switch(c = Menu("************************\n"
						"* ͨѶ¼(AdrBook1.dat) *\n"
						"************************\n"
						"*    A - ������ϵ��    *\n"
						"*    B - ������ϵ��    *\n"
						"*    R - ɾ����ϵ��    *\n"
						"*    M - �޸���ϵ��    *\n"
						"*    S - ��ѯ��ϵ��    *\n"
						"*    C - ����ͨѶ¼    *\n"
						"*    Q - ����          *\n"
						"************************\n"
						"��ѡ��:", "ABRMSCQL"))
		{
		case 'A':
			Input(x);
			Append(a.head, x);
			break;
		case 'B':
			Sort(a.head);
			break;
		case 'L':
			List(a.head);
			break;
		case 'R':
			cout << "���������ѧ��:";
			cin >> s;
			Remove(a.head, s);
			break;
		case 'M':
			cout << "��������޸ĵ���ϵ�˵�ѧ��:";
			cin  >> x.studentnum;
			Modify(a.head, x.studentnum);
			break;
		case 'S':
			Search(a.head);
			break;
		case 'C':
			cout << (WriteIn(a) ? "�ɹ�����!" : "���治�ɹ�!") << endl;
			cout << "����������ļ���:"; cin >> a.filename;
			if(IsExistent(a)) cout << "�ļ��Ѵ���!" << endl;
			break;
		case 'Q':
			cout << (WriteIn(a) ? "�ɹ�����!" : "���治�ɹ�!") << endl;
			break;
		}
	}
	while(c != 'Q');
	return 0;
}






