#include <iostream.h>

#include <graphics.h>

#include <conio.h>

#include "CPOINT.H"

int main()
{
	int gdriver, gmode; // ��ʾ����, ��ʾģʽ
	detectgraph(&gdriver, &gmode);//
	initgraph(&gdriver, &gmode, "c:\\bc\\bgi"); // ��ʼ��
	setbkcolor(GREEN);         // ���ñ���ɫ
	POINT a;
	CPOINT b;
	a.Show();
	a.Show();
	getch();
	return 0;
}