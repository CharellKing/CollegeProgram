/*---------STACK.H----------
  此为栈：
  操作函数：
  STACK();//构造一个空栈，length = 0；
  void Clear();//清空站内的数据
  bool IsEmpty();//判断栈是否为空
  int Length();//判断栈内的数据个数
  T& Top();//返回栈顶部的元素，并可以修改
  void Push(const T& e);//将数据e添加到栈顶
  T Pop();//推出栈顶元素并且返回其元素
  STACK<T> Traverse(T (*Visit)(const T x));//将栈里的元素全部经过Visit函数的处理
  void Display();//显示栈里所有元素
  数据成员：
  clist//为一个循环链表的对象
  length//为栈中数据的个数
---------------------------*/
#ifndef _STACK_H_

#define _STACK_H_

#include "C_LINKLIST.H"

template <typename T>
class STACK
{
public:
    STACK();
    void Clear();
    bool IsEmpty();
    int Length();
    T& Top();
    void Push(const T& e);
    T Pop();
    STACK<T> Traverse(T (*Visit)(const T x));
	void Display();
protected:
    C_LINKLIST<T> clist;
    UINT length;
};

template <typename T>
STACK<T>::STACK():clist(), length(0)
{
 
}

template <typename T>
void STACK<T>::Clear()
{
    clist.Clear();
    length = 0;
}

template <typename T>
bool STACK<T>::IsEmpty()
{
     return length == 0;
}

template <typename T>
int STACK<T>::Length()
{
    return length;
}

template <typename T>
T& STACK<T>::Top()
{
    if(length != 0)
    {
        return clist.Element(length);
    }
    else
    {
        throw string("此栈为空,无栈顶元素!"); 
    }
}

template <typename T>
void STACK<T>::Push(const T& e)
{
     clist.Append(e, ++ length);
}

template <typename T>
T STACK<T>::Pop()
{
   T element;
   if(length)
   {
       element = Top();
       clist.DeleteLast();
	   length --;
   }
   else
   {
       throw string("此栈为空, 不能推出!");
   }
   return element;
} 

template <typename T>
STACK<T> STACK<T>::Traverse(T (*Visit)(const T x))    
{
    STACK<T> a(*this);
    int i;
    for(i = 1; i <= length; i ++)
    {
        a.clist.Element(i) = (*Visit)(a.clist.Element(i));
    }
    return a;
}

template <typename T>
void STACK<T>::Display()
{
	clist.Display();
}

#endif
