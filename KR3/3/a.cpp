/*
2 2 2 2 2 7 7
2 2 2 2 2 3 7
4 4 7 7 4 7 7
4 4 5 7 4 7 7
6 4 7 7 4 7 7
4 4 5 7 4 7 7
7 7 7 7 7 7 7
*/
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

const int maxSize = 1000;

int typeOf(char c)
{
	if(c >= 'A' && c <= 'Z')
		return 1;
	
	if(c >= '0' && c <= '9')
		return 2;
	
	if(c == '.')
		return 3;
		
	if(c == '_' || c == '%' || c == '+')
		return 4;

	if(c == '-')
		return 5;
	
	if(c == '@')
		return 6;
		
	return 7;
}

int main()
{
	freopen("text.in", "r", stdin);
	
	int g[10][10];
	int vertex = 1;
	
	for (int i = 1; i <= 7; i++)
	{
		for(int j = 1; j <= 7; j++)
		{
			cin >> g[i][j];
		}
	}
	char str[maxSize];
	cin >> str;
	
	for (int i = 0; i < strlen(str); i++)
	{
		vertex = g[vertex][typeOf(str[i])];
		cerr << vertex << endl;
	}
	
	if (vertex == 6)
		cout << "Good string";
	else
		cout << "Bad string";
	
	return 0;
}