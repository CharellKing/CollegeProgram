/*7.	����������
����ͼ��ʾ�����޵ȱ�������������, �������¡���������Ϊ���еĽ����˳����롣ͼ��һЩ����Թ���������, 
��: {1, 2, 3}��{7, 9, 18}; ĳЩ�㲻�ܹ���������, ��: {3, 6, 8}��{5, 13, 14}��
���������ε�������: ��ÿ���߶��������еı��غ�; �������ߵĳ������.
 	��������
ÿ���������һ��, ��������ı��롣������Ϊ����0ʱ������
 	�������
ÿ���������һ��, ������������㹹��������ʱ, ���YES, �������NO��*/

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