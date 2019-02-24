#include "HeadRing.h"

THeadRing::THeadRing()
{
	n = 1;
	TMonom  m(1, -1);
	head = new TDatLink(nullptr, m);
	head->SetNext(head);
}

void THeadRing::AddLink(TMonom & m)
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
		int coef = m.GetCoeff() + (*cur->GetMonom()).GetCoeff();
		if (coef == 0)
		{
			last->SetNext(cur->GetNext());
			delete cur;
			n--;
		}
		else
		{
			(*cur->GetMonom()).SetCoeff(coef);
		}
	}
	else
	{
		TDatLink * d = new TDatLink(cur, m);
		last->SetNext(d);
		n++;
	}
}

ostream & operator << (ostream & out, THeadRing & h)
{
	if (h.n == 1)
	{
		out << "0";
	}
	TDatLink * h1 = h.head->GetNext();
	TMonom m;
	for (int i = 0; i < h.n - 1; i++)
	{
		if (i!=0)cout << " +";
		out << *h1->GetMonom();
		h1 = h1->GetNext();
	}
	out << endl;
	return out;
}

istream & operator >> (istream & in, THeadRing & h)
{
	TMonom m;
	cout << "Введите мономы полинома " << endl;
	cout << "Вводите коэффициент и свернутую степень" << endl;
	cout << "Если вы хотите закончить ввод мономов, введите -1 в свернутой степени" << endl;
	in >> m;
	while (m.GetPower() != -1)
	{
		h.AddLink(m);
		in >> m;
	}
	return in;
}

THeadRing::~THeadRing()
{
	TDatLink * cur, *last;
	cur = head->GetNext();
	last = head;
	for (int i = 0; i < n; i++)
	{
		delete last;
		last = cur;
		cur = cur->GetNext();
	}
}

void THeadRing::DellList()
{
	TDatLink * cur, *last;
	cur = head->GetNext();
	last = head;
	for (int i = 0; i < n; i++)
	{
		delete last;
		last = cur;
		cur = cur->GetNext();
	}
}