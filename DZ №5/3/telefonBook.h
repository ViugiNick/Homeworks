namespace Telefons
{
	struct Note
	{
		char *name;
		char *number;
	};

	char *Name(Note whant);
	char *Number(Note whant);
	
	Note createNote(char *name, char *number);
	
	void addNoteToArray(Note *&inputArray, int &numberOfRecords, char *name, char *number);
	
	void findName(Note *inputArray, int numberOfRecords, char *currNumber);
	
	void findNumber(Note *inputArray, int numberOfRecords, char *currName);
	
	void clean(Note *inputArray, int numberOfRecords);
}