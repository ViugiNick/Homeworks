#include "pair.h"
#include <iostream>
#include <string.h>

using namespace std;

bool isStringsEqual(MyString &str1, MyString &str2)
{
	int length1 = length(str1);
	int length2 = length(str2);

	if (length1 != length2) 
		return false;

	for (int i = 0; i < length1; i++)
	{
		if (str1.mainStr[i] != str2.mainStr[i])
			return false;
	}
	return true;
}

void printSecond(const Pair &p)
{
	int len = length(p.str);
	for (int i = 0; i < len; ++i)
		cout << p.str.mainStr[i];
}

void printPair(const Pair &p)
{
	cout << "|";
	int length = lengthOfMyString(p.str);
	for (int i = 0; i < length; ++i)
	{
		cout << p.str.mainString[i];
	}
	cout << " * " << p.number << "| ";
}

void deletePair(Pair &p)
{
	if (p.str.mainString != NULL)
		deleteMyString(p.str);
}