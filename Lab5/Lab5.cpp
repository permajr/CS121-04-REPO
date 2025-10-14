/*****************************************************************************************
** File name: Lab5.cpp
** Course Name: CS121-04
** Instructor Name: Dutta
** This program demonstrates an understanding of the different kinds of loops.
** Programmer: Randy Devlin-Souter
** Date created: 10/13/2024
*****************************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	//initialize variables, set decimal point
	cout << setprecision(2) << showpoint << fixed;
	int i = 0;
	double gal, lit;
	int limit;

	//cumulative adder program. the value "i" keeps getting added with the next number in sequence.
	while (i < 126)
	{
		cout << "Check this out!\n";
		i = 16 + 18;
		cout << "16 plus 18 is: " << i << endl;
		i = i + 20;
		cout << "34 + 20 is: " << i << endl;
		i = i + 22;
		cout << "54 + 22 is: " << i << endl;
		i = i + 24;
		cout << "76 + 24 is: " << i << endl;
		i = i + 26;
		cout << "This brings our total, 16 + 18 + 20 + 22 + 24 + 26, to: " << i << endl;
	}


//converting gallons to litres. error checking is done via an if else statement and the z value is reset to begin the for loop again.

	for(int z = 0; z<5; z++)
	{
			cout << "Give me a number of gallons! Just make sure it isn't negative, because negative liquid breaks the laws of physics!\n";
			cin.clear();
			cin >> gal;
			if (gal > 0)
			{
				cout << "Doing some math.\n";
				lit = gal * 3.79;
				cout << "You entered " << gal << " and I calculated that's actually " << lit << " liters!\n";
			}
			else
			{
				cout << "You entered a negative value. Try again, from the start!\n";
				z = -1;
			}

	}

//makes a square with the user's number of rows. the "goto" function is used for simplicity's sake.
square:
	cout << "Give me a number that's ten or less!";
	cin.clear();
	cin >> limit;
	cin.ignore();
	if (limit <= 10 && limit > 0)
	{
		cout << endl;
		for (int rows = 0; rows < limit; rows++)
		{
			for (int columns = 0; columns < limit; columns++)
			{
				cout << "X ";
			}
			cout << "\n";
		}
		cout << "\nPretty neat square, huh?\n\n\n";
	}
	else {
		cout << "Try again, fluffball.\n";
		goto square;
	}

	cout << "Thanks for testing. Press enter to exit!";
	cin.ignore();
	
}
	