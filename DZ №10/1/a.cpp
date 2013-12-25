#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include "list_Viu.h"

using namespace std;
using namespace Trees;
using namespace Lists;

const int MAXN = 256;

int main()
{
	freopen("text.in", "r", stdin);
	freopen("text.out", "w", stdout);
	
	int numberOfLetters[MAXN];
	char inputString[MAXN];
	cin >> inputString;
	
	for (int i = 0; i < MAXN; ++i)
		numberOfLetters[i] = 0;

	for(int i = 0; i < strlen(inputString); i++)
	{
		numberOfLetters[inputString[i]]++;
	}
	
	List * mainList = makeList();
	
	for(int i = 0; i < MAXN; i++)
	{
		if (numberOfLetters[i] > 0)
		{
			insertToSorted(makeTree(numberOfLetters[i], i), mainList);
		}
	}

	int length = sizeOfList(mainList);

	for (int i = 0; i < length - 1; ++i)
	{
		Tree * leftTree = firstInList(mainList);
		pop(mainList);
		Tree * rightTree = firstInList(mainList);
		pop(mainList);
		Tree * newTree = makeNewTree(leftTree, rightTree);
		insertToSorted(newTree, mainList);
	}

	Tree * mainTree = mainList->head->next->tree;
	char * final = toStr(mainTree);
	cout << final << endl;
	
	delete[] final;

	for(int i = 0; i < strlen(inputString); i++)
		print(mainTree, inputString[i]);
	
	deleteList(mainList);
	delete mainList;
	delete mainTree;

	return 0;
}