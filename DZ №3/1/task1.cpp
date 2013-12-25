#include <cstdio>
#include <string.h>

using namespace std;

const int maxC = 130;

int main()
{
	int sizeOfString = 0;
	printf("Input size of your strings:\n");
	scanf("%d", &sizeOfString);
	
	char *inputString1 = new char[sizeOfString];
	char *inputString2 = new char[sizeOfString];
	
	printf("Input your first string:\n");
	scanf("%s", inputString1);
	
	
	printf("Input your second string:\n");
	scanf("%s", inputString2);

	int *numbersOfChar = new int[maxC];
	
	for (int i = 0; i < maxC; i++)
	{	
		numbersOfChar[i] = 0;
	}
	
	for (int i = 0; i < sizeOfString; i++)
		numbersOfChar[int(inputString1[i])]++;	
	
	for (int i = 0; i < sizeOfString; i++)
		numbersOfChar[int(inputString2[i])]--;
		
	bool flag = true;	
		
	for (int i = 0; i < maxC; i++)
	{	
		if (numbersOfChar[i] != 0)
		{
			flag = false; 
			break;
		}	
	}
		
	printf(flag ? "Yes" : "No");	
	
	delete [] inputString1;
	delete [] inputString2;
	delete [] numbersOfChar;
	
	numbersOfChar = NULL;
	inputString1 = NULL;
	inputString2 = NULL;
	return 0;
}