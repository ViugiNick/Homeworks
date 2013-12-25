#include "iostream"
#include "cstdio"
#include "list_Viu.h"

using namespace std;
using namespace Trees;

namespace Lists
{
	void pop(List *& l)
	{
		ListElement * listElement = l->head->next;
		l->head->next = l->head->next->next;
		delete listElement;
	}
	
	Tree * firstInList(List *& l)
	{
		return l->head->next->tree;
	}
	
	int sizeOfList(List *& l)
	{
		ListElement *temp = l->head;
		int size = 0;
		
		while (temp->next != NULL)
		{
			temp = temp->next;
			size++;
		}

		return size;
	}
	
	void insertToSorted(Tree *tree, List *& l)
	{
		ListElement *temp = l->head;
		
		while ((temp->next != NULL) && (temp->next->tree->root->val < tree->root->val))
		{
			temp = temp->next;
		}

		ListElement * newElement = new ListElement();
		newElement->tree = tree;
		newElement->next = temp->next;
		
		temp->next = newElement;
	}

	void deleteElement(ListElement *& listElement)
	{
		if(listElement->next != NULL)
		{
			deleteElement(listElement->next);
			deleteTree(listElement->next->tree);
			delete listElement->next;
		}
	}

	void deleteList(List *& l)
	{
		deleteElement(l->head);
		delete l->head->tree;
		delete l->head;
		l->head = NULL;
	}
	
	List * makeList()
	{
		List * l = new List();
		
		l->head = new ListElement();
		l->head->next = NULL;
		l->head->tree = NULL;
		
		return l;
	}
}