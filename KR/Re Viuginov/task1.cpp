#include <cstdio>
#include <string.h>
#include <windows.h>
#include <cmath>

using namespace std;

const int maxSizeOfArray = 100;
const int maxInt = (int)1e9;

int inputArray[maxSizeOfArray];
int outputArray[maxSizeOfArray];
bool used[maxSizeOfArray];

int main()
{
	srand(GetTickCount());
	
	int sizeOfArray = 0;
	int type;

	printf("Input size of your array\n");
 	scanf("%d", &sizeOfArray);
	
	printf("Input 0, if you whant to input your array.\nInput 1, if you whant to work with random array\n");
 	scanf("%d", &type);
	
	if (type == 0)
	{
		for (int i = 0; i < sizeOfArray; i++)		
			scanf("%d", &inputArray[i]);
	}
	else
	{
		for (int i = 0; i < sizeOfArray; i++)
			inputArray[i] = rand() % 32 + 11;
	}
	
	for (int i = 0; i < sizeOfArray; i++)
		printf("%d ", inputArray[i]);
	printf("\n");
		
	for (int i = 1; i < sizeOfArray; i += 2)
		outputArray[i] = inputArray[i];
	
	for (int i = 0; i < sizeOfArray; i += 2)
	{
		int minElement = maxInt;
		int indexMinElement = 0;
		
		for (int j = 0; j < sizeOfArray; j += 2)
		{
			if (!used[j])
			{
				if (inputArray[j] < minElement)
				{
					minElement = inputArray[j];
					indexMinElement = j; 
				}
			}
		}
		
		outputArray[i] = minElement;
		used[indexMinElement] = true;
	}

	printf("Output array : ");	
	for (int i = 0; i < sizeOfArray; i++)
		printf("%d ", outputArray[i]);
	
	return 0;
}
