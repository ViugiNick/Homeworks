#include "stack@Viu.h"
#include <cstdio>
#include <cstdlib>

using namespace Stacks;

int main()
{
	Stack our;
	StackElement *temp = new StackElement;
	temp -> value = -1;
	temp -> next = NULL;
	our.head = temp;

	push(our, 1);
	push(our, 2);
	pop(our);
	push(our, 3);
	
	printf("%d\n", pop(our));	
    printf("%d\n", pop(our));	
    printf("%d\n", pop(our));	

	stackDelete(our);

	return 0;
}