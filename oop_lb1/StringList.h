#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

typedef struct ListNode{
	char *str;
	ListNode* next;
	ListNode* prev;
}ListNode;

typedef const ListNode* POSITION;

class StringList{
public:
	 StringList(void);
	~StringList(void);
	POSITION GetHead();
	POSITION GetTail();
	void AddHead(const char *);
	void AddHead(const StringList * sl);
	void AddTail(const char *);
	void AddTail(const StringList * sl);
	void RemoveAll();
	void RemoveHead();
	void RemoveTail();
 	void AppendExclusively(const StringList * sl);
	void Splice(POSITION where, StringList *sl, POSITION first, POSITION last);
	void Unique();
	POSITION GetNext();
	POSITION GetPrev();
	POSITION GetHeadPosition();
	const char* GetAt(int )const;
	void RemoveAt(int );
	void SetAt(char *, int );
	void InsertAfter(char *, int);
	void InsertBefore(char *, int);
	POSITION Find(char *);
	int FindIndex(char *)const;
	int GetSize()const;
	bool IsEmpty()const;
	void PrintNode(POSITION p);
	void PrintNodet();

private:
	ListNode* it;
	ListNode* head;
	ListNode* tail;
};
