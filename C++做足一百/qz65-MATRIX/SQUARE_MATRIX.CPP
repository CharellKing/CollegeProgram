#include <iostream>

using namespace std;

#include "SQUARE_MATRIX.H"

SQUARE_MATRIX::SQUARE_MATRIX(int row)
{
	if(row <= 1) row = 2;
	this->row = this->colume = row;
	this->matrix = new double[row * row];
	for(int i = 0; i < row * row; i ++) this->matrix[i] = 0;
}

SQUARE_MATRIX::SQUARE_MATRIX(const SQUARE_MATRIX &x)
{
	this->row = x.row, this->colume = x.colume;
	this->matrix = new double[x.colume * x.row];
	for(int i = 0; i < row * colume; i ++) this->matrix[i] = x.matrix[i];
}

SQUARE_MATRIX::SQUARE_MATRIX(const MATRIX &x)
{
	int i, j;
	this->row = x.Row(), this->colume = x.Colume();
	if(row != colume)
	{
		cout << "非方阵,不能转换!" << endl;
		exit(1);
	}
	this->matrix = new double[colume * row];
	for(i = 1; i <= this->row; i ++)
	{
		for(j = 1; j <= this->colume; j ++)
		{
			matrix[(i - 1) * colume + j - 1] = x(i, j);
		}
	}
}

SQUARE_MATRIX SQUARE_MATRIX::Power(int n)const
{
	SQUARE_MATRIX a(*this);
	for(int i = 2; i <= n; i ++)
	{
		a *= (*this);
	}
	return a;
}

SQUARE_MATRIX& SQUARE_MATRIX::operator =(const SQUARE_MATRIX &x)
{
	if(this->row != x.row || this->colume != x.colume)
	{
		delete []this->matrix;
		this->row = x.row, this->colume = x.colume;
		this->matrix = new double[x.row * x.colume];
	}
	if(*this != x)
	{
		for(int i = 0; i < row * colume; i ++) this->matrix[i] = x.matrix[i];
	}
	return (*this);
}

double SQUARE_MATRIX::Algebraic_Complement(int row, int colume)const
{
	double value;
	if(!this->Parameter_IsValid(row, colume) && this->row >= 3 && this->colume >= 3)
	{
		cout << "不正确的参数!" << endl;
		exit(1);
	}
	value = Cofactor(row, colume);
	if((row + colume) % 2) value = -value;
	return value;
}

double SQUARE_MATRIX::Cofactor(int row, int colume)const
{
	double value;
	int k, i;
	SQUARE_MATRIX x(this->row - 1);
	x = Remainder_Matrix(row, colume);
	if(x.row <= 2 && x.colume <= 2)
		return value = x.matrix[0] * x.matrix[3] - x.matrix[1] * x.matrix[2];
	else
	{
		value = 0; k = 1;
		for(i = 1; i <= x.colume; i ++)
		{
			value += k * x(1, i) * x.Cofactor(1, i);
			k = -k;
		}
		return value;
	}
}

SQUARE_MATRIX SQUARE_MATRIX::Remainder_Matrix(int row, int colume)const
{
	if(!this->Parameter_IsValid(row, colume) && this->row >= 3 && this->colume >= 3)
	{
		cout << "不正确的参数!" << endl;
		exit(1);
	}
	SQUARE_MATRIX x(this->row - 1);
	int k = 0;
	for(int i = 0; i < this->row * this->colume; i ++)
	{
		if(i % this->colume != colume - 1 && i / this->colume != row - 1)
			x.matrix[k ++] = this->matrix[i];
	}
	return x;
}

bool SQUARE_MATRIX::Parameter_IsValid(int row, int colume)const
{
	return row >= 1 && row <= this->row && colume >= 1 && colume <= this->colume;
}

SQUARE_MATRIX SQUARE_MATRIX::Unit_Matrix()const
{
	int i;
	SQUARE_MATRIX x(this->row);
	for(i = 1; i <= x.colume; i ++)
	{
		x.matrix[(i - 1) * (colume + 1)] = 1;
	}
	return x;
}

SQUARE_MATRIX SQUARE_MATRIX::Adjoint_Matrix()const
{
	int row, colume;
	if(this->row <= 2)
	{
		cout << "无伴随矩阵!" << endl;
		exit(1);
	}
	SQUARE_MATRIX x(this->row);
	for(row = 1; row <= this->row; row ++)
	{
		for(colume = 1; colume <= this->colume; colume ++)
		{
			x.matrix[(colume - 1) * this->row + row - 1] = Algebraic_Complement(row, colume);
		}
	}
	return x;
}

