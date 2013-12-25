#include <iostream>
#include <cstdio>
#include <string.h>
#include "stack_Viu.h"

using namespace Stacks;

const int maxN = 100;

void badResult()
{
	printf("Bad string\n");
	exit(0);
}

void goodResult()
{
	printf("Good string\n");
	exit(0);
}


int main()
{
	char inputString[maxN];

	Stack mainStack;
	makeStack(mainStack);
	
	int sizeOfString = 0;
	printf("Input size of your string\n");
	scanf("%d", &sizeOfString);
	
	scanf("%s", &inputString);
	
	for(int i = 0; i < sizeOfString; i++)
	{
		char newElement = inputString[i];
		
		if((newElement >= 'a' && newElement <= 'z') || (newElement >= 'A' && newElement <= 'Z'))
			continue;
		
		switch (newElement)
		{
			case '(': 
			{
				push(mainStack, int('('));
				break;
			}
			case '[': 
			{
				push(mainStack, int('['));
				break;
			}
			case '{':
			{
				push(mainStack, int('{'));
				break;
			}
			
			case ')':
			{
				if(sizeOfStack(mainStack) == 0)
				{
					badResult();
				}
				
				if(top(mainStack) == int('('))
				{
					pop(mainStack);
				}
				else
				{
					badResult();
				}
				break;
			}
			case ']':
			{
				if(sizeOfStack(mainStack) == 0)
					badResult();
			
				if(top(mainStack) == int('['))
				{
					pop(mainStack);
				}
				else
				{
					badResult();
				}
				break;
			}
			case '}':
			{
				if(sizeOfStack(mainStack) == 0)
					badResult();
			
				if(top(mainStack) == int('{'))
				{
					pop(mainStack);
				}
				else
				{
					badResult();
				}
				break;
			}
		}	
	}

	if(sizeOfStack(mainStack) != 0)
		badResult();
	else
		goodResult();
	
	stackDelete(mainStack);
	return 0;
}
