#include "TTextMem.h"
#include "TTextLink.h"
#include "TText.h"
#include <cstdio>
#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	char line[1000];
	TText text("Header");
	int p;
	bool exit = false;
	while (!exit)
	{
		cout << endl;
		cout << "1)Вставка в том же уровне " << "2)Вставка в подуровне " << "3)удалить следуюший " << "4)Удалить нижний" << endl;
		cout << "5)Дальше                  " << "6)Вниз                " << "7)Вверх             " << "8)В начало"  << endl;
		cout << "9)Сохранить               " << "10)Загрузить          " << "11)Замена строки    " << "12)чтение текущей строки" << endl;
		cout << "13)Печать                 " << "14)Печать памяти      " << "15)Cборка мусора    " << "16)Выход " <<endl;
		cin >> p;
		switch (p) {
		case 1:
			cin.get();
			cout << "Введите строку" << endl;
			gets_s(line, 1000);
			text.InsNextLine(line);
			break;
		case 2:
			cin.get();
			cout << "Введите строку" << endl;
			gets_s(line, 1000);
			text.InsDownLine(line);
			break;
		case 3:
			text.DelNextLine();
			break;
		case 4:
			text.DelDownLine();
			break;
		case 5:
			text.GoNextLink();
			break;
		case 6:
			text.GoDownLink();
			break;
		case 7:
			text.GoPrevLink();
			break;
		case 8:
			text.GoFirstLink();
			break;
		case 9:
			text.Save("text.txt");
			break;
		case 10:
			text.load("text.txt");
			break;
		case 11:
			cin.get();
			cout << "Введите строку" << endl;
			gets_s(line, 1000);
			text.SetLine(line);
			break;
		case 12:
			cout << text.GetLine() << endl;
			break;
		case 13:
			text.Print();
			break;
		case 14:
			text.PrintLink();
			break;
		case 15:
			text.MemCleaner();
			break;
		case 16:
			exit = true;
			break;
		}
	}
	return 0;
}


