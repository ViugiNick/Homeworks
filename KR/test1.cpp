#include <iostream>
#include <cstdio>
#include <string.h>
#include "stack_Viu.h"

using namespace Stacks;

int main()
{
	Stack mainStack;
	makeStack(mainStack);
	Stack stack1;
	makeStack(stack1);
	Stack stack2;
	makeStack(stack2);
	
	int sizeOfStack1 = 0;
	int sizeOfStack2 = 0;
	
	printf("Input size of first stack\n");
	scanf("%d", &sizeOfStack1);
	
	for (int i = 0; i < sizeOfStack1; i++)
	{
		int newStackElement = 0;
		scanf("%d", &newStackElement);
		
		push(stack1, newStackElement);
	}
	
	printf("Input size of second stack\n");
	scanf("%d", &sizeOfStack2);
	
	for (int i = 0; i < sizeOfStack2; i++)
	{
		int newStackElement = 0;
		scanf("%d", &newStackElement);
		
		push(stack2, newStackElement);
	}
	
	for (int i = 0; i < sizeOfStack1 + sizeOfStack2; i++)
	{
		if (sizeOfStack(stack1) != 0 && sizeOfStack(stack2) != 0)
		{
    		if (top(stack1) < top(stack2))
    		{
    			push(mainStack, top(stack1));
    			pop(stack1);
    		}
    		else
    		{
    			push(mainStack, top(stack2));
    			pop(stack2);
    		}
		}
		else
		{
			if (sizeOfStack(stack1) == 0)
			{
				push(mainStack, top(stack2));
    			pop(stack2);
			}
			else
			{
				push(mainStack, top(stack1));
    			pop(stack1);	
			}
		}
	}
	
	printf("Your final stack is : \n");
	printStack(mainStack);
	
	stackDelete(mainStack);
	stackDelete(stack1);
	stackDelete(stack2);
	return 0;
}


// Ассимптотика N + M, если N - размер первой стопки, а M - размер второй стопки.
// Тоесиь слить два отсортированных стека можно за сумму их длин