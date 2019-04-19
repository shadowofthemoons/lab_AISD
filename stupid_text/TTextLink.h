#pragma once
#include<iostream>
using namespace std;
class TTextLink {
protected:
	char line[255]; // поле для хранения строки текста
	TTextLink* next;
	TTextLink* down;// указатели по тек. уровень и на подуровень
	bool flag;
//	static TTextMem MemHeader; // система управления памятью
public:
	//void print();
	TTextLink* GetNext();
	TTextLink* GetDown();
	int IsAtom();
	TTextLink(char * s = nullptr, TTextLink* pn = nullptr, TTextLink* pd = nullptr);
	friend class TTextMem;
};

/*


static TTextMem MemHeader; // система управления памятью
public:
static void InitMemSystem (int size=MemSize); // инициализация памяти
static void PrintFreeLink (void); // печать свободных звеньев
void * operator new (size_t size); // выделение звена
void operator delete (void *pM); // освобождение звена
static void MemCleaner (const TText &txt); // сборка мусора

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