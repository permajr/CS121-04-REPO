// File: cs132Lab4_driver.cpp
// Course: CS132 Lab4
// Semester: sp2026
// Programmer: Randy Devlin-Souter
// Description: Driver to demonstrate Set class operations

#include <iostream>
#include "set.h"
using namespace std;
int main()
{
    // All sets use universe 1..10
    Set<int> A(1, 10);
    Set<int> B(1, 10);
    Set<int> C(1, 10);

    // Build sets using add()
    A.add(1); A.add(3); A.add(8);
    B.add(2); B.add(3); B.add(5); B.add(10);
    C.add(4); C.add(6);

    cout << "Set A = "; A.writeSet();
    cout << "Set B = "; B.writeSet();
    cout << "Set C = "; C.writeSet();
    cout << endl;

    Set<int> result(1, 10);

    cout << "A && B = ";
    result = A && B;
    result.writeSet();
   cout << "A - B  = ";
    result = A - B;
    result.writeSet();

    cout << "A || B = ";
    result = A || B;
    result.writeSet();

    cout << "A / B  = ";
    result = A / B;
    result.writeSet();

    cout << endl;

    cout << "A && C = ";
    result = A && C;
    result.writeSet();

    cout << "A - C  = ";
    result = A - C;
    result.writeSet();

    cout << "A || C = ";
    result = A || C;
    result.writeSet();

    cout << "A / C  = ";
    result = A / C;
    result.writeSet();

    return 0;
    

/*
CONSOLE OUTPUT:
===============
Set A = {1,3,8}
Set B = {2,3,5,10}
Set C = {4,6}

A && B = copy constructor has been calledsource loEl is: 1 source hiELis: 10
{3}
A - B  = copy constructor has been calledsource loEl is: 1 source hiELis: 10
{1,8}
A || B = copy constructor has been calledsource loEl is: 1 source hiELis: 10
{1,2,3,5,8,10}
A / B  = copy constructor has been calledsource loEl is: 1 source hiELis: 10
{1,2,5,8,10}

A && C = copy constructor has been calledsource loEl is: 1 source hiELis: 10
{}
A - C  = copy constructor has been calledsource loEl is: 1 source hiELis: 10
{1,3,8}
A || C = copy constructor has been calledsource loEl is: 1 source hiELis: 10
{1,3,4,6,8}
A / C  = copy constructor has been calledsource loEl is: 1 source hiELis: 10
{1,3,4,6,8}

C:\Users\randy\Documents\GitHub\CS121-04-REPO\CS-132-LAB4\x64\Debug\CS-132-LAB4.exe (process 42128) exited with code 0 (0x0).
Press any key to close this window . . .
*/
}