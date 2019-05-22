#include "TTextMem.h"

TTextMem::TTextMem(int size)
{
	this->size = size;
	first = new TTextLink[size];
	free = first;
    last = &first[size - 1];
	for (int i = 0; i < size - 1; i++) {
		first[i].next = &first[i + 1];
		first[i].down = nullptr;
		first[i].line[0] = '\0';
		first[i].flag = false;
	}
	last->next = nullptr;
	last->down = nullptr;
	last->line[0] = '\0';
	last->flag = false;
}

TTextMem::~TTextMem()
{
	delete []first;
}

TTextLink* TTextMem::GetNewLink()
{
	TTextLink* res = free;
	if (res == nullptr) {
		throw -1;
	}
	free = free->next;
	res->next = nullptr;
	res->down = nullptr;
	res->line[0] = '\0';
	res->flag = false;
	return res;
}

void TTextMem::ReturnLink(TTextLink* link)
{
	link->next = free;
	link->down = nullptr;
	link->line[0] = '\0';
	link->flag = false;
	free = link;
}

void TTextMem::MemCleaner()
{
	stack<TTextLink*> garbage;
	for (TTextLink* i = first; i != first + size; i++) 
	{
		if (i->flag)
		{
			i->next = nullptr;
			garbage.push(i);
		}
	}
	garbage;
	while (!garbage.empty())
	{
		TTextLink* link = garbage.top();
		garbage.pop();
		if (link->next != nullptr) {
			garbage.push(link->next);
		}
		if (link->down != nullptr) {
			garbage.push(link->down);
		}
		ReturnLink(link);
	}


}

void TTextMem::PrintLink()
{
	bool* IsInFree = new bool[size];
	for (int i = 0; i < size; i++) {
		IsInFree[i] = false;
	}
	TTextLink* curr = free;
	while (curr != nullptr) {
		IsInFree[(int)(curr - first)] = true;
		curr = curr->next;
	}
	cout << "Звенья "<<endl;
	int free_in_row = 0;
	for (int i = 0; i < size; i++) {
		if (!(free_in_row >= 10 && IsInFree[i]))
			cout << i <<"  ";
		if (IsInFree[i]) {
			if (free == &first[i] && free_in_row < 10)
				cout << "Первое ";
			if (free_in_row < 10) {
				cout << "Свободное; Следующее свободное " << (first[i].next - first);
			}
			else if (free_in_row == 10) {
				cout << "\n***\n***\n***" << endl;
			}
			free_in_row++;
		}
		else if (first[i].flag) {
			cout << "Удаленное";
			free_in_row = 0;
		}
		else {
			cout << "value: " << first[i].line << ";  next: ";
			if (first[i].next - first < 0)
			{
				cout << "nullptr";
			}
			else
			{
				cout << first[i].next - first;
			}
			cout << ";   down: ";
			if (first[i].down - first < 0)
			{
				cout << "nullptr";
			}
			else
			{
				cout << first[i].down - first;
			}
			free_in_row = 0;
		}
		if (!(free_in_row >= 10 && IsInFree[i]))
			cout << endl;
	}
	delete[] IsInFree;
}

void TTextMem::PrintFreeLink()
{
	TTextLink* curr = free;
	cout << "Свободные звенья"<<endl;
	while (curr != nullptr)
	{
		cout << '#' << int(curr - first) << '#' << endl;
		curr = curr->next;
	}
}