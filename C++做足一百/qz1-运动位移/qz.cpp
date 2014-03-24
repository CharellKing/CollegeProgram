//1.	物体的位移:
//输入物体的初速度v0, 加速度a和时间t, 计算并输出其位移。

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


 
