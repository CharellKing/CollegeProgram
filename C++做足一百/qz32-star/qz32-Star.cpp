//1.	星形线方程
//编写星形线函数Star, 输入t, 输出x和y:
//修改主函数, 使t的值从0到2 变化, 计算出每个点坐标, 画出上图所示的函数图像。


#include <iostream.h>

#include <conio.h>

#include <graphics.h>

#include <math.h>

void MyOwnStar(int x0, int y0);

void StarPoint(double angle, double &x, double &y);

const double pi = 3.1415926;

const int pieces = 1000;

int main()
{
	int gdrive, gmode;
	char *drvpath = "c:\\bc\\bgi";
	detectgraph(&gdrive, &gmode);
	initgraph(&gdrive, &gmode, drvpath);
	setbkcolor(0);
	setcolor(2);
	cleardevice();
	MyOwnStar(320, 230);
	getch();
	closegraph();
	return 0;
}

void MyOwnStar(int x0, int y0)
{
	double deltPiece = 2.0 / pieces, k = 0, angle = 0, x, y;
	StarPoint(angle, x, y);
	moveto(x * 100 + x0, y * 100 + y0);
	for(k += deltPiece; k <= 2; angle = k * pi, k += deltPiece)
	{
		StarPoint(angle, x, y);
		lineto(x * 100 + x0, y * 100 + y0);
	}
}

void StarPoint(double angle, double &x, double &y)
{
	double i = cos(angle), j = sin(angle);
	x = i * i * i;
	y = j * j * j;
}

