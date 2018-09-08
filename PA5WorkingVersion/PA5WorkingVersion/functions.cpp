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

#include "header.h"
#include <iostream>

using namespace std;

/* Pre: Parameters Initialized
* Post: Array tests performed
* Purpose: Perform array tests
*******************************************/
void arrayTests(User userListMax[], User userListMed[], User userListSm[])
{
	//populate from 0
	populateUserArrayFront("sm", userListSm);
	populateUserArrayFront("med", userListMed);
	populateUserArrayFront("max", userListMax);

	cout << endl;

	delete[] userListMax;
	delete[] userListMed;
	delete[] userListSm;

	userListMax = new User[MAX];
	userListMed = new User[MED];
	userListSm = new User[SMALL];

	//populate from last index
	populateUserArrayBack("sm", userListSm);
	populateUserArrayBack("med", userListMed);
	populateUserArrayBack("max", userListMax);


	cout << endl;

	delete[] userListMax;
	delete[] userListMed;
	delete[] userListSm;
}

/* Pre: Parameters Initialized
* Post: Double linked list tests performed
* Purpose: Perform double linked list tests
*******************************************/
void doubleLinkedListTests(DoublyLinkedListt<User> maxDoubleList, DoublyLinkedListt<User> medDobuleList, DoublyLinkedListt<User> smDoubleList)
{
	//insert at head

	populateUserDoubleListFront("sm", smDoubleList);
	populateUserDoubleListFront("med", medDobuleList);
	populateUserDoubleListFront("max", maxDoubleList);


	cout << endl;

	maxDoubleList.clear();
	medDobuleList.clear();
	smDoubleList.clear();

	//insert at tail
	populateUserDoubleListBack("sm", smDoubleList);
	populateUserDoubleListBack("med", medDobuleList);
	populateUserDoubleListBack("max", maxDoubleList);



	cout << endl;

	maxDoubleList.clear();
	medDobuleList.clear();
	smDoubleList.clear();


	//insert sorted
	populateUserDoubleListSorted("sm", smDoubleList);
	populateUserDoubleListSorted("med", medDobuleList);
	populateUserDoubleListSorted("max", maxDoubleList);


	cout << endl;

	maxDoubleList.clear();
	smDoubleList.clear();
	smDoubleList.clear();

	system("pause");
}

/* Pre: Parameters Initialized
* Post: Linked list tests performed
* Purpose: Perform linked list tests
*******************************************/
void linkedListTests(LinkedList<User> maxList, LinkedList<User> medList, LinkedList<User> smList)
{
	//insert at head
	populateUserListFront("sm", smList);
	populateUserListFront("med", medList);
	populateUserListFront("max", maxList);


	cout << endl;

	maxList.clear();
	medList.clear();
	smList.clear();

	//insert at tail
	populateUserListBack("sm", smList);
	populateUserListBack("med", medList);
	populateUserListBack("max", maxList);

	cout << endl;

	maxList.clear();
	medList.clear();
	smList.clear();

	//insert sorted
	populateUserListSorted("sm", smList);
	populateUserListSorted("med", medList);
	populateUserListSorted("max", maxList);



	cout << endl;

	maxList.clear();
	medList.clear();
	smList.clear();
}


/* Pre: User object on the both sides
* Post: Return true or false
* Purpose: Overload less than operator
*******************************************/
bool operator <(User lhs, User rhs)
{
	bool result = false;

	if (lhs.cashBalance < rhs.cashBalance)
		result = true;

	return result;
}


/* Pre: User object on the both sides
* Post: Return true or false
* Purpose: Overload not equal than operator
*******************************************/
bool operator !=(User lhs, User rhs)
{
	bool result = false;

	if (lhs.cashBalance != rhs.cashBalance)
		result = true;

	return result;
}

/* Pre: User object on the both sides
* Post: Return true or false
* Purpose: Overload greater than operator
*******************************************/
bool operator >(User lhs, User rhs)
{
	bool result = false;

	if (lhs.cashBalance > rhs.cashBalance)
		result = true;

	return result;
}


/* Pre: User object on the both sides
* Post: Return true or false
* Purpose: Overload greater than or equal operator
*******************************************/
bool operator >=(User lhs, User rhs)
{
	bool result = false;

	if (lhs.cashBalance >= rhs.cashBalance)
		result = true;

	return result;
}

