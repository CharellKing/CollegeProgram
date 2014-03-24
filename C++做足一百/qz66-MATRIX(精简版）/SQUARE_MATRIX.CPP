#include <iostream>

using namespace std;

#include "SQUARE_MATRIX.H"

SQUARE_MATRIX::SQUARE_MATRIX(int row): MATRIX(row, row)
{
}

SQUARE_MATRIX::SQUARE_MATRIX(const SQUARE_MATRIX &x): MATRIX(x)
{
}



SQUARE_MATRIX& SQUARE_MATRIX::operator =(const SQUARE_MATRIX &x)
{
	MATRIX::operator =(x);
	return *this;
}

SQUARE_MATRIX SQUARE_MATRIX::operator +(const SQUARE_MATRIX &x) const
{
	SQUARE_MATRIX y(row);
	y.Add(*this, x);
	return y;
}

SQUARE_MATRIX SQUARE_MATRIX::operator -(const SQUARE_MATRIX &x) const
{
	SQUARE_MATRIX y(x.row);
	y.Sub(*this, x);
	return y;
}

SQUARE_MATRIX SQUARE_MATRIX:: operator +()const
{
	return SQUARE_MATRIX(*this);
}

SQUARE_MATRIX SQUARE_MATRIX::operator -()const
{
	SQUARE_MATRIX y(*this);
	y.NegativeSign(*this);
	return y;
}

SQUARE_MATRIX SQUARE_MATRIX::operator *(const SQUARE_MATRIX &x) const
{
	SQUARE_MATRIX y(row);
	y.Mul(*this, x);
	return y;
}


SQUARE_MATRIX SQUARE_MATRIX::operator *(double x)const
{
	SQUARE_MATRIX y(*this);
	y.Mul(*this, x);
	return y;
}

SQUARE_MATRIX operator *(double x, const SQUARE_MATRIX& y)
{
	SQUARE_MATRIX z(y);
	z.Mul(y, x);
	return z;
}
	
SQUARE_MATRIX SQUARE_MATRIX::Transpose_Matrix()const
{
	//SQUARE_MATRIX x(row);
	//x.Transpose_Matrix();
	SQUARE_MATRIX x;
	x.MATRIX::Transpose_Matrix(*this);
	return x;
}

SQUARE_MATRIX SQUARE_MATRIX::Zero_Matrix()const
{
	SQUARE_MATRIX x(*this);
	x.MATRIX::Zero_Matrix(*this);
	return x;
}

SQUARE_MATRIX SQUARE_MATRIX::Rows_Exchange(int row1, int row2) const
{
	SQUARE_MATRIX x(*this);
	x.MATRIX::Rows_Exchange(*this, row1, row2);
	return x;
}

SQUARE_MATRIX SQUARE_MATRIX::Rows_Calculate(int row1, int row2, double mutiple) const
{
	SQUARE_MATRIX x(*this);
	x.MATRIX::Rows_Calculate(*this, row1, row2, mutiple);
	return x;
}

SQUARE_MATRIX SQUARE_MATRIX::SingleRow_Calculate(int row1, double mutiple) const
{
	SQUARE_MATRIX x(*this);
	x.MATRIX::SingleRow_Calculate(*this, row1, mutiple);
	return x;
}

SQUARE_MATRIX SQUARE_MATRIX::Ladder_line_matrix() const
{
	SQUARE_MATRIX x(*this);
	x.MATRIX::Ladder_line_matrix(*this);
	return x;
}

SQUARE_MATRIX SQUARE_MATRIX::Erase_Colume(int colume1) const
{
	SQUARE_MATRIX x(*this);
	x.MATRIX::Erase_Colume(*this, colume1);
	return x;
}

SQUARE_MATRIX SQUARE_MATRIX::Columes_Exchange(int colume1, int colume2) const
{
	SQUARE_MATRIX x(*this);
	x.MATRIX::Columes_Exchange(*this, colume1, colume2);
	return x;
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

double SQUARE_MATRIX::Algebraic_Complement(int row, int colume)const
{
	double value;
	if(!this->Parameter_IsValid(row, colume) && this->row >= 3 && this->colume >= 3)
	{
		cout << "不正确的参数!" << endl;
		exit(1);
	}
	value = Cofactor(row, colume);
	return ((row + colume) % 2 ? - value : value);
}

double SQUARE_MATRIX::Cofactor(int row, int colume)const
{
	double value;
	int k, i;
	SQUARE_MATRIX x(this->row - 1);
	x = Remainder_SQUARE_MATRIX(row, colume);
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

SQUARE_MATRIX SQUARE_MATRIX::Remainder_SQUARE_MATRIX(int row, int colume)const
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

SQUARE_MATRIX SQUARE_MATRIX::Unit_SQUARE_MATRIX()const
{
	int i;
	SQUARE_MATRIX x(this->row);
	for(i = 1; i <= x.colume; i ++)
	{
		x.matrix[(i - 1) * (colume + 1)] = 1;
	}
	return x;
}

SQUARE_MATRIX SQUARE_MATRIX::Adjoint_SQUARE_MATRIX()const
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

SQUARE_MATRIX SQUARE_MATRIX::Inverse_SQUARE_MATRIX()const
{
	int i, j, k, m, a = row * row;
	double mutiple;
	SQUARE_MATRIX x = this->Unit_SQUARE_MATRIX();
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
			x = x.SingleRow_Calculate(i, mutiple);
		}
	}
	return x;
}

double SQUARE_MATRIX::Determinant() const
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

bool SQUARE_MATRIX::IsInverseSQUARE_MATRIX(const SQUARE_MATRIX& x) const
{
	return ((*this) * x == x.Unit_SQUARE_MATRIX()) && (x * (*this) == x.Unit_SQUARE_MATRIX());
}

SQUARE_MATRIX SQUARE_MATRIX::Triangle_SQUARE_MATRIX() const
{
	SQUARE_MATRIX x(*this);
	x = x.Ladder_line_matrix();
	return x;
}

bool SQUARE_MATRIX::IsSymmetricSQUARE_MATRIX() const
{
	return (*this) == this->Transpose_Matrix();
}

bool SQUARE_MATRIX::IsAntisymmetricSQUARE_MATRIX() const	
{
	return -(*this) == this->Transpose_Matrix();
}

bool SQUARE_MATRIX::SingularSQUARE_MATRIX() const
{
	return this->Determinant() != 0;
}

SQUARE_MATRIX SQUARE_MATRIX::DiagonalSQUARE_MATRIX() const
{
	int i, j, k, m;
	double mutiple;
	SQUARE_MATRIX x(*this);
	x = x.Triangle_SQUARE_MATRIX();
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
	int i, j, k, m, a = row * colume, n = 1;
	double value = 1, mutiple;
	SQUARE_MATRIX x(*this);
	for(i = 1; i <= x.row; i ++)
	{
		j = (i - 1) * (x.colume + 1);
		if(x.matrix[j] == 0)
		{
			k = i;
			m = j;
			while(m += x.colume, m < a && !x.matrix[m]) k ++;
			if(m >= a) break;
			x = x.Rows_Exchange(i, k + 1);
			n = -n;
		}
		for(k = i + 1; k <= x.row; k ++)
		{
			m = (k - i) * x.colume + j;
			mutiple = x.matrix[m] / x.matrix[j];
			x = x.Rows_Calculate(k, i, -mutiple);
		}
	}
	for(i = 1; i <= x.row; i ++)
	{
		value *= x.matrix[(i -1) * (x.row + 1)];
	}
	return n * value;
}



/*int main()
{
	SQUARE_MATRIX x(3, 4), y;
	x.Input();
	x.Output(); cout << endl;
	y = x.Erase_Colume(2);
	y.Output(); cout << endl;
	return 0;
}*/

/*int main()
{
	SQUARE_MATRIX a(3), b(3), c (3);
	a.Input();
	a.Output();
	b.Input();
	b.Output();
	c = a + b;
	c.Output();
	return 0;
}*/

int main()
{
	SQUARE_MATRIX a(3), b(3), c(2), d(4);
	cin >> a;
	cout << a << endl;
	/*cin >> b;
	cout << b << endl;
	cin >> c;
	cout << c << endl;
	d = a + b;
	cout << d << endl;
	d = a - b;
	cout << d << endl;
	d = a * b;
	cout << d << endl;
	cout << a * c << endl;
	d = c.Columes_Exchange(1, 3);
	cout << d << endl;*/
	cout << a.Zero_Matrix() << endl;
	return 0;
}
