#include <cstdio>
#include <string.h>

using namespace std;

const int maxInputNumber = 100;

int main()
{
	bool isSimple[maxInputNumber];

	for (int i = 0; i < maxInputNumber; i++)
	{
		isSimple[i] = true;
	}
	
	int inputNumber = 0;	
	scanf("%d", &inputNumber);	
		
	for (int i = 2; i < inputNumber; i++)
	{
		if(isSimple[i])
		{
			for (int j = 2 * i; j <= inputNumber; j += i)
			{
				isSimple[j] = false;
			}
		}
	}	
 
	int numberOfSimple = 0;
	
	for (int i = 2; i <= inputNumber; i++)
	{
		if (isSimple[i])
		{
			printf("%d\n", i);		
	
			numberOfSimple++;
		}
	}
	
	printf("Total : %d\n", numberOfSimple);		
			
	return 0;
}