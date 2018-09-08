/*
Author: Walter Hill
	Class : Data Structures & Algorithims(CSI 281 - 01)
	Assignment : PA5 - Part 2
	Date Assigned : 10 / 19 / 17
	Due Date : 10 / 26 / 17

	Program Description : Data Structure Analysis

	Certification of Authenticity :
I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may,
for the purpose of assessing this assignment : -Reproduce this assignment and provide a copy to another member of
academic staff; and/or -Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include "timerSystem.h"
#include "DoublyLinkedListt.h"
#include "LinkedList.h"

using namespace std;

typedef struct User
{
	string phoneNumber;
	double cashBalance;
	bool isPremium;
} User;

const int MAX = 500000;
const int MED = 5000;
const int SMALL = 100;
const string USER_DATATSET = "userDataset.txt";

void arrayTests(User userListMax[], User userListMed[], User userListSm[]);
void doubleLinkedListTests(DoublyLinkedListt<User> maxDoubleList, DoublyLinkedListt<User> medDoubleList, DoublyLinkedListt<User> smDoubleList);
void linkedListTests(LinkedList<User> maxList, LinkedList<User> medList, LinkedList<User> smList);

void populateUserDoubleListBack(string listSize, DoublyLinkedListt<User> maxList);
void populateUserDoubleListFront(string listSize, DoublyLinkedListt<User> maxList);
void populateUserDoubleListSorted(string listSize, DoublyLinkedListt<User> maxList);

void populateUserListBack(string listSize, LinkedList<User> maxList);
void populateUserListFront(string listSize, LinkedList<User> maxList);
void populateUserListSorted(string listSize, LinkedList<User> maxList);

void populateUserArrayBack(string size, User userList[]);
void populateUserArrayFront(string size, User userList[]);

//operator overloads
bool operator >=(User lhs, User rhs);
bool operator <=(User lhs, User rhs);
bool operator !=(User lhs, User rhs);
bool operator >(User lhs, User rhs);
bool operator <(User lhs, User rhs);

#endif // !HEADER_H