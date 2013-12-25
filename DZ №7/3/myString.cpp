#include "myString.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::cerr;
using std::endl;

namespace myStrings
{
	MyString makeStr()
	{
		MyString myStr;
		myStr.size = 0;
		myStr.mainStr = NULL;
		return myStr;
	}
	
	MyString toStr(char *str)
	{
		MyString myStr = makeStr();
		int length = strlen(str);
		const int size = length + myStr.size;
		myStr.size = size;
		myStr.mainStr = new char[size];
		for(int i = 0; i < size; ++i)
		{
			myStr.mainStr[i] = str[i];
		}
		cerr << "!!!";
		for(int i = 0; i < size; ++i)
		{
			cerr << myStr.mainStr[i];
		}
		cerr << endl;
		return myStr;
	}
	
	MyString cloneStr(const MyString &myStr)
	{
		MyString ans = toStr(myStr.mainStr);
		return ans;
	}
	
	MyString concStr(const MyString &myStr1, const MyString &myStr2)
	{
		MyString answer = makeStr();
		answer.size = myStr1.size + myStr2.size;
		answer.mainStr = new char[answer.size];
		for(int i = 0; i < answer.size; ++i)
		{
			if(i < myStr1.size)
				answer.mainStr[i] = myStr1.mainStr[i];
			else
				answer.mainStr[i] = myStr2.mainStr[i - myStr1.size];
		}

		return answer;
	}

	char * toStr(const MyString &myStr)
	{
		return myStr.mainStr;
	}

	void printStr(const MyString &myStr)
	{
		for(int i = 0; i < myStr.size; ++i)
			cout << myStr.mainStr[i];
	}

	int length(const MyString &myStr)
	{
		return myStr.size;
	}

	bool isEqual(const MyString &myStr1, const MyString &myStr2)
	{
		if(myStr1.size == myStr2.size)
		{
			for(int i = 0; i < myStr1.size; ++i)
			{
				if(myStr1.mainStr[i] != myStr2.mainStr[i])
					return false;
			}
			return true;
		}
		return false;
	}

	bool isEmpty(const MyString &myStr)
	{
		return (myStr.size == 0);
	}

	MyString subStr(int begin, int end, const MyString &myStr)
	{
		const int size = end - begin;
		MyString answer;
		answer.size = size;
		answer.mainStr = new char[size];
		
		for(int i = begin; i < end; ++i)
			answer.mainStr[i - begin] = myStr.mainStr[i];
		return answer;
	}
	
	void deleteStr(MyString &myStr)
	{
		delete[] myStr.mainStr;
		myStr.mainStr = NULL;
	}
}