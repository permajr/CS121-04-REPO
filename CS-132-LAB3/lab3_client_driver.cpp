



////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name: lab3_clienter_driver.cpp
//
// This program displays prearranged arrays with data supplied by instructions 
// in the lab PDF, then substracts the values stored in those arrays at runtime.
// 
//
// Programmer: Randy Devlin-Souter
//
// Date created: 2/22/26
//
// Date last revised: 2/22/26
//
////////////////////////////////////////////////////////////////////////////////////////////////





#include<iostream>
#include "arrayi.h"
using namespace::std;

int main()

{
  /* an example of an arrayi double object
  Array<double> A(3), B;
  */
	cout << "Hello! Welcome to Arron's Array Adjusters! Check this out...\n";
	cout << "------------------------------------------------------------\n";
	Array<int> A1(4);
    A1[0] = 6;
    A1[1] = 7;
    A1[2] = 8;
    A1[3] = 9;
    cout << A1;
    Array<int> A2(7);
    A2[0] = 1;
    A2[1] = 2;
    A2[2] = 3;
    A2[3] = 4;
    A2[4] = 5;
    A2[5] = 6;
    A2[6] = 7;
    cout << A2;
    Array<int> A3;
    A3 = A1 - A2;
    cout << A3;
    Array<double> B1(4);
    B1[0] = 6.6;
    B1[1] = 7.7;
    B1[2] = 8.8;
    B1[3] = 9.9;
    cout << B1;
    Array<double> B2(7);
    B2[0] = 1.1;
    B2[1] = 2.2;
    B2[2] = 3.3;
    B2[3] = 4.4;
    B2[4] = 5.5;
    B2[5] = 6.6;
    B2[6] = 7.7;
    cout << B2;
    Array<double> B3;
    B3 = B1 - B2;
    cout << B3;
    Array<float> C1(4);
    C1[0] = 6.66;
    C1[1] = 7.77;
    C1[2] = 8.88;
    C1[3] = 9.99;
    cout << C1;
    Array<float> C2(7);
    C2[0] = 1.11;
    C2[1] = 2.22;
    C2[2] = 3.33;
    C2[3] = 4.44;
    C2[4] = 5.55;
    C2[5] = 6.66;
    C2[6] = 7.77;
    cout << C2;
    Array<float> C3;
    C3 = C1 - C2;
    cout << C3;

    return 0;
}

// Initialize static data member at file scope
template<typename T>
int Array<T>::arrayCount = 0;   // no objects yet

//subtract values stored in arrays & take the difference
template <typename T>
Array<T> Array<T>::operator - (const Array& right)
{
    int large, small;
    if (size > right.size)
    {
        large = size;
        small = right.size;
    }
    else
    {
        large = right.size;
        small = size;
    }
    Array z(large);
    int i;
    for (i = 0; i < small; i++)
        z.ptr[i] = ptr[i] - right.ptr[i];
    for (i = small; i < large; i++)
    {
        if (right.size == small)
            z.ptr[i] = ptr[i];
        else z.ptr[i] = -right.ptr[i];  // negate remaining right elements
    }
    cout << "# of arrays instantiated " << getArrayCount() << endl;
    return z;
}

// Default constructor for class Array
template<typename T>
Array<T>::Array(int arraySize)
{
    ++arrayCount;             // count one more object
    size = arraySize;         // default size is 10
    ptr = new T[size];      // create space for array
    assert(ptr != 0);  // terminate if memory not allocated
    int i;
    for (i = 0; i < size; i++)
        ptr[i] = 0;            // initialize array
    cout << "calling the constructor \n";
}

// Copy constructor for class Array
template<typename T>
Array<T>::Array(const Array& init)
{
    ++arrayCount;             // count one more object
    size = init.size;         // size this object
    ptr = new T[size];      // create space for array
    assert(ptr != 0);  // terminate if memory not allocated
    cout << "copy constr arrayi " << endl;
    int i;
    for (i = 0; i < size; i++)
        ptr[i] = init.ptr[i];  // copy init into object
    cout << endl << "copy constructor working" << endl;
}

