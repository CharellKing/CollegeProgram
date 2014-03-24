#include <iostream>

using namespace std;

#include <cmath>

#include <iomanip>

#include "DEFINITION.H"

#include "LREAL.H"

LREAL::LREAL()
{
	sign = P;
	left = 1;
	right = 0;
	dreal = new double[left + right];
	dreal[0] = 0;
}

LREAL::~LREAL()
{
	delete [] dreal;
}

LREAL::LREAL(const LREAL &x)
{
	sign = x.sign;
	left = x.left;
	right = x.right;
	int k = left + right;
	dreal = new double[k];
	for(int i = 0; i < k; i ++) dreal[i] = x.dreal[i];
}

LREAL& LREAL::operator =(const LREAL &x)
{
	sign = x.sign;
	left = x.left;
	right = x.right;
	int k = left + right;
	delete [] dreal;
	dreal = new double[k];
	for(int i = 0; i < k; i ++) dreal[i] = x.dreal[i];
	return *this;
}

LREAL LREAL::operator -() const
{
	LREAL x(*this);
	x.sign = -x.sign;
	return x;
}

LREAL LREAL::operator +() const
{
	return *this;
}

istream& operator >>(istream &in, LREAL &x)
{
	char c;
	bool b;
	string sreal;
	do
	{
		while(c = cin.get(), isspace(c));
		if(c == '+') x.sign = P;
		else if(c == '-') x.sign = N;
		else x.sign = P, cin.putback(c);
		in >> sreal;
		b = x.IsValid(sreal);
		if(!b) cout << "ÊäÈë´íÎó, ÇëÖØÐÂÊäÈë!" << endl;
	}
	while(!b);
	x.Simple(sreal);
	x.DReal(sreal);
	return in;
}

ostream& operator <<(ostream &out, const LREAL &y)
{
	LREAL x = y;
	x = y.Precision();
	if(x.sign == N && !x.IsZero()) out << '-';
	int i = x.left + x.right - 1, k = 1, j = 0;
	out << (int)x.dreal[i --];
	for(; i >= x.right; i --) cout << setfill('0') << setw(7) << (int)x.dreal[i];
	if(x.right) cout << '.';
	for(; i > 0; i --) cout << setfill('0') << setw(7) << (int)x.dreal[i];
	if(i == 0)
	{
		while(k *= 10, int(x.dreal[i]) % k == 0) j ++;
		cout << setfill('0') << setw(7 - j) << int(x.dreal[0]) * 10 / k;
	}
	cout << setfill(' ');
	return out;
}

LREAL LREAL::operator +(const LREAL &x) const
{
	LREAL y;
	if(IsZero()) return x;
	if(x.IsZero()) return *this;
	if(x.sign + sign) y = D_Add(x);
	else 
	{
		int k = D_ABS_C(x);
		if(k == 1) y = D_Sub(x);
		if(k == -1) y = x.D_Sub(*this);
	}
	return y;
}

LREAL LREAL::operator -(const LREAL &x) const
{
	LREAL y;
	if(IsZero()) return -x;
	if(x.IsZero()) return *this;
	if(sign - x.sign) y = D_Add(x);
	else
	{
		int k = D_ABS_C(x);
		if(k == 1) y = D_Sub(x);
		if(k == -1) y = x.D_Sub(*this), y.sign = -y.sign;
	}
	return y;
}

LREAL& LREAL::operator -=(const LREAL &x)
{
	LREAL y = *this - x;
	return *this = y;
}

LREAL LREAL::operator *(const LREAL &x) const
{
	LREAL y;
	if(IsZero() || x.IsZero()) return y;
	if(x.IsOne()) return *this;
	if(IsOne()) return x;
	if(x.IsNOne()) return -*this;
	if(IsNOne()) return -x;
	y = D_Mul(x);
	return y;
}

LREAL LREAL::operator /(const LREAL &x) const
{
	LREAL y;
	if(x.IsZero()) throw 1;
	if(IsZero()) return y;
	if(x.IsOne()) return *this;
	if(x.IsNOne()) return -*this;
	y = D_Div(x);
	return y;
}




bool LREAL::IsValid(const string x)
{
	int pointNum = 0;
	for(int i = 0; i < x.size(); i ++)
	{
		if(!isdigit(x[i]) && x[i] != '.') return false;
		if(x[i] == '.') pointNum ++;
	}
	if(pointNum > 1) return false;
	if(x[0] == '0' && isdigit(x[1])) return false;
	if(x[0] == '.') return false;
	return true;
}

