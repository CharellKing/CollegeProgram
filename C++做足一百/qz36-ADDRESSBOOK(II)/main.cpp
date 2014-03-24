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
	cout << "输入文件名:";
	cin >> a.filename;
	if(ReadOut(a)) cout << "文件已存在!" << endl;
	do
	{
		switch(c = Menu("************************\n"
						"* 通讯录(AdrBook1.dat) *\n"
						"************************\n"
						"*    A - 增加联系人    *\n"
						"*    B - 排序联系人    *\n"
						"*    R - 删除联系人    *\n"
						"*    M - 修改联系人    *\n"
						"*    S - 查询联系人    *\n"
						"*    C - 更换通讯录    *\n"
						"*    Q - 结束          *\n"
						"************************\n"
						"请选择:", "ABRMSCQL"))
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
			cout << "请输入该人学号:";
			cin >> s;
			Remove(a.head, s);
			break;
		case 'M':
			cout << "请输入待修改的联系人的学号:";
			cin  >> x.studentnum;
			Modify(a.head, x.studentnum);
			break;
		case 'S':
			Search(a.head);
			break;
		case 'C':
			cout << (WriteIn(a) ? "成功保存!" : "保存不成功!") << endl;
			cout << "输入更换的文件名:"; cin >> a.filename;
			if(IsExistent(a)) cout << "文件已存在!" << endl;
			break;
		case 'Q':
			cout << (WriteIn(a) ? "成功保存!" : "保存不成功!") << endl;
			break;
		}
	}
	while(c != 'Q');
	return 0;
}






