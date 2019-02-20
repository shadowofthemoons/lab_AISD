#pragma once
#include "DatLink.h"

class THeadRing
{
	TDatLink * head;
	int n;
public:
	THeadRing();
	void AddLink(TMonom & m);
	friend ostream & operator << (ostream & out, THeadRing & h);
	friend istream & operator >> (istream & in, THeadRing & h);
};

