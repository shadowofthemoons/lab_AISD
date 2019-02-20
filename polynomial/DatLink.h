#pragma once
#include "Monom.h"
#include <iostream>
using namespace std;

class TDatLink
{
	TMonom mon;
	TDatLink* next;
public:
	TDatLink (TDatLink * pN , TMonom &m);
	TDatLink * GetNex(); 
	void SetNext(TDatLink * pN);
	TMonom GetMonom();
	void SetMonom(TMonom & m);
};

