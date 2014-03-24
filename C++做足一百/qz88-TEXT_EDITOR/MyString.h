/*-----MyString.h--------
  ������һ��MyString Classs
  ���ݳ�Ա��
  data : ����ΪT��ָ������
  length��Ϊ�����д洢���ݵĸ���
  size��data���ٵĿռ��С
  ���ݲ�����
  MyString(int size = INIT_SIZE);
  //��ʼ��size������һ������
  //���size <= 0 ��ô����INIT_SIZE��ֵ 
  
  MyString(const MyString<T>& x);
  //�������� 
  
  ~MyString();
  //����
  
  const MyString& operator=(const MyString<T>& x);
  //��ֵ
   
  bool operator==(const MyString<T>& x)const;
  //�ж��Ƿ����
   
  UINT Length()const;
  //���ش��ĳ���
   
  MyString<T> Concat(const MyString<T>& x)const;
  //�ϲ�������X�ӵ�this���Ľ�β
   
  MyString<T> SubStr(int from, int length)const;
  //��this���еĵ�from�����ݣ���
  //�к�������length���ȣ������������Ĵ�
  //�������û��length�����ȣ�ֱ������this
  //���洢�����ݵĽ�β
   
  MyString<T> InsStr(const MyString<T>& x, int pos = length + 1)const;
  //����X���뵽this�ĵ�pos�����ݵ�λ��
  //���pos <= 0 ,��Ϊpos = 1
  //���pos > length + 1, ��Ϊpos = length + 1��
   
  MyString<T> DelStr(int from, int length)const;
  //��this�������ݴӵ�from��λ����ɾ�����length������
  //���γɵ��´�
   
  MyString<T> RepStr(int from, int length)const;
  //�ڴ�this�У�����from�����ݿ�ʼ��length�����ݹ��ɵ��Ӵ�
  //�ô�x�滻�����ز������´�
   
  void Display()const;
  //��ӡ���е�����
   
  static void Concat(MyString<T>& x, const MyString<T>& y);
  //��y����x���ϲ����ı�x, ������x
   
  static void SubStr(MyString<T>& x, int from, int length);
  //ֻ����x���ݵĴ�from�����ݼ��Ժ�length������
   
  static void InsStr(MyString<T>& x, const MyString<T>& y, int pos = length + 1);
  //��y�����뵽x��posλ�ã��ı�x������x
   
  static void DelStr(MyString<T>& x, int from, int length);
  //ɾ��x�Ĵ�from�����ݿ�ʼ�Ժ��length�����ݣ��ı�
  //x������x
   
  static void RepStr(MyString<T>& x, const MyString<T>& y, int from, int length);
  //��x���ĵ�from�����ݣ����Ժ��length - 1�����ȵ������Ӵ���y������
   
 ---------------------------------------*/ 
#ifndef _MyString_H_

#define _MyString_H_

#include <iostream>

#include "INIT_TRAITS.H"

typedef unsigned int UINT;

const UINT INIT_SIZE = 1;

const UINT INCREASEMENT = 1;

template <typename T>
class MyString
{
public:
    MyString(int size = INIT_SIZE);
    MyString(const MyString<T>& x);
    ~MyString();
    const MyString& operator=(const MyString<T>& x);
    bool operator==(const MyString<T>& x)const;
    UINT Length()const;
    MyString<T> Concat(const MyString<T>& x)const;
    MyString<T> SubStr(int from, int length)const;
    MyString<T> InsStr(const MyString<T>& x, int pos)const;
    MyString<T> DelStr(int from, int length)const;
    //MyString<T> RepStr(const MyString<T>& x, int from, int length)const;
    //friend ostream& operator <<(ostream& out, const MyString<T>& x);
    void Output()const;
    void Input();
    void Append(const T& x);
    void Clear();
    static void Concat(MyString<T>& x, const MyString<T>& y);
    static void SubStr(MyString<T>& x, int from, int length);
    static void InsStr(MyString<T>& x, const MyString<T>& y, int pos);
    static void DelStr(MyString<T>& x, int from, int length);
    static void RepStr(MyString<T>& x, const MyString<T>& y, int from, int length);
private:
	T* data;
	UINT length, size;
};

