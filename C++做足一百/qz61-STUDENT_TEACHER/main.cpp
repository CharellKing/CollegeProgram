/*
1.	ѧ���ͽ�ʦ
1)	������
������ƹ�����(PEOPLE), ������4��˽�����ݳ�Ա: id��name��gender��birth��, �ֱ��ʾ���֤�š��������Ա𡢳������ڵ�, ��Ϊ�����д���е���������������
2)	ѧ����
���������е�˽�г�Ա��Ϊ������Ա, �ɹ�����������ѧ����(STUDENT), ����1��������Ա: sid, ��ʾѧ�š���д���롢���������
3)	��ʦ��
��������ְ��ö������, ������4��ö�ٳ���: assistant, lecture, associate_professor, professor, �ֱ��ʾ���̡���ʦ�������ںͽ��ڡ���д���롢���������
Ȼ���ɹ�������������ʦ��(TEACHER), ����1��������Ա: position, ��ʾְ�ơ���д���롢���������
4)	�о�����
��ѧ����ͽ�ʦ��˫���������о�����(GRADUATE), ������1��������Ա: field, ��ʾ�о�������д���롢�����������ϸ�۲�����˫���������������⡣
���������Ϊ�����, �ٹ۲��о�����������
*/

#include <iostream>

using namespace std;

//#include "TEACHER.H"

#include "GRADUATE.H"


/*int main()
{
	PEOPLE a;
	cout << "���֤:";
	a.SetId();
	cout << "��  ��:";
	a.SetName();
	cout << "��  ��:";
	a.SetGender();
	cout << "��  ��:";
	a.SetBirth();
	cout << "��� ֤:" << a.GetId() << endl;
	cout << "��   ��:" << a.GetName() << endl;
	cout << "��   ��:" << (a.GetGender() ? "��" : "Ů") << endl;
	cout << "��   ��:"; a.Birth(); cout << endl;
	return 0;
}*/

/*int main()
{
	STUDENT a;
	cout << "ѧ  ��:";
	a.SetSlid();
	cout << "ѧ  ��:" << a.GetSlid() << endl;
	return 0;
}*/

/*int main()
{
	TEACHER a;
	a.SetPosition();
	cout << "ְ ��:";
	a.Position();
	cout << endl;
	return 0;
}*/

int main()
{
	GRADUATE a;
	cout << "���֤:";
	a.SetId();
	cout << "��  ��:";
	a.SetName();
	cout << "��  ��:";
	a.SetGender();
	cout << "��  ��:";
	a.SetBirth();
	cout << "��� ֤:" << a.GetId() << endl;
	cout << "��   ��:" << a.GetName() << endl;
	cout << "��   ��:" << (a.GetGender() ? "��" : "Ů") << endl;
	cout << "��   ��:"; a.Birth(); cout << endl;
	cout << "ѧ  ��:";
	a.SetSlid();
	cout << "ѧ  ��:" << a.GetSlid() << endl;
	a.SetPosition();
	cout << "ְ ��:";
	a.Position();
	cout << endl;
	cout << "�о�����:";
	a.SetField();
	cout << "�о�����:";
	cout << a.GetField();
	cout << endl;
	return 0;
}
