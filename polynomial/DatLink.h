#pragma once
#include "Monom.h"
#include <iostream>
using namespace std;

class TDatLink
{
	TMonom mon;
	TDatLink * next;
public:
	TDatLink(TDatLink * n, TMonom & m);
	TDatLink * GetNext();
	TMonom * GetMonom();
	void SetNext(TDatLink * n);
	void SetMonom(TMonom & m);
	void SetCoefMonom(int c);
};
