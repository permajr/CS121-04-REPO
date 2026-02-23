

////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name: arrayi.h
//
// This file defines the core elements of a simple Array class.
// 
//
// Programmer: Randy Devlin-Souter
//
// Date created: 2/22/26
//
// Date last revised: 2/22/26
//
////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ARRAYI_H_
#define ARRAYI_H_

#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;


template<typename T> class Array;
template<typename T> ostream& operator<< (ostream& output, const Array<T>& a);
template<typename T> istream& operator>> (istream& input, Array<T>& a);
template <typename T>
class Array
{
public:
    Array(int = 10);	//constructor
    Array(const Array&);	//copy constructor
    ~Array();		//destructor
    int getSize() const;	//return size
    Array& operator = (const Array&);
    int operator==(const Array&) const;
    int operator != (const Array&) const;
    T& operator[] (int);
    Array operator + (const Array&);
    static int getArrayCount();	//get count of existing array objects
    friend ostream &operator<< <>(ostream& output, const Array<T>& a);
    friend istream &operator>> <>(istream& input, Array<T>& a);
    Array operator- (const Array&);
    
private:
    T* ptr;	//ptr to first array element
    int size;	//size of the array
    static int arrayCount;	// #of arrays instantiated
};


#include "arrayi.t"
#endif







