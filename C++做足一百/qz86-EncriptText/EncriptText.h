#ifndef _EncriptText_H_

#define _EncriptText_H_

#include <fstream>

using namespace std;

#include "CharWeight.h"

#include "AVLTREE.H"

#include "HuffmanTree.h"

class EncriptText
{
public:
	EncriptText();
	~EncriptText();
    EncriptText(const EncriptText& A);
    const EncriptText& operator = (const EncriptText& A);
    void CreateAVL(const string& filename);
    void CreateHuffman();
	void EnCode(const string& filename);
	void DeCode(const string& filename);
	void Show();
	void Usually(const string& filename);
	void Binary(const string& filename);
protected:
	AVLTREE<CharWeight> avl_tree;
	HuffmanTree<CharWeight> huffman_tree;
private:
    ifstream *intext;
    ofstream *outtext;
};

#endif
