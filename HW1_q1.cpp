#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include "MyVector.h"
#include "MyVector.cpp"
#include "MyList.h"
#include "MyList.cpp"

using namespace std;


//helper method used to create
//a random string, by first creating
//a random length and then randomly adding
//characters to it
string createString(){
    string s1;
    //create random length string
    //of length between 1 and 10
    int length = rand() % 10 + 1;
    for (int i = 0; i < length; i++)
    {
        //generate random int 
        int randInt = rand()%26 + 97;
        //convert it to char
        char randChar = randInt + '0';
        //append it to string 
        s1 += randChar;
    }
    
    return s1;
}

int main() {

    //Custom Vector class and
    //List class variable declarations
    MyVector<int> v1(100000);
    MyVector<string> v2(100000); 
    MyVector<string> v3(100000); 
    MyList<int> list1;
    MyList<string> list2;
    MyList<string> list3;
    string someString; 
    
    /* initialize random seed: */
    srand(time(NULL));

    //variable to time the function
    auto start = chrono::system_clock::now();
    
    //populate the array with random ints 1-100
    for (int i = 0; i < 100000; i++)
    {
        v1[i] = rand() % 100 + 1;
    }

    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    cout << "Vector elapsed time: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();
    
    //populate list with random ints 1-100
    for (int i = 0; i < 100000; i++)
    {
        list1.insertFirst(rand() % 100 + 1);
    }

    end = chrono::system_clock::now();
    elapsed_seconds = end-start;
    cout << "Linked List elapsed time: " << elapsed_seconds.count() << "s\n";

    
    start = chrono::system_clock::now();

    //use helper function that returns a string
    //to put that string into array 
    for (int i = 0; i < 100000; i++)
    {
        v2.push_back(createString());
    }
    end = chrono::system_clock::now();
    elapsed_seconds = end-start;
    cout << "String vector elapsed time: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();

    //put randomly generated string into a list
    for (int i = 0; i < 100000; i++)
    {
        list2.insertFirst(createString());
    }

    end = chrono::system_clock::now();
    elapsed_seconds = end-start;
    cout << "String Linked List elapsed time: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();

    //use move semantics to create a string and add it 
    //to vector
    for (int i = 0; i < 100000; i++)
    {
        v3.push_back(move(createString()));
    }
    end = chrono::system_clock::now();
    elapsed_seconds = end-start;
    cout << "String vector with move semantics elapsed time: " << elapsed_seconds.count() << "s\n";

    start = chrono::system_clock::now();

    //use move semantics to create a string and add it 
    //to a list 
    for (int i = 0; i < 100000; i++)
    {
        list3.insertFirst(move(createString()));
    }

    end = chrono::system_clock::now();
    elapsed_seconds = end-start;
    cout << "String Linked List with move semantics elapsed time: " << elapsed_seconds.count() << "s\n";


    return 0;
}
