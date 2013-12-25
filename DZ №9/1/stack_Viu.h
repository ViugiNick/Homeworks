#include <cstdio>
#include <cstdlib>
#include "myString.h"

using namespace myStrings;

namespace Stacks
{
    struct StackElement 
    {
    	MyString value;
    	StackElement *next;
    };

    struct Stack 
    {
    	StackElement *head;
    };

 	int sizeOfStack(Stack &st);
    void printStack(Stack &st);
	void makeStack(Stack &l);
	bool inStack(MyString str, Stack &st);
	void push(Stack &st, MyString val);
    MyString pop(Stack &st);
    MyString top(Stack &st);
    void stackDelete(Stack &st);
}