/* Pre: User object on the both sides
* Post: Return true or false
* Purpose: Overload less than or equal operator
*******************************************/
bool operator <=(User lhs, User rhs)
{
	bool result = false;

	if (lhs.cashBalance <= rhs.cashBalance)
		result = true;

	return result;
}

/* Pre: User object on the right side
* Post: Display User info to the console
* Purpose: Overload insertion operator
*******************************************/
ostream& operator<<(ostream& output, User obj)
{
	string isPremium = "Standard";

	if (obj.isPremium == true)
		isPremium = "Premium";

	output << fixed << "Phone: " << obj.phoneNumber << endl
		<< "Balance: " << obj.cashBalance << endl
		<< "Account Status: " << isPremium << endl << endl;

	return output;
}

/* Pre: Parameters Initialized & doubleLinkedListTests called
* Post: List populated from tail
* Purpose: Populates User list from file
*******************************************/
void populateUserDoubleListBack(string size, DoublyLinkedListt<User> userList)
{
	//input from file & time it & display results
	ifstream fin;
	int i, count;
	TimerSystem timer;
	User janeDeer;

	if (size == "max")
		count = MAX;
	else if (size == "med")
		count = MED;
	if (size == "sm")
		count = SMALL;

	fin.open(USER_DATATSET, ios::in);

	timer.startClock();

	while (!fin.eof())
	{
		for (i = 0; i < count; i++)
		{
			fin >> janeDeer.phoneNumber
				>> janeDeer.cashBalance
				>> janeDeer.isPremium;

			userList.insertAtEnd(janeDeer);
		}

		if (i == count)
			break;
	}

	cout << size + " DobulyLinkedList Back | Time: " << timer.getTime() << endl;

	fin.clear();
	fin.seekg(0, ios::beg);

	fin.close();
}

/* Pre: Parameters Initialized & doubleLinkedListTests called
* Post: List populated from the head
* Purpose: Populates User list from file
*******************************************/

void populateUserDoubleListFront(string size, DoublyLinkedListt<User> userList)
{
	ifstream fin;
	int i, count;
	TimerSystem timer;
	User janeDeer;

	if (size == "max")
		count = MAX;
	else if (size == "med")
		count = MED;
	if (size == "sm")
		count = SMALL;

	fin.open(USER_DATATSET, ios::in);

	timer.startClock();

	while (!fin.eof())
	{
		for (i = 0; i < count; i++)
		{
			fin >> janeDeer.phoneNumber
				>> janeDeer.cashBalance
				>> janeDeer.isPremium;

			userList.insertAtBeginning(janeDeer);
		}

		if (i == count)
			break;
	}

	cout << size + " DobulyLinkedList Front | Time: " << timer.getTime() << endl;

	fin.clear();
	fin.seekg(0, ios::beg);

	fin.close();
}

/* Pre: Parameters Initialized & doubleLinkedListTests called
* Post: List populated in sorted fasahion
* Purpose: Populates User list from file
*******************************************/
void populateUserDoubleListSorted(string size, DoublyLinkedListt<User> userList)
{
	ifstream fin;
	int i, count;
	TimerSystem timer;
	User janeDeer;

	if (size == "max")
		count = MAX;
	else if (size == "med")
		count = MED;
	if (size == "sm")
		count = SMALL;

	fin.open(USER_DATATSET, ios::in);

	timer.startClock();

	while (!fin.eof())
	{
		for (i = 0; i < count; i++)
		{
			fin >> janeDeer.phoneNumber
				>> janeDeer.cashBalance
				>> janeDeer.isPremium;

			userList.insertInMiddle(janeDeer);
		}

		if (i == count)
			break;
	}

	cout << size + " DobulyLinkedList Sorted | Time: " << timer.getTime() << endl;

	//userList.display();

	fin.clear();
	fin.seekg(0, ios::beg);

	fin.close();
}