void LREAL::Simple(string &sreal)
{
	if(0 == sreal.find('.')) sreal += '.';
	for(int i = 0; sreal[i] == '0' && i <= PPoint(sreal) - 3; i ++);
	for(int j = sreal.size() - 1; (sreal[j] == '0'|| sreal[j] == '.') && j >= PPoint(sreal) - 1; j --);
	if(sreal[j] == '.') j --;
	sreal = sreal.substr(i, j + 1);
}


void LREAL::DReal(const string &sreal)
{
	int i, j, k;
	unsigned int m;
	double sum;
	string x = sreal;
	int pos = PPoint(sreal);
	if(pos == sreal.size() + 1) x += '.';
	right = (x.size() - pos) / 7; if((x.size() - pos) % 7) right ++;
	left = (pos - 1) / 7; if((pos - 1) % 7) left ++;
	delete [] dreal;
	dreal = new double[right + left];
	for(i = pos, j = right -1; i < x.size();)
	{
		m = 1e6; sum = 0;
		for(k = 0; k < 7 && i < x.size(); k ++) sum += (m * (x[i ++] - '0')), m /= 10;
		dreal[j --] = sum;
	}
	for(i = pos - 2, j = right; i >= 0;)
	{
		m = 1, sum = 0;
		for(k = 0; k < 7 && i >= 0; k ++) sum += (m * (x[i --] - '0')), m *= 10;
		dreal[j ++] = sum;
	}
}

int LREAL::PPoint(const string &sreal)
{
	int pos = sreal.find('.');
	if(pos == string::npos) pos = sreal.size();
	return pos + 1;
}


LREAL LREAL::D_Add(const LREAL &x) const
{
	LREAL y;
	int l_max, r_max, i, j, k = 0, m;
	l_max = (left > x.left ? left : x.left);
	r_max = (right > x.right ? right : x.right);
	double *d = new double[l_max + 1 + r_max];
	for(i = 0; i <= l_max + r_max; i ++) d[i] = 0; 
	if(right > x.right)
	{
		for(i = 0; i < right - x.right; i ++) d[k ++] = dreal[i];
		for(j = 0; i < r_max; i ++, j ++) m = dreal[i] + x.dreal[j] + d[k], d[k] = m % ds, d[++k] = m / ds;
	}
	else
	{
		for(i = 0; i < x.right - right; i ++) d[k ++] = x.dreal[i];
		for(j = 0; i < r_max; i ++, j ++) m = x.dreal[i] + dreal[j] + d[k], d[k] = m % ds, d[++k] = m / ds;
	}

	if(left > x.left)
	{
		for(i = right, j = x.right; j < x.right + x.left; i ++, j ++)
			m = dreal[i] + x.dreal[j] + d[k], d[k] = m % ds, d[++k] = m / ds;
		for(; i < right + left; i ++) m = dreal[i] + d[k], d[k] = m % ds, d[++k] = m / ds;
	}
	else
	{
		for(i = right, j = x.right; i < right + left; i ++, j ++)
		{
			m = dreal[i] + x.dreal[j] + d[k];
			d[k] = m % ds;
			d[++k] = m / ds;
		}
		for(; j < x.right + x.left; j ++) m = x.dreal[j] + d[k], d[k] = m % ds, d[++k] = m / ds;
	}

	for(i = 0; d[i] == 0 && i < r_max; i ++);
	y.right = r_max - i; y.left = (d[l_max + r_max] ? l_max + 1 : l_max);
	delete [] y.dreal; y.dreal = new double[y.left + y.right];
	y.sign = sign;
	for(j = 0; j < y.right + y.left; i++, j ++) y.dreal[i] = d[i];
	delete [] d;
	return y;
}
	
