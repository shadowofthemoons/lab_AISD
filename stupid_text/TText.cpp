#include "TText.h"

TText::TText(const char * line)
{
	mem = new TTextMem(1000);
	TTextLink* link = new(mem) TTextLink(line);
	this->First = this->Current = link;
}

TText::~TText()
{
	delete mem;
}

void TText::InsDownLine(const char* line)
{
	TTextLink* d = Current->down;
	Current->down=new(mem) TTextLink(line);
	Current->down->next = d;
}

void TText::InsNextLine(const char* line)
{

	TTextLink* n = Current->next;
	Current->next = new(mem) TTextLink(line);
	Current->next->next = n;
}

void TText::GoFirstLink(void)
{
	while (!St.empty()) {
		St.pop();
	}
	 Current= First;
	 if (Current == nullptr)
	 {
		 cout << "������ ������"<<endl;
	 }
}

void TText::GoDownLink(void)
{
	if (Current->down != nullptr)
	{
		St.push(Current);
		Current = Current->down;
	}
	else
	{
		cout << "���� ������� ����" << endl;
	}	
}

void TText::GoNextLink(void)
{
	if (Current->next != nullptr)
	{
		Current = Current->next;
	}
	else
	{
		cout << "��������� ����� �� ���� ������" << endl;
	}
}

void TText::GoPrevLink(void)
{
	if (!St.empty()) 
	{
		Current = St.top();
		St.pop();
	}
}

void TText::DelNextLine(void)
{
	if (Current->next != nullptr)
	{
		TTextLink* dellink = Current->next;
		Current->next = dellink->next;
		delete dellink;
	}
	else
	{
		cout<<"��� ���������� ��������";
	}
}

void TText::DelDownLine(void)
{
	if (Current->down != nullptr)
	{
		TTextLink* dellink = Current->down;
		Current->down = dellink->next;
		delete dellink;
	}	
	else
	{
		cout << "��� ������� ��������";
	}
}

void TText::MemCleaner()
{
	mem->MemCleaner();
}

void TText::PrintFreeLink()
{
	mem->PrintFreeLink();
}

void TText::PrintLink()
{
	mem->PrintLink();
}

void TText::SetLine(const char* s)
{
	if (Current == nullptr)
	{
		cout << "������ ������" << endl;
	}
	else
	{ 
		Current->setline(s);
	}
	
}

string TText::GetLine(void)
{

	if (Current == nullptr)
	{
		return string("");
	}
	else
	{
		return string( Current->line);
	}
}
	


void TText::Save(const char* filename)
{
	ofstream fout = ofstream(filename);
	stack< TTextLink* > stec;
	TTextLink* c = First;
	while (1)
	{
		if (c != nullptr)
		{
			fout << "&&& " << c->line<<' '; // ��������� �����
			stec.push(c); 
			if (c->down != nullptr)
				fout << "{ ";// ������ � ����
			c = c->down;// ������� �� ����������
		}
		else if (stec.empty()) break;
		else {

			
			c = stec.top(); 
			stec.pop();
			if (c->down != nullptr)
				fout << "} ";// ������� �� �����
			c = c->next; // ������� �� ���� ��
		} // ������
	}
	fout.close();
}

void TText::Print(void)
{
	stack< TTextLink* > stec;
	TTextLink* c = First;
	while (1)
	{
		if (c != nullptr)
		{
			cout << "&&& " <<  c->line << ' '; // ��������� �����
			stec.push(c);
			if (c->down != nullptr)
				cout << "{ ";// ������ � ����
			c = c->down;// ������� �� ����������
		}
		else if (stec.empty()) break;
		else {


			c = stec.top();
			stec.pop();
			if (c->down != nullptr)
				cout << "} ";// ������� �� �����
			c = c->next; // ������� �� ���� ��
		} // ������
	}

}

void TText::Reset()
{
	Current = First;
	if (Current != nullptr)
	{
		St.push(Current);
		if (Current->next != nullptr)
			St.push(Current->next);
		if (Current->down != nullptr)
			St.push(Current->down);
	}
}

void TText::load(const char* fileName)
{
	ifstream fin = ifstream(fileName);
	char res[1000] = { "" };
	char var[1000] = { "" };
	int down =0;
	GoFirstLink();
	while (First->next != nullptr)
	{
		DelNextLine();
	}
	while (First->down != nullptr)
	{
		DelDownLine();
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
			InsNextLine(res);
			break;
		}
		if (strcmp(var, "&&&") == 0)
		{
			if (res[0] != '\0')
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
				res[0] = ' ';
				res[1] = '\0';
			}
		}

		if (strcmp(var, "}") == 0)
		{
			if (res[0] != '\0')
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
				res[0] = '\0';
			}
			GoPrevLink();
		}
		if (strcmp(var, "{") == 0)
		{
			if (res[0] != '\0')
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
				res[0] = '\0';
			}
			down++;
		}
	}
	TTextLink* d = First;
	First = First->next;
	d->flag = true;
	d->next = nullptr;
	d->down = nullptr;
	fin.close();
	GoFirstLink();
}
