/*2.	��ƷĿ¼
ʹ��string����ַ����������洢��Ʒ���ơ����������, ��ʾ����ͼ��ʾ�Ĳ˵�: 
A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > _
�������ĺ�����ɲ�Ʒ�����ӡ�ɾ�����޸ġ���ѯ��������ʾ�ȹ���:
����(Append): ���Ʒ��x(��Ʒ���Ʋ����ظ�)
ɾ��(Remove): ɾ��Ʒ��x
�޸�(Modify): ����Ʒ��Ϊx�Ľ��, ��Ʒ���޸�Ϊy
����(Find): ����Ʒ��Ϊx�Ľ��, ���ɹ�, �򷵻ظý��ǰ�����ĵ�ַ, ���򷵻�NULL
����(Sort): ��Ʒ����������
��ʾ(Display): ��ʾȫ��Ʒ��
�������о���:
A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > A 
���Ʒ��: Apple 
��ӳɹ�

A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > A 
���Ʒ��: Banana 
��ӳɹ�

A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > A 
���Ʒ��: Orange 
��ӳɹ�

A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > A 
���Ʒ��: Banana 
Ʒ���ظ�, ���ʧ��

A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > D 
��Ʒ�嵥: Apple Banana Orange

A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > R 
ɾ��Ʒ��: Banana 
ɾ���ɹ�

A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > D 
��Ʒ�嵥: Apple Orange

A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > M 
�޸�Ʒ��: Peach 
��Ʒ��: Pear 
�޴˲�Ʒ, �޸�ʧ��

A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > M 
�޸�Ʒ��: Apple 
��Ʒ��: Pear 
�޸ĳɹ�

A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > D 
��Ʒ�嵥: Pear Orange

A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > F 
����: Apple 
����ʧ��

A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > F 
����: Pear 
���ҳɹ�

A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > S 
����ɹ�

A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > D 
��Ʒ�嵥: Orange Pear

A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� > Q 
*/

#include <iostream>

using namespace std;

#include <string>

#include "MyMenu.h"

#include "MyProductList.h"

int main()
{
	LIST L;
	char c;
	string s, s1;
	int len = 0;
	Init(L);
	do
	{
		switch(c = Menu("A-���  R-ɾ��  M-�޸�  F-����  S-����  D-��ʾ  Q-���� >",
						"ARMFSDQ"))
		{
		case 'A':
			cout << "���Ʒ��: ";
			cin >> s;
			Append(L, s);
			break;
		case 'R':
			cout << "ɾ��Ʒ��: ";
			cin >> s;
			Remove(L, s);
			cout << "ɾ���ɹ�" << endl;
			break;
		case 'M':
			cout << "�޸�Ʒ��: ";
			cin  >> s;
			cout << "��Ʒ��: ";
			cin >> s1;
			Modify(L, s, s1);
			break;
		case 'F':
			cout << "����: ";
			cin >> s;
			cout << "POSITION: " << Find(L, s) << endl;
			break;
		case 'S':
			cout << "����: \n";
			Sort(L);
			cout << "����ɹ�!\n";
			break;
		case 'D':
			cout << "��Ʒ�嵥: ";
			List(L);
			break;
		}
	}
	while(c != 'Q');
	return 0;
}



	