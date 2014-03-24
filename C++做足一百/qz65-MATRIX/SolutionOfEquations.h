#ifndef _SolutionOfEquations_H_

#define _SolutionOfEquations_H_

#include "SQUARE_MATRIX.H"

#include <string>

#include <string>

class DBL_STR
{
public:
	string result;
	double value;
};

class SolutionOfEquations : public virtual MATRIX
{
public:
	SolutionOfEquations(int equations = 1);//方程组的扩展矩阵
	SolutionOfEquations(const SolutionOfEquations &x);//拷贝构造函数
	SolutionOfEquations(const MATRIX &x);//将基类转换为派生类的拷贝构造函数
	~SolutionOfEquations();
	void ShowSolutions()const;//显示方程的解
	SolutionOfEquations& operator = (const SolutionOfEquations &x);//赋值函数
protected:
	DBL_STR *a;
private:
	static DBL_STR AnalyseValue(double x1, double x2);//分析值；无解，无穷解等
	void Cramer()const;//克拉默法则
	void OutputDBL_STR(DBL_STR)const;//打印分析的结果
};

	


#endif