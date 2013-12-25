#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include "list_Viu.h"
#include "tree_Viu.h"

using std::cin;
using std::cout;

const int maxN = 1000;

using namespace Trees;

int main()
{
	freopen("text.in", "r", stdin);
	freopen("text.out", "w", stdout);

	char * str = new char[maxN];
	cin >> str;

	Tree * tree = Construct(str);	
	TreeNode * temp = tree->root;
	
	char inputString[maxN];
	cin >> inputString;
	
	for(int i = 0; i < strlen(inputString); i++)
	{
		if(inputString[i] == '1')
			temp = temp->right;
		
		if(inputString[i] == '0')
			temp = temp->left;
		
			
		if((temp->left == NULL) && (temp->right == NULL))
		{
			cout << temp->ch;
			temp = tree->root;
		}
	}

	delete[] str;
	deleteTree(tree);
	delete tree;
	return 0;
}