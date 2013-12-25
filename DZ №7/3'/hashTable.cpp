#include "hashTable.h"
#include <string.h>
#include <iostream>

using namespace std;

namespace HashTableSpace
{
	HashTable makeHashTable(int size)
	{
		HashTable TempTable;
		hashT.size = size;
		hashT.all = new List[size];
		for (int i = 0; i < size; ++i)
		{
			List st;
			init(st);
			hashT.all[i] = st;
		}
		return TempTable;
	}

	int hash(MyString &str, int size)
	{
		int p = 239017; 
		int len = length(str);
		int ans = 0;
		for (int i = 0; i < len; ++i)
			ans = (ans * p  + str.mainStr[i]) % size;
		return ans;
	}

	void add(MyString &str, const HashTable &MyTable)
	{
		int TempHash = hash(str, MyTable.size);
		insert(str, MyTable.all[TempHash]);	
	}

	void printHashTable(const HashTable &MyTable)
	{
		for (int i = 0; i < MyTable.size; ++i)
		{
			if (!isEmpty(MyTable.all[i]))
			{
				printList(MyTable.all[i]);
				cout << endl;
			}
		}
	}

	void deleteHashTable(HashTable &MyTable)
	{
		for (int i = 0; i < MyTable.size; ++i)
			deleteList(MyTable.all[i]);
		delete[] MyTable.all;
	}

	int middleLists(const HashTable &MyTable)
	{
		int sum = 0;
		for (int i = 0; i < MyTable.size; i++)
			sum += length(MyTable.all[i]);
		return sum / MyTable.size;
	}

	void bigestList(const HashTable &MyTable)
	{
		int maxx = 0;
		int index = 0;
		for (int i = 0; i < MyTable.size; ++i)
		{
			if (maxx < length(hashT.all[i]))
			{
				maxx = length(hashT.all[i]);
				index = i;
			}
		}
		cout << maxx << " ";
		printList(MyTable.all[index]);
	}
}