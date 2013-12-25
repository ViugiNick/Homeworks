#include "list.h"

using namespace ListSpace;

namespace HashTableSpace
{
	struct HashTable
	{
		List * arr;
		int size;
	};

	HashTable makeHashTable(int size);
	int hash(MyString &str, int size);
	void add(MyString &str, const HashTable &MyTable);
	void printHashTable(const HashTable &MyTable);
	void deleteHashTable(HashTable &MyTable);
	int middleLists(const HashTable &MyTable);
	void bigestList(const HashTable &MyTable);
}