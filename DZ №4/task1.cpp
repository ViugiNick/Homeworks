#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxArraySize = 100;

void updateArray(int * inputArray, int left, int right)
{
	int j = left;
 	int newElem = inputArray[left];
 	
 	while (j <= right / 2) 
 	{
 		int futureIndex = 2 * j;
 		if (futureIndex < right && inputArray[futureIndex] < inputArray[futureIndex + 1]) 
 			futureIndex++;
 		
 		if (newElem >= inputArray[futureIndex]) 
 			break; 
 	
 		inputArray[j] = inputArray[futureIndex];
 		j = futureIndex;
   	}
   	inputArray[j] = newElem;
}

int main()
{
	int sizeOfArray = 0;
	printf("Input size of your array : \n");
	scanf("%d", &sizeOfArray);
	
	
	int inputArray[maxArraySize]; 
	printf("Input your array : \n");
	for (int i = 0; i < sizeOfArray; i++)
		scanf("%d", &inputArray[i]);
	
	for (int i = sizeOfArray / 2; i >= 0; i--)
	{
		updateArray(inputArray, i, sizeOfArray - 1);	
	}	

	for (int i = sizeOfArray - 1; i >= 0; i--)
	{
		int temp = inputArray[0];
		inputArray[0] = inputArray[i];
		inputArray[i] = temp;
		
		updateArray(inputArray, 0, i - 1);	
	}
	
	for (int i = sizeOfArray - 1; i >= 1; i--)
	{
		if(inputArray[i] == inputArray[i - 1])
		{
			printf("Your element is : %d", inputArray[i]);
			exit(0);
		}
	}

	printf("No such element");
			
	return 0;
}