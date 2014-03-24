#include <iostream.h>

#include<dos.h>

#include <conio.h>

#include <graphics.h>

#include <math.h>

void MyOwnStar(int x0, int y0, double angle0);

void StarPoint(double angle, double &x, double &y);

const double pi = 3.1415926;

const int pieces = 1000;

const int speed = 10;

int main()
{
	int gdrive, gmode, i;
	char *drvpath = "c:\\bc\\bgi";
	double k = 2 * pi / 100, angle0;
	detectgraph(&gdrive, &gmode);
	initgraph(&gdrive, &gmode, drvpath);
	setbkcolor(0);
	setcolor(2);
	cleardevice();
	while(!kbhit())
	{
		for(i = 0; i <= 200; i ++)
		{
			angle0 = k * i;
			MyOwnStar(100, 100, 2 * pi - angle0);
			//cleardevice();
			//delay(speed);
			MyOwnStar(100, 380, angle0);
			//cleardevice();
			//delay(speed);
			MyOwnStar(500, 100, angle0);
			//cleardevice();
			//delay(speed);
			MyOwnStar(500, 380, 2 * pi - angle0);
			delay(speed);
			cleardevice();
		}
	}
	getch();
	closegraph();
	return 0;
}

void MyOwnStar(int x0, int y0, double angle0)
{
	double deltPiece = 2.0 / pieces, k = 0, angle = 0, x, y, distance, x1, y1;
	StarPoint(angle, x1, y1);
	distance = sqrt(x1 * x1 + y1 * y1);
	x = distance * cos(angle0 + angle);
	y = distance * sin(angle0 + angle);
	moveto(x * 100 + x0, y * 100 + y0);
	for(k += deltPiece; k <= 2; angle = k * pi, k += deltPiece)
	{
		StarPoint(angle, x1, y1);
		distance = sqrt(x1 * x1 + y1 * y1);
		x = distance * cos(angle0 + angle);
		y = distance * sin(angle0 + angle);
		lineto(x * 100 + x0, y * 100 + y0);
	}
}

void StarPoint(double angle, double &x, double &y)
{
	double i = cos(angle), j = sin(angle);
	x = i * i * i;
	y = j * j * j;
}
