#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	bool repeat = false;
	int switcher;
	cout << "Feed me an integer:\n";
	cin >> switcher;
	cin.ignore();

	while (!repeat)
	{
		switch (switcher)
		{
		case 1:
			cout << "First result.";
			repeat = true;
			break;
		case 2:
			cout << "Second result.";
			repeat = true;
			break;
		case 3:
			cout << "Third result.";
			repeat = true;
			break;



		}
	}

	/*	bool repeat = false;
		string ans;
			if ('A' > 'a')
			cout << "False";//compares the ASCII value of each individual character against one another
	if ("Anna" > "Alice")
		cout << "anything";//compares the ASCII values of each individual character in the string against one another
							// this could be used to compare and organize things alphabetically, but the user input might have to be cleaned beforehand or smth similar.
							//short circuit coding basically means if a condition with an || or && operator checks an operand, whatever condition it's looking to satisfy doesn't waste time checking on the rest of the possible conditions
		cout << "wrong or rigt?\n";
		while (!cond)
		{
			getline(cin, ans);
			if (ans == "correct" || ans == "right")
			{
				cout << "conditionally correct";
				break;
			}
			else
			{
				cout << "kys\n";
			}
		}
	*/

}