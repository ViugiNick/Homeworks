#include <cstdio>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <cstdlib>

using namespace std;

const int maxSize = 100;

bool isDate(char * str)
{
	if(strlen(str) != 10 || str[2] != '.' || str[5] != '.')
	{
		return false;
	}
	
	for(int i = 0; i < 10; i++)
	{
		if(i != 2 && i != 5 && !(str[i] >= '0' && str[i] <= '9'))
			return false;
	}
	
	return true;
}

int toNumber(char c)
{
	return(int(c - '0'));
}

char * maxDate(char * str1, char * str2)
{
	int d1 = toNumber(str1[0]) * 10 + toNumber(str1[1]);
	int d2 = toNumber(str2[0]) * 10 + toNumber(str2[1]);
	
	int m1 = toNumber(str1[3]) * 10 + toNumber(str1[4]);
	int m2 = toNumber(str2[3]) * 10 + toNumber(str2[4]);
	
	int y1 = toNumber(str1[6]) * 1000 + toNumber(str1[7]) * 100 + toNumber(str1[8]) * 10 + toNumber(str1[9]);
	int y2 = toNumber(str2[6]) * 1000 + toNumber(str2[7]) * 100 + toNumber(str2[8]) * 10 + toNumber(str2[9]);
	
	if(y1 >= y2 || (y1 == y2 && m1 >= m2) || (y1 == y2 && m1 == m2 && d1 >= d2))
		return str1;
	else
		return str2;
}

int main()
{
	freopen("text.in", "r", stdin);

	char * str = new char[maxSize];
	char * ans = new char[10];
	ans = "";
	while(cin >> str)
	{
		if(isDate(str))
		{
			if(ans == "")
				ans = str;
			else
				ans = maxDate(ans, str);
		}
	}
	
	if(ans == "")
		printf("No date in input");
	else
		printf("%s", ans);
	
	delete[] str;
	delete[] ans;
	
	return 0;
}