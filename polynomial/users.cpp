#include "Monom.h"
#include<stdio.h>
#include<conio.h>
#include "HeadRing.h"
#include "DatLink.h"
#include "TPolinom.h"
#include <iostream>
using namespace std;

int main()
{
	TPolinom p, p1, p2;
	setlocale(LC_ALL, "Russian");
	cin >> p >> p1;
	cout.width(42);
	cout << endl << "Введенные полиномы" << endl << endl;
	cout << "p =" << p;
	cout << "p1 =" << p1;
	cout.width(70);
	p2 = p1 + p;
	cout << endl<<"Сложение с использование дополнительной памяти" <<endl<< endl;
	cout <<  "p+p1 =" << p2 ;
	cout <<  "p =" << p;
	cout <<  "p1 =" << p1;
	p += p1;
	cout.width(72);
	cout << endl<<"Сложение без использования дополнительной памяти" <<endl<< endl;
	cout <<  "p1+p =" << p;
	cout <<  "p =" << p;
	cout <<  "p1 =" << p1;
	_getch();
	return 0;
}