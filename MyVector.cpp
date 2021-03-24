#pragma once
/*
By Yevgeniy Sumaryev
3/20/21
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <algorithm>
#include "MyVector.h" 
using namespace std;
/*
This is an implementation of a custom vector class
since this is a template class in order to use it we
must declare both .h and .cpp file in the file
that is using this class
*/

template<class T>
MyVector<T>::MyVector(size_t initial_capacity){

        data = new T[initial_capacity];
	    capacity = initial_capacity;
	    used = 0;
}

//copy constructor
template<class T>
MyVector<T>::MyVector(const MyVector& source){
    
    data = new T[source.capacity];
	capacity = source.capacity;
	used = source.used;

	//copy function 
	//to copy the array
    copy(source);
}

//move constructor
template<class T>
MyVector<T>::MyVector(MyVector&& source){
    data = new T[source.capacity];
	capacity = source.capacity;
	used = source.used;

	//for the move constructor
	//copy array and then make 
	//passed in array point to null
    copy(source);

    //pointer to null as it's rvalue
    source.data = nullptr;
}

//destructor
template<class T>
MyVector<T>::~MyVector(){
    delete[] data;
}

//insert function
//when max capacity is reached
//we double the size 
template<class T>
void MyVector<T>::insert(const T& entry){
    
    if (used == capacity)
	    reserve(used*2);
	data[used] = entry;
	++used;

}

//A function to erase a specific element 
//in vector class
template<class T>
bool MyVector<T>::erase_one(const T& target){

    size_t index; // The location of target in the data array    

	// Set index to the location of target in the data array,
	// which could be as small as 0 or as large as used-1.
	// If target is not in the array, then index will be set equal to used.
	for (index = 0; (index < used) && (data[index] != target); ++index)
	    ; // No work in the body of this loop.

	if (index == used) // target isn't in array, so no work to do
	    return false;

	// When program reaches here, target is in the array at data[index].
	// So, reduce used by 1 and copy the last item onto data[index].
	--used;
	data[index] = data[used];
	return true;

}

//function to increase capacity
//of our vector class
template <class T>
void MyVector<T>::reserve(size_t new_capacity){
    T *larger_array;

	if (new_capacity == capacity)
	    return; // The allocated memory is already the right size

	if (new_capacity < used)
	    new_capacity = used; // Can't allocate less than we are using

	larger_array = new T[new_capacity];

	//copy the contents of array
	//to the new larger array
    for (int i = 0; i < used; i++)
	{
		larger_array[i] = data[i];
	}

	//delete dynamic array variable
	delete [] data;
	data = larger_array;
	capacity = new_capacity;
}

//delete last item in array
//decrease the items counter in array
template <class T>
T MyVector<T>::pop_back() const
{
    T lastItem = data[used];
    --used;

    return lastItem;
}

//push new value into vector
//by adding it to the end
template <class T>
void MyVector<T>::push_back(const T& entry){
    
    if (used == capacity)
	    reserve(used*2);
    data[used] = entry;
    ++used;
}

//push_back method with move semantics
template <class T>
void MyVector<T>::push_back(T&& entry){
    
    if (used == capacity)
	    reserve(used*2);
    data[used] = std::move(entry);
    ++used;
}

//overload = operator
template <class T>
void MyVector<T>::operator =(const MyVector& source)
{
	T *new_data;

	// Check for possible self-assignment:
	if (this == &source)
            return;

	// If needed, allocate an array with a different size:
	if (capacity != source.capacity)
	{ 
	    new_data = new T[source.capacity];
	    delete [] data;
	    data = new_data;
	    capacity = source.capacity;
	}

	// Copy the data from the source array:
	used = source.used;
	copy(source);
}

//overload +=operator
template <class T>
void MyVector<T>:: operator +=(const MyVector& addend)
{
	if (used + addend.used > capacity)
            reserve(used + addend.used);

	for (int i = used; i < addend.used; i++)
	{
		data[i] = addend.data[i];
	}
    
    used += addend.used;
}



//print the contents of the vector
template<class T>
void MyVector<T>::print(){
    for (int i = 0; i < used; i++)
    {
        cout << *(data + i) << " ";
    }
    
}

template<class T>
void MyVector<T>::copy(const MyVector& source){
    
    //copy the contents of source array
	//into the contents of new array
	for (int i = 0; i < used; i++)
	{
		data[i] = source.data[i];
	}

}

