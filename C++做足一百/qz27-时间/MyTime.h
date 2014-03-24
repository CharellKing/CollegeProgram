#ifndef _MYTIME_H

#define _MYTIME_H

struct TIME
{
	char hour, minute, second;
};

void Input (TIME &x); // ����ʱ������

void Output (const TIME &x); // ���ʱ������

TIME Add (const TIME &x, int s); // ��ʱ��x��s�����õ�ʱ��(ע: sΪ��������)

TIME Sub (const TIME &x, int s); // ��ʱ��x��s�����õ�ʱ��(ע: sΪ��������)

int Sub(const TIME &x, const TIME &y); // ������ʱ��x��y֮�����������

bool IsValid(int hout, int minute, int second); // �ж�hour, minute, second�Ƿ�Ϊ�Ϸ�ʱ��

void Set(int hour, int minute, int second); // ����ʱ��

void Get(int &hour, int &minute, int &second); // ��ȡʱ��

#endif