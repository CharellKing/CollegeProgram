//1.	�����߷���
//��д�����ߺ���Star, ����t, ���x��y:
//�޸�������, ʹt��ֵ��0��2 �仯, �����ÿ��������, ������ͼ��ʾ�ĺ���ͼ��


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

