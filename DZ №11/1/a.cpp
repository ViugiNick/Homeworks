#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include "list_Viu.h"

using namespace std;

using namespace Lists;

int main()
{
	freopen("a.in", "r", stdin);
	
	List list1;
	makeList(list1);
	List list2;
	makeList(list2);
	
	
	int sizeOfFirtsPolinom = 0;
	cout << "Input size of first polinom" << endl;
	
	cin >> sizeOfFirtsPolinom;
	
	cout << "Input your polinom" << endl;
	
	for (int i = 0; i < sizeOfFirtsPolinom; i++)
	{
		int a = 0;
		int b = 0;
		
		cin >> a >> b;
		ListElement *temp = new ListElement;
		temp->value = b;
		temp->poww = a;
		
		insertToSorted(temp, list1);
	}
	printList(list1);
	
	int sizeOfSecondPolinom = 0;
	cout << "Input size of second polinom" << endl;
	
	cin >> sizeOfSecondPolinom;
	
	cout << "Input your polinom" << endl;
	
	for (int i = 0; i < sizeOfSecondPolinom; i++)
	{
		int a = 0;
		int b = 0;
		
		cin >> a >> b;
		ListElement *temp = new ListElement;
		temp->value = b;
		temp->poww = a;
		
		insertToSorted(temp, list2);
	}
	
	printList(list2);
	
	cout << "Values in point 1" << endl;
	cout << value(list1, 1) << " " << value(list2, 1) << endl;
	cout << equals(list1, list2) << endl;
	
	List list3;
	makeList(list3);
	
	add(list1, list2, list3);
	cerr << "!!!" << endl;
	printList(list3);
	
	deleteList(list1);
	deleteList(list2);
	deleteList(list3);
	
	return(0);
}