#include <cstdio>
#include <string.h>

using namespace std;

const int maxStringSize = 100;

void reverseSubStr(int left, int right, char* a)
{
	for (int i = 0; 2 * i < (right - left); i++)
	{
		a[left + i] += a[right - i];
		a[right - i] = a[left + i] - a[right - i];
		a[left + i] -= a[right - i]; 
	}
}

int main()
{
	char inputString[maxStringSize];
	int inputN = 0; 
	int inputM = 0; 
	
	printf("Input string : \n");
	scanf("%s", inputString);
	
	printf("Input M and N : \n");
	scanf("%d%d", &inputM, &inputN);
	
	reverseSubStr(0, inputM - 1, inputString);
	reverseSubStr(inputM, inputM + inputN - 1, inputString);
	reverseSubStr(0, inputM + inputN - 1, inputString);
	
	printf("Your new string is :\n%s\n", inputString);
	
	return 0;
}