#include <cstdio>
#include <cstdlib>

namespace Stacks
{
    struct StackElement 
    {
    	int value;
    	StackElement *next;
    };

    struct Stack 
    {
    	StackElement *head;
    };

 	int sizeOfStack(Stack &st);
    void printStack(Stack &st);
	void makeStack(Stack &l);
	void push(Stack &st, int val);
    int pop(Stack &st);
    int top(Stack &st);
    void stackDelete(Stack &st);
}