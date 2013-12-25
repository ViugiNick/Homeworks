#include <cstdio>
#include <string.h>

using namespace std;

const int maxDigit = 10;
const int maxSum = 30;

int sqr(int number)
{
	return number * number; 
}

int main()
{

	int numberOfTicketsWithThisSum[maxSum];	
	int numberOfLuckyTickets = 0;
	
	for (int i = 0; i < maxSum; i++)
	{
		numberOfTicketsWithThisSum[i] = 0;
	}
	
	for (int i1 = 0; i1 < maxDigit; i1++)
	{
		for (int i2 = 0; i2 < maxDigit; i2++)
		{
			for (int i3 = 0; i3 < maxDigit; i3++)
			{
				numberOfTicketsWithThisSum[i1 + i2 + i3]++;		
			}
		}
	}

	for (int i = 0; i < maxSum; i++)
	{
		numberOfLuckyTickets += sqr(numberOfTicketsWithThisSum[i]); 	
	}
	
	printf("Number of Lucky tickets = %d\n", numberOfLuckyTickets);
	
		
	return 0;
}