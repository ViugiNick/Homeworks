#include "stack_Viu.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>

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
    	if (st.head->next == NULL)
    	{
    		return -1;
    	}

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
		le->value = -1;
		le->next = NULL;
		l.head = le;
	}
    
	void printStack(Stack &st)
    {
    	
    	StackElement *tempElement = st.head->next;    		    		
    	while (tempElement != NULL)
    	{
    		if(tempElement->value > 0)
    			printf("%d ", tempElement->value);
    		else
    			printf("%c ", char(-(tempElement->value)));
    			
    		tempElement = tempElement->next;	
    	}
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