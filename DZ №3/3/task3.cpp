#include <cstdio>
#include <string.h>

using namespace std;

const int maxSizeOfNumber = 100;

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
	printf("Input your number:\n");
	int inputNumber = 0;
	scanf("%d", &inputNumber);

	int inputArray[maxSizeOfNumber];
	int index = 0;
	
	while(inputNumber > 0)
	{
		inputArray[index++] = inputNumber % 10;
		inputNumber /= 10;
	}
	
	qSort(0, index - 1, inputArray);
	
	int answer = 0;
	
	for(int i = 0; i < index; i++)
	{	
		answer *= 10;
		answer += inputArray[i];
	}
	
	printf("Your number : %d", answer);
	
	return 0;
}