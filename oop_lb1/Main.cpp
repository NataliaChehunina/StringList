#include "StringList.h"

void main(){

	StringList *lt1 = new StringList();
	StringList *lt2 = new StringList();
	 
	lt1->AddHead("1");
	lt1->AddHead("2");
	lt1->AddHead("3");

	lt2->AddTail("a");
	lt2->AddTail("b");
	lt2->AddTail("c");

	cout << "GetHead() + PrintNode();  : " << endl;
	lt1->PrintNode(lt1->GetHead());
	cout << "__________\n";

	cout << "GetTail() + PrintNode();  : " << endl;
	lt1->PrintNode(lt1->GetTail());
	cout << "__________\n";

	lt1->AddHead(lt2);
	cout<<"AddHead:" << endl;
	lt1->PrintNodet();
	cout << "__________\n";

	lt1->AddTail(lt2);
	cout<<"AddTail:" << endl;
	lt1->PrintNodet();
	cout << "__________\n";

	cout << "RemoveHead() + RemoveTail()" << endl;
	lt1->RemoveHead();
	lt1->RemoveTail();
	lt1->PrintNodet();
	cout << "__________\n";

	lt1->RemoveAt(2);
	cout<<"RemoveAt:" << endl;
	lt1->PrintNodet();
	cout << "__________\n";

	lt1->SetAt("SET" , 1);
	cout<<"SetAt:" << endl;
	lt1->PrintNodet();
	cout << "__________\n";

	cout << "ApendExclusively() : " << endl;
	lt1->AppendExclusively(lt2);
	lt1->PrintNodet();
	cout << "__________\n";

	lt1->InsertAfter("123" , 2);
	cout<<"InsertAfter:" << endl;
	lt1->PrintNodet();
	cout << "__________\n";

	lt1->AddTail("2");
	lt1->AddTail("SET");
	lt1->AddTail("c");
	lt1->AddTail("dfghj");

	lt1->InsertBefore("qwerty" , 3);
	cout<<"InsertBefore:" << endl;
	lt1->PrintNodet();
	cout << "__________\n";

	lt1->Unique();
	cout<<"Unique:" << endl;
	lt1->PrintNodet();
	cout << "__________\n";

	cout << "FindIndex() :" << endl;
	cout << "index \"123\" = " << lt1->FindIndex("123") << endl;
	cout << "__________\n";

	cout << "GetSize() : " << endl;
	cout << "size lt1 = " <<  lt1->GetSize() << endl;
	cout << "__________\n";

	cout << "IsEmpty() : " << endl;
	cout << "IsEmpty lt1?  " << lt1->IsEmpty() <<endl; 
	cout << "__________\n";

	cout << "GetAt : " << endl;
	cout << "elem =  "<< lt1->GetAt(2) <<endl; 
	cout << "__________\n";



	cout << "Iteration : " << endl;
	for(POSITION pos = lt1->GetHeadPosition(); pos != NULL; pos = lt1->GetNext())
	{
		lt1->PrintNode(pos);
	}
	cout << "__________\n";


	cout << "splice() + find() : " << endl; 
	lt2->AddTail("d");
	lt2->AddTail("e");
	lt2->AddTail("f");
	cout << "LIST2 : " <<endl;
	lt2->PrintNodet();
	cout << "..........\n";

	POSITION ln1 = lt2->Find("b");
	POSITION ln2 = lt2->Find("e");
	POSITION Where = lt1->Find("123");
	lt1->Splice(Where, lt2, ln1, ln2);
	cout << "LIST1 : " << endl;
	lt1->PrintNodet();
	cout << "..........\n";
	cout << "LIST2 : " << endl;
	lt2->PrintNodet();
	cout << "__________\n";
}