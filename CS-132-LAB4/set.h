// File: set.h
// Course: CS132 Lab4
// Semester: sp2026
// Programmer: Randy Devlin-Souter
// Description: Set class template definition

#ifndef SET_H_
#define SET_H_

#include <iostream>
#include <cassert>
#include "array_v.h"

using std::cout;
using std::endl;

template <class Universe>
class Set : protected Array_V<Universe, bool>
{
public:
    Set(Universe loElement, Universe hiElement);
    Set<Universe>(Set<Universe> &initSet);
    ~Set();
    void operator = (Set<Universe> &&source);
    bool empty();
    bool operator == (Set<Universe>& t);
    bool operator <= (Set<Universe>& t);
    Set operator || (Set<Universe>& t);
    Set operator && (Set<Universe>& t);
    Set operator - (Set<Universe>& t);
    Set operator / (Set<Universe>& t);
    void add(Universe element);
    void remove(Universe element);
    void writeSet();
    bool inSet(Universe element);
protected:
    Universe loElement, hiElement;
};

#include "set.t"

#endif