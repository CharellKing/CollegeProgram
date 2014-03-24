#ifndef _MATRIX_H_

#define _MATRIX_H_

typedef  unsigned short int USINT; 

#include <iostream>

using namespace std;

class MATRIX
{
public:
	MATRIX(int row = 2, int colume = 2);//构造初始化
	MATRIX(const MATRIX& x);//拷贝构造
	~MATRIX();
	void Input();
	friend istream& operator >>(istream& in, MATRIX &x);
	void Output() const;
	friend ostream& operator <<(ostream& out, const MATRIX &x);
	MATRIX operator +(const MATRIX &x)const;//加法
	MATRIX operator -(const MATRIX &x)const;//减法
	MATRIX& operator +=(const MATRIX &x);//追加
	MATRIX& operator -=(const MATRIX &x);//追减
	MATRIX& operator =(const MATRIX &x);//赋值
	bool operator ==(const MATRIX &x)const;//判断两矩阵相等
	bool operator !=(const MATRIX &x)const;//判断两矩阵不相等
	MATRIX operator -()const;//取反
	MATRIX operator *(const MATRIX &x)const;//乘法
	MATRIX& operator *=(const MATRIX &x);//追乘
	MATRIX operator *(double x)const;//矩阵与实数的乘法
	friend MATRIX operator *(double x, const MATRIX& y);//实数与矩阵的乘法
	MATRIX Mul(double x)const;//实数与矩阵的乘法
	MATRIX Transpose_Matrix()const;//矩阵的转置
	double operator ()(int row, int colume)const;//获取矩阵中的元素
	USINT Colume()const;//返回列数
	USINT Row()const;//返回行数
	MATRIX Zero_Matrix()const;//零矩阵
	MATRIX Rows_Exchange(int row1, int row2)const;//行间元素交换
	MATRIX Rows_Calculate(int row1, int row2, double mutiple)const;//行间元素计算
	MATRIX SingleRows_Calculate(int row, double mutiple)const;//某行的元素增加同样的倍数
	MATRIX Ladder_line_matrix()const;//矩阵的行阶梯变换
	MATRIX Erase_Colume(int colume)const;//删除某一列
	MATRIX Columes_Exchange(int colume1, int colume2)const;//列之间的元素转换
protected:
	USINT row, colume;
	double *matrix;
private:
	static void Swap(double &x, double &y);
};

#endif