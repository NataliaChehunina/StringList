#include "StringList.h"

using namespace std;

StringList::StringList(void){
	head = NULL;
	tail = NULL;
	it = NULL;
}

StringList::~StringList(void){
	RemoveAll();
}

bool StringList::IsEmpty()const{
	if (!head && !tail)
		return 1;
	else
		return 0;
}

POSITION StringList::GetHead(){
	return head;
}

POSITION StringList::GetTail(){
	return tail;
}


void StringList::AddHead(const char *chr){
	bool fl = IsEmpty();
	ListNode *lst = new ListNode();
	if (!fl){
		lst->next = head;
		lst->str = new char(strlen(chr) + 1);
		strcpy(lst->str , chr);
		head->prev = lst;
		head = lst;
		lst->prev = NULL;	
	}
	else{
		head = lst;
		tail = lst;
		lst->str = new char(strlen(chr) + 1);
		strcpy(lst->str , chr);
		lst->next = NULL;
		lst->prev = NULL;
	}
}

void StringList::AddTail(const char *chr){
	bool fl = IsEmpty();
	ListNode *lst = new ListNode();
	if (!fl){
		lst->prev = tail;
		lst->str = new char(strlen(chr) + 1);
		strcpy(lst->str , chr);
		tail->next = lst;
		tail = lst;
		lst->next = NULL;	
	}
	else{
		head = lst;
		tail = lst;
		lst->str = new char(strlen(chr) + 1);
		strcpy(lst->str , chr);
		lst->next = NULL;
		lst->prev = NULL;
	}
}
void StringList::PrintNodet(){
	bool fl = IsEmpty(); 
	int i = 0;
	ListNode *lst;
	if (!fl){
		lst = head;
		while(lst != tail){
			cout << "Elem: " << i << " => ";
			cout << lst->str << endl;
			i++;
			lst = lst->next;
		}
		cout <<"Elem: " << i << " => ";
		cout << tail->str << endl;
	}
	else
		cout <<"List is empty"<<endl;
}

void StringList::PrintNode(POSITION p){
	bool fl = IsEmpty();
	if (!fl){
			cout <<"Elem => ";
			cout << p->str << endl;
	}
	else
		cout <<"List is empty"<<endl;
}

int StringList::GetSize()const{
	int quant = 0;
	ListNode *lst = head;
	bool fl = IsEmpty();
	if (!fl){
		while(lst != tail){
			quant++;
			lst = lst->next;
		}
		quant++;
	}
	return quant;
}

int StringList::FindIndex(char *chr)const{
	int index = 0;
	ListNode *lst;
	bool fl = IsEmpty();
	if (!fl){
		lst = head;
		while(lst != tail){			
			if ( strcmp(lst->str , chr) == 0)
				return index;
			index++;
			lst = lst->next;
		}
		if(strcmp(lst->str , chr) == 0)
			return index;
		return -1;
	}
	else{
		index = -1;
		return index;
	}
}

POSITION StringList::Find(char *chr){
	ListNode *lst;
	POSITION pos;
	bool fl = IsEmpty();
	if (!fl){
		lst = head;
		while((lst != tail) && (lst->str != chr)){			
			if ( strcmp(lst->str , chr) == 0){
				pos = lst;
				return pos;
			}
			lst = lst->next;
		}
		if(strcmp(lst->str , chr) == 0){
			pos = lst;
			return pos;
		}
		return NULL;
	}
	else
		return NULL;
}

void StringList::RemoveAll(){
	bool fl = IsEmpty(); 
	ListNode *lst;
	if (!fl){
		lst = head;
		while(lst != tail){   //while(lst != NULL) !!!!!!!!!!!!!!!
			lst = lst->next;
			delete[] head;
			head = lst;
		}
		delete[] tail;
		tail = NULL;
		head = NULL;
	}
}

void StringList::RemoveHead(){
	bool fl = IsEmpty(); 
	if ((!fl) && (head != tail)){
		ListNode *lst;
		lst = head;
		head = lst->next;
		head->prev = NULL;
		delete[] lst; 
	}else{
	if ((!fl) && (head = tail)){
		delete[] head; 
		head = NULL;
		tail = NULL;
	}
	}
}

void StringList::RemoveTail(){
	bool fl = IsEmpty(); 
	if ((!fl) && (head != tail)){
		ListNode *lst;
		lst = tail;
		tail = lst->prev;
		tail->next = NULL;
		delete[] lst; 
	}
	else{
		if ((!fl) && (head = tail)){
		delete[] tail; 
		head = NULL;
		tail = NULL;
		}
	}
}

