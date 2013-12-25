#include "stack_Viu.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

namespace Stacks
{
    void push(Stack &st, MyString val)
    {
    	StackElement *newElement = new StackElement;
    	newElement->value = val;
    	newElement->next = st.head->next;
    	st.head->next = newElement;
    }

    MyString pop(Stack &st)
    {
    	MyString topElement = st.head->next->value;
    	StackElement *tempElement = st.head->next;
    	st.head->next = st.head->next->next;
    	delete(tempElement);
    	tempElement = NULL;

    	return topElement;
    }

    MyString top(Stack &st)
    {
    	return st.head->next->value;
    }

    void makeStack(Stack &l)
	{
		StackElement *le = new StackElement;
		le->value = toStr("0");
		le->next = NULL;
		l.head = le;
	}
    
	void printStack(Stack &st)
    {
    	StackElement *tempElement = st.head->next;    		    		
    	while (tempElement != NULL)
    	{
    		printStr(tempElement->value);
    		printf(" ");
    		tempElement = tempElement->next;	
    	}
    }

	bool inStack(MyString str, Stack &st)
    {
    	StackElement *tempElement = st.head -> next;    		    		
    	
    	while (tempElement != NULL)
    	{
    		cerr << "!!!" << endl;
    		if(isEqual(tempElement->value, str))
    			return true;
    		tempElement = tempElement->next;	
    	}
    	
    	return false;
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
    		deleteStr(tempElement->value);
    		delete(tempElement);
    		tempElement = NULL;
    	}
    	deleteStr(st.head->value);
    	delete(st.head);
    }
}