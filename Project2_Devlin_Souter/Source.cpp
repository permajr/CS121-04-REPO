#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
//declare one million variables
const double REGULAR_RATE = 0.20;
const double PREMIUM_RATE1 = 0.10;
const double PREMIUM_RATE2 = 0.05;
const double REG_THRESH = 50.00;
const double PREEM_THRESH_DAY = 75.00;
const double PREEM_THRESH_NIGHT = 100.00;
void getInput(char);
double regularBill(double, double, double&);
double premiumBill(double, double, double&);
void display(double&, string);
void exitLoop();
double minutes = 0.0; 
double regflat = 10.0;
double preemflat = 25.0;
double totalbill;
double tb_day;
double tb_night;
char servtype;
string service;
bool loop = false;
bool loop2 = false;
char yesno;

int main()
{
	while (!loop)
	{
		//setting decimal point
		cout << showpoint << fixed << setprecision(2);
		cout << "Welcome to your local cellular provider. Please enter your service code.\n";
		//this function figures out what type of service the user has, then calls the matching funtion inside the loop
		getInput(servtype);
		if (service == "regular")
		{
			//calculates the price of the stanrdard plan
			regularBill(minutes, regflat, totalbill);
		}
		else if (service == "premium")
		{
			//calculates the price of the premium plan
			premiumBill(minutes, preemflat, totalbill);
		}
		//this function displays the final result of all the info the user entered.
		display(totalbill, service);

		exitLoop();
		cin.ignore();

	}

}

//using a while loop in the case of any erroes, we determine the service code and display a matching name for each plan.
void getInput(char servtype)
{	
	while (!loop) 
	{
		cin.clear();
		cin >> servtype;
		cin.clear();
		if (servtype == 'r' || servtype == 'R')
		{
			service = "regular";
			loop = true;
		}
		else if (servtype == 'p' || servtype == 'P')
		{
			service = "premium";
			loop = true;
		}
		else
		{
			cout << "Entry incorrect. Please enter your service code.\n";
			cin.clear();
			loop = false;
		}
	}

}


//using the regular minute threshold, the flat rate, and the number of minutes the user entered we calculate the price of the standard bill. while loop functions for error validation.
double regularBill(double minutes, double regflat, double& totalbill)
{
	loop = false;
	while (!loop) 
	{
		cout << "Please enter how many minutes you used.\n";
		cin.clear();
		cin >> minutes;
		cin.clear();
		if (minutes <= REG_THRESH)
		{
			totalbill = regflat;
			loop = true;
		}
		else if (minutes > REG_THRESH)
		{
			totalbill = ((minutes - REG_THRESH) * REGULAR_RATE) + regflat;
			loop = true;
		}
		else
		{
			cout << "Let's give that another shot!\n";
			loop = false;
		}
	}
	return totalbill;
}


//using the premium minute threshold, the flat rate, and the number of minutes the user entered we calculate the price of the premium bill. while loop functions for error validation.
double premiumBill(double minutes, double preemflat, double& totalbill)
{
	loop = false;
	while (!loop) {
		cout << "Please enter how many minutes you used from 6AM to 6PM.\n";
		cin.clear();
		cin >> minutes;
		cin.clear();
		if (minutes <= PREEM_THRESH_DAY)
		{
			tb_day = preemflat;
			loop = true;
		}
		else if (minutes > PREEM_THRESH_DAY)
		{
			tb_day = ((minutes - PREEM_THRESH_DAY) * PREMIUM_RATE1) + preemflat;
			loop = true;
		}
		else
		{
			cout << "Why don't we try that again?\n";
			loop = false;
		}
		cout << "Now, please enter how many minutes you used from 6PM to 6AM.\n";
		cin.clear();
		cin >> minutes;
		cin.clear();
		if (minutes <= PREEM_THRESH_NIGHT)
		{
			tb_night = 0;
			loop = true;
		}
		else if (minutes > PREEM_THRESH_NIGHT)
		{
			tb_night = (minutes - PREEM_THRESH_NIGHT) * PREMIUM_RATE2;
			loop = true;
		}
	}
	totalbill = tb_day + tb_night;
	return totalbill;
}

//displays info gathered from functions above.
void display(double& totalbill, string service) 
{
	cout << "You're paying for the " << service << " plan." << endl;
	cout << "Your total bill is: " << totalbill<< endl;
}

void exitLoop()
{
	loop2 = false;
	while (!loop2)
	{
		cout << "---------------------------------------\n";
		cout << "Do you want to run another user's bill?";
		cin.clear();
		cin >> yesno;
		cin.clear();
		if (yesno == 'y' || yesno == 'Y')
		{
			loop2 = true;
			loop = false;
		}
		else if (yesno == 'n' || yesno == 'N')
		{
			cout << "Thank you for using the Phone Company! Press enter to exit.";
			cin.ignore();
			loop2 = true;
			loop = true;
		}

		else
		{
			cout << "Incorrect entry! Let's try that again.";
			loop2 = false;
			loop = false;
		}
	}
}