const char* StringList::GetAt(int index)const{
	ListNode *lst;
	bool fl = IsEmpty();
	int i = 0;
	if (!fl){
		lst = head;
		while((lst != tail) && (i != index)){			
			lst = lst->next;
			i++;
		}
		if (i == index){
			return lst->str;		
		}
		return NULL;
	}
	return NULL;
}


POSITION StringList::GetHeadPosition(){
	it = head;
	return it;
}
POSITION StringList::GetNext(){
	it = it->next;
	return it;
}

POSITION StringList::GetPrev(){
	it = it->prev;
	return it;
}


void StringList::AddHead(const StringList * sl){
	const ListNode *ln = sl->tail;
	while (ln != NULL){
		AddHead(ln->str);
		ln = ln->prev;
	}	
}


void StringList::AddTail(const StringList * sl){
	ListNode *ln = sl->head;
	while (ln != NULL){
		AddTail(ln->str);
		ln = ln->next;
	}
}

void StringList::RemoveAt(int index){
	ListNode *lst;
	bool fl = IsEmpty();
	int i = 0;
	if (!fl){
		lst = head;
		while((lst != tail) && (i != index)){			
			lst = lst->next;
			i++;
		}
		if (i == index){
			if (lst == head)
				RemoveHead();
			else{
				if (lst == tail)
					RemoveTail();
						else{
							lst->next->prev = lst->prev;
							lst->prev->next = lst->next;
							delete[] lst;
						}
				}			
		}
	}
}

void StringList::SetAt(char *chr, int index){
ListNode *lst;
	bool fl = IsEmpty();
	int i = 0;
	if (!fl){
		lst = head;
		while((lst != tail) && (i != index)){			
			lst = lst->next;
			i++;
		}
		if (i == index){
			//delete[] lst->str;
			//lst->str = new char(strlen(chr) + 1);
			strcpy(lst->str , chr);		
		}
	}
}


void StringList::AppendExclusively(const StringList * sl){
	const ListNode *ln = sl->head;
	while (ln != NULL){
		if (FindIndex(ln->str)<0)
		AddTail(ln->str);
		ln = ln->next;
	}

}

void StringList::InsertBefore(char *chr,int index){
	if ((index != 0) || (!IsEmpty())){
		int i = 1;
		for(GetHeadPosition(); (it != NULL && i != index ); GetNext()){
			i++;
		}
		if (i == index){
			ListNode *elem = new ListNode();
			elem->str = new char(strlen(chr)+1);
			strcpy(elem->str , chr);
			elem->prev = it->prev;
			elem->next = it;
			it->prev->next = elem;
			//elem->prev = it->prev;
			it->prev = elem;
		}
		else 
			AddTail(chr);
	}
	else
		AddHead(chr);
}

void StringList::InsertAfter(char *chr,int index){
	if ((index != 0) || (!IsEmpty())){
		int i = 1;
		for(GetHeadPosition(); (it != NULL && i != index); GetNext()){
			i++;
		}
		if (i == index){
			ListNode *elem = new ListNode();
			elem->str = new char(strlen(chr)+1);
			strcpy(elem->str , chr);
			elem->next = it->next;
			elem->prev = it;
			it->next->prev = elem;
			it->next = elem;
		}
	
		else 
			AddTail(chr);
	}
	else
		AddHead(chr);
}

void StringList::Splice(POSITION Where, StringList *sl, POSITION first, POSITION last){
	if (!Where || !sl || !first || !last)
		return;
	ListNode *insert = (ListNode*)Where;
	ListNode *ls = (ListNode*)last;
	ListNode *fr = (ListNode*)first;
	if (fr == sl->head){
		if(ls == sl->tail)
			sl->head = sl->tail;
		else
			sl->head = ls->next;
	}
	fr->prev->next = ls->next;	
	if (ls == sl->tail){
		if(fr = sl->head)
			sl->tail = sl->head;
		else
			sl->tail = fr->prev;
	}
	ls->next->prev = fr->prev;
	fr->prev = insert->prev;
	ls->next = insert;
	insert->prev->next = fr;
	insert->prev = ls;
	
}

void StringList::Unique(){
	if (head != tail){
		ListNode *lst = tail;
		int i = GetSize() - 1;
		while(lst != NULL){
			if (FindIndex(lst->str) != i){
				lst = lst->prev;
				RemoveAt(i);
			}
			else
				lst = lst->prev;
			i--;
			//lst = lst->prev;
		}
	}
}