#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
// collecting input
	int num;
	cout << "Enter an integer number:";
	cin >> num;

	if (num % 2 == 0)
	{
		cout << "It's so fucking even, bruh." << endl;
		cout << "Here's the quotient, yo. 8===D " << num / 2;
	}
	else
	{
		cout << "It's unbelievably odd, bruh." << endl;
		cout << "This is the shit that's left, yo. 8===D " << num % 2;
	}
}