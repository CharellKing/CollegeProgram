#include <iomanip>

#include "MATRIX.H"

MATRIX::MATRIX(int row, int colume)
{
	if(this->row < 1 || this->colume < 1 || (this->row == 1 && this->colume == 1)) row = 2 ,colume = 2;
	this->row = row, this->colume = colume;
	this->matrix = new double[row * colume];
	for(int i = 0; i < row * colume; i ++) this->matrix[i] = 0;
}

MATRIX::MATRIX(const MATRIX& x)
{
	this->row = x.row, this->colume = x.colume;
	this->matrix = new double[x.colume * x.row];
	for(int i = 0; i < row * colume; i ++) this->matrix[i] = x.matrix[i];
}

MATRIX::~MATRIX()
{
	delete []matrix;
}
	
void MATRIX::Input()
{
	char c;
	double x;
	int k = 0;
	cin.sync();
	do
	{
		while(c = cin.get(), c == 10 || c == ' ');
		cin.putback(c);
		cin >> x;
		if(cin)
		{
			matrix[k ++] = x;
		}
		else
		{
			cin.clear();
			cin.sync();
			delete [] matrix;
			matrix = new double[row * colume];
			k = 0;
			cout << "不正确的输入，请重新输入!" << endl;
		}
	}
	while(k != row * colume);
	cin.sync();
}

istream& operator >>(istream& in, MATRIX& y)
{
	char c;
	double x;
	int k = 0;
	cin.sync();
	do
	{
		while(c = cin.get(), c == 10 || c == ' ');
		cin.putback(c);
		cin >> x;
		if(cin)
		{
			y.matrix[k ++] = x;
		}
		else
		{
			cin.clear();
			cin.sync();
			delete [] y.matrix;
			y.matrix = new double[y.row * y.colume];
			k = 0;
			cout << "不正确的输入，请重新输入!" << endl;
		}
	}
	while(k != y.row * y.colume);
	return in;
}

	
void MATRIX::Output() const
{
	int i, j;
	cout << endl;
	for(i = 0; i < row; i ++)
	{
		for(j = 0; j < colume; j ++)
		{
			cout << setw(6) << matrix[i * colume + j] << ' ';
		}
		cout << endl;
	}
}

ostream& operator <<(ostream& out, const MATRIX &x)
{
	int i, j;
	cout << endl;
	for(i = 0; i < x.row; i ++)
	{
		for(j = 0; j < x.colume; j ++)
		{
			cout << setw(6) << x.matrix[i * x.colume + j] << ' ';
		}
		cout << endl;
	}
	return out;
}

MATRIX MATRIX::operator +(const MATRIX &x)const
{
	MATRIX y;
	if(this->row != x.row || this->colume != x.colume)
	{
		cout << "两个矩阵不能相加!" << endl;
		exit(1);
	}
	else
	{
		y = *this;
		y += x;
	}
	return y;
}

MATRIX MATRIX::operator -(const MATRIX &x)const
{
	MATRIX y;
	if(this->row != x.row || this->colume != x.colume)
	{
		cout << "两个矩阵不能相减!" << endl;
		exit(1);
	}
	else
	{
		y = *this;
		y -= x;
	}
	return y;
}

MATRIX& MATRIX::operator +=(const MATRIX &x)
{
	int i;
	if(this->row != x.row || this->colume != x.colume)
	{
		cout << "此矩阵不能追加!" << endl;
		exit(1);
	}
	else
	{
		for(i = 0; i < row * colume; i ++) this->matrix[i] += x.matrix[i];
	}
	return (*this);
}

MATRIX& MATRIX::operator -=(const MATRIX &x)
{
	MATRIX y;
	int i;
	if(this->row != x.row || this->colume != x.colume)
	{
		cout << "此矩阵不能追减!" << endl;
		exit(1);
	}
	else
	{
		for(i = 0; i < row * colume; i ++) this->matrix[i] -= x.matrix[i];
	}
	return (*this);
}

MATRIX& MATRIX::operator =(const MATRIX &x)
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

bool MATRIX::operator ==(const MATRIX &x)const
{
	if(this->colume != x.colume || this->row != x.row) return false;
	else
	{
		for(int i = 0; i < x.colume * x.row; i ++)
		{
			if(x.matrix[i] != this->matrix[i]) return false;
		}
	}
	return true;
}

bool MATRIX::operator !=(const MATRIX &x)const
{
	if(colume != x.colume || row != x.row) return true;
	else
	{
		for(int i = 0; i < colume * row; i ++)
		{
			if(x.matrix[i] != matrix[i]) return true;
		}
	}
	return false;
}

MATRIX MATRIX::operator -()const
{
	MATRIX a;
	a.colume = this->colume, a.row = this->row;
	a.matrix = new double[a.colume * a.row];
	for(int i = 0; i < a.colume * a.row; i ++) a.matrix[i] = -this->matrix[i];
	return a;
}

MATRIX MATRIX::operator *(const MATRIX &x)const
{
	int i, j, k, m;
	MATRIX y(this->row, x.colume);
	if(this->colume != x.row)
	{
		cout << "两矩阵不能相乘!" << endl;
		exit(1);
	}
	else
	{
		k = 0;
		for(i = 0; i < this->row; i ++)
		{
			for(j = 0; j < x.colume; j ++)
			{
				y.matrix[k] = 0;
				for(m = 0; m < this->colume; m ++)
				{
					y.matrix[k] += (this->matrix[i * this->colume + m] * x.matrix[m * x.colume + j]);
				}
				k ++;
			}
		}
	}
	return y;
}

