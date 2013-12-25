#include <cstdio>
#include <string.h>

using namespace std;

const int maxSizeOfString = 100;

int main()
{
	char inputString[maxSizeOfString];
  
	printf("Enter your string : \n");
	scanf("%s", inputString);

	int sizeOfString = (int)strlen(inputString);
	int balance = 0;
	
	for (int i = 0; i < sizeOfString; i++)
	{
		if (inputString[i] == '(')
			balance++;
		else
			balance--;
			
		if (balance < 0)
		{
			break;
		}	
	}
	
	if (balance == 0)
	{
		printf("Right string!\n");
	}
	else
	{
		printf("Not a right string!\n");
	}
	
	return 0;
}