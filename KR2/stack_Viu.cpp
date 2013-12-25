#include "stack_Viu.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

namespace Stacks
{
    void push(Stack &st, int val)
    {
    	StackElement *newElement = new StackElement;
    	newElement->value = val;
    	newElement->next = st.head->next;
    	st.head->next = newElement;
    }

    int pop(Stack &st)
    {
    	int topElement = st.head->next->value;
    	StackElement *tempElement = st.head->next;
    	st.head->next = st.head->next->next;
    	delete(tempElement);
    	tempElement = NULL;

    	return topElement;
    }

    int top(Stack &st)
    {
    	return st.head->next->value;
    }

    void makeStack(Stack &l)
	{
		StackElement *le = new StackElement;
		le->value = char(0);
		le->next = NULL;
		l.head = le;
	}
    
	void printElement(StackElement *&elem)
	{
		if(elem != NULL)
		{
			printElement(elem -> next);
			printf("%d ", elem->value);
		}
	}	
	
	void printStack(Stack &st)
    {
    	printElement(st.head -> next);
    }

	int sizeOfStack(Stack &st)
	{
		int answer = 0;
		StackElement *tempElement = st.head->next;    		    		
    	while (tempElement != NULL)
    	{
    		answer++;
    		tempElement = tempElement->next;	
    	}
    	
    	return answer;
	}
	
    void stackDelete(Stack &st)
    {
    	while (st.head->next != NULL)
    	{
    		StackElement *tempElement = st.head->next;    		    		
    		st.head->next = st.head->next->next;
    		delete(tempElement);
    		tempElement = NULL;
    	}
    	delete(st.head);
    }
}