/* Pre: Parameters Initialized & linkedListTests called
* Post: List populated from tail
* Purpose: Populates User list from file
*******************************************/
void populateUserListBack(string size, LinkedList<User> userList)
{
	ifstream fin;
	int i, count;
	TimerSystem timer;
	User johnDoe;

	if (size == "max")
		count = MAX;
	else if (size == "med")
		count = MED;
	if (size == "sm")
		count = SMALL;

	fin.open(USER_DATATSET, ios::in);

	timer.startClock();

	while (!fin.eof())
	{
		for (i = 0; i < count; i++)
		{
			fin >> johnDoe.phoneNumber
				>> johnDoe.cashBalance
				>> johnDoe.isPremium;

			userList.insertAtEnd(johnDoe);
		}

		if (i == count)
			break;
	}

	cout << size + " LinkedList Back | Time: " << timer.getTime() << endl;

	fin.clear();
	fin.seekg(0, ios::beg);

	fin.close();
}


/* Pre: Parameters Initialized & linkedListTests called
* Post: List populated from head
* Purpose: Populates User list from file
*******************************************/
void populateUserListFront(string size, LinkedList<User> userList)
{
	ifstream fin;
	int i, count;
	TimerSystem timer;

	User johnDoe;

	if (size == "max")
		count = MAX;
	else if (size == "med")
		count = MED;
	if (size == "sm")
		count = SMALL;

	fin.open(USER_DATATSET, ios::in);

	timer.startClock();

	while (!fin.eof())
	{
		for (i = 0; i < count; i++)
		{
			fin >> johnDoe.phoneNumber
				>> johnDoe.cashBalance
				>> johnDoe.isPremium;

			userList.insertAtBeginning(johnDoe);
		}

		if (i == count)
			break;
	}

	cout << size + " LinkedList Front | Time: " << timer.getTime() << endl;

	fin.clear();
	fin.seekg(0, ios::beg);

	fin.close();
}


/* Pre: Parameters Initialized & linkedListTests called
* Post: List populated in sorted fashion
* Purpose: Populates User list from file
*******************************************/
void populateUserListSorted(string size, LinkedList<User> userList)
{
	ifstream fin;
	int i, count;
	TimerSystem timer;
	User johnDoe;

	if (size == "max")
		count = MAX;
	else if (size == "med")
		count = MED;
	if (size == "sm")
		count = SMALL;

	fin.open(USER_DATATSET, ios::in);

	timer.startClock();

	while (!fin.eof())
	{
		for (i = 0; i < count; i++)
		{
			fin >> johnDoe.phoneNumber
				>> johnDoe.cashBalance
				>> johnDoe.isPremium;

			userList.insertAtMiddle(johnDoe); //OVERLOAD
		}

		if (i == count)
			break;
	}

	cout << size + " LinkedList Sorted | Time: " << timer.getTime() << endl;

	//userList.display();

	fin.clear();
	fin.seekg(0, ios::beg);

	fin.close();
}


/* Pre: Parameters Initialized & arrayTests called
* Post: Array populated from back
* Purpose: Populates User list from file
*******************************************/
void populateUserArrayBack(string size, User userList[])
{
	ifstream fin;
	int i, index, count = 0;
	TimerSystem timer;

	if (size == "max")
		index = MAX;
	else if (size == "med")
		index = MED;
	if (size == "sm")
		index = SMALL;

	fin.open(USER_DATATSET, ios::in);

	timer.startClock();

	while (!fin.eof())
	{
		for (i = index - 1; i > count; i--)
		{
			fin >> userList[i].phoneNumber
				>> userList[i].cashBalance
				>> userList[i].isPremium;
		}

		if (i == count)
			break;
	}

	cout << size + " Array Back | Time: " << timer.getTime() << endl;

	fin.clear();
	fin.seekg(0, ios::beg);

	fin.close();

}


/* Pre: Parameters Initialized & arrayTests called
* Post: Array populated from front
* Purpose: Populates User list from file
*******************************************/
void populateUserArrayFront(string size, User userList[])
{
	ifstream fin;
	int i, count;
	TimerSystem timer;

	if (size == "max")
		count = MAX;
	else if (size == "med")
		count = MED;
	if (size == "sm")
		count = SMALL;

	fin.open(USER_DATATSET, ios::in);

	timer.startClock();

	while (!fin.eof())
	{
		for (i = 0; i < count; i++)
		{
			fin >> userList[i].phoneNumber
				>> userList[i].cashBalance
				>> userList[i].isPremium;
		}

		if (i == count)
			break;
	}

	cout << size + " Array Front | Time: " << timer.getTime() << endl;

	fin.clear();
	fin.seekg(0, ios::beg);

	fin.close();
}