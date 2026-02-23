////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name: arrayi.h
//
// This file defines an istream and ostream function for a simple aray class.
// 
//
// Programmer: Randy Devlin-Souter
//
// Date created: 2/22/26
//
// Date last revised: 2/22/26
////
////////////////////////////////////////////////////////////////////////////////////////////////





#ifndef ARRAYI_T_
#define ARRAYI_T_





#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace::std;



/* Default constructor for class Array
template<typename T>
Array<T>::Array(int arraySize)
{
    cout << "calling the constructor \n";
}
*/


//Overloaded output operator for class Array
template<typename T>
ostream &operator<<(ostream &output, const Array<T> &a)
{

  int i;
  output << "{ ";

  for (i = 0; i < a.size; i++)
    {
      output << a.ptr[i] << ' ';

      if ((i + 1) % 10 == 0)
        output << "}" << endl;
    }  //end for

  if (i % 10 != 0)
    output << "}" << endl;

  return output;   // enables cout << x << y;
}

// Overloaded input operator for class Array;
// inputs values for entire array.
template<typename T>
istream &operator>>(istream &input, Array<T> &a)
{
  int i;
  for (i = 0; i < a.size; i++)
    input >> a.ptr[i];

  return input;   // enables cin >> x >> y;
}




#endif



