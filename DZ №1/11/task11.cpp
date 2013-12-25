#include <cstdio>
#include <string.h>

using namespace std;

const int maxSizeOfArray = 100;

void qSort(int left, int right, int * inputArray)
{
  	int i = left; 
 	int j = right; 
  	int m = inputArray[(i + j) / 2];
	int temp = 0;
    
  	do
  	{
  		while (inputArray[i] < m) 
  		{
  			i++; 
        }
        
        while (inputArray[j] > m)
        {	
        	j--; 
        }
        
        if (i <= j)
        {
          	temp = inputArray[i]; 
          	inputArray[i] = inputArray[j]; 
          	inputArray[j] = temp;
          	i++; 
          	j--;
        }
  	}
  	while(i <= j);    
  
  
  	if (left < j) 
  	{
  		qSort(left, j, inputArray);
  	}
  	
  	if (i < right)
  	{
  		qSort(i, right, inputArray); 
  	}	
}

int main()
{
	printf("Input size of your array:\n");
	int sizeOfArray = 0;
	scanf("%d", &sizeOfArray);
	
	int inputArray[maxSizeOfArray];
	
	printf("Input your array:\n");
	
	for(int i = 0; i < sizeOfArray; i++)
		scanf("%d", &inputArray[i]);

	qSort(0, sizeOfArray - 1, inputArray);
	
	printf("Sorted array:\n");
	for(int i = 0; i < sizeOfArray; i++)
		printf("%d ", inputArray[i]);
	
	return 0;
}