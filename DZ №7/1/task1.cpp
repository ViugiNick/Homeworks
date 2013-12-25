#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int maxSize = 100;

int main()
{
	int parent[maxSize];
	int numberOfStudents = 0;
	int numberOfSubmits = 0;
	
	printf("Input number of students\n");
	scanf("%d", &numberOfStudents);
	
	printf("Input number of submits\n");
	scanf("%d", &numberOfSubmits);
	
	int student = 0;
	int link = 0;
	
	for(int i = 0; i < numberOfStudents; i++)
		parent[i] = -1;
	parent[0] = 0;
	parent[1] = 1;
	parent[2] = 2;
	for (int i = 0; i < numberOfSubmits; i++)
	{
		scanf("%d%d", &student, &link);
		student--;
		link--;
		parent[student] = link;
	}
	
	for(int i = 0; i < numberOfStudents; i++)
	{
		for(int j = 0; j < numberOfStudents; j++)
		{
			if(parent[j] != -1 && 0 <= parent[parent[j]] && parent[parent[j]] <= 2)
			{
				parent[j] = parent[parent[j]];
			}
		}
	}
	for(int i = 0; i < numberOfStudents; i++)
	{
		if(parent[i] == -1)
		{
			cout << "Send down student number " << i + 1 << endl;
		}
		else
		{
			cout << "Student number " << i + 1 << " " << "copy from " << parent[i] + 1 << endl;
		}
	}
	return 0;
}