#ifndef _HuffmanTree_H_

#define _HuffmanTree_H_

#include <stack>

#include <string>

#include "HNODE.h"

template <typename T>
class HuffmanTree
{
public:
	HuffmanTree(const HNODE<T>* tree = NULL, int leaves = 0);
	~HuffmanTree();
	HuffmanTree(const HuffmanTree<T>& A);
	const HuffmanTree& operator =(const HuffmanTree<T>& A);
	void Set(T** data, int leaves);
	void Create();
	void EnCode(int num, stack<char>& code);
	void DeCode(char c, int& child, char& decode)const;
	void Save(ofstream* out)const;
	void Read(ifstream* in);
	void Output()const;
	int Leaves()const;
protected:
	HNODE<T>* tree;
	int leaves;
private:
    ifstream *in;
    ofstream *out;
};

template <typename T>
HuffmanTree<T>::HuffmanTree(const HNODE<T>* tree, int leaves)
{
	int i;
	this->tree = NULL;
	if(leaves < 0)
	{
		leaves = 0;
	}
	this->leaves = leaves;
	if(this->leaves > 0)
	{
		this->tree = new HNODE<T>[2 * this->leaves - 1];
	}
	for(i = 0; i < leaves; i ++)
	{
		this->tree[i] = tree[i];
	}
}

template <typename T>
HuffmanTree<T>::~HuffmanTree()
{
	if(tree != NULL)
	{
		delete [] tree;
		tree = NULL;
	}
}

template <typename T>
HuffmanTree<T>::HuffmanTree(const HuffmanTree<T>& A)
{
	int size = 2 * A.leaves - 1, i;
	leaves = A.leaves;
	tree = NULL;
	if(leaves > 0)
	{
		tree = new HNODE<T>[size];
	}
	for(i = 0; i < size; i ++)
	{
		tree[i] = A.tree[i];
	}
}

template <typename T>
const HuffmanTree<T>& HuffmanTree<T>::operator =(const HuffmanTree<T>& A)
{
	int size = 2 * A.leaves - 1, i;
	if(tree != NULL)
	{
		delete [] tree;
		tree = NULL;
	}
	leaves = A.leaves;
	if(leaves != 0)
	{
		tree = new HNODE<T>[size];
	}
	for(i = 0; i < size; i ++)
	{
		tree[i] = A.tree[i];
	}
	return *this;
}

template <typename T>
void HuffmanTree<T>::Set(T** data, int leaves)
{
	int size = 2 * leaves - 1, i;
	if(this->tree != NULL)
	{
		delete [] this->tree;
		this->tree = NULL;
	}
	this->leaves = leaves;
	if(this->leaves != 0)
	{
		this->tree = new HNODE<T>[size];
	}
	for(i = 0; i < this->leaves; i ++)
	{
		this->tree[i].data = *data[i];
	}
	for(; i < size; i ++)
	{
		this->tree[i].data.num = i;
	}
}

template <typename T>
void HuffmanTree<T>::Create()
{
	int least_pos, less_pos, size = 2 * leaves - 1, end, i;
	double least_weight, less_weight;
	for(end = leaves; end < size; end ++)
	{
		least_weight = 1e308;
		less_weight = 1e308;
		least_pos = -1;
		less_pos = -1;
		for(i = 0; i < end; i ++)
		{
			if(tree[i].parent == -1)
			{
				if(tree[i].data.weight < least_weight)
				{
					least_weight = tree[i].data.weight;
					least_pos = i;
				}
				else if(tree[i].data.weight < less_weight)
				{
					less_weight = tree[i].data.weight;
					less_pos = i;
				}
			}
		}
		tree[end].data.weight = least_weight + less_weight;
		tree[end].lchild = least_pos;
		tree[end].rchild = less_pos;
		tree[least_pos].parent = end;
		tree[less_pos].parent = end;
	}
}

template <typename T>
void HuffmanTree<T>::EnCode(int num, stack<char>& code)
{
	int parent, child;
	if(num >= 0 && num < leaves)
	{
		child = num;
		parent = tree[child].parent;
		while(parent != -1)
		{
			if(child == tree[parent].lchild)
			{
				code.push('1');
			}
			else
			{
				code.push('0');
			}
			child = parent;
			parent = tree[parent].parent;
		}
	}
}

template <typename T>
void HuffmanTree<T>::DeCode(char code, int& child, char& decode)const
{
	if(code == '1')
	{
		child = tree[child].lchild;
	}
	else
	{
		child = tree[child].rchild;
	}
	if(child < leaves)
	{
		decode = tree[child].data.c;
	}
}

template <typename T>
void HuffmanTree<T>::Save(ofstream* out)const
{
     int size, i;
     out->write((char*)&leaves, sizeof(int));
     size = leaves * 2 - 1;
     for(i = 0; i < size; i ++)
     {
         out->write((char*)&tree[i], sizeof(HNODE<T>));
     }
}

template <typename T>
void HuffmanTree<T>::Read(ifstream* in)
{
    int size, i;
    in->read((char*)&leaves, sizeof(int));
    size = leaves * 2 - 1;
    if(leaves > 0)
    {
        tree = new HNODE<T>[size];
    }
    for(i = 0; i < size; i ++)
    {
        if(in->read((char*) &tree[i], sizeof(HNODE<T>)) == NULL)
		{
			throw ("此文件不是加密文件!");
		}
    }
}

template <typename T>
void HuffmanTree<T>::Output()const
{
	int i;
	for(i = 0; i < leaves * 2 - 1; i ++)
	{
		tree[i].Output();
	}
}

template <typename T>
int HuffmanTree<T>::Leaves()const
{
	return leaves;
}

#endif
