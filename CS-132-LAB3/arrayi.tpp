////////////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : 
//
// This file....
// 
//
// Programmer        : 
//
// Date created      : 
//
// Date last revised :
//
////////////////////////////////////////////////////////////////////////////////////////////////





#ifndef ARRAYI_T_
#define ARRAYI_T_





#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace::std;





//Default constructor for class Array
template<typename T>
Array<T>::Array(int arraySize)
{
cout << "calling the constructor \n"; 
}





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



#endif



