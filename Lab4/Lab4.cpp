/*****************************************************************************************
** File name: Lab4
** Course Name: CS121094
** Instructor Name: Dutta
** This program calcuates the average of three grades.
** Programmer: Randy Devlin-Souter
** Date created: 10/02/2025
*****************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() 
{
	//ask for user name & get first variable, establish while loop and a couple of variables
	string name, yesno;
	bool ans = false;
	cout << setprecision(2)<<showpoint <<fixed ;
	cout << "Enter the student's name:\n";
	getline(cin, name);
	cout << "Thank you." << endl;

/***************************************************************
	this loop repeats when any wrong answer is entered.
	get first grade & start loop again if answered incorrectly.
***************************************************************/
	while (!ans)
	{

		double gra1 = 0.0, gra2 = 0.0, gra3 = 0.0;
		double avg = 0.0;
		cin.clear();
		cout << "Give me the student's first grade:\n";
		cin >> gra1;
		if (gra1 > 100 || gra1 < 0)
		{
			cout << "Give it another shot!\n";
			ans = false;
			cin.clear();
		}
		else
		{
			//get second answer and start loop again if answered incorrectly.
			cout << "Enter the second grade.\n";
			cin >> gra2;
			cin.clear();
			if (gra2 > 100 || gra1 < 0)
			{
				cout << "Try again from the start!\n";
				ans = false;
			}
			else
			{
				//get second answer and start loop again if answered incorrectly.
				cout << "Enter the third grade.\n";
				cin >> gra3;
				cin.clear();
				if (gra3 > 100 || gra1 < 0)
				{
					cout << "Try again from the start!\n";
					ans = false;
				}
				else
				{					
					//calculate average as well as letter grade.
					cout << "Thank you!. Cruching some numbers. \n";
					avg = (gra1 + gra2 + gra3) / 3;
					cout << avg << endl;
					cin.clear();
					if (avg >= 90)
					{
						cout << "This grade is an A!\n";
						cin.ignore();
						return 0;
					}
					else if (avg >= 80 && avg < 90)
					{
						cout << "This grade is a B!\n";
						cin.ignore();
						return 0;
					}
					else if (avg >= 70 && avg < 80)
					{
						cout << "This grade is a C.\n";
						cin.ignore();
						return 0;
					}
					else if (avg >= 50 && avg < 70)
					{
						cout << "This grade is a D.\n";
						cin.ignore();
						return 0;
					}
					else if (avg <= 50)
					{
						cout << "This grade is an F.\n";
						cin.ignore();
						return 0;
					}
				}
			}

		}

	}

}
