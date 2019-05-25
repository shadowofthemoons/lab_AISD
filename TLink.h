#pragma once
#include<stdlib.h>
#include<string.h>
class TText;
class TLink;

struct TMem
{
	TLink* pFirst, * pFree, * pLast;
};
class TLink
{
public:
	char str[100];
	TLink* pNext,* pDown;
	static TMem mem;
	bool flag;
	TLink(const char* s = nullptr, TLink* pN = nullptr, TLink* pD = nullptr);
	~TLink();
	void SetLine(const char* s);
	char* GetLine();
	void* operator new(size_t s);
	void operator delete(void* p);
	static void InitMem(int s);
	static void PrintFree2();
	static void MemClean(TText& t);
	 
};

