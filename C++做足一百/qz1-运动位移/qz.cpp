//1.	�����λ��:
//��������ĳ��ٶ�v0, ���ٶ�a��ʱ��t, ���㲢�����λ�ơ�

#include <iostream>

using namespace std;

int main()
{
	double s, a, t, v0;
	cout << "Input the original speed:\n";
	cin >> v0;
	cout << "Input the moving time:\n";
	cin >> t;
	cout << "Input the speed of change of speed:";
	cin >> a;
	s = v0 * t + 0.5 * a * t * t;
	cout << "Output the distance :" << s << "\n";
	return 0;
}


 
