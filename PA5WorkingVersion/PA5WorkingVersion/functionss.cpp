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
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "Functionss.h"
#include "DoublyLinkedListt.h"
#include "LinkedList.h"
#include "TimerSystem.h"
#include <iostream>

using namespace std;


Functionss::Functionss()
{

}

Functionss::~Functionss()
{
	delete[] myArray;
	delete[] myString;
	delete[] mySecondArray;
	delete[] mySecondString;
}


void Functionss::arrayInsertBeginning()
{
	//initialize variables
	int i = 0;
	int number = 0;

	ifstream myFile;
	myArray = new int[505100];
	myFile.open("integerFile.txt");
	TimerSystem timer;

	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);

	//check if the file is good and add to the file

	cout << "Inserting 100 integers in array at beginning: " << endl;
	srand(unsigned(time(NULL)));
	if (myFile.good())
	{
		timer.startClock();
		while (i < 100)
		{
			myFile >> number;
			myArray[i] = number;
			i++;
		}
		cout << timer.getTime() << endl;


		cout << "Inserting 5000 integers in array at beginning: " << endl;
		i = 0;
		timer.startClock();
		while (i < 5000)
		{
			myFile >> number;
			myArray[i] = number;
			i++;
		}
		cout << timer.getTime() << endl;


		cout << "Inserting 500000 integers in array at beginning: " << endl;
		i = 0;
		timer.startClock();
		while (i < 500000)
		{
			myFile >> number;
			myArray[i] = number;
			i++;
		}
		cout << timer.getTime() << endl;
	}
	myFile.close();
	cout << endl << endl;
	//--------------------------------------------------------------------------------------
	string word;
	myString = new string[505100];
	ifstream myOtherFile;
	myOtherFile.open("stringFile.txt");
	i = 0;


	if (myOtherFile.good())
	{
		cout << "Inserting 100 strings in array at beginning: " << endl;
		timer.startClock();
		while (i < 100)
		{
			myOtherFile >> word;
			myString[i] = word;
			i++;
		}
		i = 0;
		cout << timer.getTime() << endl;


		cout << "Inserting 5000 strings in array at beginning: " << endl;
		timer.startClock();
		while (i < 5000)
		{
			myOtherFile >> word;
			myString[i] = word;
			i++;
		}
		i = 0;
		cout << timer.getTime() << endl;


		cout << "Inserting 500000 strings in array at beginning: " << endl;
		timer.startClock();
		while (i < 500000)
		{
			myOtherFile >> word;
			myString[i] = word;
			i++;
		}
		cout << timer.getTime() << endl;
	}
	myOtherFile.close();
	cout << endl << endl;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Functionss::arrayInsertAtEnd()
{
	int i = 0;
	int number = 0;
	mySecondArray = new int[505100];

	ifstream myFile;
	myFile.open("integerFile.txt");
	TimerSystem timer;

	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);


	cout << "Inserting 100 integers in array at end: " << endl;
	srand(unsigned(time(NULL)));
	if (myFile.good())
	{
		timer.startClock();
		while (i < 100)
		{
			myFile >> number;
			mySecondArray[100 - i - 1] = number;
			i++;
		}
		cout << timer.getTime() << endl;


		cout << "Inserting 5000 integers in array at end: " << endl;
		i = 0;
		timer.startClock();
		while (i < 5000)
		{
			myFile >> number;
			mySecondArray[5000 - i - 1] = number;
			i++;
		}
		cout << timer.getTime() << endl;


		cout << "Inserting 500000 integers in array at end: " << endl;
		i = 0;
		timer.startClock();
		while (i < 500000)
		{
			myFile >> number;
			mySecondArray[500000 - i - 1] = number;
			i++;
		}
		cout << timer.getTime() << endl;
	}
	myFile.close();
	cout << endl << endl;
	//--------------------------------------------------------------------------------------
	string word;
	mySecondString = new string[505100];
	ifstream myOtherFile;
	myOtherFile.open("stringFile.txt");
	i = 0;


	if (myOtherFile.good())
	{
		cout << "Inserting 100 strings in array at end: " << endl;
		timer.startClock();
		while (i < 100)
		{
			myOtherFile >> word;
			mySecondString[100 - i - 1] = word;
			i++;
		}
		i = 0;
		cout << timer.getTime() << endl;


		cout << "Inserting 5000 strings in array at end: " << endl;
		timer.startClock();
		while (i < 5000)
		{
			myOtherFile >> word;
			mySecondString[5000 - i - 1] = word;
			i++;
		}
		i = 0;
		cout << timer.getTime() << endl;


		cout << "Inserting 500000 strings in array at end: " << endl;
		timer.startClock();
		while (i < 500000)
		{
			myOtherFile >> word;
			mySecondString[500000 - i - 1] = word;
			i++;
		}
		cout << timer.getTime() << endl;
	}
	myOtherFile.close();
	cout << endl << endl;
}

