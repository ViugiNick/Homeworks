#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include "telefonBook.h"

using namespace std;
using namespace Telefons;

const int maxSize = 20;
const int maxNumerOfTelefons = 20;

int main ()
{
	Note * inputArray = new Note[maxNumerOfTelefons];

	int numberOfRecords = 0;
  	
  	ifstream fin("PhoneBook.txt");

	int temp = 0;
	fin >> temp;
   
  	for(int i = 0; i < temp; i++)
  	{
  		char * str1 = new char[maxSize];
		char * str2 = new char[maxSize];

  		fin >> str1 >> str2;
  		addNoteToArray(inputArray, numberOfRecords, str1, str2);
  	}
  	fin.close();

  	int type = 0;
  	
  	while (true)
	{
		printf("0 - exit\n");	
		printf("1 - add\n");	
		printf("2 - find telefon number\n");	
		printf("3 - find name\n");	
		printf("4 - save\n");	
		
		cin >> type;
		
		if (type == 4)
		{			
			ofstream fout("PhoneBook.txt");
  
			fout << numberOfRecords << endl;
			
			for(int i = 0; i < numberOfRecords; i++)
			{	
				fout << inputArray[i].name << " " << inputArray[i].number << endl;
			}
			
			fout.close();
		}
		
		if (type == 0)
		{
			clean(inputArray, numberOfRecords);
			exit(0);
		}
		
		if (type == 1)
		{
			char * str1 = new char[maxSize];
			char * str2 = new char[maxSize];
			
			cin >> str1 >> str2;			
			addNoteToArray(inputArray, numberOfRecords, str1, str2);
		}
		
		if (type == 2)
		{
			printf("Input name :\n");
			char * str3 = new char[maxSize];
			cin >> str3;
			findNumber(inputArray, numberOfRecords, str3);
			delete[] str3;
		}
		
		if (type == 3)
		{
			printf("Input mobile number:\n");
			char * str3 = new char[maxSize];
			cin >> str3;
			findName(inputArray, numberOfRecords, str3);		
			delete[] str3;
		}
	}
	
  	return 0;
}