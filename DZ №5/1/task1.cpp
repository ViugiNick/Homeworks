#include <cstdio>
#include <string.h>

using namespace std;

const int maxSizeOfString = 130;
const int maxChar = 500;
char inputString[maxSizeOfString];
int charIsUsed[maxSizeOfString];

int main()
{
	freopen("a.in", "r", stdin);
	
	while (scanf("%s", &inputString) > 0)
	{
		for (int i = 0; i < maxSizeOfString; i++)
			charIsUsed[i] = 0;
		for (int i = 0; i < strlen(inputString); i++)
			charIsUsed[int(inputString[i])] = 1;
				
		for (int i = 0; i < strlen(inputString); i++)
			if (charIsUsed[int(inputString[i])] == 1)
			{	
				charIsUsed[int(inputString[i])]--;
				printf("%c", inputString[i]);
			}
			
		printf("\n");	
	}
	
	return 0;
}