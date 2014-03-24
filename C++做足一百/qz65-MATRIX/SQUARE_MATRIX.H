#ifndef _SQUARE_MATRIX_H_

#define _SQUARE_MATRIX_H_

#include "MATRIX.H"

class SQUARE_MATRIX: public virtual MATRIX
{
public:
	SQUARE_MATRIX(int row = 2);//方阵的构造
	SQUARE_MATRIX(const SQUARE_MATRIX &x);
	SQUARE_MATRIX::SQUARE_MATRIX(const MATRIX &x);//矩阵转换为方阵的拷贝函数
	SQUARE_MATRIX Power(int n)const;//方阵的N次方
	SQUARE_MATRIX& operator =(const SQUARE_MATRIX &x);//方阵的赋值
	double Algebraic_Complement(int row, int colume)const;//求代数余子式
	double Cofactor(int row, int colume)const;//求余子式
	SQUARE_MATRIX Remainder_Matrix(int row, int colume)const;//求删除某一元素所在行和列后的方阵
	SQUARE_MATRIX Unit_Matrix()const;//单位方阵
	SQUARE_MATRIX Adjoint_Matrix()const;//伴随方阵
	SQUARE_MATRIX Inverse_Matrix()const;//逆方阵
	double Determinant()const;//行列式
	bool IsInverseMatrix(const SQUARE_MATRIX& x) const;//判断两方阵是不是互逆方阵
	SQUARE_MATRIX Triangle_Matrix()const;//方阵的三角化
	bool IsSymmetricMatrix()const;//判断某方阵是对称矩阵
	bool IsAntisymmetricMatrix()const;//判断某方阵是反对称矩阵
	bool SingularMatrix()const;//判断是奇异矩阵
	SQUARE_MATRIX DiagonalMatrix()const;//对角矩阵
	double RDeterminant()const;//第二种求行列式的方法
private:
	bool Parameter_IsValid(int row, int colume)const;//判断ROW, COLUME是有效地
};


#endif