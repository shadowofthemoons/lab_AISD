#include "DatLink.h"

TDatLink::TDatLink(TDatLink * n, const TMonom & m)
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

void TDatLink::SetMonom(const TMonom & m)
{
	mon = m;
}
