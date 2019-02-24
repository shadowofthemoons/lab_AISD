#pragma once
#include "DatLink.h"

class THeadRing
{
protected:
	TDatLink * head;
	int n;
public:
	THeadRing();
	~THeadRing();
	void AddLink(TMonom & m);
	void DellList();
	friend ostream & operator << (ostream & out, THeadRing & h);
	friend istream & operator >> (istream & in, THeadRing & h);
};

