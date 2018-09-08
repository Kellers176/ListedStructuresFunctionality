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
#ifndef DOUBLYLINKEDLISTT_H
#define DOUBLYLINKEDLISTT_H

#include <iostream>

using namespace std;

template <typename T>
class DoublyLinkedListt
{
	template <typename R>
	struct Node
	{
		R       mData;
		Node<R> *mNext;
		Node<R> *mPrevious;

		/*      Pre:  None
		*     Post:  This object is initialized using default values
		*  Purpose:  To initialize date object
		********************************************************************/
		Node()
		{
			mData = R();
			mNext = NULL;
			mPrevious = NULL;
		}


		/*      Pre:  None
		*     Post:  This object is initialized using specified data
		*  Purpose:  To intialize date object
		********************************************************************/
		Node(R data)
		{
			mData = data;
			mNext = NULL;
			mPrevious = NULL;
		}
	};

private:
	Node<T> *mHead, *mTail;
	int     mCount;

public:
	DoublyLinkedListt();
	~DoublyLinkedListt();

	bool insertAtBeginning(T data);
	bool insertAtEnd(T data);
	bool insertInMiddle(T data);
	void clear();


};
/*      Pre:  None
*     Post:  This object is initialized using the default
*  Purpose:  To initialize date object
************************************************************************/
template <typename T>
DoublyLinkedListt<T>::DoublyLinkedListt()
{
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}

//DONE
/*      Pre:  None
*     Post:  All the nodes in the list is deleted
*  Purpose:  To remove all the nodes in the list
************************************************************************/
template <typename T>
DoublyLinkedListt<T>::~DoublyLinkedListt()
{
	// remove all nodes
	clear();

	// reinitialize the pointers
	mHead = NULL;
	mTail = NULL;

	// reinitialize count
	mCount = 0;
}

//DONE
/*      Pre:  The list is initiated
*     Post:  All the nodes in the list is deleted
*  Purpose:  To remove all the nodes in the list
************************************************************************/
template <typename T>
void DoublyLinkedListt<T>::clear()
{
	Node<T> *tmp, *toBeDeleted;

	tmp = mHead;

	// removing node by node
	while (tmp != NULL)
	{
		toBeDeleted = tmp;
		tmp = tmp->mNext;
		toBeDeleted->mNext = NULL;
		toBeDeleted->mPrevious = NULL;

		delete toBeDeleted;
	}

	// reinitialize the pointers
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}

/*      Pre:  The list is instantiated and the data is available
*     Post:  The data is inserted in ascending order
*  Purpose:  To insert a data into the list at the head
************************************************************************/
template<typename T>
bool DoublyLinkedListt<T>::insertAtBeginning(T data)
{
	Node<T> *tmp, *oneBefore, *newNode;

	newNode = new Node<T>(data);
	//there is no new node
	if (newNode == NULL)
		return false;

	//list is empty
	if (mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
		mHead->mPrevious = NULL;
		mHead->mNext = NULL;
	}
	else
	{
		tmp = newNode;
		tmp->mData = data;
		tmp->mPrevious = NULL;
		tmp->mNext = mHead;
		mHead->mPrevious = tmp;
		mHead = tmp;

	}
	mCount++;
	return true;
}
/*      Pre:  The list is instantiated and the data is available
*     Post:  The data is inserted in ascending order
*  Purpose:  To insert a data into the list at the tail
************************************************************************/
template<typename T>
bool DoublyLinkedListt<T>::insertAtEnd(T data)
{
	Node<T> *tmp, *oneBefore, *newNode;

	newNode = new Node<T>(data);
	//there is no new node
	if (newNode == NULL)
		return false;

	//list is empty
	if (mTail == NULL)
	{
		mHead = newNode;
		mTail = newNode;
		mHead->mPrevious = NULL;
		mHead->mNext = NULL;
	}
	else
	{
		tmp = newNode;
		tmp->mData = data;
		tmp->mPrevious = mTail;
		tmp->mNext = NULL;
		mTail->mNext = tmp;
		mTail = tmp;

	}
	mCount++;
	return true;
}
/*      Pre:  The list is instantiated and the data is available
*     Post:  The data is inserted in ascending order
*  Purpose:  To insert a data into the list in descending order.
*            However, if the data already existed in the list, it will
*            not be added again
************************************************************************/
template<typename T>
bool DoublyLinkedListt<T>::insertInMiddle(T data)
{
	Node<T> *tmp, *oneBefore, *newNode;

	newNode = new Node<T>(data);
	//there is no new node
	if (newNode == NULL)
		return false;

	//list is empty
	if (mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
		mHead->mPrevious = NULL;
		mHead->mNext = NULL;
	}
	else
	{
		//if data is greater than the head so add at the beginning
		if (data >= mHead->mData)
		{
			tmp = newNode;
			tmp->mData = data;
			tmp->mPrevious = NULL;
			tmp->mNext = mHead;
			mHead->mPrevious = tmp;
			mHead = tmp;

		}
		//if data is less than the tail so add at the end
		else if (data <= mTail->mData)
		{
			tmp = newNode;
			tmp->mData = data;
			tmp->mPrevious = mTail;
			tmp->mNext = NULL;
			mTail->mNext = tmp;
			mTail = tmp;

		}
		//add to the middle
		else
		{
			tmp = mHead;
			oneBefore = mHead;
			while (tmp->mData > data)
			{
				oneBefore = tmp;
				tmp = tmp->mNext;
			}

			newNode->mPrevious = tmp->mPrevious;
			newNode->mNext = tmp;
			(tmp->mPrevious)->mNext = newNode;
			tmp->mPrevious = newNode;

		}
	}

	mCount++;

	return true;
}

#endif