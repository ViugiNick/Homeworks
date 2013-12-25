#include <cstdio>
#include <string.h>

using namespace std;

const int maxSizeOfArray = 130;

int main()
{
	int sizeOfArray = 0;
	printf("Input size of your array:\n");
	scanf("%d", &sizeOfArray);
	
	int inputArray[maxSizeOfArray][maxSizeOfArray];
	
	for(int i = 0; i < sizeOfArray; i++)
	{	
		for(int j = 0; j < sizeOfArray; j++)
		{
			scanf("%d", &inputArray[i][j]);
		}	
	}

	int answer[maxSizeOfArray * maxSizeOfArray];
	int indexInAnswer = 0;
	
	for(int i = 0; i < (sizeOfArray - 1) / 2; i++)
	{
		for(int j = i; j < sizeOfArray - i; j++)
		{
			answer[indexInAnswer++] = inputArray[i][j];
		}
		for(int j = sizeOfArray - i - 2; j >= i + 1; j--)
		{
			answer[indexInAnswer++] = inputArray[j][sizeOfArray - 1 - i];
		}
		for(int j = sizeOfArray - i - 1; j >= i; j--)
		{
			answer[indexInAnswer++] = inputArray[sizeOfArray - 1 - i][j];
		}
		for(int j = i + 1; j < sizeOfArray - i - 1; j++)
		{
			answer[indexInAnswer++] = inputArray[j][i];
		}
	}
	answer[indexInAnswer] = inputArray[(sizeOfArray - 1) / 2][(sizeOfArray - 1) / 2];
	
	for(int i = indexInAnswer; i >= 0; i--)
		printf("%d ", answer[i]);
	
	return 0;
}