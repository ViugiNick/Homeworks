#include "hashTable.h"
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

namespace HashTables
{
	HashTable makeHashTable(int size)
	{
		HashTable tempTable;
		tempTable.size = size;
		tempTable.all = new Stack[size];
		for (int i = 0; i < size; ++i)
		{
			Stack st;
			makeStack(st);
			tempTable.all[i] = st;
		}
		return tempTable;
	}

	int hash(MyString str, int size)
	{
		int p = 239017; 
		int ans = 0;
		for (int i = 0; i < length(str); ++i)
			ans = (ans * p  + toStr(str)[i]) % size;
		return ans;
	}

	void add(MyString str, const HashTable &myTable)
	{
		int TempHash = hash(str, myTable.size);
		push(myTable.all[TempHash], str);
	}

	void printHashTable(const HashTable &myTable)
	{
		for (int i = 0; i < myTable.size; ++i)
		{
			cout << i << ") ";
			if (sizeOfStack(myTable.all[i]) != 0)
				printStack(myTable.all[i]);
			cout << endl;
		}
	}

	void deleteHashTable(HashTable &myTable)
	{
		for (int i = 0; i < myTable.size; ++i)
			stackDelete(myTable.all[i]);
		delete[] myTable.all;
	}

	int middleLists(const HashTable &myTable)
	{
		int sum = 0;
		for (int i = 0; i < myTable.size; ++i)
			sum += sizeOfStack(myTable.all[i]);
		return sum / myTable.size;
	}

	void bigestList(const HashTable &myTable)
	{
		int maxx = 0;
		int index = 0;
		for (int i = 0; i < myTable.size; ++i)
		{
			if (maxx < sizeOfStack(myTable.all[i]))
			{
				maxx = sizeOfStack(myTable.all[i]);
				index = i;
			}
		}
		cout << maxx << ": ";
		printStack(myTable.all[index]);
	}
}