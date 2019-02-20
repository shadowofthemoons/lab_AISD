#include "DatLink.h"



TDatLink::TDatLink(TDatLink * pN , TMonom &m)
{
	next = pN;
	mon = m;
}

TDatLink * TDatLink::GetNex()
{
	return next;
}

void TDatLink::SetNext(TDatLink * pN)
{
	next = pN;
}

TMonom TDatLink::GetMonom()
{
	return mon;
}

void TDatLink::SetMonom(TMonom & m)
{
	mon = m;
}