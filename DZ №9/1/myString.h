
namespace myStrings
{
	struct MyString
	{
		int size;
		char * mainStr;
	};
	
	MyString makeStr();
	MyString toStr(char *str);
	MyString cloneStr(const MyString &myStr);
	MyString concStr(const MyString &myStr1, const MyString &myStr2);
	char * toStr(const MyString &myStr);
	void printStr(const MyString &myStr);
	int length(const MyString &myStr);
	bool isEqual(const MyString &myStr1, const MyString &myStr2);
	bool isEmpty(const MyString &myStr);
	MyString subStr(int begin, int end, const MyString &myStr);
	void deleteStr(MyString &myStr);
}