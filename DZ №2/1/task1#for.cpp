#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
	int indexOfFibonacci = 0;
	printf("Input index of fibonacci number, you whant\n");
	scanf("%d", &indexOfFibonacci);
	
	int preFibonacci = 1;
	int prepreFibonacci = 1;
	
	for (int i = 3; i <= indexOfFibonacci; i++)
	{
		int temp = preFibonacci + prepreFibonacci;
		
		prepreFibonacci = preFibonacci;
		preFibonacci = temp;
	}
		
	printf("Your number = %d", preFibonacci);


	
	return 0;
}