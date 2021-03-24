# HW1_Problem_1
HW1__Problem_1
/*
By Yevgeniy Sumaryev
3/20/21
*/

In this problem we had to create a custom vector class and a custom linked list class, and then time insertion times for each of the classes.
I tried to use all the conventional methods in vector and list class such as insert(), erase(), pop_back() and push_back(), along with constructors, for copy and move, a destructor and operator overloads. 
I’ve used a header file and implementation file for both a vector and list class. Additionally I added an Iterator class to each header file instead of creating a separate file for it 
since I thought it would be more compact and easier to read the code.
Also it allowed an Iterator to have access to all the necessary variables. 
Since my vector and list class were template classes in my main file I had to #include both .h and .cpp file otherwise
the compilation wouldn’t work for me.
 In the main function I used chrono class to time the functions and when creating random strings 
 I’ve used a helper function that firstly created a variable sized length, and then generated random characters that I appended to a string.
 When timing the classes I’ve noticed how vector class is much faster for insertion, 
 and using move semantics increased the speed time for inserting strings in both vector and list classes  

