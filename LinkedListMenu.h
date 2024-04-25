#pragma once
#include "LinkedList.h"
#include <iostream>
#include <cstring>
#include "MenuItem.h"
using namespace std;


class LinkedListMenu : public LinkedList<MenuItem>
{
        public:
          MenuItem* searchById(int id, bool & found) const;
          void insertByPrice(MenuItem a);
          void deleteById(int id);

};

void LinkedListMenu::insertByPrice(MenuItem a)
{
	NodePtr tempPtr = myFirst;
	NodePtr prevPtr = NULL;
	NodePtr newNode = new Node(a);
	assert(newNode != NULL);

	if (isEmpty())
	{
		myFirst = newNode;
		mySize++;
		return;
	}
	while (tempPtr != NULL && tempPtr->data.getPrice() < a.getPrice())
	{
		prevPtr = tempPtr;
		tempPtr = tempPtr->next;
	}
	if (prevPtr == NULL)
	{
		newNode->next = myFirst;
		myFirst = newNode;
	}
	else
	{
		prevPtr->next = newNode;
		newNode->next = tempPtr;
	}
	mySize++;
}

MenuItem* LinkedListMenu::searchById(int id,bool & found) const
{
	NodePtr tempPtr = myFirst;
    
    if (tempPtr == NULL || id > 499 || id < 100)
    {
		found = false;
		return NULL;
	}

    while (tempPtr != NULL)
    {
        if (tempPtr->data.getId() == id)
        {
			found = true;
			return & tempPtr->data;
		}
        tempPtr = tempPtr->next;
	}
	found = false;
	return NULL;
}

void LinkedListMenu::deleteById(int id)
{
	NodePtr tempPtr = myFirst;
	NodePtr prevPtr = NULL;

	if (!isEmpty() && id <= 499 && id >= 100)
	{

		while (tempPtr != NULL && tempPtr->data.getId() != id)
		{
			prevPtr = tempPtr;
			tempPtr = tempPtr->next;
		}

		if (tempPtr == NULL)
		{
			return;
		}

		if (prevPtr == NULL)
		{
			myFirst = myFirst->next;
			delete tempPtr;
		}
		else
		{
			prevPtr->next = tempPtr->next;
			delete tempPtr;
		}
		mySize--;
	}
}

ostream& operator<<(ostream& out, const LinkedListMenu & list) {
	list.displayList(out);
	return out;
}



 

