#include <iostream>
#include <string.h>
#include "parseDouble.h"

using namespace std;

enum State
{
	start, 
	integerPart, 
	dotPart, 
	exponentPart, 
	afterExponentPart
};

bool isDigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

bool isSign(char ch)
{
	return (ch == '+' || ch == '-');
}

bool isExponent(char ch)
{
	return (ch == 'E');
}

bool isDot(char ch)
{
	return (ch == '.');
}

bool isFinishState(State vertex)
{
	return (vertex == integerPart || vertex == dotPart || vertex == afterExponentPart);
}

bool isFinishState(State vertex);

bool isGoodDouble(char *& str, const int right, int &left)
{
	State vertex = start;

	while(left < right)
	{
		char curChar = inputString[left];
		
		switch(vertex)
		{
		
		case start:
			if (isSign(curChar))
			{
				vertex = integerPart;
				left++;
				
				if (!((left != right) && isDigit(inputString[left])))
					return false;
			}
			else 
			if (isDigit(curChar))
				vertex = integerPart;
			else
				return false;
			
			break;

		case integerPart:
			if (isDigit(curChar))
				left++;
			else if (isDot(curChar))
			{
				vertex = dotPart;
				left++;
				if (!((left != right) && isDigit(inputString[left])))
					return false;
			}
			else if (isExponent(curChar))
			{
				vertex = exponentPart;
				left++;
				if (!((left != right) && (isDigit(inputString[left]) || isSign(inputString[left]))))
					return false;
			}
			else
				return true;
			break;

		case dotPart:
			if (isDigit(curChar))
				left++;
			else if (isExponent(curChar))
			{
				vertex = exponentPart;
				left++;
				
				if (!((left != right) && (isDigit(inputString[left]) || isSign(inputString[left]))))
					return false;
			}
			else
				return true;
			break;

		case exponentPart:
			if (isSign(curChar))
			{
				vertex = afterExponentPart;
				left++;
				if (!((left != right) && isDigit(inputString[left])))
					return false;
			}
			else if (isDigit(curChar))
				vertex = afterExponentPart;
			else
				return false;
			break;

		case afterExponentPart:
			if (isDigit(curChar))
				left++;
			else
				return true;
			break;
		}
	}

	if (isFinishState(vertex))
		return true;
	return false;
}