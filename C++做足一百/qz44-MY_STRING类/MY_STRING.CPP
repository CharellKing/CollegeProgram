#include <iostream>

using namespace std;

#include "MY_STRING.H"

MY_STRING::MY_STRING()
{
	size = 0;
	elements = new char[1];
	elements[0] = '\0';
}

MY_STRING::MY_STRING(const char *s)
{
	int i;
	for(i = 0; s[i]; i ++);
	size = i;
	elements = new char[i+1];
	for(i = 0; i < size; i ++) elements[i] = s[i];
	elements[i] = '\0';
}

MY_STRING::MY_STRING(const MY_STRING &x)
{
	int i;
	size = x.size;
	elements = new char[size + 1];
	for(i = 0; i < x.size; i ++) elements[i] = x.elements[i];
	elements[i] = '\0';
}

istream& operator>>(istream& in, MY_STRING &x)
{
	int i = 0;
	char c, s[70];
	while(c = getchar(), c != ' ' && c != 10 && i < 69) s[i++] = c;
	if(s[i - 1] != 10) while(c = getchar(), c != 10);
	delete x.elements;
	x.size = i - 1;
	x.elements = new char[i];
	for(i = 0; i < x.size; i ++) x.elements[i] = s[i];
	x.elements[i] = 0;
	return in;

}

void MY_STRING::Destroy()
{
	delete elements;
}

ostream& operator<<(ostream& out, MY_STRING &x)
{
	int i;
	for(i = 0; i < x.size; i ++) out << x.elements[i];
	return out;
}

MY_STRING MY_STRING::operator = (const MY_STRING &x)
{
	MY_STRING y;
	int i;
	y.elements = new char[x.size + 1];
	for(i = 0; i < x.size; i ++) y.elements[i] = x.elements[i];
	y.elements[i] = '\0';
	y.size = x.size;
	return y;
}

MY_STRING operator+(const MY_STRING &x, const MY_STRING &y)
{
	MY_STRING z;
	int i, j;
	z.elements = new char[x.size + y.size + 1];
	z.size = x.size + y.size;
	for(i = 0; i < x.size; i ++) z.elements[i] = x.elements[i];
	for(j = 0; j < y.size; j ++, i ++) z.elements[i] = y.elements[j];
	z.elements[i] = '\0';
	return z;
}

bool operator >(const MY_STRING &left, const MY_STRING &right)
{
	int i = 0;
	for(i = 0; i < left.size && i < right.size; i ++)
	{
		if(left.elements[i] > right.elements[i]) return true;
		if(left.elements[i] < right.elements[i]) return false;
	}
	if(left.size > right.size) return true;
	else  return false;
}
bool operator <(const MY_STRING &left, const MY_STRING &right)
{
	int i = 0;
	for(i = 0; i < left.size && i < right.size; i ++)
	{
		if(left.elements[i] < right.elements[i]) return true;
		if(left.elements[i] > right.elements[i]) return false;
	}
	if(left.size < right.size) return true;
	else  return false;
}
bool operator !=(const MY_STRING &left, const MY_STRING &right)
{
	int i;
	if(left.size != right.size) return true;
	else
	{
		for(i = 0; i < left.size; i ++) if(left.elements[i] != right.elements[i]) return true;
	}
	return false;
}

bool operator >=(const MY_STRING &left, const MY_STRING &right)
{
	int i = 0;
	for(i = 0; i < left.size && i < right.size; i ++)
	{
		if(left.elements[i] > right.elements[i]) return true;
		if(left.elements[i] < right.elements[i]) return false;
	}
	if(left.size >= right.size) return true;
	else  return false;
}
bool operator <=(const MY_STRING &left, const MY_STRING &right)
{
	int i = 0;
	for(i = 0; i < left.size && i < right.size; i ++)
	{
		if(left.elements[i] < right.elements[i]) return true;
		if(left.elements[i] > right.elements[i]) return false;
	}
	if(left.size <= right.size) return true;
	else  return false;
}

bool operator==(const MY_STRING &left, const MY_STRING &right)
{
	int i;
	if(left.size != right.size) return false;
	else
	{
		for(i = 0; i < left.size; i ++) if(left.elements[i] != right.elements[i]) return false;
	}
	return true;
}

int MY_STRING::Size()
{
	return size;
}

char* MY_STRING::StringToCharArray()
{
	int i = 0;
	char *s;
	s = new char[size + 1];
	for(; i < size; i ++) s[i] = elements[i];
	s[i] = '\0';
	return s;
}

bool MY_STRING::IsEmpty()
{
	if(size == 0) return true;
	else return false;
}