#include <cstdio>
#include <string.h>

using namespace std;

const int maxSum = 100;

void recExpansion(int sum, int minSummand, int * alreadyDone, int sizeOfAlreadyDone)
{
	if (sum == 0)
	{
		for (int i = 0; i < sizeOfAlreadyDone; i++)
		{
			if(i != 0)
				printf(" + ");
			
			printf("%d", alreadyDone[i]);
		}
		printf("\n");
	}
	else
	{
		for (int i = minSummand; i <= sum; i++)
		{
			alreadyDone[sizeOfAlreadyDone] = i;
			recExpansion(sum - i, i, alreadyDone, sizeOfAlreadyDone + 1);
		}
	}	
}

int main()
{
	int inputSum = 0;	
	
	printf("Input your sum\n");
	
	scanf("%d", &inputSum);	
	
	int alreadyDone[maxSum]; 
	
	recExpansion(inputSum, 1, alreadyDone, 0);
	
	return 0;
}