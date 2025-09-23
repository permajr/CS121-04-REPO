/*****************************************************************************************
** File name:Lab3.cpp
** Course Name: CS121-04
** Instructor Name: Dutta
** This program write a description of what this program does: Calcualtes discriminant.
** Programmer: Randy Devlin-Souter
** Date created: 09-23-25
*****************************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	//declare necessary variables and constants
	int a, b, c;
	double  root1, root2, dis;
	//decimal formatting
	cout << setprecision(2) << fixed << showpoint;
	//prompt for three integer values a,b,c
	cout << "I would love it if you gave me three integer values!\n";
	cout << "Values:\n";
	cin >> a;
	cin.ignore();
	cin >> b;
	cin.ignore();
	cin >> c;
	cin.ignore();
	cout << "Doing some math now...";
	//calculate discriminant and save in variable named dis
	dis = (b ^ 2) - (4 * a * c);
	//display if dis is equal to 0, if it's imaginary, or if it's positive and to display all values.
	if (dis == 0)
	{

	}
	else if (dis < 0)
	{
		cout << root1 << ", " << root2;
	}
	else if (dis > 0);
	{
		cout << root1 << ", " << root2;
	}


//end main
	return 0;
}