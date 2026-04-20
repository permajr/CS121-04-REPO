/////////////////////////////////  cs132lab5driver.cpp  ///////////////////////
//
// File name         : cs132lab5driver.cpp
//
// This program read an any input file into a list,prints it deletes the fifth
// entry ,prints it again, requests a new entry and adds it to the beginning 
// of the list.
//
// Programmer        : B.J. Streller AND WHO
//
// Date created      : 
//
// Date last revised :
//
///////////////////////////////////////////////////////////////////////////////


#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include "list.h"
using namespace std;



struct Disney                                              //declare a struct
{
	char  name[20];
	int   id;

	// YOU create friends for insertion and extraction
	friend ostream& operator<< (ostream& out, const Disney& d);
	friend istream& operator>> (istream& in, Disney& d);

};

fstream infile;
string fname, temp;
List<Disney> disList;


string getInputFileName(string&);
void readFileToList();
void printList();
void addToList();


////////////////////////////////////  main  ///////////////////////////////////


int main()
{
	getInputFileName(fname);

	//read file into list
	readFileToList();

	//print the list
	printList();

	//move to fourth item in list
	//delete the fifth item
	disList.makeCurrent(4);
	disList.next();
	Disney* removed = disList.examine();
	cout << "\nRemoving: " << *removed << endl;
	delete removed;
	disList.remove();

	//print list after deletion
	cout << "\nList after removing fifth item:\n";
	printList();

	//request and add item to list
	addToList();

	//print final list
	cout << "\nFinal list:\n";
	printList();

	// close the file
	infile.close();

	return 0;

}




ostream& operator<< (ostream& out, const Disney& d)
{
	out << setw(15) << d.name << setw(10) << d.id;
	return out;
}

istream& operator>> (istream& in, Disney& d)
{
	in >> d.name >> d.id;
	return in;
}

/////////////////////////////////// getInputFileName //////////////////////////
string getInputFileName(string& fname)
{
	bool errCheck = false;
	cout << "Welcome to Randy's Disney Character Storage & Retrieval Service!\n";
	cout << "Please enter the name of the file, with full path, you'd like to read from!\n";
	while (!errCheck)
	{
		cin >> fname;
		infile.open(fname);
		if (!infile)
		{
			cout << "uh oh! try again!\n";
			errCheck = false;

		}
		else
		{
			cout << "Now watch us work our magic!\n";
			errCheck = true;
		}
	}
	return fname;
}



/////////////////////////////////// readFileToList ////////////////////////////
void readFileToList()
{
	Disney character;
	int disCount = 0;

	disList.first();
	while (infile >> character)
	{
		if (disCount == 0)
		{
			disList.insertAfter(character);
		}
		else
		{
			disList.last();
			disList.insertAfter(character);
		}
		disCount++;
	}
	cout << endl << "Read " << disCount << " characters from file." << endl;
}




/////////////////////////////////// printList /////////////////////////////////
void printList()
{
	if (disList.count() == 0)
	{
		cout << "List is empty." << endl;
		return;
	}

	disList.first();
	for (int i = 0; i < disList.count(); i++)
	{
		Disney* temp = disList.examine();
		cout << *temp << endl;
		delete temp;
		if (i < disList.count() - 1)
			disList.next();
	}
}




/////////////////////////////////// addToList /////////////////////////////////
void addToList()
{
	Disney newCharacter;

	cout << "\nEnter a new Disney character to add to the beginning of the list:\n";
	cout << "Name: ";
	cin >> newCharacter.name;
	cout << "ID: ";
	cin >> newCharacter.id;

	disList.first();
	disList.insertBefore(newCharacter);
	cout << "Added: " << newCharacter << endl;
}




/*
OUTPUT:
Welcome to Randy's Disney Character Storage & Retrieval Service!
Please enter the name of the file, with full path, you'd like to read from!
disneyin.txt
Now watch us work our magic!

Read 12 characters from file.
		  daisy       123
		 donald       345
		  goofy       654
		 mickey       593
		 minnie       489
		  daffy       432
		  pluto       765
		   huey       321
		  dewey       987
		  lewey       554
		  porky       333
		  buggs       778

Removing:          minnie       489

List after removing fifth item:
		  daisy       123
		 donald       345
		  goofy       654
		 mickey       593
		  daffy       432
		  pluto       765
		   huey       321
		  dewey       987
		  lewey       554
		  porky       333
		  buggs       778

Enter a new Disney character to add to the beginning of the list:
Name: randy
ID: 1337
Added:           randy      1337

Final list:
		  randy      1337
		  daisy       123
		 donald       345
		  goofy       654
		 mickey       593
		  daffy       432
		  pluto       765
		   huey       321
		  dewey       987
		  lewey       554
		  porky       333
		  buggs       778

C:\Users\randy\Documents\GitHub\CS121-04-REPO\CS132-LAB5\x64\Debug\CS132-LAB5.exe (process 21332) exited with code 0 (0x0).
Press any key to close this window . . .
*/