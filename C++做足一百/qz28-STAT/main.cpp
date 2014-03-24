/*2.	统计正实数
从键盘输入一组正实数(以零结束), 计算并输出这组实数的总和、最大值、最小值、平均值和标准差(小数格式, 只显示2位小数); 在查找数组中查找某个实数, 若查找成功, 则显示其在数组中的位置, 否则显示错误信息; 将这组实数按升序进行排序然后输出(小数格式, 只显示2位小数)。
输入: 输入一组正实数(以零结束)到数组p中, 并记录正实数的个数
void Input(double *p, int &n);
输出: 输出数组中的全部正实数
void Output(const double *p, int n);
统计: 求数组中正实数的总和、最大值、最小值和平均值
void Stat(const double *p, int n, double &sum, double &max, double &min, double &avg);
查找: 查找数组中第一个值为x的实数, 若查找成功, 则返回其位置(1~n), 否则返回0
int Find(const double *p, int n, double x);
排序: 用冒泡法对数组按升序排序
void Sort(double *p, int n);
交换: 交换正实数x和y的值
void Swap(double &x, double &y);
最后, 编写主函数, 显示如下图所示的菜单*/

#include <iostream>

using namespace std;

#include "MyMenu.h"

#include "MyStat.h"

int main()
{
	NODE *L;
	char x;
	double sum, max, min, avg, a;
	Init(L);
	do
	{
		switch(x = Menu("*********************************************\n"
					"*                统计正实数                 *\n"
					"* ----------------------------------------- *\n"
					"* 1-输入 2-输出 3-统计 4-查找 5-排序 0-结束 *\n"
					"*********************************************\n"
					"请选择:",
					"012345"))
		{
		case '1':
			Append(L);
			break;
		case '2':
			List(L);
			break;
		case '3':
			Stat(L, sum, max, min, avg);
			cout << "SUM: " << sum << endl;
			cout << "MAX: " << max << endl;
			cout << "MIN: " << min << endl;
			cout << "AVG: " << avg << endl;
			break;
		case '4':
			cout << "Input the number you find:";
			cin >> a;
			cout << "POSITION: " << Find(L, a) << endl;
			break;
		case '5':
			Sort(L);
			List(L);
			break;
		case '0':
			break;
		}
	}
	while('0' !=  x);
	return 0;
}
