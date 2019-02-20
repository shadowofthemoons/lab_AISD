#include "Monom.h"
#include "HeadRing.h"
#include "DatLink.h"
#include <iostream>
using namespace std;

int main()
{
	TMonom d,d1,d2;
	THeadRing sp;
	cin >>d>>d1>>d2;
    sp.AddLink(d);
	sp.AddLink(d1);
	sp.AddLink(d2);
    cout << sp;
	cin >> d;
	return 0;
	
}