#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
	int inputA = 0;
	int inputB = 0;
  
	scanf("%d%d", &inputA, &inputB);

	while (inputA >= inputB)
	{
		inputA -= inputB;
	}
	
	printf("%d", inputA);
	
	return 0;
}