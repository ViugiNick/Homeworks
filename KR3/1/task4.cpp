#include <cstdio>
#include <string.h>
#include "list_Viu.h"
#include <iostream>

using namespace Lists;
using namespace std;

int main()
{
	List mainList;
	makeList(mainList);
	
	int newElement = 0;
	
	while(true)
	{
		cin >> newElement;
		
		if(newElement == -1)
		{
			printList(mainList);
			deleteList(mainList);
			return(0);
		}
		
		ListElement *temp = new ListElement;
		temp->value = -newElement;
		
		insertToSorted(temp, mainList);
	}
	
	return 0;
}
