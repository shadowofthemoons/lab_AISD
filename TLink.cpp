#include"TLink.h"
#include"TText.h"
class TLink;
class TText;


TLink::TLink(const char* s, TLink* pN, TLink* pD)
{
	pNext = pN;
	pDown = pD;
	if (s == nullptr)
	{
		str[0] = '\0';
	}
	else
	{
		strcpy_s(str, s);
	}
}

TLink:: ~TLink()
{
}

void TLink::SetLine(const char* s)
{
	strcpy_s(str, s);
}

char* TLink::GetLine()
{
	return str;
}

void* TLink::operator new(size_t s)
{
	TLink* tmp = mem.pFree;
	if (mem.pFree != nullptr)
		mem.pFree = mem.pFree->pNext;
	return tmp;
}

void TLink::operator delete(void* p)
{
	TLink* tmp = (TLink*)p;
	tmp->pNext = mem.pFree;
	mem.pFree = tmp;
}

void TLink::InitMem(int s)
{
	mem.pFirst = (TLink*)new char[sizeof(TLink) * s];
	mem.pFree = mem.pFirst;
	mem.pLast = mem.pFirst + (s - 1);
	TLink* tmp = mem.pFree;
	for (int i = 0; i < s - 1; i++)
	{
		tmp->str[0] = '\0';
		tmp->pNext = tmp + 1;
		tmp++;
	}
	tmp->str[0] = '\0';
	mem.pLast->pNext = nullptr;
}

void TLink::PrintFree2()
{
	/*TLink* tmp = mem.pFirst;
	for (int i = 0; i < 40; i++)
	{
		cout << i << "  " << tmp[i].str << endl;
	}*/
	cout << endl;
	int i = 1;
	for (TLink* tmp = mem.pFree;tmp!=nullptr; tmp = tmp->pNext)
	{
		cout << i << "  " << tmp->str << endl;
		i++;
	}
}
void TLink::MemClean(TText& t)
{
	for (t.Reset(); !t.IsEnd(); t.GoNext())
		t.MarkCurr();
	TLink* tmp;
	tmp = mem.pFree;
	while (tmp != mem.pLast)
	{
		tmp->flag = true;
		tmp = tmp->pNext;
	}
	tmp->flag = true;
	tmp = mem.pFirst;
	while (tmp != mem.pLast)
	{
		if (!tmp->flag)
		{
			TLink* buf = mem.pFree;
			mem.pFree = tmp;
			mem.pFree->pNext = buf;
		}
		tmp->flag = false;
		tmp = tmp++;
	}
	if (!tmp->flag)
	{
		TLink* buf = mem.pFree;
		mem.pFree = tmp;
		mem.pFree->pNext = buf;
	}
	tmp->flag = false;
}

