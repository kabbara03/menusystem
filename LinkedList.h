#ifndef LINKED_LIST
#define LINKED_LIST

#include<iostream>
#include<cassert>
#include<new>

using namespace std;
template <typename ElementType>

class LinkedList
{
public:
	
	LinkedList();
	LinkedList(const LinkedList& alist);
	~LinkedList();
	bool isEmpty() const;
	void insertAtPos(const ElementType & a, int pos);
	void deleteAtPos(const ElementType & a, int pos);
	void displayList(ostream& out) const;
	LinkedList& operator=(const LinkedList& rightHand);
	int getSize() const;
	ElementType getMyFirst() const;

protected:

	class Node {
	public:
		Node(ElementType d) {
			next = NULL;
			data = d;
		}
		Node* next;
		ElementType data;
	};
	typedef Node* NodePtr;
	NodePtr myFirst;
	int mySize;
};

template <typename ElementType>
inline LinkedList<ElementType>::LinkedList() {
	mySize = 0;
	myFirst = NULL;
}

template <typename ElementType>
inline LinkedList<ElementType>::LinkedList(const LinkedList& alist) {
	if (alist.myFirst != NULL) {
		myFirst = new Node(alist.myFirst->data);
		mySize = alist.mySize;

		NodePtr origPtr = alist.myFirst->next;
		NodePtr tempPtr = myFirst;

		while (origPtr != NULL) {
			tempPtr->next = new Node(origPtr->data);
			origPtr = origPtr->next;
			tempPtr = tempPtr->next;
		}
	}
	else
		exit(-1);
}

template <typename ElementType>
inline LinkedList<ElementType>::~LinkedList() {
	if (!isEmpty()) {
		NodePtr tempPtr = myFirst->next;
		while (tempPtr != NULL) {
			delete myFirst;
			myFirst = tempPtr;
			tempPtr = tempPtr->next;
		}
	}
}

template <typename ElementType>
inline bool LinkedList<ElementType>::isEmpty() const {
	return myFirst == NULL;
}

template <typename ElementType> inline 
void LinkedList<ElementType>::insertAtPos(const ElementType & a, int pos){

	NodePtr tempPtr = myFirst;
	
	if (pos < 0 || pos > mySize)
		exit(-1);
	else {
		NodePtr newPtr = new (nothrow) Node(a);

		assert(newPtr != NULL);

		 if (mySize == 0 || pos == 0) {
			newPtr->next = myFirst;
			myFirst = newPtr;
		 }

		else if (pos == mySize) {
			tempPtr = myFirst;
			while (tempPtr->next != NULL) {
				tempPtr = tempPtr->next;
			}
			tempPtr->next = newPtr;
			return;
		}

		else {

			for (int i = 0; i < pos - 1; i++) {
				tempPtr = tempPtr->next;
			}

			newPtr->next = tempPtr->next;
			tempPtr->next = newPtr;
		}
		
	}
	mySize++;
}

template <typename ElementType> inline 
void LinkedList<ElementType>::deleteAtPos(const ElementType & a, int pos) {
	NodePtr tempPtr = myFirst;

	assert(myFirst != NULL);

	assert(pos >= 0 && pos < mySize);

	if (pos == 0) {
		myFirst = myFirst->next;
		delete tempPtr;
	}
	else {
		NodePtr prevPtr = myFirst;
		tempPtr = myFirst->next;

		for (int i = 0; i < pos - 1; i++) {
			prevPtr = prevPtr->next;
			tempPtr = tempPtr->next;
		}

		prevPtr->next = tempPtr->next;
		delete tempPtr;
	}
}

template <typename ElementType> inline int LinkedList<ElementType>::getSize() const {
	return mySize;
}

template <typename ElementType> inline ElementType LinkedList<ElementType>::getMyFirst() const {
	return myFirst->data;
}

template <typename ElementType>
void LinkedList<ElementType>::displayList(ostream& out) const {
	NodePtr tempPtr = myFirst;

	while (tempPtr != NULL) {
		out << tempPtr->data << " ";
		tempPtr = tempPtr->next;
		out << endl;
	}

}

template <typename ElementType> inline LinkedList<ElementType>
& LinkedList<ElementType>::operator=(const LinkedList& rightHand) {
	if (this == &rightHand)
		return *this;	

	NodePtr tempPtr = myFirst->next;

	while (myFirst != NULL) {
		myFirst = myFirst->next;
		delete tempPtr;
		tempPtr = myFirst;
	}
	mySize = rightHand.mySize;
	if (rightHand.myFirst != NULL) {
		myFirst = new (nothrow) Node(rightHand.myFirst->data);

		assert(myFirst != NULL);

		NodePtr origPtr = rightHand.myFirst;
		NodePtr newPtr = myFirst;

		while (newPtr != NULL) {
			newPtr->next = new (nothrow) Node(origPtr->data);
			assert(newPtr->next != NULL);
			origPtr = origPtr->next;
			newPtr = newPtr->next;
		}
	}
	return*this;
}



template <typename ElementType>
ostream& operator<<(ostream& out, const LinkedList<ElementType> & list) {
	list.displayList(out); 
	return out;
}



#endif