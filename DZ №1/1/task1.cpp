#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
	int inputNumber = 0;	
	scanf("%d", &inputNumber);

	int inputNumberSqr = inputNumber * inputNumber;
	
	int answer = (inputNumberSqr + inputNumber) * (inputNumberSqr + 1);
	
	printf("%d", answer);
	
	return 0;
}