template <typename T>
MyString<T>::MyString(int size)
{
    UINT i;
	if(size <= 0) size = INIT_SIZE;
	this->size = size;
	length = 0;
	data = new T[this->size];
	for(i = 0; i < this->size; i ++)
	{
        data[i] = Init_Traits<T>::Init();
    }
}

template <typename T>
MyString<T>::MyString(const MyString<T>& x)
{
	UINT i;
	size = x.size;
	length = x.length;
	data = new T[size];
	for(i = 0; i < length; i ++)
	{
		data[i] = x.data[i];
	}
}

template <typename T>
MyString<T>::~MyString()
{
	delete [] data;
}


template <typename T>
const MyString<T>& MyString<T>::operator=(const MyString<T>& x)
{
	UINT i;
	if(this != &x)
	{
		if(size != x.size)
		{
			size = x.size;
			delete [] data;
			data = new T[size];
		}
		length = x.length;
		for(i = 0; i < length; i ++)
		{
			data[i] = x.data[i];
		}
	}
	return *this;
}


template <typename T>
bool MyString<T>::operator==(const MyString<T>& x)const
{
	bool result = false;
	UINT i;
	if(length != x.length)
	{
		result =false;
	}
	else
	{
		for(i = 0; i < length && data[i] == x.data[i]; i ++);
		if(i == length) result = true;
	}
	return result;
}
			


template <typename T>
UINT MyString<T>::Length()const
{
	return length;
}

template <typename T>
MyString<T> MyString<T>::Concat(const MyString<T>& x)const
{
	UINT add_size = size + x.size, i, j;
	MyString<T> y(add_size);
	for(i = 0; i < length; i ++)
	{
		y.data[i] = data[i];
	}
	for(j = 0; j < x.length; j ++, i ++)
	{
		y.data[i] = x.data[j];
	}
	y.length = length + x.length;
	return y;
}
		
template <typename T>
MyString<T> MyString<T>::SubStr(int from, int length)const
{
	UINT i;
	MyString<T> x(size);
	if(from > 0 && from <= this->length)
	{
		for(i = 0, from --; i < length && from < this->length; i ++, from ++)
		{
			x.data[i] = data[from];
		}
		x.length = i;
	}
	return x;
}

template <typename T>
MyString<T> MyString<T>::InsStr(const MyString<T>& x, int pos)const
{
	UINT size = x.length + this->size, i, j;
	MyString<T> y(size);
	if(pos <= 0) pos = 1;
	else if(pos > length + 1) pos = length + 1;
	y.length = x.length + length;
	for(i = 0; i < pos - 1; i ++)
	{
		y.data[i] = data[i];
	}
	for(j = 0; j < x.length; j ++, i ++)
	{
		y.data[i] = x.data[j];
	}
	for(j = pos - 1; j < length; j ++, i ++)
	{
		y.data[i] = data[j];
	}
	return y;
}



template <typename T>
MyString<T> MyString<T>::DelStr(int from, int length)const
{
	MyString x(*this);
	UINT i;
	if(from >= 1 && from <= this->length && length >= 1)
	{
        i = from + length - 1;
        if(i >= this->length)
        {
           x.length = from - 1;
        }
        else
        {
            for(from --; i < this->length; from ++, i ++)
		    {
                x.data[from] = x.data[i];
            }
            x.length = from;
		}
	}
	return x;
}


/*
template <typename T>
MyString<T> MyString<T>::RepStr(const MyString& x, int from, int length)const
{
   if(from >= 1 && from <= x.length)
   {
       
}
*/
/*
template <typename T>
ostream& operator <<(ostream& out, const MyString<T>& x)
{
    UINT i;
    for(i = 0; i < x.length; i ++)
    {
        cout << x.data[i] << ' ';
    }
    return out;
}
*/

template <typename T>
void MyString<T>::Output()const
{
    UINT i;
    for(i = 0; i < length; i ++)
    {
        cout << data[i] << ' ';
    }
}

