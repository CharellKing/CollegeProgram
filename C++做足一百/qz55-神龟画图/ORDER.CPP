#include <iostream>

using namespace std;

#include "ORDER.H"

ORDER::ORDER()
{
	int i;
	for(i = 0; i < M * M; i ++) grids[i] = last_grids[i] = false;
	last_location.x = 1, last_location.y = 1;
	now_location.x = 1, now_location.y = 1;
	this->orient = 'L';
	last_orient = orient;
	steps = 0;
}

void ORDER::Steps()
{
	char c;
	c = Menu("**************\n"
			 "*J - 移动一步*\n"
			 "*L - 移动六步*\n"
			 "**************\n"
			 "请选择:", "JL");
	c == 'J' ? steps = 1 : steps = 6;
}

char ORDER::Orient()
{
	char c;
	last_orient = orient;
	c = Menu("******************\n"
			 "*E - 向        上*\n"
			 "*C - 向        下*\n"
			 "*S - 向        左*\n"
			 "*F - 向        右*\n"
			 "*D - 返回上次操作*\n"
			 "*Q - 结        束*\n"
			 "**********\n"
			 "请选择:", "ECSFDQ");
	orient = c;
	return c;
}

void ORDER::Move()
{
	int i;
	switch(this->orient)
	{
	case 'E':
		for(i = 0; i < M * M; i ++) last_grids[i] = grids[i];
		last_location.x = now_location.x, last_location.y = now_location.y;
		Steps();
		now_location.x -= steps;
		Restriction();
		if ('Y' == Menu("是否让笔尖朝下( Y - yes, N - no)", "YN")) Cover1();
		break;
	case 'C':
		for(i = 0; i < M * M; i ++) last_grids[i] = grids[i];
		last_location.x = now_location.x, last_location.y = now_location.y;
		Steps();
		now_location.x += steps;
		Restriction();
		if('Y' == Menu("是否让笔尖朝下( Y - yes, N - no)", "YN")) Cover2();
		break;
	case 'S':
		for(i = 0; i < M * M; i ++) last_grids[i] = grids[i];
		last_location.x = now_location.x, last_location.y = now_location.y;
		Steps();
		now_location.y -= steps;
		Restriction();
		if ('Y' == Menu("是否让笔尖朝下( Y - yes, N - no)", "YN")) Cover3();
		break;
	case 'F':
		for(i = 0; i < M * M; i ++) last_grids[i] = grids[i];
		last_location.x = now_location.x, last_location.y = now_location.y;
		Steps();
		now_location.y += steps;
		Restriction();
		if('Y' == Menu("是否让笔尖朝下( Y - yes, N - no)", "YN")) Cover4();
		break;
	case 'D':
		Cover5();
		for(i = 0; i < M * M; i ++) grids[i] = last_grids[i];
		now_location.y = last_location.y, now_location.x = last_location.x;
		break;
	}
	
}

int ORDER::X()
{
	return now_location.x;
}

int ORDER::Y()
{
	return now_location.y;
}

ORDINATE ORDER::Now_location()const
{
	return now_location;
}


const bool* ORDER::Grids()const
{
	return grids;
}

void ORDER::Cover1()
{
	int i, k;
	for(i = 0; i < steps; i++)
	{
		k = (this->last_location.x - i -1) * M + this->last_location.y - 1;
		if(last_location.x - i >= 1) grids[k] = true;
	}
}
	
void ORDER::Cover2()
{
	int i, k;
	for(i = 0; i < steps; i++)
	{
		k = (this->last_location.x + i - 1) * M + this->last_location.y - 1;
		if(i + last_location.x <= M) grids[k] = true;
	}
}

void ORDER::Cover3()
{
	int i, k;
	for(i = 0; i < steps; i++)
	{
		k = (this->last_location.x - 1) * M + this->last_location.y - i - 1;
		if(last_location.y - i >= 1) grids[k] = true;
	}
}
	
void ORDER::Cover4()
{
	int i, k;
	for(i = 0; i < steps; i++)
	{
		k = (this->last_location.x - 1) * M + this->last_location.y + i - 1;
		if(i + last_location.y <= M) grids[k] = true;
	}
}
void ORDER::Cover5()
{
	switch(last_orient)
	{
	case 'E':
		now_location.x -= steps;
		break;
	case 'C':
		now_location.x += steps;
		break;
	case 'S':
		now_location.y -= steps;
		break;
	case 'F':
		now_location.y += steps;
		break;
	}
}

void ORDER::Restriction()
{
	if(now_location.x < 1) now_location.x = 1;
	if(now_location.x > M) now_location.x = M;
	if(now_location.y < 1) now_location.y = 1;
	if(now_location.y > M) now_location.y = M;
}







