#pragma once
#include <iostream>
using namespace std;

class TMonom 
{
	int coeff;   // коэффициент монома
	int power;   // свертка степеней
public:
	TMonom(int cval = 0, int pval = 0);
	void SetCoeff(int cval);
	int GetCoeff();
	void SetPower(int ival);
	int GetPower();
	TMonom & operator = (const TMonom &tm);
	int operator < (const TMonom &tm);
	int operator > (const TMonom &tm);
	int operator == (const TMonom &tm);
	friend istream & operator >> (istream& in, TMonom & m);
	friend ostream & operator << (ostream& out, TMonom & m);
};



