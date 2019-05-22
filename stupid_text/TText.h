#pragma once
#include "TTextMem.h"
#include "TTextLink.h"
#include<sstream>
#include<fstream>
class TText
{
protected:
	TTextLink* First; // ��������� ����� ������
	TTextLink* Current; // ��������� ������� ������
	stack< TTextLink* > St;
	TTextMem* mem;

public:
	TText(const char* line);
	~TText();
	//���������� �����
	void InsDownLine(const char* s); // ������� ������ � ����������
	void InsNextLine(const char* s); // ������� ������ � ��� �� ������
	//���������
	void GoFirstLink(void); // ������� � ������ ������
	void GoDownLink(void); // ������� � ��������� ������ �� Down
	void GoNextLink(void); // ������� � ��������� ������ �� Next
	void GoPrevLink(void); // ������� � ���������� ������� � ������
	void Reset(); // ���������� �� ������ �������
	//��������
	void DelNextLine(void); // �������� ������ � ��� �� ������
	void DelDownLine(void); // �������� ������ � ���������
	//������ � �������
	void MemCleaner();
	void PrintFreeLink();
	void PrintLink();
	void Print(void); // ������ ������
	void Save(const char* filename);
	void load(const char* fileName); // ���� ������ �� �����
	//������ ������ �����
	void SetLine(const char* s); // ������ ������� ������
	string GetLine(void); // ������ ������� ������
};
