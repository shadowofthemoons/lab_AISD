#include "DatLink.h"
#include <iostream>
using namespace std;

TDatLink::TDatLink(TDatLink * n, TMonom & m)
{
	next = n;
	mon = m;
}

TDatLink * TDatLink::GetNext()
{
	return next;
}

void TDatLink::SetNext(TDatLink * n)
{
	next = n;
}

TMonom * TDatLink::GetMonom()
{
	return &mon;
}

void TDatLink::SetMonom(TMonom & m)
{
	mon = m;
}

void TDatLink::SetCoefMonom(int c)
{
	mon.SetCoeff(c);
}