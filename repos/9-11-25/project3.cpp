#include <iostream>
#include <string>
using namespace std;

int main()
{
	char ch;
	int num;
	string name, city;
	cout << "give me your damn name, choom \n";
	getline(cin, name);
	//cin >> name; cringe. doesn't accept whitespace. 
	cout << "where do you come from, slime \n";
	getline(cin, city);
	//cin >> city; cringe. doesn't accept whitespace.

	cout << "hello " << name << ", i know youre from " << city << endl;
	//next bit

	cout << "give me all your money, bitch \n";
	cin >> num;
	//cin.get(num); retrieves the variable, is very stupid and WILL accept whitespace character in the keyboard buffer. not very smart at all
	cout << "give me your single alphanumeric character, pussy \n";
	cin >> ch;
	//cin.get(ch); retrieves the variable, is very stupid and WILL accept whitespace character in the keyboard buffer. not very smart at all
	cout << "You gave me $" << num << "? Poor ass. " << "And you only had '" << ch << "' as your singular alphanumeric character? Worthless.";

	/*not using this rn, but cin.ignore ignores characters from the user's keyboard buffer. 
	cin.ignore(3, \n) will ignore 3 characters OR newline character, whichever it sees first, then store the rest of the info in the variable.
	*/

	/*cin.clear() just clears the input buffer. would be useful to loop back around to start of a function probably
	*/



}