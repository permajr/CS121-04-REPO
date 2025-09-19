#include <iostream>

using namespace std;

int test()
{
	int val;
	double num;
	char ch;
	cout << "Enter an integger followed by decimal and a character: " << endl;
	cin >> val >> num >> ch;

	cout << "Int = " << val << endl;
	cout << "Decimal = " << num << endl;
	cout << "character = " << ch << endl;

	//Restore stream
	cin.clear();//clears input stream
	cin.ignore(500, '\n');//skips over first 500 characters OR \n

	//ask user to re-enter inputs
	cout << "Enter an integer followed by decimal and a character: " << endl;
	cin >> val >> num >> ch;

	cout << "Int = " << val << endl;
	cout << "Decimal = " << num << endl;
	cout << "character = " << ch << endl;

	return 0;
}