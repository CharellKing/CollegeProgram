#include <iostream>
using namespace std;

#include <cstring>

#include <stdio.h>
#include "Char_Str.h"

//template <>
MyString::MyString(int size)
{
	if(size <= 0) size = INIT_SIZE;
	this->size = size;
	data = new char[this->size];
	length = 0;
	data[length] = '\0';
}

//template <>
MyString::MyString(const MyString& x)
{
	size = x.size;
	length = x.length;
	data = new char[size];
	strcpy(data, x.data);
}

//template <>
MyString::~MyString()
{
	delete [] data;
}

//template <>
const MyString& MyString::operator =(const MyString x)
{
	if(this != &x)
	{
		if(size <= x.length)
		{
			data = new char[x.size];
		}
		length = x.length;
		strcpy(data, x.data);
	}
	return *this;
}

char MyString::operator[](int pos)
{
    if(pos >= 1 && pos <= 1)
    {
        return data[pos - 1];
    }
    else
    {
        throw string("不正确的引用!");
    }
}
 
//template <>
void MyString::Input()
{
	char c;
	Clear();
	while(c = getchar(), c != '\n')
	{
		Append(c);
	}
}

//template <>
void MyString::Append(char c)
{
	if(length == size - 1)
	{
		size += INCREASEMENT;
		ExpendSpace(data, size);
	}
	data[length] = c;
	length ++;
	data[length] = '\0';
}

//template <>
void MyString::Output()const
{
	UINT start;
	for(start = 0; start < length; start ++)
	{
		cout << data[start];
	}
}

//template <>
bool MyString::IsEmpty()const
{
	return length == 0;
}

//template <>
int MyString::StrCompare(const MyString& x)const
{
	int result = 1;
	result = strcmp(data, x.data);
	if(result > 0) result = 1;
	else if(result < 0) result = -1;
	return result;
}

//template <>
UINT MyString::Length()const
{
	return length;
}

//template <>
void MyString::Clear()
{
	length = 0;
}

//template <>
MyString MyString::ConCat(const MyString& x)
{
	MyString y(size + x.length);
	y.data = strcpy(y.data, data);
	y.data = strcat(y.data, x.data);
	y.length = x.length + length;
	return y;
}

//template <>
MyString MyString::SubStr(int pos, int length)
{
	MyString x(size);
	UINT start, count;
	if(pos >= 1 && pos <= this->length)
	{
		pos --;
		for(start = pos, count = 0; count < length && start < this->length; start ++, count ++)
		{
			x.data[count] = data[start];
		}
		x.length = count;
	}
	return x;
}


//template <>
int MyString::Index(const MyString& x)
{
	UINT x_start, the_start, record, result;
	for(x_start = 0, the_start = 0;
	x_start < x.length && the_start < length; the_start ++, x_start ++)
	{
		if(data[the_start] != x.data[x_start] && x_start != -1)
		{
			record = x_start;
			do
			{
				x_start --;
			}
			while(x_start != -1 && !Matched_Behind(x.data, x_start, record));
		}
	}
	if(x_start != x.length || x.length == 0) result = 0;
	else result = the_start - x.length + 1;
	return result;
}

//template <>
bool MyString::Matched_Behind(const char* data, int pos, int before)
{
	bool result = true;
	do
	{
		if(data[pos] != data[before]) result = false;
		pos --;
		before --;
	}
	while(result && pos >= 0);
	return result;
}


//template <>
MyString MyString::Replace(const MyString& passive, const MyString& initiative)
{
	int pos;
	MyString c(*this);
	do
	{
		pos = Index(passive);
    }
    while(1);
    return MyString();
		
}


//template <>
MyString MyString::StrInsert(int pos, const MyString& target)
{
	MyString x(size + target.length);
	UINT start, t_start;
	if(pos <= 0) pos = 1;
	if(pos > length + 1) pos = length + 1;
	pos --;
	for(start = 0; start < pos; start ++)
	{
		x.data[start] = data[start];
	}
	for(t_start = 0; t_start < target.length; t_start ++, start ++)
	{
		x.data[start] = target.data[t_start];
	}
	for(t_start = pos; t_start < length; t_start ++, start ++)
	{
		x.data[start] = data[t_start];
	}
	x.length = length + target.length;
	return x;
}

//template <>
MyString MyString::StrDelete(int pos, int length)
{
	MyString x(*this);
	UINT start, end;
	if(pos >= 1 && pos <= x.length)
	{
		end = pos + length;
		pos --;
		for(start = end - 1; start < x.length; start ++, pos ++)
		{
			x.data[pos] = x.data[start];
		}
		x.length = pos;
	}
	return x;
}

//template <>
void MyString::ExpendSpace(char *&data, int sum_size)
{
	char* new_data = NULL;
	if(sum_size > 0)
	{
		UINT length = strlen(data);
		new_data = new char[length + 1];
		strcpy(new_data, data);
		delete [] data;
		data = new char[sum_size];
		strcpy(data, new_data);
		delete [] new_data;
		new_data = NULL;
	}
}

//template <>
void MyString::ConCat(MyString& x, const MyString& y)
{
    if(x.length + y.length >= x.size)
	{
		x.size += x.length + y.length + INCREASEMENT;
		x.ExpendSpace(x.data, x.size);
	}
	x.data = strcat(x.data, y.data);
	x.length += y.length;
}

//template <>
void MyString::SubStr(MyString& x, int pos, int length)
{
	UINT i, j;
	if(pos >= 1 && pos <= x.length)
	{
		for(i = pos - 1, j = 0; i < x.length && j < length; j ++, i ++)
		{
			x.data[j] = x.data[i];
		}
		x.length = j;
	}
	else
	{
        x.Clear();
    }
}
		

//template <>
void MyString::Replace(MyString& x, const MyString& passive, const MyString& initiative)
{
	
}

//template <>
void MyString::StrInsert(MyString& x, int pos, const MyString& t)
{
	UINT i, j;
	if(pos <= 0) pos = 1;
	else if(pos > x.length + 1) pos = x.length + 1;
	if(x.size <= x.length + t.length)
	{
		x.size = x.length + t.length + INCREASEMENT;
		x.ExpendSpace(x.data, x.size);
	}
	for(i = pos - 1; i < x.length; i ++)
	{
		x.data[i + t.length] = x.data[i];
	}
	for(i = pos - 1, j = 0; j < t.length; i ++, j ++)
	{
		x.data[i] = t.data[j];
	}
	x.length += t.length;
	x.data[x.length] = '\0';
}

//template <>
void MyString::StrDelete(MyString& x, int pos, int length)
{
	UINT i;
	if(pos >= 1 && pos <= x.length && length > 0)
	{
		for(i = pos + length - 2; i < x.length; i ++)
		{
			x.data[i - length] = x.data[i];
		}
		if(i > x.length) x.length = length;
		else x.length = i - length;
	}
	else
	{
		x.Clear();
	}
}
