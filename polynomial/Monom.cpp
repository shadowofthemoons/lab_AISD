#include "Monom.h"
#include <iostream>
using namespace std;

TMonom::TMonom(int cval, int pval)
{
	coeff = cval;
	power = pval;
}

void TMonom::SetCoeff(int cval)
{
	coeff = cval;
}

int TMonom::GetCoeff(void)
{
	return coeff;
}

void TMonom::SetPower(int pval)
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

int TMonom:: operator < (const TMonom &tm)
{
	return power < tm.power;
}

int TMonom:: operator > (const TMonom &tm)
{
	return power > tm.power;
}

int TMonom:: operator == (const TMonom &tm)
{
	return power == tm.power;
}

ostream & operator << (ostream & out, TMonom &m)
{
	out << m.GetCoeff() << "  " << m.GetPower() << endl;
	return out;
}

istream & operator >> (istream & in, TMonom &m)
{
	int c, p;
	in >> c >> p;
	m.SetCoeff(c);
	m.SetPower(p);
	return in;
}