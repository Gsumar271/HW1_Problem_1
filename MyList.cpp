#pragma once
/*
By Yevgeniy Sumaryev
3/20/21
*/
#include "MyList.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <algorithm>
#include "MyList.h" 
using namespace std;



/*
An implementation file of MyList class
since this is a template, both .h and .cpp file
must be included in main file
*/

//constructor
template<class T>
MyList<T>::MyList() {
		first = last = nullptr;
		count = 0;
}

//copy constructor
template<class T>
MyList<T>::MyList(const MyList<T>& otherList) {
		first = nullptr;
		copyList(otherList);
}

//move constructor
template<class T>
MyList<T>::MyList(MyList<T>&& otherList) {
		first = nullptr;
		copyList(otherList);

		//pointer to null since it's rvalue
		otherList.first = nullptr;
}


//destructor
template<class T>
MyList<T>::~MyList() {
		destroyList();
}

//assignment operator
template<class T>
const MyList<T>& MyList<T>::operator=(const MyList<T>& otherList) {
		if (this != &otherList) {
			copyList(otherList);
		}
		return *this;
}

// function to print the list
template<class T>
void MyList<T>::print(){
		node<T>* current;
		current = first;

		while (current != nullptr) {
			cout << current->info << " ";
			current = current->link;
		}
}

//get front element data of the list
//assert to make sure first is not null
template<class T>
T MyList<T>::front() {
		assert(first != nullptr);
		return first->info;
}

//get the last element data of the list
//assert to make sure back is not null
template<class T>
T MyList<T>::back(){
		assert(last != nullptr);
		return last->info;
}

//get first element
template<class T>
node<T>* MyList<T>::getFirst(){
		assert(first != nullptr);
		return first;
}

//get last element
template<class T>
node<T>* MyList<T>::getLast(){
		assert(last != nullptr);
		return last;
}

//function to delete all the nodes in the list 
template<class T>
void MyList<T>::destroyList() {
		node<T>* temp;

		while (first != nullptr) {
			temp = first;
			first = first->link;
			delete temp;
		}
		last = nullptr;
		count = 0;
}

template<class T>
void MyList<T>::initializeList() {
		destroyList();
}

//return true if list is empty 
template<class T>
bool MyList<T>::isEmptyList() const {
		return (first == nullptr);
	}


//copies the list, position by position
template<class T>
void MyList<T>::copyList(const MyList<T>& otherList) {
		node<T>* newNode;
		node<T>* current;

		//empty our list if it is not empty already
		if (first != nullptr) {
			destroyList();
		}

		if (otherList.first == nullptr) {
			first = last = nullptr;
			count = 0;
		}
		else {
			current = otherList.first;
			count = otherList.count;

			first = new node<T>;
			first->info = current->info;
			first->link = nullptr;

			last = first;

			current = current->link;

			while (current != nullptr) {
				newNode = new node<T>;
				newNode->info = current->info;
				newNode->link = nullptr;

				last->link = newNode;
				last = newNode;

				current = current->link;
			}
		}
}
	
//search for a particular item in the list 
template<class T>
bool MyList<T>::search(const T& searchItem) const {
		node<T>* current;
		bool found = false;

		//linearly go through all the links
		//until item is found
		current = first;
		while (current != nullptr) {
			if (current->info == searchItem) {
				return true;
			}
			else {
				current = current->link;
			}
		}
		return false;
}

	
//insert element to the front of the list 
template<class T>
void MyList<T>::insertFirst(const T& newItem) {
		node<T>* newNode;
		newNode = new node<T>;
		newNode->info = newItem;

		newNode->link = first;
		first = newNode;
		count++;

		//if the list were empty then newNode would also be the last node in the list
		if (last == nullptr) {
			last = newNode;
		}
}

//insert with move semantics
template<class T>
void MyList<T>::insertFirst(T&& newItem) {
		node<T>* newNode;
		newNode = new node<T>;
		newNode->info = newItem;

		newNode->link = first;
		first = newNode;
		count++;

		//if the list were empty then newNode would also be the last node in the list
		if (last == nullptr) {
			last = newNode;
		}

}

//insert element to the back of the list 
template<class T>
void MyList<T>::insertLast(const T& newItem) {
		node<T>* newNode;
		newNode = new node<T>;
		newNode->info = newItem;
		newNode->link = nullptr;

		//if otherwise empty
		if (first == nullptr) {
			first = last = newNode;
			count++;
		}
		else {
			last->link = newNode;
			last = newNode;
			count++;
		}
}

//insertLast with move semantics
template<class T>
void MyList<T>::insertLast(T&& newItem) {
		node<T>* newNode;
		newNode = new node<T>;
		newNode->info = newItem;
		newNode->link = nullptr;

		//if otherwise empty
		if (first == nullptr) {
			first = last = newNode;
			count++;
		}
		else {
			last->link = newNode;
			last = newNode;
			count++;
		}

		newItem = nullptr;
}


//deleting a node can have several options
//the list is empty, the first node is to be deleted, a subsequent node is to be deleted, the info is not in the list
template<class T>
void MyList<T>:: deleteNode(const T& deleteItem) {
		node<T>* current;
		node<T>* trailCurrent;
		bool found;

		if (first == nullptr) {
			cout << "Can't delete from an empty list." << endl;
		}
		else {
			if (first->info == deleteItem) {   //if found in first spot
				current = first;
				first = first->link;
				count--;

				if (first == nullptr) last = nullptr; //if the list has only one node
				delete current;
			}
			else {
				found = false;
				trailCurrent = first;

				current = first->link;

				while (current != nullptr && !found) {
					if (current->info != deleteItem) {
						trailCurrent = current;
						current = current->link;
					}
					else {
						found = true;
					}
				}

				if (found) {
					trailCurrent->link = current->link;
					count--;
					
					if (last == current) last = trailCurrent; //if deleted node was the last node
					delete current;
				}
				else {
					cout << "Item not found in list." << endl;
				}
			}
		}
}