MATRIX& MATRIX::operator *=(const MATRIX &x)
{
	MATRIX y(this->row, x.colume);
	if(this->colume != x.row)
	{
		cout << "此矩阵不能追乘!" << endl;
		exit(1);
	}
	else
	{
		y = (*this) * x;
	}
	(*this) = y;
	return *this;
}

MATRIX MATRIX::operator *(double x)const
{
	MATRIX y(*this);
	for(int i = 0; i < this->row * this->colume; i ++) y.matrix[i] *= x;
	return y;
}

MATRIX operator *(double x, const MATRIX& y)
{
	return MATRIX(y * x);
}

MATRIX MATRIX::Mul(double x) const
{
	return MATRIX((*this) * x);
}

MATRIX MATRIX::Transpose_Matrix()const
{
	int k = 0, i, j;
	MATRIX x(this->colume, this->row);
	for(i = 0; i < this->colume; i ++)
	{
		for(j = 0; j < this->row; j ++)
		{
			x.matrix[k ++] = this->matrix[j * this->colume + i];
		}
	}
	return x;
}

double MATRIX::operator ()(int row, int colume)const
{
	if(row < 1 || row > this->row || colume < 1 || colume > this->colume)
	{
		cout << "不正确的参数!" << endl;
		exit(1);
	}
	else
	{
		return this->matrix[(row - 1) * this->colume + colume - 1];
	}
}

USINT MATRIX::Colume()const
{
	return this->colume;
}

USINT MATRIX::Row()const
{
	return this->row;
}

MATRIX MATRIX::Zero_Matrix()const
{
	return MATRIX(this->row, this->colume);
}

MATRIX MATRIX::Rows_Exchange(int row1, int row2)const
{
	MATRIX x(*this);
	if(row1 != row2 && row1 >= 1 && row1 <= this->row && row2 >= 1 && row2 <= this->row)
	{
		for(int i = 0; i < this->colume; i ++)
		{
			x.Swap
	(x.matrix[(row1 - 1) * this->colume + i], x.matrix[(row2 -1) * this->colume + i]);
		}
	}
	return x;
}

void MATRIX::Swap(double &x, double &y)
{
	double z = x;
	x = y;
	y = z;
}

MATRIX MATRIX::Rows_Calculate(int row1, int row2, double mutiple)const
{
	int i, j, k;
	MATRIX x(*this);
	if(row1 >= 1 && row1 <= this->row && row2 >= 1 && row2 <= this->row)
	{
		j = (row1 -1) * this->colume;
		k = (row2 -1) * this->colume;
		for(i = 0; i < this->colume; i ++)
		{
			x.matrix[j + i] += x.matrix[k + i] * mutiple;
		}
	}
	return x;
}

MATRIX MATRIX::SingleRows_Calculate(int row, double mutiple)const
{
	int i, j;
	MATRIX x(*this);
	if(row >= 1 && row <= this->row)
	{
		i = (row - 1) * this->colume;
		for(j = 0; j < this->colume; j ++)
		{
			x.matrix[i + j] *= mutiple;
		}
	}
	return x;
}

MATRIX MATRIX::Ladder_line_matrix()const
{
	int i, j, k, m, a = row * row;
	double mutiple;
	MATRIX x(*this);
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
		}
		for(k = i + 1; k <= x.row; k ++)
		{
			m = (k - i) * colume + j;
			mutiple = x.matrix[m] / x.matrix[j];
			x = x.Rows_Calculate(k, i, -mutiple);
		}
	}
	return x;
}

MATRIX MATRIX::Erase_Colume(int colume)const
{
	int k;
	if(colume < 1 || colume > this->colume) return MATRIX(*this);
	else
	{
		k = 0;
		MATRIX x(this->row, this->colume - 1);
		for(int i = 0; i < this->row * this->colume; i ++)
		{
			if(i % this->colume != colume - 1) x.matrix[k ++] = this->matrix[i];
		}
		return x;
	}	
}

MATRIX MATRIX::Columes_Exchange(int colume1, int colume2)const
{
	MATRIX x(*this);
	if(colume1 != colume2 && colume1 >= 1 && colume1 <= this->colume && colume2 >= 1 && colume2 <= this->colume)
	{
		int j = colume1 - 1;
		int k = colume2 - 1;
		for(int i = 0; i < this->row; i ++)
		{
			x.Swap(x.matrix[j], x.matrix[k]);
			j += x.colume;
			k += x.colume;
		}
	}
	return x;
}
/*int main()
{
	MATRIX a(3, 2);
	MATRIX b;
	a.Input();
	a.Output(); cout << endl;
	b = a.Transpose_Matrix();
	b.Output(); cout << endl;
	cout << b(1, 3) << endl;
	return 0;
}*/
/*2x1 + 2x2 - x3 + x4 = 4,
4x1 + 3x2 - x3 + 2x4 = 6,
8x1 + 5x2 - 3x3 + 4x3 = 12,
3x1 + 3x2 - 2x3 + 2x4 = 6;
青 争 11:35:22
ok
刘观文 11:37:26
答案啊(1,1,-1,-1)

青 争 11:39:19
马上得出正确的答案

青 争 11:39:26
除了一些故障
刘观文 11:39:39
*/