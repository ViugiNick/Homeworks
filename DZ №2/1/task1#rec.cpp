#include <cstdio>
#include <string.h>

using namespace std;

int recFibonacci(int indexOfFibonacci) 
{
	if (indexOfFibonacci <= 2)
		return 1;
	
	return (recFibonacci(indexOfFibonacci - 1) + recFibonacci(indexOfFibonacci - 2)); 
}

int main()
{
	int indexOfFibonacci = 0;
	printf("Input index of fibonacci number, you whant\n");
	scanf("%d", &indexOfFibonacci);
	
	int yourNumber = recFibonacci(indexOfFibonacci);
	printf("Your number = %d", yourNumber);
	
	return 0;
}