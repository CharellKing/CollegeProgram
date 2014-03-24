#include <iostream>

using namespace std;

#include <conio.h>

#include <process.h>

#include <windows.h>

#include <time.h>

#include <cstring>

#include "GAME.H"


TURTLE_GRAPHICS::TURTLE_GRAPHICS()
{
	int i = 0;
	head = new NODE;
	ReadOut();
}

TURTLE_GRAPHICS::~TURTLE_GRAPHICS()
{
	LNODE p;
	while(head)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

void TURTLE_GRAPHICS::Graphics()
{
	char c;
	cout << "现在是你尽才智的时刻!(按B开始)" << endl;
	while(c = getch(), c != 'B' && c != 'b') putchar('\a');
	cout << "Let's begin!" << endl;
	Sleep(1000);
	do
	{
		system("cls");
		Convert_Grids();
		Convert_Now_location();
		draw.Draw(M, M);
		//Sleep(10000);
		//system("cls");
		c = order.Orient();
		order.Move();
		cout << "(" << order.X() << ',' << order.Y() << ")" << endl;
	}
	while(c != 'Q');
	if('Y' == Menu("是否保存:(Y - yes, N - no)", "YN")) Save();
}

void TURTLE_GRAPHICS::Convert_Grids()
{
	draw.Grids(order.Grids());
}

void TURTLE_GRAPHICS::Convert_Now_location()
{
	draw.Now_location(order.Now_location());
}

void TURTLE_GRAPHICS::ReadOut()
{
	LNODE p = head, s;
	FILE *fp;
	DRAW a;
	fp = fopen("TURTLE_GRAPHICS.dat", "rb");
	if(fp)
	{
		s = new NODE;
		while(fread(&a, sizeof(DRAW), 1, fp) == 1)
		{
			s = new NODE;
			s->aDraw = a;
			p->next = s;
			p = s;
		}
		p->next = NULL;
		if('Y' == Menu("是否浏览所存著作:(Y - yes, N - no)", "YN")) Reference();
		fclose(fp);
	}
	else
	{
		p->next = NULL;
		cout << "无存放作品!" << endl;
	}
}

void TURTLE_GRAPHICS::Reference()
{
	LNODE p = head;
	system("cls");
	while(p = p->next)
	{
		cout << "作者:" << p->aDraw.name << endl;
		draw.Grids(p->aDraw.grids);
		draw.Now_location(p->aDraw.now_location);
		draw.Draw(M, M);
		cout << "等候10秒!" << endl;
		Sleep(10000);
		system("cls");
	}
	if(p == head->next) cout << "无保存作品!" << endl;
}


void TURTLE_GRAPHICS::Save()
{
	int i;
	LNODE p = head->next, s;
	s = new NODE;
	s->aDraw.now_location.x = 0;
	s->aDraw.now_location.y = 0;
	for(i = 0; i < M * M; i ++) s->aDraw.grids[i] = (order.Grids())[i];
	cout << "请输入你的名字:";
	cin >> s->aDraw.name;
	head->next = s;
	s->next = p;
	WriteIn();
}

void TURTLE_GRAPHICS::WriteIn()
{
	FILE *fp;
	LNODE p = head;
	DRAW a;
	fp = fopen("TURTLE_GRAPHICS.dat", "wb");
	if(fp)
	{
		while(p = p->next)
		a = p->aDraw, fwrite(&a, sizeof(DRAW), 1, fp);
	}
	fclose(fp);
}
