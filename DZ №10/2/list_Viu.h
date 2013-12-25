#include "tree_Viu.h"

using namespace Trees;

namespace Lists
{	
	struct ListElement 
	{
		Tree * tree;
		ListElement *next;
	};

	struct List 
	{
		ListElement *head;
	};

	void pop(List *& l);
	Tree * firstInList(List *& l);
	int sizeOfList(List *& l);
	void insertToSorted(Tree *tree, List *& l);
	void deleteElement(ListElement *& listElement);
	void deleteList(List *& l);
	List * makeList();
}