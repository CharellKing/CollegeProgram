#ifndef _BST_H_


#define _BST_H_

#include <list>

#include "NODE.H"

template <typename T>
class BST
{
public:
	BST();
	~BST();
	BST(const BST<T>& x);
	const BST<T>& operator =(const BST<T>& x);
	void Insert(const T& x);
	void Display()const;
	void Remove(const T& x);
	int Tree_type1()const;//方法一：判断二叉树的类型，满二叉树(0), 完全二叉树(1), 非完全二叉树(2), 空树(3)
	int Tree_type2()const;//方法二:判断二叉树的类型，满二叉树(0), 完全二叉树(1), 非完全二叉树(2), 空树(3)
private:
	static void Tree_type(const NODE<T>* root, int& height, int& balance);
	static void Display(const NODE<T>* root);
	static void Copy(NODE<T>*& accept, const NODE<T>* give);
	static void Destroy(NODE<T>*& root);
	static void Insert(NODE<T>*& root, const T& x);
	static void Remove(NODE<T>* parent, NODE<T>*& root, NODE<T>* remove, int orient, const T& x);
	static void Child(NODE<T>* parent, int orient, NODE<T>*& child);
	static void Swap(T& x, T& y);
	NODE<T>* root;
	int data_num;
};

template <typename T>
BST<T>::BST()
{
	root = NULL;
	data_num = 0;
}

template <typename T>	
BST<T>::~BST()
{
	Destroy(root);
}

template <typename T>
BST<T>::BST(const BST<T>& x)
{
	Copy(root, x.root);
	data_num = x.data_num;
}

template <typename T>
const BST<T>& BST<T>::operator =(const BST<T>& x)
{
	if(this != &x)
	{
		Destroy(root);
		Copy(root, x.root);
		data_num = x.data_num;
	}
	return *this;
}

template <typename T>
void BST<T>::Destroy(NODE<T>*& root)
{
	if(root)
	{
		Destroy(root->left);
		Destroy(root->right);
		delete [] root;
		root = NULL;
	}
}

template <typename  T>
void BST<T>::Copy(NODE<T>*& root_one, const NODE<T>* root_other)
{
	if(root_other != NULL)
	{
		root_one = new NODE<T>(root_other->data);
		Copy(root_one->left, root_other->left);
		Copy(root_one->right, root_other->right);
	}
}

template <typename T>
void BST<T>::Insert(const T& x)
{
	Insert(root, x);
}

template <typename T>
void BST<T>::Display()const
{
	Display(root);
}

template <typename T>
void BST<T>::Remove(const T& x)
{
	Remove(NULL, root, NULL, -1, x);
}

template <typename T>
int BST<T>::Tree_type1()const
{
	int height, balance;
	Tree_type(root, height, balance);
	if(height == 0 && balance == 0)
	{
		balance = 3;
	}
	return balance;
}

template <typename T>
int BST<T>::Tree_type2()const
{
	list<NODE<T>*> a;
	list<NODE<T>*>::iterator begin, end;
	int flag = 3, balance, i, n;//1 2 3
	if(root == NULL)
	{
		balance = 3;
	}
	else
	{
		a.push_back(root);
		while(flag != -1 && !a.empty())
		{
			if(flag == 2) flag = 2;
			if(flag == 3) flag = 0;
			for(begin = a.begin(), i = 0, n = a.size(); i < n && flag != -1; begin ++, i ++)
			{
				if((*begin)->left == NULL && (*begin)->right == NULL)
				{
					if(flag == 0 || flag == 1) flag = 1;
					else flag = 2;
				}
				else if((*begin)->left != NULL && (*begin)->right == NULL)
				{
					a.push_back((*begin)->left);
					if(flag == 0 || flag == 3) flag = 2;
					else flag = -1;
				}
				else if((*begin)->left == NULL && (*begin)->right != NULL)
				{
					flag = -1;
				}
				else
				{
					if(flag == 0 || flag == 3) flag = 3;
					else flag = -1;
					a.push_back((*begin)->left);
					a.push_back((*begin)->right);
				}
			}
			if(flag != -1)
			{
				a.erase(a.begin(), begin);
			}
		}
		if(flag == -1) balance = 2;
		else if(flag == 2) balance = 1;
		else balance = 0;
	}
	return balance;
}
	
template <typename T>
void BST<T>::Tree_type(const NODE<T>* root, int& height, int& balance)
{
	int left_height, right_height, left_balance, right_balance, delt_height;
	if(root == NULL)
	{
		height = 0;
		balance = 0;
	}
	else
	{
		Tree_type(root->left, left_height, left_balance);
		if(left_balance != 2)
		{
			Tree_type(root->right, right_height, right_balance);
			if(right_balance != 2)
			{
				delt_height = left_height - right_height;
				if(delt_height < 0 || delt_height > 1)
				{
					balance = 2;
				}
				else if(delt_height == 1)
				{
					balance = right_balance + 1;
				}
				else
				{
					balance = (right_balance >= left_balance ? right_balance : 2);
				}
			}
			else
			{
				balance = 2;
			}
			height = (left_height > right_height ? left_height : right_height) + 1;
		}
		else
		{
			balance = 2;
		}
	}
}

template <typename T>
void BST<T>::Display(const NODE<T>* root)
{
	if(root != NULL)
	{
		Display(root->left);
		cout << root->data << ' ';
		Display(root->right);
	}
}

template <typename T>
void BST<T>::Insert(NODE<T>*& root, const T& x)
{
	if(root == NULL)
	{
		root = new NODE<T>(x);
	}
	else
	{
		if(root->data >= x)
		{
			Insert(root->left, x);
		}
		else
		{
			Insert(root->right, x);
		}
	}
}

template <typename T>
void BST<T>::Remove(NODE<T>* parent, NODE<T>*& root, NODE<T>* remove, int orient, const T& x)
{
	NODE<T>* p;
	if(root)
	{
		if(remove == NULL)
		{
			if(root->data > x)
			{
				Remove(root, root->left, remove, 0, x);
			}
			else if(root->data < x)
			{
				Remove(root, root->right, remove, 1, x);
			}
			else
			{
				if(root->left == NULL)
				{
					if(orient != -1)
					{
						p = root->right;
						delete [] root;
						if(orient == 1) parent->right = p;
						else parent->left = p;
						root = p;
					}
					else
					{
						parent = root;
						root = root->right;
						delete [] parent;
					}

				}
				else if(root->right == NULL)
				{
					if(orient != -1)
					{
						p = root->left;
						delete [] root;
						if(orient == 1) parent->right = p;
						else parent->left = p;
						root = p;
						orient = 0;
					}
					else
					{
						p = root;
						root = root->left;
						delete [] p;
					}
					Remove(parent, root, NULL, orient, x);
				}
				else
				{
					Remove(root, root->right, root, 1, x);
					Remove(root, root->left, NULL, 0, x);
				}
			}
		}
		else
		{
			Remove(root, root->left, remove, 0, x);
			if(remove != NULL && remove->data == x)
			{
				Swap(remove->data, root->data);
				Remove(parent, root, NULL, orient, x);
			}
		}
	}
}

template <typename T>
void BST<T>::Child(NODE<T>* parent, int orient, NODE<T>*& child)
{
	if(orient == 0)
	{
		child = parent->left;
	}
	else if(orient == 1)
	{
		child = parent->right;
	}
	else
	{
		child = NULL;
	}
}

template <typename T>
void BST<T>::Swap(T& x, T& y)
{
	T z;
	z = x;
	x = y;
	y = z;
}

#endif