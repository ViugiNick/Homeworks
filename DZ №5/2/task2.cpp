#include <iostream>
#include <bitset>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstring>

using namespace std;

const int maxPow = 20;

long double mantiseCalculation(unsigned char *t, int *pow_2)
{
    long double answer = 1.0;
    unsigned char mask = pow_2[3];
    long double multiplier = 0.5;
    while (mask != 0)
    {
        if (mask & *t)
        	answer += multiplier;
        multiplier /= 2;
        mask >>= 1;
    }
    
    for (int i = 0; i < 6; i++)
    {
        t--;
        mask = pow_2[7];
        while (mask != 0)
        {
            if (mask & *t)
            	answer += multiplier;
            multiplier /= 2;
            mask >>= 1;
        }
    }
    return answer;
}

int exponentCalculation(unsigned char *t, int *pow_2)
{
    unsigned char mask = pow_2[4];
    long int answer = 0;
    int multiplier = 1;
    t--;
    while (mask != 0)
    {
        if (mask & *t)
        	answer += multiplier;
        multiplier *= 2;
        mask <<= 1;
    }
    t++;
    
    mask = 1;
    while (mask != pow_2[7])
    {
        if (mask & *t)
        	answer += multiplier;
        multiplier *= 2;
        mask <<= 1;
    }

    return (answer - pow_2[10] + 1);
}

int main()
{
    int pow_2[maxPow];
    pow_2[0] = 1;
    for(int i = 1; i < 20; i++)
    	pow_2[i] = pow_2[i - 1] * 2;
    
    double inputNumber;
    cout << "Input your number:\n";
    cin >> inputNumber;
    cout << "Binary:\n";
    unsigned char* t = (unsigned char*)(&inputNumber + 1);
    
    for (int i = 0; i < 8; i++)
    {
        t--;
        cout << bitset<8>(*t) << " ";
    }
    
    cout << endl;
  
    int mask = pow_2[7];
    t = (unsigned char*)(&inputNumber + 1);
    t--;
    
    cout << ((mask & *t) ? "-" : "+") << mantiseCalculation(t - 1, pow_2) << "*2^(" << exponentCalculation(t, pow_2) << ")"; 
    
    return 0;
}

