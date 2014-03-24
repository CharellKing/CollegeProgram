#include <iostream>

using namespace std;

#include <fstream>

#include <string>

#include "EncriptText.H"

EncriptText::EncriptText()
{
	intext = NULL;
	outtext = NULL;
}

EncriptText::~EncriptText()
{
	if(intext != NULL)
	{
		delete [] intext;
	}
	if(outtext != NULL)
	{
		delete [] outtext;
	}
}

EncriptText::EncriptText(const EncriptText& A)
{
    avl_tree = A.avl_tree;
    huffman_tree = A.huffman_tree;
}

const EncriptText& EncriptText::operator = (const EncriptText& A)
{
    avl_tree = A.avl_tree;
    huffman_tree = A.huffman_tree;
	return *this;
}

void EncriptText::CreateAVL(const string& filename)
{
	CharWeight a;
	AVLNODE<CharWeight>* result;
	intext = new ifstream(filename.c_str(), ios::in | ios::binary);
	if(!(*intext))
	{
		
		throw string("���ܴ򿪴���Ҫ���ܵ��ļ�!");
	}
	else
	{
		cout << "���ڼ�����,���Ե�......";
		while(intext->read((char*) &a.c, sizeof(char)))
		{
			result = avl_tree.SetInsert(a, &CompareWeight);
			result->data.weight ++;
		}
	}
	intext->close();
	delete [] intext;
	intext = NULL;
}

void EncriptText::CreateHuffman()
{
    int i;
	CharWeight** char_weight_list;
	int leaves;
	avl_tree.GetData(char_weight_list);
	leaves = avl_tree.DataNumber();
	for(i = 0; i < leaves; i ++)
	{
        char_weight_list[i]->num = i;
    }
	huffman_tree.Set(char_weight_list, leaves);
	delete [] char_weight_list;
	huffman_tree.Create();
}

void EncriptText::EnCode(const string& filename)
{
    string encode_file;
    stack<char> code;
    CharWeight a;
	do
	{
		cout << "������洢���ĵ��ļ���(����Ҫ��չ��):";
		cin >> encode_file;
		encode_file += ".encode";
		if(filename == encode_file)
		{
			cout << "����������ļ����ͻ,����������!" << endl;
		}
	}
	while(filename == encode_file);
    CreateAVL(filename);
    CreateHuffman();
    outtext = new ofstream(encode_file.c_str(), ios::out | ios::binary);
	outtext->close();
    delete [] outtext;
    outtext = new ofstream(encode_file.c_str(), ios::out | ios::binary);
    intext = new ifstream(filename.c_str(), ios::in | ios::binary);
	huffman_tree.Save(outtext);
    while(intext->read(&a.c, sizeof(char)))
    {
        avl_tree.Find(a, &CompareWeight);
        huffman_tree.EnCode(a.num, code);
        while(!code.empty())
        {
            outtext->write(&code.top(), sizeof(char));
            code.pop();
        }
    }
    intext->close();
    outtext->close();
    delete [] intext;
    delete [] outtext;
    intext = NULL;
    outtext = NULL;
}

void EncriptText::DeCode(const string& filename)
{
	string decode_file = filename;
	int child, huffman_tree_root;
	HNODE<CharWeight> a;
	char code, decode;
	cout << "������洢���ĵ��ļ���(����Ҫ��չ��):";
	do
	{
		cin >> decode_file;
		decode_file += ".decode";
		if(filename == decode_file)
		{
			cout << "����������ļ����ͻ������������!" << endl;
		}
	}
	while(filename == decode_file);
	intext = new ifstream(filename.c_str(), ios::in | ios::binary);
	if(!(*intext))
	{
        throw string("���ܴ򿪴�����!");
	}
	else
	{
		cout << "���ڽ�����,���Ե�......";
		huffman_tree.Read(intext);
		huffman_tree_root = huffman_tree.Leaves() * 2 - 2;
		outtext = new ofstream(decode_file.c_str(), ios::out | ios::binary);
		outtext->close();
		delete [] outtext;
		outtext = new ofstream(decode_file.c_str(), ios::out | ios::binary);
		child = huffman_tree_root;
		while(intext->read(&code, sizeof(char)))
		{
			if(code != '0' && code != '1')
			{
				throw ("���ļ������ڼ����ļ�!");
			}
			huffman_tree.DeCode(code, child, decode);
			if(child < huffman_tree.Leaves())
			{
				child = huffman_tree_root;
				outtext->write(&decode, sizeof(char));
			}
        }
	}
	intext->close();
	outtext->close();
	delete [] intext;
	delete [] outtext;
	outtext = NULL;
	intext = NULL;
}

void EncriptText::Usually(const string& filename)
{
	string usual_filename;
	char c;
	intext = new ifstream(filename.c_str(), ios::in | ios::binary);
	if(!*intext)
	{
		throw string("���ܴ򿪴���Ҫת�����ļ�!");
	}
	else
	{
		cout << "����ת����,���Ե�......";
		usual_filename = filename.substr(0, 4) + ".txt";
		outtext = new ofstream(usual_filename.c_str(), ios::out);
		if(!*outtext)
		{
			throw string("�����洢�ļ�ʧ��!");
		}
		else
		{
			while(intext->read(&c, sizeof(char)))
			{
				outtext->write(&c, sizeof(char));
			}
		}
		delete [] outtext;
		outtext = NULL;
	}
	delete [] intext;
	intext = NULL;
}

void EncriptText::Binary(const string& filename)
{
	string binary_filename;
	char c;
	intext = new ifstream(filename.c_str(), ios::in);
	if(!*intext)
	{
		throw string("���ܴ򿪴���Ҫת�����ļ�!");
	}
	else
	{
		cout << "����ת����,���Ե�......";
		binary_filename = filename.substr(0, 4) + ".dat";
		outtext = new ofstream(binary_filename.c_str(), ios::out | ios::binary);
		if(!*outtext)
		{
			throw string("�����洢�ļ�ʧ��!");
		}
		else
		{
			while(intext->read(&c, sizeof(char)))
			{
				outtext->write(&c, sizeof(char));
			}
		}
		delete [] outtext;
		outtext = NULL;
	}
	delete [] intext;
	intext = NULL;
}
