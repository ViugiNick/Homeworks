#include "hashTable.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;
using namespace HashTables;

const int maxSize = 1000;
const int numberOfStrings = 100;

int main()
{
	freopen("table.in", "r", stdin);
	freopen("table.out", "w", stdout);

	HashTable MyTable = makeHashTable(numberOfStrings);
	int sizeOfString;
	
	cin >> sizeOfString;	
	for(int i = 0; i < sizeOfString; i++)
	{	
		char * str = new char[maxSize];
		cin >> str;
		add(toStr(str), MyTable);
		delete[] str;
	}
	cerr << "NEXT File" << endl;
	//printHashTable(MyTable);

	freopen("table2.in", "r", stdin);

	cin >> sizeOfString;
	for(int i = 0; i < sizeOfString; i++)
	{	
		char * str = new char[maxSize];
		cin >> str;
		MyString myStr = toStr(str);
		
		if(inTable(myStr, MyTable))
		{
			cout << str << endl;
		}
		
		deleteStr(myStr);
		delete[] str;
	}
	deleteHashTable(MyTable);
	return 0;
}