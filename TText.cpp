#include"TText.h"
using namespace std;


TText::TText()
{
	pCurr=pFirst = new TLink("heder");
}

void TText::GoNextLink() {
	if (pCurr->pNext != nullptr)
	{
		pCurr = pCurr->pNext;
	}
}


void TText::GoDownLink() {
	if (pCurr->pDown != nullptr)
	{
		st.push(pCurr);
		pCurr = pCurr->pDown;
	}
}

void TText::GoPrevLink() {
	if (!st.empty())
	{
		pCurr = st.top();
		st.pop();
	}
}

void TText::GoFirstLink(void)
{
	while (!st.empty())
	{
		st.pop();
	}
	pCurr = pFirst;

}

void TText::InsNextLine(const char* s) {
	TLink* p = new TLink(s, pCurr->pNext, nullptr);
	pCurr->pNext = p;
}

void TText::InsNextSection(const char* s) {
	TLink* p = new TLink(s, nullptr, pCurr->pNext);
	pCurr->pNext = p;
}

void TText::InsDownLine(const char* s) {
	TLink* p = new TLink(s, pCurr->pDown, nullptr);
	pCurr->pDown = p;
}

void TText::InsDownSection(const char* s) {
	TLink* p = new TLink(s, nullptr, pCurr->pDown);
	pCurr->pDown = p;
}

void TText::DelNext() {
	if (pCurr->pNext != nullptr)
	{
		TLink* p = pCurr->pNext;
		pCurr->pNext = p->pNext;
		delete p;
	}
}

void TText::DelDown() {
	if (pCurr->pDown != nullptr)
	{
		TLink* p = pCurr->pDown;
		pCurr->pDown = p->pDown;
		delete p;
	}
}
void TText::Print()
{
     PrintText(pFirst);
}

void TText::PrintText(TLink* tmp)
{
	stack< TLink* > stec;
	TLink* c = tmp;
	int level = 0;
	while (1)
	{
		if (c != nullptr)
		{
			cout << endl;
			for (int i = 0; i < level; i++)
			{
				cout << "       ";
			}
			cout  <<c->str << ' '; 
			stec.push(c);
			level++;
			c = c->pDown;
		}
		else
		{
			if (stec.empty()) 
			{ 
				break; 
			}
			else 
			{
				c = stec.top();
				stec.pop();
				level--;
				c = c->pNext;
			}
		}
	}
	cout << endl;
}

void TText::Reset() {
	while (!st.empty())
		st.pop();

	pCurr = pFirst;
	st.push(pCurr);
	if (pFirst->pDown != nullptr)
		st.push(pFirst->pDown);

	if (pFirst->pNext != nullptr)
		st.push(pFirst->pNext);
}

bool TText::IsEnd() {
	return st.empty();
}

void TText::GoNext() {
	if (!st.empty())
	{
		pCurr = st.top();
		st.pop();
	}

	if (pCurr != pFirst)
	{
		if (pCurr->pNext != nullptr)
			st.push(pCurr->pNext);
		if (pCurr->pDown != nullptr)
			st.push(pCurr->pDown);
	}
}


void TText::Save(const char* filename)
{
	ofstream fout = ofstream(filename);
	stack< TLink* > stec;
	TLink* c = pFirst;
	while (1)
	{
		if (c != nullptr)
		{
			fout << "&&& " << c->str << ' '; // обработка звена
			stec.push(c);
			if (c->pDown != nullptr)
			{
				fout << "{ ";// запись в стек
			}
			c = c->pDown;// переход на подуровень
		}
		else
		{
			if (stec.empty())
			{
				break;
			}
			else
			{
				c = stec.top();
				stec.pop();
				if (c->pDown != nullptr)
				{
					fout << "} ";// выборка из стека
				}
				c = c->pNext; // переход по тому же
			} // уровню
		}
	}
	fout.close();
}

void TText::MarkCurr()
{ 
	pCurr->flag = true; 
}

TLink* TText::GetCurr()
{
	return pCurr;
}

void TText::SetLine(const char* s)
{
	if (pCurr == nullptr)
	{
		cout << "Ошибка памяти" << endl;
	}
	else
	{
		pCurr->SetLine(s);
	}
}

string TText::GetLine(void)
{
	if (pCurr == nullptr)
	{
		return string("");
	}
	else
	{
		return string(pCurr->str);
	}
}


void TText::load(const char* fileName)
{
	ifstream fin = ifstream(fileName);
	char res[1000] = { "" };
	char var[1000] = { "" };
	int down = 0;
	bool w = true;
	GoFirstLink();
	while (pFirst->pNext != nullptr)
	{
		DelNext();
	}
	while (pFirst->pDown != nullptr)
	{
		DelDown();
	}
	while (1)
	{
		fin >> var;
		if (var[0] != '\0' && strcmp(var, "&&&") != 0 && strcmp(var, "{") != 0 && strcmp(var, "}") != 0)
		{
			strcat_s(res, var);
			strcat_s(res, " ");
		}
		if (var[0] == '\0')
		{
			if (res[0] != '\0')
				if (w == true)
				{
					SetLine(res);
					
				}
				else
				InsNextLine(res);
			break;
		}
		if (strcmp(var, "&&&") == 0)
		{
			if (res[0] != '\0')
			{
				if (w == true)
				{
					SetLine(res);
					w = false;
				}
				else
				{
					if (down > 0)
					{
						InsDownLine(res);
						GoDownLink();
						down--;
					}
					else
					{
						InsNextLine(res);
						GoNextLink();
					}
					
				}
				res[0] = '\0';
			}
		}
		if (strcmp(var, "}") == 0)
		{
			if (res[0] != '\0')
			{
				if (w == true)
				{
					SetLine(res);
					w = false;
				}
				else
				{
					if (down > 0)
					{
						InsDownLine(res);
						GoDownLink();
						down--;
					}
					else
					{
						InsNextLine(res);
					}
					
				}
				res[0] = '\0';
			}
			GoPrevLink();
		}
		if (strcmp(var, "{") == 0)
		{
			if (res[0] != '\0')
			{
				if (w==true)
				{
					SetLine(res);
					w = false;
				}
				else
				{
					if (down > 0)
					{
						InsDownLine(res);
						GoDownLink();
						down--;
					}
					else
					{
						InsNextLine(res);
						GoNextLink();
					}
					
				}
				res[0] = '\0';
			}
			down++;
		}
	}
	fin.close();
	GoFirstLink();
}