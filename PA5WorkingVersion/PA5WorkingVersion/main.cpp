#include  <iostream>
#include "Functionss.h"
#include "header.h"

using namespace std;

int main()
{
	/*
	Author: Walter Hill
	Class: Data Structures & Algorithims (CSI 281-01)
	Assignment: PA5 - Part 2
	Date Assigned: 10/19/17
	Due Date: 10/26/17

	Program Description: Data Structure Analysis

	Certification of Authenticity:
	I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
	I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may,
	for the purpose of assessing this assignment:- Reproduce this assignment and provide a copy to another member of
	academic staff; and/or - Communicate a copy of this assignment to a plagiarism checking service
	(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
	*/
	Functionss myFunction;


	//console formatting
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);

	//Array tests - deleted in function
	User *userGroupMax, *userGroupMed, *userGroupSm;

	userGroupMax = new User[MAX];
	userGroupMed = new User[MED];
	userGroupSm = new User[SMALL];

	arrayTests(userGroupMax, userGroupMed, userGroupSm);

	//Linked List Test
	LinkedList<User> maxList;
	LinkedList<User> medList;
	LinkedList<User> smList;

	linkedListTests(maxList, medList, smList);


	//Double Linked List Tests
	DoublyLinkedListt<User> maxDoubleList;
	DoublyLinkedListt<User> medDoubleList;
	DoublyLinkedListt<User> smDoubleList;

	doubleLinkedListTests(maxDoubleList, medDoubleList, smDoubleList);

	/*
	Author: Kelly Herstine
	Class: Data Structures & Algorithims (CSI 281-01)
	Assignment: PA5 - Part 2
	Date Assigned: 10/19/17
	Due Date: 10/26/17

	Program Description: Data Structure Analysis

	Certification of Authenticity:
	I certify that this is entirely my own work, except where I have given fully-documented references to the work of others.
	I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may,
	for the purpose of assessing this assignment:- Reproduce this assignment and provide a copy to another member of
	academic staff; and/or - Communicate a copy of this assignment to a plagiarism checking service
	(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
	*/

	cout << "----------------------------------------------------------------------------" << endl;

	myFunction.arrayInsertBeginning();
	myFunction.arrayInsertAtEnd();

	cout << "----------------------------------------------------------------------------" << endl;

	myFunction.linkedListInsertBeginning();
	myFunction.linkedListInsertInMiddle();
	myFunction.linkedListInsertAtEnd();


	cout << "----------------------------------------------------------------------------" << endl;

	myFunction.doublylinkedlistInsertBeginning();
	myFunction.doublylinkedlistInsertInMiddle();
	myFunction.doublylinkedlistInsertAtEnd();

	return 0;


	system("pause");







	return 0;
}