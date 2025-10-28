#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//implementing functions for calculating each bracket
double bracket1(double, const double);
double bracket2(double, const double);
double bracket3(double, const double);
double bracket4(double, const double);
double bracket5(double, const double);
//for displaying user's input
void getInput(string, const double);
//error checker 
bool confirm(char);
//display the result of each calculation
void display(string, double, double);


int main() {
	//initilizaing, truly, a bunch of variables
	string ssn;//user's social security number
	double inc = 0;//income
	char yesno;//restart variable
	bool restart = false;//quit boolean
	const double PEN1 = 0.00;//first bracket penalty
	const double PEN2 = 3697.50;//second penalty
	const double PEN3 = 13525.50;//third
	const double PEN4 = 33644.50;//fourth
	const double PEN5 = 86348.50;//fifth
	double total = 0;//total amount owed
	int quit = 0;//used to quit program for good
	cout << showpoint << fixed << setprecision(2);//displaying only 2 decimals
	//restart or exit loop
	while (!restart) {
		cout << "Welcome to TaxPro95.\nPlease enter the current taxpyer's Social Security Number with dashes.\n";
		getline(cin, ssn);
		cout << "Now, please enter the taxable income found on Form 1080, line 38.\n";
		cin.clear();
		cin >> inc;
		getInput(ssn, inc);
		cout << "Is this information correct? Y/N\n";
		cin.clear();
		cin >> yesno;
		cin.ignore();
		//confirming if user entered it right and1 moving onto the next step
		if (confirm(yesno)) 
		{
			//first bracket
			if (inc >= 0 && inc < 24650)
			{
				total = bracket1(inc, PEN1);
				display(ssn, inc, total);
				cout << "Would you like to enter another user's information or leave?\n";
				cout << "1. Go again\n";
				cout << "2. Quit\n";
				cin.clear();
				cin >> quit;
				cin.ignore();
				if (quit == 1)
					bool restart = false;
				else if (quit == 2)
					return 0;
				else 
				{
					cout << "We'll just assume you want to run it again.";
					return 0;
				}

			}
			else if (inc >= 24650 && inc < 59750)
			{
				//second bracket
				total = bracket2(inc, PEN2);
				display(ssn, inc, total);
				cout << "Would you like to enter another user's information or leave?\n";
				cout << "1. Go again\n";
				cout << "2. Quit\n";
				cin.clear();
				cin >> quit;
				cin.ignore();
				if (quit == 1)
					bool restart = false;
				else if (quit == 2)
					return 0;
				else
				{
					cout << "We'll just assume you want to run it again.";
					return 0;
				}
			}
			else if (inc >= 59750 && inc < 124650)
			{
				//third bracket
				total = bracket3(inc, PEN3);
				display(ssn, inc, total);
				cout << "Would you like to enter another user's information or leave?\n";
				cout << "1. Go again\n";
				cout << "2. Quit\n";
				cin.clear();
				cin >> quit;
				cin.ignore();
				if (quit == 1)
					bool restart = false;
				else if (quit == 2)
					return 0;
				else
				{
					cout << "We'll just assume you want to run it again.";
					return 0;
				}
			}
			else if (inc >= 124650 && inc < 271050)
			{
				//fourth bracket
				total = bracket4(inc, PEN4);
				display(ssn, inc, total);
				cout << "Would you like to enter another user's information or leave?\n";
				cout << "1. Go again\n";
				cout << "2. Quit\n";
				cin.clear();
				cin >> quit;
				cin.ignore();
				if (quit == 1)
					bool restart = false;
				else if (quit == 2)
					return 0;
				else
				{
					cout << "We'll just assume you want to run it again.";
					return 0;
				}
			}
			else if (inc >= 271080)
			{
				//fifth bracket
				total = bracket5(inc, PEN5);
				display(ssn, inc, total);
				cout << "Would you like to enter another user's information or leave?\n";
				cout << "1. Go again\n";
				cout << "2. Quit\n";
				cin.clear();
				cin >> quit;
				cin.ignore();
				if (quit == 1)
					bool restart = false;
				else if (quit == 2)
					return 0;
				else
				{
					cout << "We'll just assume you want to run it again.";
					return 0;
				}
			}
			else
			{
				//in case the user ends up having a number out of bounds, which isn't likely, but best practices right? edge cases?
				cout << "You messed up somwhere. Let's try it all from the start!";
				bool restart = false;
			}
		}
		//if the user realizes they made a mistake, this loops backto the start
		else 
		{
			{
				cout << "Let's try entering in that info again.\n";
				bool restart = false;
			}
		}
	}
}

//all functions here are described earlier when they're prototyped
void getInput(string ssn, double inc) {
	cout << "The SSN entered was: " << ssn << endl;
	cout << "And for the taxpayer's income, you entered: $" << inc << endl;
}

bool confirm(char yesno) {
	if (yesno == 'y' || yesno == 'Y')
		return true;
	else if (yesno == 'n' || yesno == 'N')
		return false;
	else
	{
		cout << "We're gonna assume you meant no.\n";
		return false;
	}
		
}

void display(string ssn, double inc, double total) 
{
	cout << "User " << ssn << " made " << inc << " in the current tax period.\n";
	cout << "User " << ssn << " owes " << total << " in taxes for this period.\n";
}

double bracket1(double inc, const double PEN1)
{
	return (PEN1 + (.15 * (inc - 0)));
}

double bracket2(double inc, const double PEN2)
{
	return (PEN2 + (.28 * (inc - 24650)));
}

double bracket3(double inc, const double PEN3)
{
	return (PEN3 + (.31 * (inc - 59750)));
}

double bracket4(double inc, const double PEN4)
{
	return (PEN4 + (.36 * (inc - 124650)));
}

double bracket5(double inc, const double PEN5)
{
	return (PEN5 + (.36 * (inc - 271050)));
}