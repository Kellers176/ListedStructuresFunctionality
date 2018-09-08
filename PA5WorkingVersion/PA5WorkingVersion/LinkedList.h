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
#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{

	template <typename R>
	struct Node
	{

		R       mData;
		Node<R> *mNext;

		/*      Pre:  None
		*     Post:  This object is initialized using default values
		*  Purpose:  To initialize date object
		********************************************************************/
		Node()
		{
			mData = R();
			mNext = NULL;
		}


		/*      Pre:  None
		*     Post:  This object is initialized using specified data
		*  Purpose:  To intialize date object
		********************************************************************/
		Node(R data)
		{
			mData = data;
			mNext = NULL;
		}


	};
private:
	Node<T> *mHead, *mTail;
	int     mCount;
public:
	LinkedList();
	~LinkedList();

	bool insertAtBeginning(T data);
	bool insertAtEnd(T data);
	bool insertAtMiddle(T data);
	void clear();


};
/*      Pre:  None
*     Post:  This object is initialized using the default
*  Purpose:  To initialize date object
************************************************************************/
template <typename T>
LinkedList<T>::LinkedList()
{
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}


/*      Pre:  None
*     Post:  All the nodes in the list is deleted
*  Purpose:  To remove all the nodes in the list
************************************************************************/
template <typename T>
LinkedList<T>::~LinkedList()
{
	// remove all nodes
	clear();

	// reinitialize the pointers
	mHead = NULL;
	mTail = NULL;

	// reinitialize count
	mCount = 0;
}

/*      Pre:  The list is instantiated and the data is available
*     Post:  The data is inserted in ascending order
*  Purpose:  To insert a data into the list at the head
************************************************************************/
template<typename T>
bool LinkedList<T>::insertAtBeginning(T data)
{
	Node<T> *tmp, *oneBefore, *newNode;

	newNode = new Node<T>(data);
	if (newNode == NULL)
		return false;

	if (mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		newNode->mNext = mHead;
		mHead = newNode;
	}
	mCount++;
	return true;
}
/*      Pre:  The list is instantiated and the data is available
*     Post:  The data is inserted in ascending order
*  Purpose:  To insert a data into the list at the tail
************************************************************************/
template<typename T>
bool LinkedList<T>::insertAtEnd(T data)
{
	Node<T> *tmp, *oneBefore, *newNode;

	newNode = new Node<T>(data);
	if (newNode == NULL)
		return false;

	if (mTail == NULL)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		mTail->mNext = newNode;
		mTail = newNode;
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
bool LinkedList<T>::insertAtMiddle(T data)
{
	Node<T> *tmp, *oneBefore, *newNode;

	newNode = new Node<T>(data);
	if (newNode == NULL)
		return false;

	if (mHead == NULL)
	{
		mHead = newNode;
		mTail = newNode;
	}
	else
	{
		if (data < mHead->mData)
		{
			newNode->mNext = mHead;
			mHead = newNode;
		}
		else if (data > mTail->mData)
		{
			mTail->mNext = newNode;
			mTail = newNode;
		}
		else
		{
			tmp = mHead;
			oneBefore = mHead;
			while (tmp->mData < data)
			{
				oneBefore = tmp;
				tmp = tmp->mNext;
			}

			if (tmp->mData != data)
			{
				newNode->mNext = tmp;
				oneBefore->mNext = newNode;
			}
			else
			{
				delete newNode;
				return false;
			}
		}
	}

	mCount++;

	return true;

}
/*      Pre:  The list is initiated
*     Post:  All the nodes in the list is deleted
*  Purpose:  To remove all the nodes in the list
************************************************************************/
template<typename T>
inline void LinkedList<T>::clear()
{
	Node<T> *tmp, *toBeDeleted;

	tmp = mHead;

	// removing node by node
	while (tmp != NULL)
	{
		toBeDeleted = tmp;
		tmp = tmp->mNext;
		toBeDeleted->mNext = NULL;

		delete toBeDeleted;
	}

	// reinitialize the pointers
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}




#endif