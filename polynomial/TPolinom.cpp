#include "TPolinom.h"

TPolinom::TPolinom() :THeadRing()
{
}

TPolinom::TPolinom(const TPolinom &p)
{
	n = 1;
	TMonom  m(1, -1);
	head = new TDatLink(nullptr, m);
	head->SetNext(head);
	TDatLink * h = p.head->GetNext();
	for (int i = 1; i < p.n; i++)
	{
		this->AddLink(*h->GetMonom());
		h = h->GetNext();
	}
}

TPolinom& TPolinom:: operator+(const TPolinom &p)
{
	TPolinom * pol = new TPolinom(*this);
	TDatLink * h = p.head->GetNext();
	for (int i = 1; i < p.n; i++)
	{
		pol->AddLink(*h->GetMonom());
		h = h->GetNext();
	}
	return *pol;
}

TPolinom& TPolinom:: operator+=(const TPolinom &p)
{
	TDatLink * h = p.head->GetNext();
	for (int i = 1; i < p.n; i++)
	{
		this->AddLink(*h->GetMonom());
		h = h->GetNext();
	}
	return *this;
}

TPolinom & TPolinom:: operator=(const TPolinom &q)
{
	if (this == &q)
	{
		return *this;
    }
	this->DellList();
	n = 1;
	TMonom  m(1, -1);
	head = new TDatLink(nullptr, m);
	head->SetNext(head);
	TDatLink * h = q.head->GetNext();
	for (int i = 1; i < q.n; i++)
	{
		this->AddLink(*h->GetMonom());
		h = h->GetNext();
	}
	return *this;
}
