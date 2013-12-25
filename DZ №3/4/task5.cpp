#include <cstdio>
#include <string.h>
#include "list_Viu.h"

using namespace Lists;

int main()
{
	//freopen("a.out", "w", stdout);
	
	List mainList;
	makeList(mainList);
	
	int inputN = 0;
	int inputM = 0;
		
	printf("Input your N and M : ");
	scanf("%d %d", &inputN, &inputM);
	
	for (int i = 1; i <= inputN; i++)
	{
		ListElement *temp = new ListElement;
		temp->value = i;

		insertToEndOfCiclicList(temp, mainList);
	}
	
	ListElement *temp = mainList.head->next;
	while (sizeOfList(mainList) != 1)
	{
		for (int i = 0; i < inputM - 2; i++)
			temp = goToNext(temp, mainList);
		
		deleteInCiclicNext(temp, mainList);	
		temp = goToNext(temp, mainList);
	}
	
	printf("Your element is : %d", mainList.head->next->value);
	
	deleteCiclicList(mainList);
	
	return 0;
}
