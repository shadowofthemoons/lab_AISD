#include "TTextLink.h"
#include "TTextMem.h"

TTextLink::TTextLink(const char* s, TTextLink* pn, TTextLink* pd)
{
	next = pn;
	down = pd;
	if (s != NULL)
	{
		strcpy_s(line, s);
	}
	else line[0] = '\0';
}

TTextLink * TTextLink::GetNext()
{
	return next;
}
TTextLink * TTextLink::GetDown()
{
	return down;
}

void TTextLink::setline(const char* str)
{
	strcpy_s(line, str);
}

int TTextLink::IsAtom()
{
	return down == nullptr;
}
 
void * TTextLink::operator new(size_t size, TTextMem * mem)
{
	TTextLink* res = mem->GetNewLink();
	return res;
}

void TTextLink::operator delete(void* p)
{
	TTextLink* link = (TTextLink*)p;
	link->flag = true;
}