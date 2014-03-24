/*------------NODE.H-------------
  此为双向链表的节点:
  数据操作：
  NODE(NODE<T>* prior = NULL, NODE<T>* next = NULL, T data = T());
  //构造函数，采用缺省，其前驱和后继被默认为NULL,
  //数据被默认为数据的默认构造或伪构造
  NODE<T>*& Prior();//返回前驱的节点
  NODE<T>*& Next();//返回后继的节点
  T& Data();//返回数据(允许其修改)
---------------------------------*/
#ifndef _NODE_H_

#define _NODE_H_

template <typename T>
class NODE
{
public:
	NODE(NODE<T>* prior = NULL, NODE<T>* next = NULL, T data = T());
	NODE<T>*& Prior();
	NODE<T>*& Next();
	T& Data();
private:
	T data;
	NODE<T>* prior;
	NODE<T>* next;
};

template <typename T>
NODE<T>::NODE(NODE<T>* prior, NODE<T>* next, T data):prior(prior), next(next), data(data)
{

}


template <typename T>
NODE<T>*& NODE<T>::Prior()
{
	return prior;
}

template <typename T>
NODE<T>*& NODE<T>::Next()
{
	return next;
}

template <typename T>
T& NODE<T>::Data()
{
	return data;
}
#endif