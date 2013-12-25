#include <iostream>
#include <cstdio>
#include <string.h>
#include "stack_Viu.h"

using namespace Stacks;

const int maxSizeOfNumber = 10;
const int maxChar = 500;

int operation(char c, int a, int b)
{
	if(c == '+')
		return a + b;
	if(c == '*')
		return a * b;
	if(c == '-')
		return a - b;	
	if(c == '/')
		return a / b;
}

int main()
{
	int priority[maxChar];
	
	priority['+'] = 1;
	priority['-'] = 1;
	
	priority['*'] = 2;
	priority['/'] = 2;

	Stack stack1;
	makeStack(stack1);
	Stack stack2;
	makeStack(stack2);
	Stack stack3;
	makeStack(stack3);
	
	printf("Input size of your expression : \n");
	int n;
	scanf("%d", &n);

// ------------------------ ןונוגמה ג ÎÏÇ ----------------
	
	for (int i = 0; i < n; i++)
	{
		char temp[maxSizeOfNumber];
		scanf("%s", &temp);
		
		if (temp[0] == '*' || temp[0] == '/' || temp[0] == '+' || temp[0] == '-')
		{
			if (sizeOfStack(stack2) != 0 && priority[-top(stack2)] == priority[temp[0]])
			{
				push(stack1, top(stack2));
				pop(stack2);
				push(stack2, -int(temp[0]));	
			}
			else
			{
				push(stack2, -int(temp[0]));	
			}
			continue;
		}
		
		if (temp[0] == '(')
		{
			push(stack2, -int(temp[0]));
			continue;
		}
		
		if (temp[0] == ')')
		{
			while (1)
			{
				if (top(stack2) == -int('('))
				{
					pop(stack2);
					break;
				}	
				
				push(stack1, top(stack2));
				pop(stack2);
			}
			continue;
		}

		if (temp[0] != '(' && temp[0] != ')')
		{		
    		int newElement = 0;

    		for (int i = 0; i < strlen(temp); i++)
    		{	
    			newElement *= 10;	
    			newElement += temp[i] - '0';
    		}
    		
    		push(stack1, newElement);
		}
	}

	while (sizeOfStack(stack2) != 0)
	{
		push(stack1, top(stack2));
		pop(stack2);	
	}	
	
	while (sizeOfStack(stack1) != 0)
	{
		push(stack3, top(stack1));
		pop(stack1);	
	}
	
//------------------------------

	stackDelete(stack1);
	makeStack(stack1);
	
	while (sizeOfStack(stack3) > 0)
	{
		int curr1 = top(stack3);	
		pop(stack3);
		
		if (curr1 > 0)
			push(stack1, curr1);
		else
		{
			int curr2 = top(stack1);
			pop(stack1);
			int curr3 = top(stack1);
			pop(stack1);
			
			push(stack1, operation(char(-curr1), curr2, curr3));
		}
	}
	
	printf("%d", top(stack1));
	
	stackDelete(stack1);
	stackDelete(stack2);
	stackDelete(stack3);
	return 0;
}