// Destructor for class Array
template<typename T>
Array<T>::~Array()
{
    --arrayCount;             // one fewer objects
    delete[] ptr;            // reclaim space for array
}

// Get the size of the array
template <typename T>
int Array<T>::getSize() const
{
    return size;
}

// Overloaded assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array& right)
{
    if (&right != this)
    {    // check for self-assignment
        delete[] ptr;        // reclaim space
        size = right.size;    // resize this object
        ptr = new T[size];  // create space for array copy
        assert(ptr != 0);     // terminate if memory not allocated
        int i;
        for (i = 0; i < size; i++)
            ptr[i] = right.ptr[i];  // copy array into object
    }
    //this points to ptr to int,  *this returns ptr value
    //ie, the address of the array
    return *this;   // enables x = y = z;
}

// + operator for arrays
template <typename T>
Array<T>  Array<T>::operator + (const Array& right)
{
    int large, small;
    if (size > right.size)
    {
        large = size;
        small = right.size;
    }
    else
    {
        large = right.size;
        small = size;
    }
    Array z(large);
    int i;
    for (i = 0; i < small; i++)
        z.ptr[i] = ptr[i] + right.ptr[i];
    for (i = small; i < large; i++)
    {
        if (right.size == small)
            z.ptr[i] = ptr[i];
        else  z.ptr[i] = right.ptr[i];
    }
    cout << "# of arrays instantiated " << getArrayCount() << endl;
    return z;
}

// Determine if two arrays are equal and
// return 1 if true, 0 if false.
template <typename T>
int Array<T>::operator==(const Array& right) const
{
    if (size != right.size)
        return 0;    // arrays of different sizes
    int i;
    for (i = 0; i < size; i++)
        if (ptr[i] != right.ptr[i])
            return 0; // arrays are not equal

    return 1;       // arrays are equal
}

// Determine if two arrays are not equal and
// return 1 if true, 0 if false.
template <typename T>
int Array<T>::operator!=(const Array& right) const
{
    if (size != right.size)
        return 1;         // arrays of different sizes
    int i;
    for (i = 0; i < size; i++)
        if (ptr[i] != right.ptr[i])
            return 1;      // arrays are not equal

    return 0;            // arrays are equal
}

// Overloaded subscript operator
template <typename T>
T& Array<T>::operator[](int subscript)
{
    // check for subscript out of range error
    assert(0 <= subscript && subscript < size);
    return ptr[subscript];   // reference return creates lvalue
}

// Return the number of Array objects instantiated
template <typename T>
int Array<T>::getArrayCount()
{
    return arrayCount;
}



/***************************************************************************************
//CONSOLE OUTPUT//
Hello! Welcome to Arron's Array Adjusters! Check this out...
------------------------------------------------------------
calling the constructor
{ 6 7 8 9 }
calling the constructor
{ 1 2 3 4 5 6 7 }
calling the constructor
calling the constructor
# of arrays instantiated 4
{ 5 5 5 5 -5 -6 -7 }
calling the constructor
{ 6.6 7.7 8.8 9.9 }
calling the constructor
{ 1.1 2.2 3.3 4.4 5.5 6.6 7.7 }
calling the constructor
calling the constructor
# of arrays instantiated 4
{ 5.5 5.5 5.5 5.5 -5.5 -6.6 -7.7 }
calling the constructor
{ 6.66 7.77 8.88 9.99 }
calling the constructor
{ 1.11 2.22 3.33 4.44 5.55 6.66 7.77 }
calling the constructor
calling the constructor
# of arrays instantiated 4
{ 5.55 5.55 5.55 5.55 -5.55 -6.66 -7.77 }

C:\Users\randy\Documents\GitHub\CS121-04-REPO\CS-132-LAB3\x64\Debug\CS-132-LAB3.exe (process 30568) exited with code 0 (0x0).
Press any key to close this window . . .
************************************************************************************************/



