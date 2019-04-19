#pragma once
#include "TTextLink.h"
#include<stack>
class TTextMem
{
	TTextLink* first;
	TTextLink* last;
	TTextLink* free;
	int size;
public:
	TTextMem(unsigned long int size);
	~TTextMem();
	TTextLink* GetNewNode();
	void ReturnNode(TTextLink* node);
	void CollectGarbage();
//	void PrintMem();
	~TTextMem();
	friend class TTextLink;
};

