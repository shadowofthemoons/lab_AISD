#include "TTextLink.h"



TTextLink * TTextLink::GetNext()
{
	return next;
}

TTextLink * TTextLink::GetDown()
{
	return down;
}

int TTextLink::IsAtom()
{
	return down == nullptr;
}

TTextLink::TTextLink(char * s, TTextLink* pn, TTextLink* pd)
{
	next = pn; 
	down = pd;
	if (s != NULL)
	{
		strcpy_s(line, s);
	}
	else line[0] = '\0';
}




/*
void TTextLink::print()
{
	cout << down << endl;
	cout << next << endl;
	for (int i=0;line[i]!='\0';i++)
	{
		cout << line[i];
	}
	cout <<"    111"<< endl;

}*/