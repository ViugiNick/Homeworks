#include "hashTable.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;
using namespace HashTables;

const int maxSize = 1000;

int main()
{
	freopen("table.in", "r", stdin);
	freopen("table.out", "w", stdout);

	int numberOfStrings = 0;
	scanf("%d", &numberOfStrings);
	HashTable MyTable = makeHashTable(numberOfStrings);
	char * str = new char[maxSize];
	
	while(cin >> str)
	{
		add(str, MyTable);
		delete[] str;
		str = new char[maxSize];
	}
	
	cout << "The average length : " << middleLists(MyTable) << endl;
	bigestList(MyTable);
	cout << endl;

	printHashTable(MyTable);
	deleteHashTable(MyTable);
	return 0;
}