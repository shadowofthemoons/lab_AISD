#pragma once
#include "Monom.h"

class TDatLink
{
	TMonom mon; 
	TDatLink * next;
public:
	TDatLink(TDatLink * n, const TMonom & m);
	TDatLink * GetNext();
	TMonom * GetMonom();
	void SetNext(TDatLink * n);
	void SetMonom(const TMonom & m);
};