LREAL LREAL::D_Sub(const LREAL &x) const
{
	LREAL y;
	int l_max, r_max, i, j, k = 0, m;
	l_max = (left > x.left ? left : x.left);
	r_max = (right > x.right ? right : x.right);
	double *d = new double[l_max + r_max];
	for(i = 0; i < l_max + r_max; i ++) d[i] = 0;
	if(right > x.right)
	{
		for(i = 0; i < right - x.right; i ++) d[k ++] = dreal[i];
		for(j = 0; i < r_max; j ++, i ++)
		{
			m = d[k] + dreal[i] - x.dreal[j];
			if(m < 0) d[k] = m + ds, d[++k] --;
			else d[k ++] = m;
		}
	}
	else
	{
		for(i = 0; i < x.right - right; i ++)
		{
			m = d[k] - x.dreal[i];
			if(m < 0) d[k] = m + ds, d[++k]--;
			else d[k ++] = m;
		}
		for(j = 0; i < r_max; j ++, i ++)
		{
			m = d[k] + dreal[j] - x.dreal[i];
			if(m < 0) d[k] = m + ds, d[++k] --;
			else d[k ++] = m;
		}
	}
	
	
	for(i = right, j = x.right; j < x.left + x.right; i ++, j ++)
	{
		m = d[k] + dreal[i] - x.dreal[j];
		if(m < 0) d[k] = m + ds, d[++k] --;
		else d[k ++] = m;
	}
	for(; i < left + right; i ++)
	{
		m = d[k] + dreal[i];
		if(m < 0) d[k] = m + ds, d[++k] --;
		else d[k ++] = m;
	}

	y.sign = sign;
	for(i = 0; d[i] == 0 && i < r_max; i ++);
	for(j = r_max + l_max - 1; d[j] == 0 && j > r_max; j --);
	y.right = r_max - i; y.left = j - r_max + 1;
	delete [] y.dreal;
	y.dreal = new double[y.right + y.left];
	for(k = 0; i <= j; i ++) y.dreal[k ++] = d[i];
	delete [] d;
	return y;
}

LREAL LREAL::D_Mul(const LREAL &x) const
{
	LREAL y;
	int i, j, k = x.right + x.left + right + left, n;
	double *d = new double[k];
	double m, r;
	for(i = 0; i < k; i ++) d[i] = 0;
	for(i = 0; i < x.left + x.right; i ++)
	{
		for(j = 0; j < left + right; j ++)
		{
			n = i + j;
			m = x.dreal[i] * dreal[j] + d[n]; 
			r = (int) (m / ds);
			d[n + 1] += r;
			d[n] = m - r * ds;
		}
	}
	y.sign = x.sign * sign;
	for(i = 0; i < x.right + right && d[i] == 0; i ++);
	for(j = k -1; j > x.right + right && d[j] == 0; j --);
	y.right = x.right + right - i;
	y.left = j - right - x.right + 1;
	delete [] y.dreal; y.dreal = new double[y.right + y.left];
	k = 0;
	for(; i <= j; i ++) y.dreal[k ++] = d[i];
	delete [] d;
	return y;
}

LREAL LREAL::D_Div(const LREAL &x) const
{
	LREAL a(*this), b(x), c, d;
	a.sign = b.sign = P;
	int r_max = (right > x.right ? right : x.right), k, l, r, i, m, start, mid, end;
	char n;
	a.MPoint(r_max), b.MPoint(r_max);
	m= 0;
	while(a.D_ABS_C(b) == 1) b.MPoint(1), m ++;
	l = 1;
	r = (precision + 1) / 7 + ((precision + 1) % 7 ? 1 : 0) + m;
	d.left = l; d.right = r;
	d.dreal = new double[l + r];
	for(i = 0; i < l + r; i ++) d.dreal[i] = 0;
	k = l + r - 1;
	r = b.right + b.left - 1;
	do
	{
		while(a.D_ABS_C(b) == -1) a.MPoint(1), k --;
		if(k < 0) break;
		l = a.right + a.left -1;
		if(a.dreal[l] <= b.dreal[r] && a.D_ABS_C(b) == 1 || a.dreal[l] > b.dreal[r])
		{
			end = ds;
			start = 1;
			mid = (end + start) / 2;
		}
		else end = start = mid = 1;
		do
		{
			c.dreal[0] = mid;
			n = a.D_ABS_C(c * b);
			if(n == 1) start = mid;
			if(n == -1) end = mid;
			if(n == 0) end = start = mid;
			mid = (end + start) / 2;
		}
		while(start != mid);
		c.dreal[0] = start;
		do c ++;
		while(a.D_ABS_C(b * c) > 1);
		c --;
		d.dreal[k] = c.dreal[0];
		if(k < 0) break;
		a -= (c * b);
	}
	while(!a.IsZero() && k >= 0);
	d.MPoint(m);
	d.sign = x.sign * sign;
	return d;
}



