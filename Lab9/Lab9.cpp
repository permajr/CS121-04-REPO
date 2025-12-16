/* Student Name: Randy Devlin-Souter
 Course Name: CS-121-04
 Instructor Name: Dutta
 Problem Specification: Search through a file for a name by using an ID number.
*/















#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//prototyping functions and declaring global variables
void fileChecker(int&, string&, string&);
string nameGetter(string&);
int idGetter(int&);
bool looper(bool&);
bool canOpener(bool&);
string idlist, name, test, yesno;
int idnumber, tempnum;
ifstream infile;
bool loop = false;
bool check = false;


int main() 
{
	while (!loop) 
	{
		//function to get the filepath of the roster
		nameGetter(idlist);
		//boolean function to check if the file is opened, if it doesnt open it loops back to the top of main
		if(!canOpener(check))
			loop = false;
		else 
		{
			//gets the id for the name to look up
			idGetter(idnumber);
			//searches through the file for the name and gives a result
			fileChecker(idnumber, name, idlist);
			infile.close();
			//loops the main body
			looper(loop);
		}
	}
}
// just prompts user for the entry of the ID number to be looked up
int idGetter(int& idnumber) 
{
	cout << "*****************************************************************************\n";
	cout << "Please enter the ID number you're trying to look up!\n";
	cout << "*****************************************************************************\n";
	cin.clear();
	cin >> idnumber;
	cin.clear();
	return idnumber;
}

//prompts the user for the filepath
string nameGetter(string& idlist) 
{
	cout << "*****************************************************************************\n";
	cout << "Thanks for using Norton's Numerous Numerical Name Enumorator '99!\n";
	cout << "Please enter the path and filename of the roster you're trying to locate!\n";
	cout << "*****************************************************************************\n";
	cin.clear();
	cin >> idlist;
	cin.clear();
	return idlist;
}


//simple comparing search function to determine if the name matches the ID
void fileChecker(int& idnumber, string& name, string& idlist)
{
	{
		if (!infile)
		{
			cout << "\n*****************************************************************************\n";
			cout << "Improper file name detected!\n";
			cout << "*****************************************************************************\n";
		}

		else
		{
			cout << "\n*****************************************************************************\n";
			cout << "Looking for that ID number now! Wish me some luck...\n";
			cout << "*****************************************************************************\n";

			/*************************************************************************************************************************************************
			* for some reason making this a boolean caused it to not actually trigger the related if statement below
			* what this does is update when a matching name is found, so it can trigger a failure message if the search fails to find a name matching the ID
			* originally it would just spit out an update every time the while loop iterated but that was really messy so this cleans it up
			**************************************************************************************************************************************************/
			int found = 100;
				while (infile >> tempnum)
				{
					infile >> test;

					//tempnum stores the variable that's currently read by the file, this is if/else compares it against the idnumber the user entered
					if (idnumber == tempnum)
					{
						cout << "\n*****************************************************************************\n";
						cout << "You entered ID number: " << idnumber << " and we found it!\n";
						cout << "The name attached to the ID number is: " << test << endl;
						cout << "*****************************************************************************\n";
						found = 0;
					}
					else
					{
						found = 100;
					}
					//terminates the while loop early when the matching name is found, again for some reason only worked as an integer
					if (found == 0)
						break;
				}

				//only triggers if the name wasn't found. for some reason only works as an integer
				if (found == 100)
				{
					cout << "\n*****************************************************************************\n";
					cout << "Looks like I wasn't able to find that ID for you.\n";
					cout << "*****************************************************************************\n";
				}
		}
	}
}

//just asks to loop the main function 
bool looper(bool& loop) 
{
	cout << "\n*****************************************************************************\n";
	cout << "Would you like to run another search? Y/N\n";
	cout << "*****************************************************************************\n";
	cin.clear();
	cin >> yesno;
	cin.clear();
	if (yesno == "n" || yesno == "N")
		loop = true;
	else if (yesno == "y" || yesno == "Y")
		loop = false;
	else
	{
		cout << "\n*****************************************************************************\n";
		cout << "Invalid entry!\n";
		cout << "*****************************************************************************\n";
		loop = false;
	}

	return loop;
}

//just checks if the file properly opened, if it fails to open the if condition in the main body loops it back to the start
bool canOpener(bool& check) 
{
	infile.open(idlist);
	if (!infile)
	{
		cout << "\n*****************************************************************************\n";
		cout << "Invalid file name OR file path, please try again!\n";
		cout << "*****************************************************************************\n";
		return false;
	}
	else
		return true;
}