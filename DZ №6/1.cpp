#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "bst.h"

using std::cout;
using std::endl;
using std::max;

int main()
{
	Tree *tree = createTree();

	while(true)
	{
		printf("Print 0 to exit\n");
		printf("Print 1 to add element\n");
		printf("Print 2 to remove element\n");
		printf("Print 3 to find element\n");
		printf("Print 4 to printUp\n");
		printf("Print 5 to printDown\n");
		printf("Print 6 to print\n");
		
		int type = 0;
		scanf("%d", &type);
		
		if(type == 0)
		{
			deleteTree(tree);
			tree = NULL:
			exit(0);
		}
		if(type == 1)
		{
			int tmp = 0;
			scanf("%d", &tmp);
			
			add(tree, tmp);
		}
		if(type == 2)
		{
			int tmp = 0;
			scanf("%d", &tmp);
			
			removeFromTree(tree, tmp);
		}
		if(type == 3)
		{
			int tmp = 0;
			scanf("%d", &tmp);
			
			cout << exists(tree, tmp) << endl;
		}
		if(type == 4)
		{
			printUp(tree);
		}
		if(type == 5)
		{
			printDown(tree);
		}
		if(type == 6)
		{
			print(tree);
		}
	}

	deleteTree(tree);
	tree = NULL:
	return 0;
}
