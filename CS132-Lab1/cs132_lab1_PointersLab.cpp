

/******************************************************************************
*
*   File name: cs132_lab1_PointersLab.cpp
*
*   This program assesses the programmer's ability to understand pointers & 
*	how the function.
*
*
*   Programmer:  Randy Devlin-Souter with contributions from B.J. Streller
*
*   Date Written:		in the past
*
*   Date Last Revised: 2-1-26
*
******************************************************************************/
#include <iostream>
using namespace std;


int main () {
	// Declarations & Definitions
	int a = 5;

	int*** p = new int**;
	*p = new int*;
	**p = &a;

	int*** q;

	int** r = new int*;
	*r = new int;
	**r = 10;

	int *t = new int;
	*t = 20;

	// Step 2 - Print Values for variables here
	// TODO  you need to add code here to print

	//processing p
	cout << p << " is the address of *p. " << endl;
	cout << *p << " is the address of **p." << endl;
	cout << **p << " is the address of a" << endl;
	cout << ***p << " is the value of a." << endl;
	cout << a << " is just a value, phew." << endl;
	// q throws up errors when running, unitialized memory.


	// processing r and t
	cout << r << " is the address of *r. " << endl;
	cout << *r << " is the address of **r." << endl;
	cout << **r << " is an int (10)" << endl;
	cout << t << " is address of *t" << endl;
	cout << *t << " value of *t (20)" << endl;





	// Process
	q = &r;
	delete *r;
	*r = t;

	// Step 3 - Print Values for variables here as well
	// TODO  you need to add code here to print

	cout << "________________________________________________" << endl;
	cout << "swapped some values and made use of q." << endl;
	cout << "------------------------------------------------" << endl;
	//processing p
	cout << p << " is the address of *p. " << endl;
	cout << *p << " is the address of **p." << endl;
	cout << **p << " is the address of a" << endl;
	cout << ***p << " is the value of a." << endl;
	cout << a << " is just a value, phew." << endl;
	//processing q 
	cout << q << " is the address of r. " << endl;
	cout << *q << " is the address of *r." << endl;
	cout << **q << " is the address of t" << endl;
	cout << ***q << " is the value of *t." << endl;
	// processing r and t
	cout << r << " is the address of *r. " << endl;
	cout << *r << " is the address of t." << endl;
	cout << **r << " is an int (20)" << endl;
	cout << t << " is address of *t" << endl;
	cout << *t << " value of *t (20)" << endl;



	// Step 4 - Clean up - free all memory that isn't automatically freed
	// TODO  you need to add code here to free memory 


	delete *r, t, *p, p, r;



return 0;

}






