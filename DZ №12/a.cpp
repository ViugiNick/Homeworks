#include <iostream>
#include <string.h>
#include <cstdio>
#include "parseDouble.h"

using namespace std;

bool isGoodExpression(int &left, char *& inputString, const int right);
bool isGoodPre(int &left, char *& inputString, const int right); 
bool isGoodSum(int &left, char *& inputString, const int right);
bool isGoodMul(int &left, char *& inputString, const int right);
bool isGoodBracket(int &left, char *& inputString, const int right);
bool isGoodNumber(int &left, char *& inputString, const int right);

const int maxSize = 100;

bool isGoodExpression(int &left, char *& inputString, const int right)
{
	if (left == right)
		return true;
	return (isGoodPre(left, inputString, right) * isGoodSum(left, inputString, right));
}

bool isGoodPre(int &left, char *& inputString, const int right)
{
	if (left == right)
		return true;
	
	return (isGoodBracket(left, inputString, right) * isGoodMul(left, inputString, right));
}

bool isGoodSum(int &left, char *& inputString, const int right)
{
	if (left == right)
		return true;

	int curIndex = left;
	
	if ((inputString[left] == '+') || (inputString[left] == '-'))
	{
		left++;
		return (isGoodPre(left, inputString, right) * isGoodSum(left, inputString, right));
	}
	left = curIndex;
	return true;
}

bool isGoodMul(int &left, char *& inputString, const int right)
{
	if (left == right)
		return true;

	int curIndex = left;
	if ((inputString[left] == '*') || (inputString[left] == '/'))
	{
		left++;
		return (isGoodBracket(left, inputString, right) * isGoodMul(left, inputString, right));
	}
	left = curIndex;
	return true;
}

bool isGoodBracket(int &left, char *& inputString, const int right)
{
	int curIndex = left;
	if ((inputString[left] == '(') && (isGoodExpression(++left, inputString, right) && inputString[left] == ')'))
	{
		left++;
		return true;
	}
	left = curIndex;

	if (isGoodNumber(left, inputString, right))
		return true;
	left = curIndex;
	return false;
}

bool isGoodNumber(int &left, char *& inputString, const int right)
{
	return (isGoodDouble(inputString, right, left));
}

int main()
{
	freopen("text.in", "r", stdin);
	
	char * inputString = new char[maxSize];
	cin >> inputString;

	int left = 0;
	const int sizeOfString = strlen(inputString);

	if((isGoodExpression(left, inputString, sizeOfString)) && (left == sizeOfString))
		cout << "Good string";
	else
		cout << "Bad sring";
	
	delete[] inputString;
	
	return 0;
}