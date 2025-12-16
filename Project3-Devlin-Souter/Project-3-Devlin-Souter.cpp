#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
ifstream infile;
ofstream outfile;
void acctFinder(int, string, double);
void acctWriter(int, string, double, double, double, int, double, int);
int acctNum;
string acctName;
double acctBal;
struct PersonAcct 
{
	int acct_num = 0;
	string name;
	double acct_bal = 0;
};
PersonAcct acctCurrent;

int main()
{
	cout << "*****************************************\n";
	cout << "Thanks for using Bank Checker 9000!\n";
	cout << "Please enter an account number.";
	acctFinder(acctNum,acctName,acctBal);
}

void acctFinder(int acctNum, string acctName, double acctBal) 
{
	infile.open("accounts.txt");
	if (!infile)
		cout << "shit!";
	else
		cout << "hot";
			
}
