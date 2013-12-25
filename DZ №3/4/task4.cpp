#include <cstdio>
#include <string.h>
#include "list_Viu.h"

using namespace Lists;

enum UserCommand {userQuit, userAddElement, userRemoveElement, userPrintList}; 

UserCommand toCommand(int a)
{
	switch (a)
	{
		case 0: return userQuit;
		case 1: return userAddElement;	
		case 2: return userRemoveElement;
		case 3: return userPrintList;
	}
}

int main()
{
	List mainList;
	makeList(mainList);
	
	while (true)
	{
		printf("You can : \n");
		printf("   input 0 to exit,\n");
		printf("   input 1 to add a value to sorted list,\n");
		printf("   input 2 to remove a value from sorted list,\n");
		printf("   input 3 to print list\n");
		
		int type = 0;
		scanf("%d", &type);

		UserCommand command = toCommand(type);
		
		switch (command)
		{
			case userQuit: 
			{
				deleteList(mainList);
	
				return 0;
			}
			
			case userAddElement: 
			{
				int val = 0;
				scanf("%d", &val);
		
				ListElement *temp = new ListElement;
				temp->value = val;
			
				insertToSorted(temp, mainList);
			}
			
			case userRemoveElement:
			{
				int val = 0;
				scanf("%d", &val);
	
				deleteElement(val, mainList);
			}

			case userPrintList:
			{
				printList(mainList);
			}
		} 
	}
	return 0;
}