int LREAL::D_ABS_C(const LREAL &x) const
{
	int i, j;
	if(left > x.left) return 1;
	if(left < x.left) return -1;
	for(i = left + right - 1, j = x.left + x.right - 1; i >= 0 && j >= 0; i --, j --)
	{
		if(dreal[i] > x.dreal[j]) return 1;
		if(dreal[i] < x.dreal[j]) return -1;
	}
	if(right > x.right) return 1;
	if(right < x.right) return -1;
	return 0;
}

void LREAL::MPoint(int n)
{
	int m = right - n, l, r, i, j, k;
	double *d;
	k = 0;
	if(m < 0)
	{
		r = 0, l = -m + left + right;
		d = new double [l];
		for(i = 0; i < -m; i ++) d[i] = 0;
		for(; i < l; i ++) d[i] = dreal[k ++];
	}
	else if(m < right + left)
	{
		r = m, l = right + left - m;
		d = new double [r + l];
		for(i = 0; i < right + left; i ++) d[i] = dreal[i];
	}
	else
	{
		r = m - right - left + 1, l = m;
		d = new double [l + r];
		for(i = 0; i < right + left; i ++) d[i] = dreal[i];
		for(; i < r + l; i ++) d[i] = 0;
	}
	for(i = r + l - 1; i > r && d[i] == 0; i --);
	for(j = 0; j < r && d[j] == 0; j ++);
	l = i - r + 1; r -= j; 
	right = r; left = l;
	delete [] dreal;
	dreal = new double[right + left];
	k = 0;
	for(; j <= i; j ++) dreal[k ++] = d[j];
	delete [] d;
}
	



bool LREAL::IsOne() const
{
	return left == 1 && dreal[0] == 1 && right == 0 && sign == 1;
}

bool LREAL::IsNOne() const
{
	return left == 1 && dreal[0] == 1 && right == 0 && sign == -1;
}

bool LREAL::IsZero() const
{
	return left == 1 && dreal[0] == 0 && right == 0;
}

LREAL& LREAL::operator ++()
{
	LREAL a;
	a.dreal[0] = 1;
	
	return *this = *this + a;;
}

LREAL LREAL::operator ++(int)
{
	LREAL a, b(*this);
	a.dreal[0] = 1;
	*this = *this + a;
	return b;
}

LREAL& LREAL::operator --()
{
	LREAL a;
	a.dreal[0] = 1;
	return *this = *this - a;
}

LREAL LREAL::operator --(int)
{
	LREAL a, b(*this);
	a.dreal[0] = 1;
	*this = *this - a;
	return b;
}

LREAL LREAL::Precision()const
{
	LREAL a, b;
	a.sign = b.sign;
	int m, n, i, j, k, l;
	m = (precision + 1) / 7;
	n = (precision + 1) % 7;
	i = precision / 7;
	j = precision % 7;
	if(n) m ++;
	if(j) i ++;
	m = right - m;
	if(m < 0) return LREAL(*this);
	l = pow(10, Digit(j) - 1);
	if((int)dreal[m] / (int)pow(10, Digit(n) - 1) % 10 >= 5)
	{
		a.left = 1, a.right = i;
		delete [] a.dreal;
		a.dreal = new double[1 + i];
		a.dreal[0] = l;
		for(k = 1; k < a.left + a.right; k ++) a.dreal[k] = 0;
		b = a + *this;
	}
	else
	{
		b = *this;
	}
	m = right - i;
	b.dreal[m] = (int)b.dreal[m] / l * l;
	for(; m < right && b.dreal[m] == 0; m ++);
	a.left = b.left, a.right = right - m;
	delete [] a.dreal;
	a.dreal = new double[a.left + a.right];
	for(k = 0; k < a.left + a.right; k ++, m ++)
	{
		a.dreal[k] = b.dreal[m];
	}
	return a;
}

int LREAL::Digit(int i)
{
	if(i) return 8 - i;
	else return 1;
}
	
int main()
{
	try
	{
		LREAL x, y;
		cin >> x;
		cout << x << endl;
		cin >> y;
		cout << y << endl;
		cout << x + y << endl;
		cout << x - y << endl;
		cout << x * y << endl;
		cout << x / y << endl; ;
	}
	catch(int)
	{
		cout << "³ýÁã´íÎó!" << endl;
	}
	return 0;
}
