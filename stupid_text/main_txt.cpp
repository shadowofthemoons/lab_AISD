#include "TTextLink.h"
#include<iostream>
using namespace std;
int main()
{
	int p;
	char g[255] = {"esergwefwefsdf"};
	TTextLink a(g);
	TTextLink b(g,&a);
	TTextLink c(g, &a,&b);

	cin >> p;
//	a.print();
	//b.print();
	//c.print();
	cin >> p;
	return 0;
}