//===========================================================================================================================================================

void Functionss::linkedListInsertBeginning()
{
	LinkedList<string> myString;
	LinkedList<int> myInt;
	TimerSystem timer;

	int number;
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);
	ifstream myFile;
	myFile.open("integerFile.txt");
	int i = 0;
	if (myFile.good())
	{
		cout << "Inserting 100 integers in linkedlist at beginning: " << endl;
		timer.startClock();
		while (i < 100)
		{
			myFile >> number;
			myInt.insertAtBeginning(number);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 5000 integers in linkedlist at beginning: " << endl;
		timer.startClock();
		while (i < 5000)
		{
			myFile >> number;
			myInt.insertAtBeginning(number);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 500000 integers in linkedlist at beginning: " << endl;
		timer.startClock();
		while (i < 500000)
		{
			myFile >> number;
			myInt.insertAtBeginning(number);
			i++;
		}
		cout << timer.getTime() << endl;
	}
	cout << endl << endl;

	myFile.close();
	//----------------------------------------------------------------------------
	string word;
	ifstream myOtherFile;
	myOtherFile.open("stringFile.txt");
	i = 0;
	if (myOtherFile.good())
	{
		cout << "Inserting 100 strings in linkedlist at beginning: " << endl;
		timer.startClock();
		while (i < 100)
		{
			myOtherFile >> word;
			myString.insertAtBeginning(word);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 5000 strings in linkedlist at beginning: " << endl;
		timer.startClock();
		while (i < 5000)
		{
			myOtherFile >> word;
			myString.insertAtBeginning(word);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 500000 strings in linkedlist at beginning: " << endl;
		timer.startClock();
		while (i < 500000)
		{
			myOtherFile >> word;
			myString.insertAtBeginning(word);
			i++;
		}
		cout << timer.getTime() << endl;
	}
	cout << endl << endl;

	myOtherFile.close();

}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
void Functionss::linkedListInsertAtEnd()
{
	LinkedList<string> myString;
	LinkedList<int> myInt;
	TimerSystem timer;

	int number;
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);
	ifstream myFile;
	myFile.open("integerFile.txt");
	int i = 0;
	if (myFile.good())
	{
		cout << "Inserting 100 integers in linkedlist at end: " << endl;
		timer.startClock();
		while (i < 100)
		{
			myFile >> number;
			myInt.insertAtEnd(number);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 5000 integers in linkedlist at end: " << endl;
		timer.startClock();
		while (i < 5000)
		{
			myFile >> number;
			myInt.insertAtEnd(number);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 500000 integers in linkedlist at end: " << endl;
		timer.startClock();
		while (i < 500000)
		{
			myFile >> number;
			myInt.insertAtEnd(number);
			i++;
		}
		cout << timer.getTime() << endl;
	}
	cout << endl << endl;

	myFile.close();
	//----------------------------------------------------------------------------
	string word;
	ifstream myOtherFile;
	myOtherFile.open("stringFile.txt");
	i = 0;
	if (myOtherFile.good())
	{
		cout << "Inserting 100 strings in linkedlist at end: " << endl;
		timer.startClock();
		while (i < 100)
		{
			myOtherFile >> word;
			myString.insertAtEnd(word);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 5000 strings in linkedlist at end: " << endl;
		timer.startClock();
		while (i < 5000)
		{
			myOtherFile >> word;
			myString.insertAtEnd(word);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 500000 strings in linkedlist at end: " << endl;
		timer.startClock();
		while (i < 500000)
		{
			myOtherFile >> word;
			myString.insertAtEnd(word);
			i++;
		}
		cout << timer.getTime() << endl;
	}
	cout << endl << endl;

	myOtherFile.close();
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void Functionss::linkedListInsertInMiddle()
{
	LinkedList<string> myString;
	LinkedList<int> myInt;
	TimerSystem timer;

	int number;
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);
	ifstream myFile;
	myFile.open("integerFile.txt");
	int i = 0;
	if (myFile.good())
	{
		cout << "Inserting 100 integers in linkedlist at middle: " << endl;
		timer.startClock();
		while (i < 100)
		{
			myFile >> number;
			myInt.insertAtMiddle(number);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 5000 integers in linkedlist at middle: " << endl;
		timer.startClock();
		while (i < 5000)
		{
			myFile >> number;
			myInt.insertAtMiddle(number);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 500000 integers in linkedlist at middle: " << endl;
		timer.startClock();
		while (i < 500000)
		{
			myFile >> number;
			myInt.insertAtMiddle(number);
			i++;
		}
		cout << timer.getTime() << endl;
	}
	cout << endl << endl;

	myFile.close();
	//----------------------------------------------------------------------------
	string word;
	ifstream myOtherFile;
	myOtherFile.open("stringFile.txt");
	i = 0;
	if (myOtherFile.good())
	{
		cout << "Inserting 100 strings in linkedlist at middle: " << endl;
		timer.startClock();
		while (i < 100)
		{
			myOtherFile >> word;
			myString.insertAtMiddle(word);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 5000 strings in linkedlist at middle: " << endl;
		timer.startClock();
		while (i < 5000)
		{
			myOtherFile >> word;
			myString.insertAtMiddle(word);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 500000 strings in linkedlist at middle: " << endl;
		timer.startClock();
		while (i < 500000)
		{
			myOtherFile >> word;
			myString.insertAtMiddle(word);
			i++;
		}
		cout << timer.getTime() << endl;
	}
	cout << endl << endl;

	myOtherFile.close();
}
//===========================================================================================================================================================================

void Functionss::doublylinkedlistInsertBeginning()
{
	DoublyLinkedListt<string> myString;
	DoublyLinkedListt<int> myInt;
	TimerSystem timer;

	int number;
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);
	ifstream myFile;
	myFile.open("integerFile.txt");
	int i = 0;
	if (myFile.good())
	{
		cout << "Inserting 100 integers in doublylinkedlist at beginning: " << endl;
		timer.startClock();
		while (i < 100)
		{
			myFile >> number;
			myInt.insertAtBeginning(number);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 5000 integers in doublylinkedlist at beginning: " << endl;
		timer.startClock();
		while (i < 5000)
		{
			myFile >> number;
			myInt.insertAtBeginning(number);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 500000 integers in doublylinkedlist at beginning: " << endl;
		timer.startClock();
		while (i < 500000)
		{
			myFile >> number;
			myInt.insertAtBeginning(number);
			i++;
		}
		cout << timer.getTime() << endl;
	}
	cout << endl << endl;

	myFile.close();
	//----------------------------------------------------------------------------
	string word;
	ifstream myOtherFile;
	myOtherFile.open("stringFile.txt");
	i = 0;
	if (myOtherFile.good())
	{
		cout << "Inserting 100 strings in doublylinkedlist at beginning: " << endl;
		timer.startClock();
		while (i < 100)
		{
			myOtherFile >> word;
			myString.insertAtBeginning(word);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 5000 strings in doublylinkedlist at beginning: " << endl;
		timer.startClock();
		while (i < 5000)
		{
			myOtherFile >> word;
			myString.insertAtBeginning(word);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 500000 strings in doublylinkedlist at beginning: " << endl;
		timer.startClock();
		while (i < 500000)
		{
			myOtherFile >> word;
			myString.insertAtBeginning(word);
			i++;
		}
		cout << timer.getTime() << endl;
	}
	cout << endl << endl;

	myOtherFile.close();
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------

void Functionss::doublylinkedlistInsertAtEnd()
{
	DoublyLinkedListt<string> myString;
	DoublyLinkedListt<int> myInt;
	TimerSystem timer;

	int number;
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);
	ifstream myFile;
	myFile.open("integerFile.txt");
	int i = 0;
	if (myFile.good())
	{
		cout << "Inserting 100 integers in doublylinkedlist at end: " << endl;
		timer.startClock();
		while (i < 100)
		{
			myFile >> number;
			myInt.insertAtEnd(number);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 5000 integers in doublylinkedlist at end: " << endl;
		timer.startClock();
		while (i < 5000)
		{
			myFile >> number;
			myInt.insertAtEnd(number);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 500000 integers in doublylinkedlist at end: " << endl;
		timer.startClock();
		while (i < 500000)
		{
			myFile >> number;
			myInt.insertAtEnd(number);
			i++;
		}
		cout << timer.getTime() << endl;
	}
	cout << endl << endl;

	myFile.close();
	//----------------------------------------------------------------------------
	string word;
	ifstream myOtherFile;
	myOtherFile.open("stringFile.txt");
	i = 0;
	if (myOtherFile.good())
	{
		cout << "Inserting 100 strings in doublylinkedlist at end: " << endl;
		timer.startClock();
		while (i < 100)
		{
			myOtherFile >> word;
			myString.insertAtEnd(word);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 5000 strings in doublylinkedlist at end: " << endl;
		timer.startClock();
		while (i < 5000)
		{
			myOtherFile >> word;
			myString.insertAtEnd(word);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 500000 strings in doublylinkedlist at end: " << endl;
		timer.startClock();
		while (i < 500000)
		{
			myOtherFile >> word;
			myString.insertAtEnd(word);
			i++;
		}
		cout << timer.getTime() << endl;
	}
	cout << endl << endl;

	myOtherFile.close();
}

void Functionss::doublylinkedlistInsertInMiddle()
{
	DoublyLinkedListt<string> myString;
	DoublyLinkedListt<int> myInt;
	TimerSystem timer;

	int number;
	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);
	ifstream myFile;
	myFile.open("integerFile.txt");
	int i = 0;
	if (myFile.good())
	{
		cout << "Inserting 100 integers in doublylinkedlist at middle: " << endl;
		timer.startClock();
		while (i < 100)
		{
			myFile >> number;
			myInt.insertInMiddle(number);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 5000 integers in doublylinkedlist at middle: " << endl;
		timer.startClock();
		while (i < 5000)
		{
			myFile >> number;
			myInt.insertInMiddle(number);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 500000 integers in doublylinkedlist at middle: " << endl;
		timer.startClock();
		while (i < 500000)
		{
			myFile >> number;
			myInt.insertInMiddle(number);
			i++;
		}
		cout << timer.getTime() << endl;
	}
	cout << endl << endl;

	myFile.close();
	//----------------------------------------------------------------------------
	string word;
	ifstream myOtherFile;
	myOtherFile.open("stringFile.txt");
	i = 0;
	if (myOtherFile.good())
	{
		cout << "Inserting 100 strings in doublylinkedlist at middle: " << endl;
		timer.startClock();
		while (i < 100)
		{
			myOtherFile >> word;
			myString.insertInMiddle(word);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 5000 strings in doublylinkedlist at middle: " << endl;
		timer.startClock();
		while (i < 5000)
		{
			myOtherFile >> word;
			myString.insertInMiddle(word);
			i++;
		}
		cout << timer.getTime() << endl;
		i = 0;
		cout << "Inserting 500000 strings in doublylinkedlist at middle: " << endl;
		timer.startClock();
		while (i < 500000)
		{
			myOtherFile >> word;
			myString.insertInMiddle(word);
			i++;
		}
		cout << timer.getTime() << endl;
	}
	cout << endl << endl;

	myOtherFile.close();
}
