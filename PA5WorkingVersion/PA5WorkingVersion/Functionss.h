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
#ifndef FUNCTIONSS_H
#define FUNCTIONSS_H

#include <iostream>
#include <string>

using namespace std;
class Functionss
{
public:
	/*      Pre:  None
	*     Post:  This object is initialized using the default
	*  Purpose:  To initialize data object
	************************************************************************/
	Functionss();
	/*      Pre:  None
	*     Post:  All the pointers in the list are deleted
	*  Purpose:  To remove all the pointers in the list
	************************************************************************/
	~Functionss();
	/*      Pre:  None
	*     Post:  Insert data types from the beginning of the array
	*  Purpose:  Makes an array
	************************************************************************/
	void arrayInsertBeginning();
	/*      Pre:  None
	*     Post:  Insert data types from the beginning of the list
	*  Purpose:  Makes a list
	************************************************************************/
	void linkedListInsertBeginning();
	/*      Pre:  None
	*     Post:  Insert data types from the beginning of the list
	*  Purpose:  Makes a list
	************************************************************************/
	void doublylinkedlistInsertBeginning();

	void arrayInsertAtEnd();
	/*      Pre:  None
	*     Post:  Insert data types from the end of the list
	*  Purpose:  Makes a list
	************************************************************************/
	void linkedListInsertAtEnd();
	/*      Pre:  None
	*     Post:  Insert data types from the end of the list
	*  Purpose:  Makes a list
	************************************************************************/
	void doublylinkedlistInsertAtEnd();

	/*      Pre:  None
	*     Post:  Insert data types from the middle of the list
	*  Purpose:  Makes a list
	************************************************************************/
	void linkedListInsertInMiddle();
	/*      Pre:  None
	*     Post:  Insert data types from the middle of the list
	*  Purpose:  Makes a list
	************************************************************************/
	void doublylinkedlistInsertInMiddle();

private:
	//variables
	int *myArray;
	string *myString;
	int *mySecondArray;
	string *mySecondString;
};


#endif // 