SQUARE_MATRIX SQUARE_MATRIX::Inverse_Matrix()const
{
	int i, j, k, m, a = row * row;
	double mutiple;
	SQUARE_MATRIX x = this->Unit_Matrix();
	SQUARE_MATRIX y(*this);
	for(i = 1; i <= x.row; i ++)
	{
		j = (i -1) * (x.row + 1);
		if(y.matrix[j] == 0)
		{
			k = i;
			m = j;
			while(m += y.colume, m < a && !y.matrix[m]) k ++;
			if(m >= a)
			{
				cout << "此方阵无逆矩阵" << endl;
				exit(1);
			}
			y = y.Rows_Exchange(i, k + 1);
		}
		for(k = i + 1; k <= x.row; k ++)
		{
			m = (k - i) * colume + j;
			mutiple = y.matrix[m] / y.matrix[j];
			y = y.Rows_Calculate(k, i, -mutiple);
			x = x.Rows_Calculate(k, i, -mutiple);
		}
	}
	for(i --; i >= 1; i --)
	{
		j = (i -1) * (x.row + 1);
		if(y.matrix[j] == 0)
		{
			cout << "此方阵无逆矩阵" << endl;
			exit(1);
		}
		for(k = i - 1; k >= 1; k --)
		{
			m = j - (i - k) * colume;
			mutiple = y.matrix[m] / y.matrix[j];
			y = y.Rows_Calculate(k, i, -mutiple);
			x = x.Rows_Calculate(k, i, -mutiple);
		}
	}
	for(i = 1; i <= x.row; i ++)
	{
		j = (i - 1) * (x.row + 1);
		if(y.matrix[j] != 1)
		{
			mutiple = 1 / y.matrix[j];
			x = x.SingleRows_Calculate(i, mutiple);
		}
	}
	return x;
}

double SQUARE_MATRIX::Determinant()const
{
	double value = 0;
	if(this->row > 2)
	{
		for(int i = 1; i <= this->colume; i ++)
		{
			value += (*this)(1, i) * Algebraic_Complement(1, i);
		}
	}
	else
	{
		value = this->matrix[0] * this->matrix[3] - this->matrix[1] * this->matrix[2];
	}
	return value;
}

bool SQUARE_MATRIX::IsInverseMatrix(const SQUARE_MATRIX& x)const
{
	return ((*this) * x == x.Unit_Matrix()) && (x * (*this) == x.Unit_Matrix());
}

SQUARE_MATRIX SQUARE_MATRIX::Triangle_Matrix()const
{
	SQUARE_MATRIX x(*this);
	x = x.Ladder_line_matrix();
	return x;
}

bool SQUARE_MATRIX::IsSymmetricMatrix()const
{
	return (*this) == this->Transpose_Matrix();
}

bool SQUARE_MATRIX::IsAntisymmetricMatrix()const	
{
	return -(*this) == this->Transpose_Matrix();
}

bool SQUARE_MATRIX::SingularMatrix()const
{
	return this->Determinant() != 0;
}

SQUARE_MATRIX SQUARE_MATRIX::DiagonalMatrix()const
{
	int i, j, k, m;
	double mutiple;
	SQUARE_MATRIX x(*this);
	x = x.Triangle_Matrix();
	for(i = x.row; i >= 1 ; i --)
	{
		j = (i -1) * (x.row + 1);
		if(x.matrix[j] == 0) break;
		for(k = i - 1; k >= 1; k --)
		{
			m = j - (i - k) * colume;
			mutiple = x.matrix[m] / x.matrix[j];
			x = x.Rows_Calculate(k, i, -mutiple);
		}
	}
	return x;
}

double SQUARE_MATRIX::RDeterminant()const
{
	double value = 1;
	SQUARE_MATRIX x(*this);
	x = x.Triangle_Matrix();
	for(int i = 1; i <= x.row; i ++)
	{
		value *= x.matrix[(i -1) * (x.row + 1)];
	}
	return value;
}



/*int main()
{
	MATRIX x(3, 4), y;
	x.Input();
	x.Output(); cout << endl;
	y = x.Erase_Colume(2);
	y.Output(); cout << endl;
	return 0;
}*/
