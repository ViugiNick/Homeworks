/*
2 3 8 8 8
8 3 8 8 8
8 3 7 8 4
8 5 8 8 8
6 5 7 8 8
8 8 7 8 8
8 7 8 8 8
8 8 8 8 8
*/

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <iostream>

using namespace std;

const int maxSize = 1000;

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

int main()
{
	freopen("text.in", "r", stdin);
	
	int g[10][10];
	int vertex = 1;
	
	for (int i = 1; i <= 9; i++)
	{
		for(int j = 1; j <= 5; j++)
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
	
	if (vertex == 3 || vertex == 5 || vertex == 9)
		cout << "Good string";
	else
		cout << "Bad string";
	
	return 0;
}