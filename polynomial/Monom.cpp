#include "Monom.h"

TMonom::TMonom(int cval, int pval)
{
	coeff = cval;
	power = pval;
}

void TMonom::SetCoeff(int cval)
{
	coeff = cval;
}

void TMonom::SetPower(int pval)
{
	power = pval;
}

int TMonom::GetCoeff(void)
{
	return coeff;
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
	out.width(2);
	out << m.GetCoeff();
	if (m.GetPower() / 100 != 0)
	{
		out << "x^" << m.GetPower() / 100;
	}
	if ((m.GetPower() / 10) % 10 != 0)
	{
		out << "y^" << (m.GetPower() / 10) % 10;
	}
	if (m.GetPower() % 10 != 0)
	{
		out << "z^" << m.GetPower() % 10;
	}
	return out;
}

istream & operator >> (istream & in, TMonom &m)
{
	int c, p;
	in >> c >> p;
	while (c == 0 || ((p > 999 || p < 0) && p != -1))
	{
		if (c == 0)
		{
			cout << "  У монома не может быть нулевой коэффициент,";
		}
		if ((p > 999 || p < 1) && p != -1)
		{
			cout << "  Неверная свернутая степень,";
		}
		cout << " введите еще раз " << endl;
		cout << "  ";
		in >> c >> p;
	}
	m.SetCoeff(c);
	m.SetPower(p);
	return in;
}

