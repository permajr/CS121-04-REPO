/* 
Student Name: Randy Devlin-Souter
Course Name: CS-121-04
Instructor Name: Dutta
Problem Specification: This program calculates the cost of a membership for a fitness center.
*/

//establish libraries, constants, loop-controlling variables, and prototype functions.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const double MEMBERSHIP = 100.00;
const double SESSION = 50.00;
const double SENIORPRICE = 70.00;
const double YEARLYDISCOUNT = .15;
const double SESSIONDISCOUNT = .20;
bool loop = false;
bool choice = false;
void info();
void get_Info(double&, double&, int&);
double calculateFee(double, double, int, double&, double&, double&);
int menu = 0;

int main() 
{
	//set decimal precision as well as variables within scope
	cout << showpoint << fixed << setprecision(2);
	double months = 0, sessions = 0, price1 = 0, price2 = 0, totalprice = 0;
	int age = 0;
	//this loop runs until the user quits thanks to a cheeky boolean.
	do {
		while (!choice) 
		{
		cout << "Welcome to Celestial Fitness! How can we help you today?\n";
		cout << "1. I want to sign up for a new membership.\n2. I want to view information about the plans available.\n3. I want to exit the program.\n";
		cin.clear();
		//setting up the menu  & options within
		cin >> menu;
		//displays the info blurb with pricing and discount information.
			if (menu == 2) 
			{
				info();
				choice = false;
				cin.clear();
			}
			//grabs user input, runs some numbers, and gives final prices for private sessions/monthly membership
			else if (menu == 1) {

				get_Info(months, sessions, age);
				cout << "Thanks so much! Crunching some numbers...\n";
				totalprice = calculateFee(months, sessions, age, price1, price2, totalprice);
				cout << "Your price breakdown looks like this:\n";
				cout << "--------------------------------------------------------------------------\n";
				cout << "Your monthly price with any applicable discount is: $" << price1 << endl ;
				cout << "The cost of all personal training sessions purchased with any applicable discount is: $" << price2 << endl;
				cout << "Your total price, all inclusive, is: $" << totalprice << endl;
				cout << "--------------------------------------------------------------------------\n";
				choice = false;
				cin.clear();
			}
			//quits the program
			else if (menu == 3) 
			{
				cin.clear();
				return 0;
			}
			//sends user back to the start if they put in any number other than 1,2, or 3
			else 
			{
				cout << "Invalid selection. Please try again!\n";
				cin.clear();
				choice = false;
			}
		}


	} while (loop == false);

}

//displays the discount rates, monthly price, session rates, and all that jazz.
void info() 
{
	cout << "Here are our current rates and discounts:\n";
	cout << "----------------------------------------------------------------------------------------------------\n";
	cout << "A monthly membership with us costs $100.\n";
	cout << "Individual sessions with us are $50 per session.\n";
	cout << "If you are a senior member, there is a 30% discount!\n";
	cout << "If you purchase yearly membership, there is a 15% discount!\n";
	cout << "If you purchase five or more personal training sessions, there is a 20% discount on the total!\n";
	cout << "----------------------------------------------------------------------------------------------------\n";
	choice = true;
}

//gets information from the user using reference variables and sends it all back to main.
void get_Info(double& months, double& sessions, int& age)
{
	cout << "How old are you? Enter your age:";
	cin.clear();
	cin >> age;
	cout << "You entered: " << age << ".\n";
	if (age >= 65)
		cout << "Congrats! You qualify for the senior discount.\n";
	else if (age < 65)
		cout << "You are not eligible for the senior discount.\n";
	else
		cout << "Invalid entry. Restart!\n\n";
	cout << "Now, how many months do you want to purchase? Reminder that purchasing 12 or more months gives you a 15% discount!";
	cin.clear();
	cin >> months;
	cout << "You entered: " << months << ".\n";
	cout << "How many personal training sessions would you like? Remember that purchasing 5 or more gives you a 20% discount on all sessions!";
	cin.clear();
	cin >> sessions;
	cout << "You entered: " << sessions << ".\n";
}

//runs some numbers, giving a total price for the monthlies as well as the sessions then adds the two together.
double calculateFee(double months, double sessions, int age, double& price1, double& price2, double& totalprice) 
{
	if (age < 65) 
	{
		if (months >= 12) 
		{
			months = months * MEMBERSHIP;
			price1 = months * YEARLYDISCOUNT;
			if (sessions >= 5) 
			{
				sessions = sessions * SESSION;
				price2 = sessions * SESSIONDISCOUNT;

			}
			else if (sessions < 5)
			{ 
				price2 = sessions * SESSION;
			}
			else 
			{
				cout << "Why don't you try all this again from the start?";
			}
		}
		else if (months < 12)
		{
			price1 = months * MEMBERSHIP;
			if (sessions >= 5)
			{
				sessions = sessions * SESSION;
				price2 = sessions * SESSIONDISCOUNT;

			}
			else if (sessions < 5)
			{
				price2 = sessions * SESSION;
			}
			else
			{
				cout << "Why don't you try all this again from the start?";
			}
		}
	}
	else if (age >= 65)
	{
		if (months >= 12)
		{
			months = months * SENIORPRICE;
			price1 = months * YEARLYDISCOUNT;
			if (sessions >= 5)
			{
				sessions = sessions * SESSION;
				price2 = sessions + SESSIONDISCOUNT;

			}
			else if (sessions < 5)
			{
				price2 = sessions * SESSION;
			}
			else
			{
				cout << "Why don't you try all this again from the start?";
			}
		}
		else if (months < 12)
		{
			price1 = months * SENIORPRICE;
			if (sessions >= 5)
			{
				sessions = sessions * SESSION;
				price2 = sessions * SESSIONDISCOUNT;

			}
			else if (sessions < 5)
			{
				price2 = sessions * SESSION;
			}
			//just in case something goes wrong
			else
			{
				cout << "Why don't you try all this again from the start?";
			}
		}
	}
	//just in case something goes wrong
	else
	{
		cout << "How'd we end up here?";
	}
	totalprice = price2 + price1;
	return totalprice;
}

