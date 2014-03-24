/*2.	产品目录
使用string类的字符串对象来存储产品名称。设计主函数, 显示如下图所示的菜单: 
A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > _
设计下面的函数完成产品的增加、删除、修改、查询、排序、显示等功能:
增加(Append): 添加品名x(产品名称不能重复)
删除(Remove): 删除品名x
修改(Modify): 查找品名为x的结点, 将品名修改为y
查找(Find): 查找品名为x的结点, 若成功, 则返回该结点前趋结点的地址, 否则返回NULL
排序(Sort): 按品名升序排序
显示(Display): 显示全部品名
测试运行举例:
A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > A 
添加品名: Apple 
添加成功

A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > A 
添加品名: Banana 
添加成功

A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > A 
添加品名: Orange 
添加成功

A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > A 
添加品名: Banana 
品名重复, 添加失败

A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > D 
产品清单: Apple Banana Orange

A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > R 
删除品名: Banana 
删除成功

A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > D 
产品清单: Apple Orange

A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > M 
修改品名: Peach 
新品名: Pear 
无此产品, 修改失败

A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > M 
修改品名: Apple 
新品名: Pear 
修改成功

A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > D 
产品清单: Pear Orange

A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > F 
查找: Apple 
查找失败

A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > F 
查找: Pear 
查找成功

A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > S 
排序成功

A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > D 
产品清单: Orange Pear

A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 > Q 
*/

#include <iostream>

using namespace std;

#include <string>

#include "MyMenu.h"

#include "MyProductList.h"

int main()
{
	LIST L;
	char c;
	string s, s1;
	int len = 0;
	Init(L);
	do
	{
		switch(c = Menu("A-添加  R-删除  M-修改  F-查找  S-排序  D-显示  Q-结束 >",
						"ARMFSDQ"))
		{
		case 'A':
			cout << "添加品名: ";
			cin >> s;
			Append(L, s);
			break;
		case 'R':
			cout << "删除品名: ";
			cin >> s;
			Remove(L, s);
			cout << "删除成功" << endl;
			break;
		case 'M':
			cout << "修改品名: ";
			cin  >> s;
			cout << "新品名: ";
			cin >> s1;
			Modify(L, s, s1);
			break;
		case 'F':
			cout << "查找: ";
			cin >> s;
			cout << "POSITION: " << Find(L, s) << endl;
			break;
		case 'S':
			cout << "排序: \n";
			Sort(L);
			cout << "排序成功!\n";
			break;
		case 'D':
			cout << "产品清单: ";
			List(L);
			break;
		}
	}
	while(c != 'Q');
	return 0;
}



	