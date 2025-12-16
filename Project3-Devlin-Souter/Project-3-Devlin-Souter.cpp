/******************************************************************
PROGRAMMER: RANDY  DEVLIN-SOUTER
CLASS: CS-121-04
PROFESSOR: DUTTA
PROBLEM STATEMENT: THIS PROGRAM ASSESSES THE MONTHLY DEPOSTS, WITHDRAWALS, BEGINNING, AND ENDING 
BALANCES OF A USER'S BANK ACCOUNT BASED ON AN INCLUDED DATABASE0
********************************************************************/
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct PersonAcct
{
	int acct_num = 0;
	string name;
	double acct_bal = 0;
};
PersonAcct acctCurrent;
ifstream infile;
ofstream outfile;
int acctGetter(int&);
bool acctFinder (int&, string&, bool&);
void acctWriter(PersonAcct&, double, double, int, double, int);
string monthGrabber(string&);
int acctNum;
string acctName, outname;
double endBal, depAmount,  witAmount;
int depQuantity, witQuantity;
bool looper(bool&);
bool loop = false;
bool check = false;
bool found = false;

int main()
{
	while(!loop)
	{
		cout << "*****************************************\n";
		cout << "Thanks for using Bank Checker 9000!\n";
		cout << "Please enter an account number.\n";
		cout << "*****************************************\n";
		acctGetter(acctNum);
		acctFinder(acctNum, acctName, loop);
		cout << "*****************************************\n";
		cout << "Thanks for that!\n";
		cout << "Here's all your info.\n";
		cout << "*****************************************\n";
		acctWriter(acctCurrent, endBal, depAmount, depQuantity, witAmount, witQuantity);
		infile.close();
		looper(loop);
	}
}


int acctGetter(int& acctNum) 
{
	cin.clear();
	cin >> acctNum;
	cin.clear();
	return acctNum;
}

bool acctFinder(int& acctNum, string& acctName, bool& loop) 
{
	infile.open("accounts.txt");
	if (!infile)
		cout << "File failed to open!";
	else
	{
		bool found = false;
			while (infile >> acctCurrent.acct_num)
			{
				infile >> acctCurrent.name;
				infile >> acctCurrent.acct_bal;
				if (acctCurrent.acct_num == acctNum)
				{
					found = true;
					break;
				}
				else
				{
					found = false;
				}
			}
			if (!found)
			{
				cout << "*****************************************\n";
				cout << "The account number: " << acctNum << " was not found.\n";
				cout << "*****************************************\n";
			}
	}
	infile.close();
	return loop;
}

void acctWriter(PersonAcct& acctCurrent, double endBal, double depAmount, int depQuantity, double witAmount, int witQuantity)
{
	//loading temps when temps are needed
	int tempvar = 0;
	double tempdbl = 0.00;
	char depwith;
		infile.open("transactions.txt");
		if (!infile)
			cout << "File failed to open!";
		else
		{
			cout << acctCurrent.acct_bal << endl << acctCurrent.acct_num << endl << acctCurrent.name << endl;
			//finding our line, skipping if the account number doesnt match the start of a line
			bool line = false;
			int justcheckin = 0;
			while (!line)
			{
				while (infile >> tempvar)
				{
					if (tempvar != acctNum)
					{
						infile.ignore(1000, '\n');
					}
					else if (tempvar == acctNum)
					{
						//are we a deposit or withdrawal?
						while (infile >> depwith)
						{
							infile >> tempdbl;
							//adder/subtractor step
							if (depwith == 'd')
							{
								endBal = tempdbl + endBal;
								if (justcheckin == 0)
									endBal = endBal + acctCurrent.acct_bal;
								depAmount = tempdbl + depAmount;
								depQuantity++;
							}
							else if (depwith == 'w')
							{
								if (justcheckin == 0)
									endBal = acctCurrent.acct_bal - tempdbl;
								else
									endBal = endBal - tempdbl;
								witAmount = tempdbl + witAmount;
								witQuantity++;
							}
							//if the deposit/withdrawal checker encounters anything other than a 'd' or 'w', break the loop
							else
							{
								line = true;
								break;
							}
						}
					}
				}
				justcheckin++;
				cout << "Your account number is: " << acctCurrent.acct_num << endl << "Your account name is: ";
				cout << acctCurrent.name << endl << "Your starting balance was: " << acctCurrent.acct_bal << endl;
				cout << "The total amount deposited was: " << depAmount << endl << "The total number of deposits was: " << depQuantity << endl;
				cout << "The total amount withdrawn was: " << witAmount << endl << "The total number of withdrawals was: " << witQuantity << endl;
				cout << "Your final balance for the month was: " << endBal << endl;
				if (justcheckin >= 5)
					line = true;
			}
		}
		monthGrabber(outname);
		outfile.open(outname);
		outfile << "Your account number is: " << acctCurrent.acct_num << endl << "Your account name is: ";
		outfile << acctCurrent.name << endl << "Your starting balance was: " << acctCurrent.acct_bal << endl;
		outfile << "The total amount deposited was: " << depAmount << endl << "The total number of deposits was: " << depQuantity << endl;
		outfile << "The total amount withdrawn was: " << witAmount << endl << "The total number of withdrawals was: " << witQuantity << endl;
		outfile << "Your final balance for the month was: " << endBal << endl;
		outfile.close();
	
}

//just asks to loop the main function 
bool looper(bool& loop)
{
	string yesno;
	cout << "\n*****************************************************************************\n";
	cout << "Would you like to run another report? Y/N\n";
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

string monthGrabber(string& outname)
{
	cout << "*****************************************************************************\n";
	cout << "Please enter the name of this report in the format '(month)_report.txt' where month is the month the transactions ocurred: ";
	cin.clear();
	cin >> outname;
	cin.clear();
	return outname;
}