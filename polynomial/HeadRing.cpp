#include "HeadRing.h"


THeadRing::THeadRing()
{
	n = 1;
	TMonom  m (1, -1);
	head  =  new TDatLink (nullptr, m);
	head->SetNext(head);
}

void THeadRing:: AddLink(TMonom & m)
{
	TDatLink * cur, *last;
	cur = head->GetNext();
	last = head;
	while (m < *cur->GetMonom())
	{
		cur = cur->GetNext();
		last = last->GetNext();
	}
	if (m == *cur->GetMonom())
	{
		(*cur->GetMonom()).SetCoeff(m.GetCoeff() + (*cur->GetMonom()).GetCoeff());
	}
	else
	{
		TDatLink * d = new TDatLink(cur,m);
		last->SetNext(d);
		n++;
	}
}

ostream & operator << (ostream & out, THeadRing & h)
{
	TDatLink * h1 = h.head->GetNext();
	TMonom m;
	for (int i = 0; i < h.n-1; i++)
	{
		out << *h1->GetMonom(); 
		h1 = h1->GetNext();
	}
	return out;
}


istream & operator >> (istream & in, THeadRing & h)
{
	
	return in;
}