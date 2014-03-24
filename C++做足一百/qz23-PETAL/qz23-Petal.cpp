#include <iostream.h>

#include <conio.h>

#include <graphics.h>

#include <math.h>

const double pi = 3.1415926;

const int pieces = 10000;

void MyOwnEllipse(int x, int y, int stangle, int endtangle, int xangle, int xradius, int yradius);
//(x, y) 中心，stangle - endtangle 决定椭圆的圆缺， xtangle 决定椭圆的倾斜度， xradius, yradius 为两半轴；

double Round(double realNumber, char afterPoint);

double absoluteValue(double number);

int Ceil(double number);

int main()
{
	int gdrive, gmode;
	char *drvpath = "c:\\bc\\bgi";
	detectgraph(&gdrive, &gmode);
	initgraph(&gdrive, &gmode, drvpath);
	setbkcolor(0);
	setcolor(2);
	cleardevice();
	//ellipse(300, 200, 50, 360,  200, 100);
	MyOwnEllipse(300, 250, 0, 360, 0, 250, 150);
	MyOwnEllipse(300, 250, 0, 360, 60, 250, 150);
	MyOwnEllipse(300, 250, 0, 360, 120, 250, 150);
	getch();
	closegraph();
	return 0;
}

void MyOwnEllipse(int x, int y, int stangle, int endtangle, int xangle, int xradius, int yradius)
{
	int deltAngle = endtangle - stangle, radius, x1, y1, i;
	double deltPiece = (deltAngle * 1.0) / pieces, relativeX, relativeY, angle1, angle2, angle = stangle;
	angle1 = (pi / 180) * stangle;
	angle2 = (pi / 180) * (xangle + stangle);
	relativeX = xradius * cos(angle1);
	relativeY = yradius * sin(angle1);
	radius = sqrt(relativeX * relativeX + relativeY * relativeY);
	x1 = (int) Round((x - radius * cos(angle2)), 0);
	y1 = (int) Round((y - radius * sin(angle2)), 0);
	moveto(x1, y1);
	for(i = 0; i < pieces; i ++)
	{
		angle += deltPiece;
		angle1 = (pi / 180) * angle;
		angle2 = (pi / 180) * (xangle + angle);
		relativeX = xradius * cos(angle1);
		relativeY = yradius * sin(angle1);
		radius = sqrt(relativeX * relativeX + relativeY * relativeY);
		x1 = (int) Round((x - radius * cos(angle2)), 0);
		y1 = (int) Round((y - radius * sin(angle2)), 0);
		lineto(x1, y1);
	}
}

double Round(double realNumber, char afterPoint)
{
	double number;
	double k = 10;
	char i = '0';
	for(; i < afterPoint; i ++)
	{
		k *= 10;
	}
	number = realNumber * k;
	return Ceil(number) / k;//get the reseved number
}

int Ceil(double number)
{
	int integer, newInteger, m;
	integer = (int)(number);
	m = absoluteValue(integer) + 5;
	newInteger = m - m % 10;
	if(integer < 0) newInteger = - newInteger;
	return newInteger;
}

double absoluteValue(double number)
{
	return number < 0 ? -number: number;
}



	




