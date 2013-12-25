#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;

const int maxSizeOfString = 200;
char inputString[maxSizeOfString];	

int main()
{
	printf("Input your string\n");
	cin.getline(inputString, maxSizeOfString);
	
	int yourSize = 0;
	printf("Input size of your string\n");
	scanf("%d", &yourSize);

	int numberOfSpaces = 0;
	int sizeOfString = strlen(inputString);
	for (int i = 0; i < sizeOfString; i++)
	{
		if (inputString[i] == ' ')
		{
			numberOfSpaces++;
		}
	}
	
	int spaceAfrerEvery = (yourSize - sizeOfString) / (numberOfSpaces);
	int leftSpaces = (yourSize - sizeOfString) % (numberOfSpaces);
	printf("Output string : \n");
	
	for (int i = 0; i < sizeOfString; i++)
	{
		if (inputString[i] == ' ')
		{
			for (int j = 0; j < spaceAfrerEvery; j++)
				printf(" ");
			if (leftSpaces > 0)
			{
				printf(" ");
				leftSpaces--;
			}
		}
		printf("%c", inputString[i]); 
	}

	return 0;
}