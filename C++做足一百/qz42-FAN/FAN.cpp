//1.	�����߷���
//��д�����ߺ���Star, ����t, ���x��y:
//�޸�������, ʹt��ֵ��0��2 �仯, �����ÿ��������, ������ͼ��ʾ�ĺ���ͼ��
#include <iostream.h>

#include <conio.h>

#include <graphics.h>

#include <math.h>

void MyOwnFan(int x0, int y0, double angle0);

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
	MyOwnFan(320, 230, 0);
	getch();
	closegraph();
	return 0;
}

void MyOwnFan(int x0, int y0, double angle0)
{
	double deltPieces = 2 * pi / pieces, angle = 0, radius, m;
	int k;
	moveto(100 * cos(angle0) + x0, 100 * sin(angle0) + y0);
	for(k = 1; k <= pieces; k ++)
	{
		angle = k * deltPieces;
		m = 10000 * cos(2 * angle);
		if(m < 0) m = -m;
		radius = sqrt(m);
		lineto(radius * cos(angle + angle0) + x0, radius * sin(angle + angle0) + y0);
	}
}