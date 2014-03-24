#include <iostream>

using namespace std;

#include "LINKLIST.H"
//polynomial
int main()
{
	int cord;
	int x, y;
	LINKLIST<int>* a = NULL;
	do
    { 
		printf("主菜单\n");   /*菜单的打印*/
		printf("1、创建单链表\n");
		printf("2、结点的插入\n");
		printf("3、结点的删除\n");
		printf("4、统计结点个数\n");
		printf("5、退出系统\n");
		printf("请输入选择(1~5)");
		scanf("%d",&cord);
		switch(cord)
        {
		case 1:
			if(a == NULL)
			{
				a = new LINKLIST<int>;
			}
			else
			{
				a->Clear();
			}
			a->Output();
			cout << endl;
			break;
		case 2:
			if(a)
			{
				cout << "在值为x的结点之前插入值为y的结点,输入x与y的值:" << endl;
				cin >> x >> y;
				a->Insert(x, y);
			}
			else
			{
				cout << "未创建链表" << endl;
			}
			break;
		case 3:
			if(a)
			{
				cout << "删除值为x的结点,请输入x" << endl;
				cin >> x;
				a->Remove(x);
			}
			else
			{
				cout << "为创建链表!" << endl;
			}
			break;
		case 4:
			if(a)
			{
				cout << "链表的长度:" << a->Cardinal() << endl;
			}
			else
			{
				cout << "为创建链表!" << endl;
			}
			break;
		case 5:
			if(a == NULL)
			{
				delete [] a;
			}
			else
			{
				a->Output();
				cout << endl;
			}
			break;
		}
			
     }
	 while(cord != 5);
	 return 0;
 }
