/*
1.	学生和教师
1)	公民类
首先设计公民类(PEOPLE), 它包含4个私有数据成员: id、name、gender、birth等, 分别表示身份证号、姓名、性别、出生日期等, 请为该类编写公有的输入和输出函数。
2)	学生类
将公民类中的私有成员改为保护成员, 由公民类派生出学生类(STUDENT), 增加1个保护成员: sid, 表示学号。重写输入、输出函数。
3)	教师类
首先声明职称枚举类型, 并定义4个枚举常量: assistant, lecture, associate_professor, professor, 分别表示助教、讲师、副教授和教授。重写输入、输出函数。
然后由公民类派生出教师类(TEACHER), 增加1个保护成员: position, 表示职称。重写输入、输出函数。
4)	研究生类
由学生类和教师类双基派生出研究生类(GRADUATE), 它增加1个保护成员: field, 表示研究方向。重写输入、输出函数。仔细观察由于双基派生产生的问题。
将公民类改为虚基类, 再观察研究生类的情况。
*/

#include <iostream>

using namespace std;

//#include "TEACHER.H"

#include "GRADUATE.H"


/*int main()
{
	PEOPLE a;
	cout << "身份证:";
	a.SetId();
	cout << "姓  名:";
	a.SetName();
	cout << "性  别:";
	a.SetGender();
	cout << "生  日:";
	a.SetBirth();
	cout << "身份 证:" << a.GetId() << endl;
	cout << "姓   名:" << a.GetName() << endl;
	cout << "性   别:" << (a.GetGender() ? "男" : "女") << endl;
	cout << "生   日:"; a.Birth(); cout << endl;
	return 0;
}*/

/*int main()
{
	STUDENT a;
	cout << "学  号:";
	a.SetSlid();
	cout << "学  号:" << a.GetSlid() << endl;
	return 0;
}*/

/*int main()
{
	TEACHER a;
	a.SetPosition();
	cout << "职 称:";
	a.Position();
	cout << endl;
	return 0;
}*/

int main()
{
	GRADUATE a;
	cout << "身份证:";
	a.SetId();
	cout << "姓  名:";
	a.SetName();
	cout << "性  别:";
	a.SetGender();
	cout << "生  日:";
	a.SetBirth();
	cout << "身份 证:" << a.GetId() << endl;
	cout << "姓   名:" << a.GetName() << endl;
	cout << "性   别:" << (a.GetGender() ? "男" : "女") << endl;
	cout << "生   日:"; a.Birth(); cout << endl;
	cout << "学  号:";
	a.SetSlid();
	cout << "学  号:" << a.GetSlid() << endl;
	a.SetPosition();
	cout << "职 称:";
	a.Position();
	cout << endl;
	cout << "研究方向:";
	a.SetField();
	cout << "研究方向:";
	cout << a.GetField();
	cout << endl;
	return 0;
}
