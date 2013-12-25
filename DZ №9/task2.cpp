#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

const int maxStringSize = 100;
const long long p = 239017;

long long getHash(int left, int right, long long * powsOfP, long long * hashOfS1)
{
	if (left == 0) 
		return hashOfS1[right];
	
	return(hashOfS1[right] - hashOfS1[left - 1] * powsOfP[right - left + 1]);
}

int main()
{
	freopen("text.in", "r", stdin);
	
	char stringS1[maxStringSize];
	char stringS2[maxStringSize];

	scanf("%s", stringS1);
	int sizeOfStringS1 = (int)strlen(stringS1);
	
	scanf("%s", stringS2);
	int sizeOfStringS2 = (int)strlen(stringS2);
	
	long long hashOfS1[maxStringSize];
	hashOfS1[0] = (long long)stringS1[0];
	for (int i = 1; i < sizeOfStringS1; i++)
	{
		hashOfS1[i] = hashOfS1[i - 1] * p + (long long)stringS1[i];
	}

	long long hashOfS2 = (long long)stringS2[0];
	for (int i = 1; i < sizeOfStringS2; i++)
	{
		hashOfS2 = hashOfS2 * p + (long long)stringS2[i];
	}
	
	int answer = 0;

	long long powsOfP[maxStringSize];
	powsOfP[0] = 1;
	for (int i = 1; i < maxStringSize; i++)
	{
		powsOfP[i] = powsOfP[i - 1] * p; 
	}
	
	for (int i = 0; i + sizeOfStringS2 <= sizeOfStringS1; i++)
	{	
		if (getHash(i, i + sizeOfStringS2 - 1, powsOfP, hashOfS1) == hashOfS2)
		{
			cout << "Position " << i << endl;
			answer++;
		}
	}
		
	printf("S2 occurs %d times\n", answer);
			
	return 0;
}