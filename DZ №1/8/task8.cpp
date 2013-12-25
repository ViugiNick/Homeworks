#include <cstdio>
#include <string.h>

using namespace std;

int countingOfFactorial(int number)
{
	if (number != 1)
		return number * countingOfFactorial(number - 1);
	return 1;
} 

int main()
{
	int inputNumber;
	
	scanf("%d", &inputNumber);
	
	int cyclicFactorial = 1; 
	
	int recursiveFactorial = countingOfFactorial(inputNumber);
	
	for (int i = 1; i <= inputNumber; i++)
		cyclicFactorial *= i;

	printf("Cyclic Factorial : %d \nRecursive Factorial : %d \n", cyclicFactorial, recursiveFactorial);				
	
	return 0;
}