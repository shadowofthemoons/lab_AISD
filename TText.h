#pragma once

#include"TLink.h"
#include<stack>
#include<fstream>
#include<iostream>
#include<Windows.h>
using namespace std;

class TText{
protected:
	TLink * pFirst, *pCurr;
	stack <TLink*>st;
public:
	TText();
	//���������
	void GoNextLink();
	void GoDownLink();
	void GoPrevLink();
	void GoFirstLink(void);
	void Reset();
	bool IsEnd();
	void GoNext();
	//�������� ������� 
	void InsNextLine(const char* s);
	void InsNextSection(const char* s);
	void InsDownLine(const char* s);
	void InsDownSection(const char* s);
	void DelNext();
	void DelDown();
	//������
	void PrintText(TLink* tmp);
	void Print();
	//��������� ��������
	void load(const char* fileName);
	void Save( const char* name);
	//
	void MarkCurr();
	TLink* GetCurr();
	//�������� ��������� ������
	void SetLine(const char* s); 
	string GetLine(void);
};
