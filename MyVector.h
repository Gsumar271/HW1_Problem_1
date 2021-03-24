#pragma once
/*
By Yevgeniy Sumaryev
3/20/21
*/
/*
This is a header file for custom template vector class meant to 
perform all the main functions of the standard
vector class. This vector uses array that can dynamically grow
when the limit is reached 
Also I've declared an Iterator inside this file,
since it looked more compact and it had access to all the 
necessary variables  
*/
template <typename T>
class MyVector{
    private:
        T *data;           // Pointer to partially filled dynamic array
        size_t used;       // How much of array is being used
        size_t capacity;   // Current capacity of the vector

    public:
        //CONSTRUCTORS AND DESTRUCTORS
        MyVector(size_t initial_capacity);
        //copy constructor
        MyVector(const MyVector& source);
        //move constructor
        MyVector(MyVector&& source);
        //destructor
        ~MyVector();

        //MODIFIER FUNCTIONS
        void insert(const T& entry);
        bool erase_one(const T& target);
        void reserve(size_t capacity);
        T pop_back() const;
        void push_back(const T& entry);
        void push_back(T&& entry);
        //operator overloading
        void operator =(const MyVector& source);
        void operator +=(const MyVector& addend);
        T& operator ++(){return data + 1; }
        T& operator [](size_t i) { return data[i]; }

        //CONSTANT MEMBER FUNCTIONS
        size_t size() const { return used; }
        
        
        

        //print entire vector
        void print();
        //helper function to copy the contents of array
        void copy(const MyVector& source);

    class V_iterator { 
	private: 
		// Dynamic array using a pointer 
		T* arr; 

	public: 
		V_iterator() { arr = nullptr; } 
		V_iterator(T* p) { arr = p;} 
		bool operator==(const V_iterator& right) const { return arr == right.arr; } 
		bool operator!=(const V_iterator& right) const{ return !(*this == right); } 
		T operator*() const { return *arr; } 
		V_iterator& operator++() { arr++; return *this; } 
	}; 

    //TO USE WITH ITERATOR
    //begin iterator
    V_iterator begin() const { return V_iterator(data); }
    //end iterator
    V_iterator end(){ return V_iterator(data + used); }

};
