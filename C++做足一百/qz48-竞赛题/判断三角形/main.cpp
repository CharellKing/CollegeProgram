/*7.	数字三角形
在下图所示的无限等边三角形网格中, 从上至下、从左至右为所有的交叉点顺序编码。图中一些点可以构成三角形, 
如: {1, 2, 3}和{7, 9, 18}; 某些点不能构成三角形, 如: {3, 6, 8}和{5, 13, 14}。
构成三角形的条件是: ①每条边都和网格中的边重合; ②三条边的长度相等.
 	输入数据
每个输入包括一行, 是三个点的编码。当输入为三个0时结束。
 	输出数据
每个输出包括一行, 若输入的三个点构点三角形时, 输出YES, 否则输出NO。*/

#include <iostream>

using namespace std;

int UpFloor(int num);

bool IsTriAngle(int point1, int point2, int point3, int floor);

void Swap(int &num1, int &num2);

int main()
{
	int point1, point2, point3, floor1, floor2, floor3;
	bool b;
	while(cin >> point1 >> point2 >> point3, point1 || point2 || point3)
	{
		floor1 = UpFloor(point1), floor2 = UpFloor(point2), floor3 = UpFloor(point3);
		if(floor1 == floor2 && floor1 == floor3 && floor2 == floor3) b = false;
		else if(floor1 != floor2 && floor1 != floor3 && floor2 != floor3) b = false;
		else
		{
			if(floor1 == floor2) b = IsTriAngle(point1, point2, point3, floor1);
			if(floor1 == floor3) b = IsTriAngle(point1, point3, point2, floor1);
			if(floor2 == floor3) b = IsTriAngle(point2, point3, point1, floor2);
		}
		cout << (b ? "YES" : "NO") << endl; 
	}
	return 0;
}

int FloorStart(int floor)
{
	return floor * (floor - 1) / 2 + 1;
}

int UpFloor(int num)
{
	int floor;
	int points = 0;
	for(floor = 1; points < num; floor ++)
	{
		points = floor * (floor + 1) / 2;
	}
	return floor - 1;
}

bool IsTriAngle(int point1, int point2, int point3, int floor)
{
	int distance1, distance2, side;
	bool b = false;
	if(point1 > point2) Swap(point1, point2);
	side = point2 - point1;
	distance1 = point2 - FloorStart(floor);
	distance2 = point1 - FloorStart(floor);
	if(point3 == FloorStart(floor + side) + distance1 || point3 == FloorStart(floor - side) + distance2) b = true;
	return b;	
}

void Swap(int &num1, int &num2)
{
	int s = num1;
	num1 = num2;
	num2 = s;
}