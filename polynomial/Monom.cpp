#include "Monom.h"

TMonom::TMonom (int cval, int pval)
{
	coeff = cval;
	power = pval;

}

void TMonom::SetCoeff(int cval)
{
	coeff = cval;
}

int TMonom:: GetCoeff (void)
{
	return coeff; 
}

void TMonom:: SetPower(int pval)
{
	power = pval; 
}

int TMonom::GetPower(void)

{ 
	return power;
}

TMonom& TMonom::operator=(const TMonom &m)
{
	coeff = m.coeff;
	power = m.power;
	return *this;
}