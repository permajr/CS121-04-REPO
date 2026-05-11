#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "employee.h"
#include "tree.h"
using namespace std;

void mainMenu();

int main() 
{
	mainMenu();
}

void mainMenu()
{
	oxyRecord currentRecord;
	bool loop = false;

	while (!loop) 
	{
		int choice = 0;
		cout << "=========================================================\n"
			<< "Welcome to the Oxy Cookie Company Company Records Cruncher\n"
			<< "Care to cross-examine the contents of our cookie company?\n"
			<< "==========================================================\n"
			<< "1: Tell us the filepath of the record you'd like to access!\n"
			<< "2: Add a new employee into the record!\n"
			<< "3: Update an employee already in the record!\n"
			<< "4: Display a specific employee!\n"
			<< "5: List out a group of employees!\n"
			<< "6: Store the employee record in a new file!\n"
			<< "7: Remove an employee from the record!\n"
			<< "8: Exit the program.\n";

		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			currentRecord.checkFile();
			loop = false;
			break;
		case 2:
			currentRecord.newEmployee();
			loop = false;
			break;
		case 3:
			currentRecord.updateRecord();
			loop = false;
			break;
		case 4:
			currentRecord.retrieveRecord();
			loop = false;
			break;
		case 5:
			currentRecord.showFile();
			loop = false;
			break;
		case 6:
			currentRecord.saveToFile();
			loop = false;
			break;
		case 7:
			currentRecord.deleteRecord();
			loop = false;
			break;
		case 8:
			loop = true;
			break;
		default:
			loop = false;
			cout << "incorrect entry, please try again";
		}
	}

}

