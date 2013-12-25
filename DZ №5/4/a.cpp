#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxNumber = 100;

void parse(int inputNumber, string * answer)
{
	if(inputNumber != 0)
	{
		if(inputNumber < 20)
		{
			cout << answer[inputNumber];
			return;
		}
		if(inputNumber < 100)
		{
			cout << answer[10 * (inputNumber / 10)] << "-" << answer[inputNumber % 10];
			return;
		}
		if(inputNumber < 1000)
		{
			cout << answer[inputNumber / 100] << " hundred ";
			parse(inputNumber % 100, answer);
			return;
		}
		
		parse(inputNumber / 1000, answer);
		cout << " thousand ";
		parse(inputNumber % 1000, answer);
		return;
	}
}

int main()
{
	string answer[maxNumber];

	answer[0] = "zero";
	answer[1] = "one";
	answer[2] = "two";
	answer[3] = "three";
	answer[4] = "four";
	answer[5] = "five";
	answer[6] = "six";
	answer[7] = "seven";
	answer[8] = "eight";
	answer[9] = "nine";
	
	answer[10] = "ten";
	answer[11] = "eleven";
	answer[12] = "twelve";
	answer[13] = "thirteen";
	answer[14] = "fourteen";
	answer[15] = "fifteen";
	answer[16] = "sixteen";
	answer[17] = "seventeen";
	answer[18] = "eighteen";
	answer[19] = "nineteen";
	
	answer[20] = "twenty";
	answer[30] = "thirty";
	answer[40] = "forty";
	answer[50] = "fifty";
	answer[60] = "sixty";
	answer[70] = "seventy";
	answer[80] = "eighty";
	answer[90] = "ninety";
	
	int inputNumber = 0;
	printf("Input your number\n");
	scanf("%d", &inputNumber);
	
	parse(inputNumber, answer);
	
	return 0;
}