template <typename T>
void MyString<T>::Input()
{
    T x;
    while(cin >> x, x != Init_Traits<T>::Init())
    {
        Append(x);
    } 
}

template <typename T>
void MyString<T>::Append(const T& x)
{
    T* data;
    UINT i;
    if(length >= size)
    {
        data = new T[length];
        for(i = 0; i < length; i ++)
        {
            data[i] = this->data[i];
        }
        delete [] this->data;
        size += INCREASEMENT;
        this->data = new T [size];
        for(i = 0; i < length; i ++)
        {
              this->data[i] = data[i];
        }
        delete [] data;
    }
    this->data[length] = x;
    data = NULL;
    length ++;
}

template <typename T>
void MyString<T>::Clear()
{
    length = 0;
}

template <typename T>
void MyString<T>::Concat(MyString<T>& x, const MyString<T>& y)
{
     T* data;
     UINT i, j;
     if(x.length + y.length > x.size)
     {
         data = new T[x.length + y.length];
         for(i = 0; i < x.length; i ++)
         {
             data[i] = x.data[i];
         }
         delete [] x.data;
         x.size = x.length + y.length;
         x.data = new T [x.length + y.length];
         for(i = 0; i < x.length; i ++)
         {
               x.data[i] = data[i];
         }
         delete [] data;
     }
     for(i = x.length, j = 0; j < y.length; j ++, i ++)
     {
         x.data[i] = y.data[j];
     }
     x.length += y.length;
}

template <typename T>
void MyString<T>::SubStr(MyString<T>& x, int from, int length)
{
     UINT i;
     if(from <= 0 || from > x.length || length <= 0)
     {
         x.length = 0;
     }
     else
     {
         if(from != 1)
         {
             for(i = 0, from --; i < length && from < x.length; i ++, from ++)
             {
                 x.data[i] = x.data[from];
             }
             x.length = i;
         }
         else
         {
             if(x.length > length) x.length = length;
         }
     }
}    
         
     
template <typename T>
void MyString<T>::InsStr(MyString<T>& x, const MyString<T>& y, int pos)
{
     T* data = NULL;
     UINT i, j;
     if(pos <= 0) pos = 1;
     else if(pos > x.length + 1) pos = x.length + 1;
     if(x.size < x.length + y.length)
     {
         data = new T[x.length];
         for(i = 0; i < x.length; i ++)
         {
            data[i] = x.data[i];
         }
         delete [] x.data;
         x.size += y.length;
         x.data = new T[x.size];
         for(i = 0; i < x.length; i ++)
         {
             x.data[i] = data[i];
         }
         delete [] data;
     }
     i = pos + y.length - 1;
     for(j = pos - 1; j < x.length; j ++, i ++)
     {
           x.data[i] = x.data[j];
     }
     for(i = pos - 1, j = 0; j < y.length; i ++, j ++)
     {
         x.data[i] = y.data[j];
     }
     data = NULL;
     x.length += y.length;           
}

template <typename T>
void MyString<T>::DelStr(MyString<T>& x, int from, int length)
{
     UINT start;
     if(from >= 1 && from <= x.length && length >= 1)
     {
        start = from + length - 1;
        if(start >= x.length)
        {
            x.length = from - 1;
        }
        else
        {
            for(from --; start < x.length; start ++, from ++)
            {
                x.data[from] = x.data[start];
            }
            x.length = from;
        }   
     }
}
             
template <typename T>
void MyString<T>::RepStr(MyString<T>& x, const MyString<T>& y, int from, int length)
{
     UINT start, end, i, j;
     T* data;
     if(length < 0) length = 0;
     if(x.size < x.length + y.length - length)
     {
         data = new T[x.length];
         for(i = 0; i < x.length; i ++)
         {
             data[i] = x.data[i];
         }
         delete [] x.data;
         x.size = x.length + y.length - length;
         for(i = 0; i < x.length; i ++)
         {
             x.data[i] = data[i];
         }
         delete [] data;
     }
}
     
         
     
#endif
