#include <cstdio>
#include <string.h>

using namespace std;

const int maxSizeOfArray = 10000;

void qSort(int left, int right, int * inputArrayA, int * inputArrayB)
{
	int i = left; 
	int j = right; 
  	
	int mA = inputArrayA[(i + j) / 2];
	int mB = inputArrayB[(i + j) / 2];
	
	int tempA = 0;
	int tempB = 0;
  	
	do
  	{
		while (inputArrayA[i] * mB < inputArrayB[i] * mA) 
		{
			i++; 
		}
        
		while (inputArrayA[j] * mB > inputArrayB[j] * mA)
		{	
			j--; 
		}
        
		if (i <= j)
		{
			tempA = inputArrayA[i]; 
			tempB = inputArrayB[i]; 
          	
			inputArrayA[i] = inputArrayA[j]; 
			inputArrayB[i] = inputArrayB[j]; 
          	
			inputArrayA[j] = tempA;
			inputArrayB[j] = tempB;
          	
			i++; 
			j--;
		}
	}
	while (i <= j);    
  
  
	if (left < j) 
	{
		qSort(left, j, inputArrayA, inputArrayB);
	}
  	
	if (i < right)
	{
		qSort(i, right, inputArrayA, inputArrayB); 
	}	
}

int gcd(int a, int b)
{
	while (true)
	{
		a = a % b;
		if (a == 0)
			return b;
		b = b % a;

		if (b == 0)
			return a;
	}
}

int main()
{
	int inputN = 0;
	scanf("%d", &inputN);

	int numerators[maxSizeOfArray];
	int denominators[maxSizeOfArray];
	
	int numberOfFractions = 0;
	
	for (int i = 1; i <= inputN; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (gcd(i, j) == 1)
			{
				numerators[numberOfFractions] = j;
				denominators[numberOfFractions] = i;
				
				numberOfFractions++;
			}
		}
	}

	qSort(0, numberOfFractions - 1, numerators, denominators);

	for (int i = 0; i < numberOfFractions; i++)
	{
		if (i != 0)
			printf("; ");
			
		printf("%d / %d ", numerators[i], denominators[i]);
	}
	return 0;
}