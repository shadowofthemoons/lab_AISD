#pragma once
#include<iostream>
using namespace std;
class TTextLink {
protected:
	char line[255]; // ���� ��� �������� ������ ������
	TTextLink* next;
	TTextLink* down;// ��������� �� ���. ������� � �� ����������
	bool flag;
//	static TTextMem MemHeader; // ������� ���������� �������
public:
	//void print();
	TTextLink* GetNext();
	TTextLink* GetDown();
	int IsAtom();
	TTextLink(char * s = nullptr, TTextLink* pn = nullptr, TTextLink* pd = nullptr);
	friend class TTextMem;
};

/*


static TTextMem MemHeader; // ������� ���������� �������
public:
static void InitMemSystem (int size=MemSize); // ������������� ������
static void PrintFreeLink (void); // ������ ��������� �������
void * operator new (size_t size); // ��������� �����
void operator delete (void *pM); // ������������ �����
static void MemCleaner (const TText &txt); // ������ ������

PTDatValue GetCopy() {return new TTextLink(Str,pNext,pDown);}

*/




/*
	class TextNode {
	public:
		TextNode() {
			next = nullptr;
			down = nullptr;
		}
		TextNode(const char val[NodeStrLen]) :TextNode()
		{
			for (int i = 0; i < NodeStrLen; i++) {
				value[i] = val[i];
			}
		}
		char value[NodeStrLen];
		bool IsDeleted;
		TextNode* next;
		TextNode* down;
		void* operator new(size_t size, MemManager* mm);
		void operator delete(void *p);
		void operator delete(void * p, MemManager * mm);
		bool IsAtom() { return down == nullptr; }
	};*/