#pragma once

namespace Lists
{	
	struct ListElement 
	{
		int value;
		int poww;
		
		ListElement *next;
	};

	struct List 
	{
		ListElement *head;
	};

	void printCiclicList(List &l);
	void deleteInCiclicNext(ListElement *temp, List &l);
	ListElement *goToNext(ListElement *temp, List &l);	
	void printList(List &l);
	void insert(ListElement *temp, int position, List &l);
	void insertToSorted(ListElement *val, List &l);
	void deleteElement(int val, List &l);
	void makeList(List &l);
	void deleteListElement(ListElement *l);
	void deleteList(List &l);
	bool equals(List &l1, List &l2);
	void add(List &l1, List &l2, List l3);
	
	int value(List &l, int x);
	
	void deleteCiclicListElement(ListElement *elem, List &l);
	void deleteCiclicList(List &l);
	
	void insertToEndOfCiclicList(ListElement *newElement, List &l);
	int sizeOfList(List &l);
}