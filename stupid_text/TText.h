#pragma once
#include "TTextMem.h"
#include "TTextLink.h"
#include<sstream>
#include<fstream>
class TText
{
protected:
	TTextLink* First; // указатель корня дерева
	TTextLink* Current; // указатель текущей строки
	stack< TTextLink* > St;
	TTextMem* mem;

public:
	TText(const char* line);
	~TText();
	//добавление строк
	void InsDownLine(const char* s); // вставка строки в подуровень
	void InsNextLine(const char* s); // вставка строки в том же уровне
	//навигация
	void GoFirstLink(void); // переход к первой строке
	void GoDownLink(void); // переход к следующей строке по Down
	void GoNextLink(void); // переход к следующей строке по Next
	void GoPrevLink(void); // переход к предыдущей позиции в тексте
	void Reset(); // установить на первую звапись
	//удвление
	void DelNextLine(void); // удаление строки в том же уровне
	void DelDownLine(void); // удаление строки в подуровне
	//работа с памятью
	void MemCleaner();
	void PrintFreeLink();
	void PrintLink();
	void Print(void); // печать текста
	void Save(const char* filename);
	void load(const char* fileName); // ввод текста из файла
	//замена чтение строк
	void SetLine(const char* s); // замена текущей строки
	string GetLine(void); // чтение текущей строки
};
