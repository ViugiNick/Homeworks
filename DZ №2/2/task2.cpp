#include <cstdio>
#include <string.h>

using namespace std;

int sqr(int x)
{
	return x * x;
}

int recPow(int a, int n)
{
	if (n == 1)
		return a;
		
	if (n % 2 == 0)
		return sqr(recPow(a, n / 2));
	else
		return a * sqr(recPow(a, n / 2));	
}

int main()
{
	int inputNumberA = 0;	
	int inputNumberN = 0;	

	printf("Input your numbers : A and N\n");
	
	scanf("%d%d", &inputNumberA, &inputNumberN);

	int result = recPow(inputNumberA, inputNumberN);
	
	printf("A^N = %d", result);
	
	return 0;
}