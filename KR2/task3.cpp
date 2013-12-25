#include <iostream>
#include <cstdio>
#include <string.h>
#include "stack_Viu.h"

using namespace Stacks;
using namespace std;

int main()
{
	freopen("f.txt", "r", stdin);
	freopen("g.txt", "w", stdout);
	
	Stack stack1;
	makeStack(stack1);
	Stack stack2;
	makeStack(stack2);
	Stack stack3;
	makeStack(stack3);
	
	int inputA = 0;
	int inputB = 0;
	int newElement = 0;
	
	scanf("%d%d", &inputA, &inputB);
	
	while(cin >> newElement)
	{
		if(newElement < inputA)
			push(stack1, newElement);
		if(newElement > inputB)
			push(stack3, newElement);
		if(inputA <= newElement && newElement <= inputB)
			push(stack2, newElement);
	}
	
	printStack(stack1);
	printStack(stack2);
	printStack(stack3);
	
	stackDelete(stack1);
	stackDelete(stack2);
	stackDelete(stack3);
	return 0;
}