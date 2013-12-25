//#include "myString.h"
#include "stack_Viu.h"

using namespace Stacks;
using namespace myStrings;

namespace HashTables
{
	struct HashTable
	{
		Stack * all;
		int size;
	};

	HashTable makeHashTable(int size);
	int hash(MyString str, int size);
	void add(MyString str, const HashTable &MyTable);
	void printHashTable(const HashTable &MyTable);
	void deleteHashTable(HashTable &MyTable);
	int middleLists(const HashTable &MyTable);
	void bigestList(const HashTable &MyTable);
}