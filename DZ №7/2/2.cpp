#include <iostream>
#include "myString.h"

using namespace std;
using namespace myStrings;

int main()
{
	MyString myStr = makeStr();
	myStr = toStr("Nickolay");
	MyString myStr2 = toStr("Viuginov");

	MyString conStr = concStr(myStr, myStr2);
	MyString subString = subStr(4, 9, conStr);
	printStr(subString);
	
	deleteStr(myStr);
	deleteStr(myStr2);
	deleteStr(conStr);
	deleteStr(subString);
	
	return 0;
}