#include <iostream>

using namespace std;

#include <conio.h>

#include "LREAL.H"

#include <cstring>

LREAL::LREAL()
{
	sign = P;
	this->real = "0";
}

LREAL::LREAL(const LREAL &x)
{
	sign = x.sign;
	real = x.real;
}

LREAL& LREAL::operator =(const LREAL &x)
{
	sign = x.sign;
	real = x.real;
	return *this;
}

istream& operator >>(istream &in, LREAL &x)
{
	char c;
	bool b;
	do
	{
		while(c = cin.get(), isspace(c));
		if(c == '+') x.sign = P;
		else if(c == '-') x.sign = N;
		else x.sign = P, cin.putback(c);
		in >> x.real;
		b = x.IsValid(x.real);
		if(!b) cout << "ÊäÈë´íÎó, ÇëÖØÐÂÊäÈë!" << endl;
	}
	while(!b);
	x.Simple();
	return in;
}

ostream& operator <<(ostream &out, const LREAL &x)
{
	if(x.sign == N) out << '-';
	out << x.real;
	return out;
}

int LREAL::APoint() const
{
	string b = real;
	if(string::npos == b.find('.')) b += '.';
	return b.size() - PPoint();
}

LREAL LREAL::operator +(const LREAL &x) const
{
	if(x.IsZero()) return *this;
	if(IsZero()) return x;
	LREAL a, b;
	int max = x.APoint();
	string c;
	if(max < APoint()) max = APoint();
	a = x.MPoint(max), b = MPoint(max);
	Reserve(a.real), Reserve(b.real);
	Char_Digit(a.real), Char_Digit(b.real);
	if(x.sign + sign) c = IAdd(a.real, b.real);
	else c = ISub(a.real, b.real);
	Digit_Char(c);
	Reserve(c);
	if(I_ABS_C(b.real, a.real) >= 0) a.sign = b.sign;
	a.real = c;
	a.Simple();
	b = a.MPoint(-max);
	return b;
}

LREAL& LREAL::operator +=(const LREAL &x)
{
	*this = *this + x;
	return *this;
}

LREAL LREAL::operator -(const LREAL &x) const
{
	if(x.IsZero()) return *this;
	if(IsZero()) return x;
	LREAL a, b;
	int max = x.APoint();
	string c;
	if(max < APoint()) max = APoint();
	a = x.MPoint(max), b = MPoint(max);
	Reserve(a.real), Reserve(b.real);
	Char_Digit(a.real), Char_Digit(b.real);
	if(x.sign - sign) c = IAdd(a.real, b.real);
	else c = ISub(a.real, b.real);
	Digit_Char(c);
	Reserve(c);
	a.sign = -a.sign;
	if(I_ABS_C(b.real, a.real) >= 0) a.sign = b.sign;
	a.real = c;
	a.Simple();
	b = a.MPoint(-max);
	return b;
}

LREAL LREAL::operator *(const LREAL &x) const
{
	if(x.IsZero()) return x;
	if(IsZero()) return *this;
	LREAL a, b;
	int y = APoint();
	int z = x.APoint();
	string c;
	a = x.MPoint(z), b = MPoint(y);
	Reserve(a.real), Reserve(b.real);
	Char_Digit(a.real), Char_Digit(b.real);
	c = IMul(a.real, b.real);
	Digit_Char(c);
	Reserve(c);
	a.sign = a.sign * b.sign;
	a.real = c;
	a.Simple();
	b = a.MPoint(-(z + y));
	return b;
}

LREAL LREAL::operator /(const LREAL &x) const
{
	if(x.IsZero()) throw 1;
	if(IsZero() || x.IsOne()) return *this;
	if(x.IsNOne()) return -(*this);
	LREAL a, b;
	int y = APoint(), z = x.APoint(), k = 0, m;
	string c;
	a = x.MPoint(z), b = MPoint(y);
	Reserve(a.real), Reserve(b.real);
	Char_Digit(a.real), Char_Digit(b.real);
	while(I_ABS_C(a.real, b.real) <= 0)
	{
		if(a.real.size() < b.real.size()) k = b.real.size() - a.real.size(), a.real = ADigit(a.real, k);
		else k ++, a.real = ADigit(a.real, 1);
	}
	m = z - y + k;
	c = IDiv(b.real, a.real, m);
	a.sign = a.sign * b.sign;
	a.real = c;
	a.Simple();
	b = a.MPoint(m);
	return b;
}

LREAL LREAL::operator -()const
{
	LREAL x(*this);
	x.sign = -sign;
	return x;
}

LREAL LREAL::operator +()const
{
	return LREAL(*this);
}

bool LREAL::IsOne()const
{
	return real[0] == '1' && real[1] == '\0' && sign == 1;
}

bool LREAL::IsNOne()const
{
	return real[0] == '1' && real[1] == '\0' && sign == -1;
}

bool LREAL::IsValid(const string real)
{
	int pointNum = 0;
	for(int i = 0; i < real.size(); i ++)
	{
		if(!isdigit(real[i]) && real[i] != '.') return false;
		if(real[i] == '.') pointNum ++;
	}
	if(pointNum > 1) return false;
	if(real[0] == '0' && isdigit(real[1])) return false;
	if(real[0] == '.') return false;
	return true;
}

