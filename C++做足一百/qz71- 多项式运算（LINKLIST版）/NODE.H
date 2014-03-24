/*------------------NODE.H----------------------
  这个头文件定义了一个单链表的节点NODE
  数据成员有:
  next---指向下一结点的指针
  data---为节点所携带的数据
  基本操作有：
  NODE(T, NODE* next)----拷贝构造函数，适于new运算，运用了缺省
  Next()---返回NODE*&,这样可以用于使用和修改各链表中的值
  Data()---返回T&,这样可以使用并修改节点里的数据
-----------------------------------------------*/
#ifndef _NODE_H_

#define _NODE_H_

template <typename T>
class NODE
{
public:
	/*************成员函数************/
	NODE(T data = T(), NODE* next = NULL);
	/*----------------------------------
	构造函数：
	初始化data和next
	前置条件:无
	后置条件:data赋给this->data， this->next指向next
	--------------------------------------*/
	NODE*& Next();
	/*------------------------------------
	返回this->next
	前置条件：无
	后置条件：返回this->next
	-------------------------------------*/
	T& Data();
	/*----------------------------------
	返回this->data
	前置条件：无
	后置条件：返回this->data
	-------------------------------------*/
private:
	/************成员数据***************/
	NODE* next;//下一个节点的地址默认为NULL
	T data;//此节点里的数据为T()(构造或伪构造
};



/*-----------成员函数的实现---------*/
template <typename T>
NODE<T>::NODE(T data, NODE<T>* next):data(data), next(next)
/*this->data this->next初始化*/
{
	
}

template <typename T>
NODE<T>*& NODE<T>::Next()
/*返回下一结点的地址*/
{
	return next;
}

template <typename T>
T& NODE<T>::Data()
/*返回此节点的数据*/
{
	return data;
}
#endif