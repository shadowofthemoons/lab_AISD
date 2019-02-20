#pragma once
#include <iostream>
using namespace std;


class TMonom  {
	int coeff;   // коэффициент монома
	int power;   // свертка степеней
public:
	TMonom (int cval = 1, int pval = 0);
	void SetCoeff (int cval);
	int GetCoeff (void);
	void SetPower(int ival);
	int GetPower(void);
	TMonom & operator = (const TMonom &tm);




	//int operator == (const TMonom &tm);
	//int operator < (const TMonom &tm);

	/*
	int operator==(const TMonom &tm) {
		return (Coeff == tm.Coeff) && (Index == tm.Index);
	}
	int operator<(const TMonom &tm) {
		return Index < tm.Index;
	}*/
};


