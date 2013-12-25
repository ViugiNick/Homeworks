#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "list_Viu.h"

namespace Lists
{
	ListElement *goToNext(ListElement *temp, List &l)	
	{
		return temp->next;
	}
	
	void insert(ListElement *temp, int position, List &l)
	{
		ListElement *newElement = l.head;
		
		while ((position > 0) && (newElement != NULL))
		{
			position--;
			newElement = newElement->next;
		}

		temp->next = newElement->next;
		newElement->next = temp;
	}
	
	void deleteInCiclicNext(ListElement *temp, List &l)
	{
		if (temp->next == l.head->next)
		{
			ListElement *newElement = temp->next;
		
			l.head->next = l.head->next->next;
			temp->next = l.head->next;
			delete(newElement);
			return;
		}
		
		ListElement *newElement = temp->next;
		
		temp->next = temp->next->next;
		delete(newElement);
	}
	
	int sizeOfList(List &l)
	{
		ListElement *temp = l.head->next;
		int size = 1;
		
		while (temp->next != l.head->next)
		{
			temp = temp->next;
			size++;
		}

		return size;
	}
	
	void insertToEndOfCiclicList(ListElement *newElement, List &l)
	{
		if (l.head->next == NULL)
		{
			l.head->next = newElement;
			newElement->next = newElement;
			return;
		}
		
		ListElement *temp = l.head->next->next;
		
		while (1)
		{
			if (temp -> next == l.head->next)
			{
				temp->next = newElement;
				newElement->next = l.head->next;
				return;
			}
			temp = temp->next;
		}
	}
	
	void insertToSorted(ListElement *val, List &l)
	{
		ListElement *temp = l.head;
		
		while ((temp->next != NULL) && (val->value > temp->next->value))
		{
			temp = temp->next;
		}

		val->next = temp->next;
		temp->next = val;
	}

	void deleteElement(int val, List &l)
	{
		ListElement *temp = l.head;
		
		while (temp->next != NULL)
		{
			if (temp->next->value == val)
			{
				ListElement *wouldBeDeleted = temp->next; 
				temp->next = temp->next->next;
				
				delete wouldBeDeleted;	
				return;
			}		
			temp = temp->next;
		}
	}
	
	void deleteListElement(ListElement *l)
	{
		if (l != NULL) 
		{
			deleteListElement(l->next);
			delete l;
		}
	}
	
	void deleteList(List &l)
	{	
		deleteListElement(l.head);
		l.head = NULL;
	}
	
	void deleteCiclicListElement(ListElement *elem, List &l)
	{	
		if (elem->next != l.head->next) 
		{
			deleteListElement(elem->next);
			delete elem;
		}
		else
		{
			delete elem;
		}
	}
	
	void deleteCiclicList(List &l)
	{	
		deleteCiclicListElement(l.head->next, l);
		delete(l.head);
		l.head = NULL;
	}
	
	void makeList(List &l)
	{
		ListElement *le = new ListElement;
		le->value = -1;
		le->next = NULL;
		l.head = le;
	}

	void printCiclicList(List &l)
	{
		ListElement *temp = l.head -> next;
		
		while(1)
		{	
			printf("%d ", temp->value);
			temp = temp->next; 	
			
			if(temp == l.head->next)
				break;
		}
		
		printf("\n");
	}
	
	void printList(List &l)
	{
		ListElement *temp = l.head;
		
		while (temp->next != NULL)
		{	
			printf("%d ", temp->next->value);
			temp = temp->next; 	
		}
		printf("\n");
	}	
}
 