LREAL LREAL::MPoint(int right)const
{
	LREAL a(*this);
	if(a.IsZero() || !right) return a;
	if(string::npos == real.find('.')) a.real += '.';
	int now_p = a.PPoint(), new_p = now_p + right;
	if(new_p <= 1)
	{
		string c(1 - new_p, '0');
		a.real = "0." + c + a.real.substr(0, now_p - 1) + a.real.substr(now_p, a.real.size() - now_p);
	}
	else if(new_p >= a.real.size())
	{
		string d(new_p - a.real.size(), '0');
		a.real = a.real.substr(0, now_p - 1) + a.real.substr(now_p, a.real.size() - now_p) + d;
	}
	else
	{
		if(right > 0) a.real = a.real.substr(0, now_p - 1) + a.real.substr(now_p, right)
			+ '.' + a.real.substr(now_p + right, a.real.size() - now_p - right);
		else a.real = a.real.substr(0, new_p - 1) + '.' + a.real.substr(new_p - 1, -right)
			+ a.real.substr(now_p, a.real.size() - now_p);
	}
	a.Simple();
	return a;
}

void LREAL::Simple()
{
	if(0 == real.find('.')) real += '.';
	for(int i = 0; real[i] == '0' && i <= PPoint() - 3; i ++);
	for(int j = real.size() - 1; (real[j] == '0'|| real[j] == '.') && j >= PPoint() - 1; j --);
	if(real[j] == '.') j --;
	real = real.substr(i, j + 1);
}

int LREAL::PPoint()const
{
	int position = real.find('.') + 1;
	if(position == 0) position = real.size() + 1;
	return position;
}

bool LREAL::IsZero()const
{
	LREAL x = *this;
	x.Simple();
	return (x.real.size() == 1 && x.real[0] == '0');
}

void LREAL::Reserve(string &x)
{
	string y = x;
	int k = x.size() - 1;
	for(int i = k; i >= 0; i --)
	{
		x[k - i] = y[i];
	}
}

void LREAL::Digit(string &x)
{
	string y = x + '\0';
	for(int i = 0; i < x.size(); i ++)
	{
		y[i + 1] += (y[i] / 10);
		y[i] = y[i] % 10;
	}
	if(!y[y.size() - 1]) x = y.substr(0, y.size() - 1);
	else x = y;
}

string LREAL::IAdd(const string &x, const string &y)
{
	string a = x, b = y;
	if(a.size() < b.size()) Swap(a, b);
	string c(a);
	for(int i = 0; i < b.size(); i ++) c[i] = a[i] + b[i];
	for(; i < a.size(); i ++) c[i] = a[i];
	Digit(c);
	return c;
}

string LREAL::ISub(const string &x, const string &y)
{
	string a, b;
	a = x, b = y;
	int k = I_ABS_C(a, b);
	if(k < 0) Swap(a, b);
	if(k == 0) return string(1, '\0');
	for(int i = 0; i < b.size(); i ++)
	{
		if(a[i] < b[i]) a[i + 1] --, a[i] += 10;
		a[i] -= b[i];
	}
	for(; i < a.size() && a[i] < 0 ; i ++) a[i + 1] --, a[i] += 10;
	for(i = a.size() -1; a[i] == 0 && i > 0; i --);
	if(i < a.size() - 1) return a.substr(0, i + 1);
	else return a;
}

string LREAL::IMul(const string &x, const string &y)
{
	string z(1, '\0');
	string a, b, c;
	for(int i = 0; i < y.size(); i ++) z = IAdd(MDigit(ADigit(x, i), y[i]), z);
	Digit(z);
	return z;
}

string LREAL::IDiv(const string &x, const string &y, int m)
{
	string a = x, c = "0.";
	int k, i, j = 0;
	char d;
	do
	{
		k = 0;
		while(I_ABS_C(a, y) == -1)
		{
			if(a.size() < y.size()) k = y.size() - a.size(), a = ADigit(a, k);
			else k ++, a = ADigit(a, 1);
		}
		j += k;
		c += string(k - 1, '0');
		for(i = 1; I_ABS_C(MDigit(y, i), a) <= 0 && i <= 9; i ++);
		i --; d = i + '0'; c += d;
		a = ISub(a, MDigit(y, i));
	}
	while(a != string(a.size(), '\0') && j < precision + m + 1);
	return c;
}
		

string LREAL::ADigit(const string &x, int n)
{
	string y(n, '\0');
	return y + x;
}

string LREAL::MDigit(const string &x, int n)
{
	string y = x;
	int i;
	for(i = 0; i < y.size(); i ++) y[i] *= n;
	Digit(y);
	return y;
}

	

int LREAL::I_ABS_C(const string &x, const string &y)
{
	int i;
	if(x.size() > y.size()) return 1;
	if(x.size() < y.size()) return -1;
	for(i = x.size() - 1; i >= 0; i --)
	{
		if(x[i] > y[i]) return 1;
		if(x[i] < y[i]) return -1;
	}
	return 0;
}

void LREAL::Digit_Char(string &x)
{
	for(int i = 0; i < x.size(); i ++)
	{
		if(x[i] <= 9 && x[i] >= 0) x[i] += '0';
	}
}
	
void LREAL::Char_Digit(string &x)
{
	for(int i = 0; i < x.size(); i ++)
	{
		if(isdigit(x[i])) x[i] -= '0';
	}
}

void LREAL::Swap(string &a, string &b)
{
	string c;
	c = a;
	a = b;
	b = c;
}

int main()
{
	LREAL a, b;
	try
	{
		cout << "Please input two numbers:" << endl;
		cin >> a;
		cin >> b;
		cout << "a + b = " << a + b << endl;
		cout << "a - b = " << a - b << endl;
		cout << "a * b = " << a * b << endl;
		cout << "a / b = " << a / b << endl;
	}
	catch(int)
	{
		cout << "³ýÁã´íÎó!" << endl;
	}
	getch();
	return 0;
}

