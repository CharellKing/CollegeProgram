#include <iostream.h>

#include <graphics.h>

#include <conio.h>

#include "CPOINT.H"

int main()
{
	int gdriver, gmode; // 显示驱动, 显示模式
	detectgraph(&gdriver, &gmode);//
	initgraph(&gdriver, &gmode, "c:\\bc\\bgi"); // 初始化
	setbkcolor(GREEN);         // 设置背景色
	POINT a;
	CPOINT b;
	a.Show();
	a.Show();
	getch();
	return 0;
}