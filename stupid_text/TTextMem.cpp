#include "TTextMem.h"
/*
void MemManager::PrintMem() {
	bool* IsInFree = new bool[size];
	for (int i = 0; i < size; i++) {
		IsInFree[i] = false;
	}
	TextNode* curr = free;
	while (curr != nullptr) {
		IsInFree[(int)(curr - mem)] = true;
		curr = curr->next;
	}
	int free_in_row = 0;
	for (int i = 0; i < size; i++) {
		if (!(free_in_row >= 5 && IsInFree[i]))
			cout << "#" << i << "#  ";
		if (IsInFree[i]) {
			if (free == &mem[i] && free_in_row < 5)
				cout << "-> ";
			if (free_in_row < 5) {
				cout << "free" << ";  next: " << (mem[i].next - mem);
			}
			else if (free_in_row == 5) {
				cout << "\n***\n***\n***" << endl;
			}
			free_in_row++;
		}
		else if (mem[i].IsDeleted) {
			cout << "deleted";
			free_in_row = 0;
		}
		else {
			cout << "value: " << mem[i].value << ";  next: " << (mem[i].next - mem) << ";   down: " << (mem[i].down - mem);
			free_in_row = 0;
		}
		if (!(free_in_row >= 5 && IsInFree[i]))
			cout << endl;
	}
	delete[] IsInFree;
}
MemManager::~MemManager() {
	delete[] mem;
}*/

TTextMem::TTextMem(unsigned long int size)
{
	this->size = size;
	first = new TTextLink [size];
	free = first;
	last = &first [size - 1];
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

TTextLink* TTextMem::GetNewNode() {
	TTextLink* res = free;
	if (res == nullptr) 
	{
		throw 2;
	}
	free = free->next;
	res->next = nullptr;
	res->down = nullptr;
	res->line[0] = '\0';
	res->flag = false;
	return res;
}
void TTextMem:: ReturnNode(TTextLink* node)
{
	node->next = free;
	node->down = nullptr;
	node->line[0] = 0;
	node->flag = false;
	free = node;
}
void TTextMem::CollectGarbage()
{

	stack<TTextLink*> garbage;
	for (int i=0;i<size;i++)
	{
		if (first[i].flag)
		{
			first[i].next = nullptr;
			garbage.push(&first[i]);
		}
	}
	garbage;
	while (!garbage.empty()) {
		TTextLink* node = garbage.top();
		garbage.pop();
		if (node->next != nullptr) {
			garbage.push(node->next);
		}
		if (node->down != nullptr) {
			garbage.push(node->down);
		}
		ReturnNode(node);
	}
}

TTextMem::~TTextMem()
{
	delete[] first;
}
