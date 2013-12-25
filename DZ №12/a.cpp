#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

const int maxSize = 1000;

bool isGoodSum(char *inputString, int &currentSymbol, int right);
bool isGoodPre(char *inputString, int &currentSymbol, int right);
bool isGoodMult(char *inputString, int &currentSymbol, int right);
bool isGoodBracket(char *inputString, int &currentSymbol, int right);
bool isGoodExpression(char *inputString, int &currentSymbol, int right);
bool isGoodDouble(char *inputString, int &left, int right);

int typeOf(char c)
{
	if(c == '+' || c == '-')
		return 1;
	
	if(c >= '0' && c <= '9')
		return 2;
	
	if(c == 'E')
		return 3;
		
	if(c == '.')
		return 5;

	return 4;
}

bool isGoodDouble(char *inputString, int &left, int right)
{
	//cerr << "LOL" << endl;
	int g[10][10];
	int vertex = 1;
	
	g = {
			{0, 0, 0, 0, 0, 0},
			{0, 2, 3, 8, 8, 8},
			{0, 8, 3, 8, 8, 8},
			{0, 8, 3, 7, 8, 4},
			{0, 8, 5, 8, 8, 8},
			{0, 8, 5, 6, 8, 8},
			{0, 7, 9, 8, 8, 8},
			{0, 8, 7, 8, 8, 8},
			{0, 8, 8, 8, 8, 8},
			{0, 8, 9, 8, 8, 8}
		};
	for (left; left < right; left++)
	{
		if (((vertex == 3 || vertex == 5 || vertex == 9 || vertex == 7) && typeOf(inputString[left - 1]) == 2) && (g[vertex][typeOf(inputString[left])] == 8))
		{
			//cerr << inputString[left] << endl;
			return true;
		}
		vertex = g[vertex][typeOf(inputString[left])];
	}
	
	if ((vertex == 3 || vertex == 5 || vertex == 9 || vertex == 7) && typeOf(inputString[left - 1]) == 2)
	{
		//cerr << inputString[left] << endl;
		return true;
	}
	else
		return false;
	
}

bool isGoodSum(char *inputString, int &left, int right) 
{
	if(left == right)
		return true;

	if(inputString[left] == '+' || inputString[left] == '-') 
	{
		left++;
		return(isGoodPre(inputString, left, right) && isGoodSum(inputString, left, right));
	}
	return true;
}

bool isGoodPre(char *inputString, int &left, int right) 
{
	if (left == right)
		return true;

	return isGoodBracket(inputString, left, right) && isGoodMult(inputString, left, right);
}

bool isGoodMult(char *inputString, int &left, int right) 
{
	if (left == right)
		return true;

	if (inputString[left] == '*' || inputString[left] == '/') 
	{
		left++;
		return isGoodBracket(inputString, left, right) && isGoodMult(inputString, left, right);
	}

	return true;
}

bool isGoodBracket(char *inputString, int &left, int right) 
{
	if(left == right)
		return true;

	if(inputString[left] == '(') 
	{
		left++;
		
		if(isGoodExpression(inputString, left, right) && inputString[left] == ')')
		{
			left++;
			return true;
		}

		return false;
	}

	int oldLeft = left;

	if(isGoodDouble(inputString, left, right))
		return true;

	left = oldLeft;
	return false;
}

bool isGoodExpression(char *inputString, int &left, int right) 
{
	if (left == right)
		return true;

	cerr << isGoodPre(inputString, left, right) << " " << isGoodSum(inputString, left, right) << endl;
		
	return (isGoodPre(inputString, left, right) && isGoodSum(inputString, left, right));
}

int main() 
{
	freopen("text.in", "r", stdin);
	char inputString[maxSize];

	printf("Enter your expression:\n");
	cin >> inputString;
	cout << inputString <<endl;
	
	int right = strlen(inputString);

	int left = 0;
	
	if (isGoodExpression(inputString, left, right) && (left == right))
		cout << "Good string";
	else
		cout << "Bad string";
		
	return 0;
}