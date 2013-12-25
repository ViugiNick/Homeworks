#include <string>
#include <iostream>
#include "telefonBook.h"

using std::string;
using std::cout;
using std::endl;
using std::cerr;

namespace Telefons
{
	Note createNote(char *name, char *number)
	{
		Note newNote;
		newNote.name = name;
		newNote.number = number;

		return newNote;
	}
	
	void addNoteToArray(Note *&inputArray, int &numberOfRecords, char *name, char *number)
	{
		Note newNote = createNote(name, number);
		inputArray[numberOfRecords] = newNote;
		numberOfRecords++;
	}
	
	void findName(Note *inputArray, int numberOfRecords, char *currNumber)
	{
		for (int i = 0; i < numberOfRecords; i++)
		{
			if (string(currNumber) == string(inputArray[i].number))
			{
				cout << inputArray[i].name << endl;
				break;
			}
		}	
	}
	
	void findNumber(Note *inputArray, int numberOfRecords, char *currName)
	{
		for (int i = 0; i < numberOfRecords; i++)
		{
			if (string(currName) == string(inputArray[i].name))
			{
				cout << inputArray[i].number << endl;
				break;
			}
		}
	}
	
	void clean(Note *inputArray, int numberOfRecords)
	{
		for (int i = 0; i < numberOfRecords; ++i)
		{
			delete[] inputArray[i].name;
			delete[] inputArray[i].number;
		}
		delete[] inputArray;
	}
}
