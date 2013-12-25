#include <iostream>
#include <string.h>
#include "tree.h"

using std::cin;
using std::cout;
using std::getline;

using namespace Trees;
using namespace std;

const int maxSize = 200;

char inputString[maxSize];

int main()
{
	cin.getline(inputString, maxSize);
	cout << endl;
	
	Tree *mainTree = create(inputString);
	printTree(mainTree);
	cout << endl << "Answer : " << answer(mainTree) << endl;
	
	deleteTree(mainTree);
	mainTree = NULL;
	
	return 0;
}