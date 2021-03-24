#pragma once
/*
By Yevgeniy Sumaryev
3/20/21
*/
/*
In this template list class I included both node class
and list class in the same file to make it easier to read
and also an iterator class which had access to all the variables 
without having to build extra variables to tie up all these classes
*/
//A template node class
template<class T>
class node {
public:
	T info;
	node<T>* link;
};

//A template List class which uses node from above
template<class T>
class MyList
{
    private:
        int count;
        node<T>* first;
	    node<T>* last;

    public:
        MyList();
        //copy constructor
	    MyList(const MyList<T>& otherList);
        //move constructor
        MyList(MyList<T>&& otherList);
        //destructor
        ~MyList();

        bool search(const T& searchItem) const;
	    
        //modifier functions
        void insertFirst(const T& newItem);
        void insertFirst(T&& newItem);
	    void insertLast(const T& newItem);
        void insertLast(T&& newItem);
	    void deleteNode(const T& deleteItem);

        //assignment operator
	    const MyList<T>& operator=(const MyList<T>& otherList);


        int getCount();
        int length() { return count; }
        void print();
        T front();
        T back();
        node<T>* getFirst();
        node<T>* getLast();
        void destroyList();
        void initializeList();
        bool isEmptyList() const;

        //copies the list, position by position
	    void copyList(const MyList<T>& otherList);

        //a custom template iterator class
        //used for the above List class
        class LL_iterator 
        { 
	    private: 
		    // Pointer to current node
		    node<T>* current;
	    public: 
		    LL_iterator() { current = nullptr; } 
		    LL_iterator(node<T>* ptr) { current = ptr; }
	    	bool operator==(const LL_iterator& right) const { return (current == right.current); } 
		    bool operator!=(const LL_iterator& right) const{ return (current != right.current); } 
		    T operator*() const { return current->info; } 
		    LL_iterator& operator++() { current = current->link; return *this; } 
	    }; 

        //returns an iterator to the first node in the list
	    LL_iterator begin() { LL_iterator temp(first); return temp; }
	    
        //returns an iterator to the last node in the list
	    LL_iterator end() { LL_iterator temp(last); return temp; }


};
