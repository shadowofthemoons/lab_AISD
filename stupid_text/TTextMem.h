class TTextLink;
#pragma once
#include "TTextLink.h"
#include<iostream>
#include<stack>
#include<stack>
using namespace std;

class TTextMem {
protected:
	TTextLink* first;
	TTextLink* last;
	TTextLink* free;
	int size;
public:
	TTextMem(int size);
	~TTextMem();
	TTextLink* GetNewLink();
	void ReturnLink(TTextLink* node);
	void MemCleaner();
	void PrintFreeLink();
	void PrintLink();
	friend class TTextLink;
};

class TTextLink {
protected:
	char line[1000]; // поле для хранения строки текста
	TTextLink* next;
	TTextLink* down;// указатели по тек. уровень и на подуровень
	bool flag;
public:
	TTextLink(const char* s = nullptr, TTextLink* pn = nullptr, TTextLink* pd = nullptr);
	TTextLink* GetNext();
	TTextLink* GetDown();
	void setline(const char* str);
	int IsAtom();
	void * operator new (size_t size, TTextMem* mem); // выделение звена
	void operator delete (void *pM); // освобождение звена
	friend class TTextMem;
	friend class TText;
};





