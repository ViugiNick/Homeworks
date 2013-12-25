#include <cstdio>
#include <string.h>

using namespace std;

const int maxSizeOfString = 100;

int main()
{
	char inputString[maxSizeOfString];
  
	printf("Enter your string : \n");
	scanf("%s", inputString);

	int sizeOfString = (int)strlen(inputString);
	
	bool isPalindrome = true; 
	
	for (int i = 0; i <= sizeOfString / 2; i++)
	{
		isPalindrome &= (inputString[i] == inputString[sizeOfString - i - 1]);
	}
	
	if (isPalindrome)
		printf("Your string is a Palindrome\n");
	else	
		printf("Your string isn't a Palindrome\n");
	
	return 0;
}