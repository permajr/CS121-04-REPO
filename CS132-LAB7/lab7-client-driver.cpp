#include "list.h"
#include "stack.h"
#include "queue.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

void prompt();
bool isPalindrome(string word);

int main() 
{
	prompt();
	return 0;
}

bool isPalindrome(string word)
{
	Stack<char> s;
	Queue<char> q;

	// remove spaces and convert each character
	string processed = "";
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] != ' ' && word[i] != '\t')
		{
			processed += tolower(word[i]);
		}
	}

	// if empty string after processing, it's technically a palindrome
	if (processed.length() == 0)
		return true;

	// Load both structures with processed characters
	for (int j = 0; j < processed.length(); j++)
	{
		s.push(processed[j]);
		q.enQ(processed[j]);
	}

	// check if stack top equals queue front
	// continue until one structure is empty
	while (!s.emptyS() && !q.emptyQ())
	{
		char* top = s.top();
		char* front = q.front();

		// if mismatch found, not palindrome
		if (*top != *front)
		{
			delete top;
			delete front;
			return false;
		}

		// clean up pointers
		delete top;
		delete front;

		// remove from both ends
		s.pop();
		q.deQ();
	}

	// if we made it here, palindrome
	return true;
}

void prompt()
{
	int ans = 0;
	bool check = false;
	string temp;

	// test cases from spec plus a couple extras
	string testList[] = {
		"live not on evil",
		"dad",
		"able was I ere I saw elba",
		"racecar",
		"madam",
		"A man a plan a canal Panama",
		"noon",
		"kayak",
		"hello",
		"world"
	};
	int listSize = 10;

	while (!check)
	{
		cout << "Welcome To Paul's Palindrome Parsing Palace and Purveyors of Premium Palindrical Passages\n";
		cout << "-------------------------------------------------------------------------------------------\n";
		cout << "Perhaps perchance you'd pass your peepers over possible paths?\n";
		cout << "1. Provide a palindrome for perusal?\n";
		cout << "2. Peruse potential palindromes?\n";
		cout << "3. Exit, passing plainly into palindrome paradise\n";
		cout << "-------------------------------------------------------------------------------------------\n";
		cin.clear();
		cin >> ans;
		cin.ignore();

		if (ans == 1)
		{
			cout << "Sorry about the alliteration! Let's go to Palindrome Town now!\n";
			cout << "Enter a possible palindrome here:\n";
			getline(cin, temp);

			if (temp.length() > 0)
			{
				cout << "\nAnalyzing: \"" << temp << "\"\n";
				cout << "Processing through Stack and Queue...\n";

				bool result = isPalindrome(temp);

				if (result)
				{
					cout << "Conclusion: This IS a palindrome! Phenomenal!\n";
				}
				else
				{
					cout << "Conclusion: This is NOT a palindrome. Perhaps practice more?\n";
				}
				cout << endl;
			}
		}
		else if (ans == 2)
		{
			cout << "Perusing potential palindromes for your pleasure:\n";
			cout << "-------------------------------------------------------------------------------------------\n";

			for (int i = 0; i < listSize; i++)
			{
				cout << (i + 1) << ". \"" << testList[i] << "\" -> ";

				bool isPalin = isPalindrome(testList[i]);

				if (isPalin)
				{
					cout << "PALINDROME\n";
				}
				else
				{
					cout << "NOT A PALINDROME\n";
				}
			}
			cout << "-------------------------------------------------------------------------------------------\n";
		}
		else if (ans == 3)
		{
			cout << "Parting pleasantly! Palindrome paradise awaits!\n";
			check = true;
		}
		else
		{
			cout << "Please pick a proper option (1, 2, or 3).\n";
		}
	}
}
/*
Welcome To Paul's Palindrome Parsing Palace and Purveyors of Premium Palindrical Passages
-------------------------------------------------------------------------------------------
Perhaps perchance you'd pass your peepers over possible paths?
1. Provide a palindrome for perusal?
2. Peruse potential palindromes?
3. Exit, passing plainly into palindrome paradise
-------------------------------------------------------------------------------------------
1
Presently Passing Through Palindrome Place!
Enter a possible palindrome here:
peep a peep

Testing: "peep a peep"
Result: IS a palindrome! Phenomenal!

Welcome To Paul's Palindrome Parsing Palace and Purveyors of Premium Palindrical Passages
-------------------------------------------------------------------------------------------
Perhaps perchance you'd pass your peepers over possible paths?
1. Provide a palindrome for perusal?
2. Peruse potential palindromes?
3. Exit, passing plainly into palindrome paradise
-------------------------------------------------------------------------------------------
2
Perusing potential palindromes for your pleasure:
-------------------------------------------------------------------------------------------
1. "live not on evil" - IS a palindrome!
2. "dad" - IS a palindrome!
3. "able was I ere I saw elba" - IS a palindrome!
4. "racecar" - IS a palindrome!
5. "madam" - IS a palindrome!
6. "A man a plan a canal Panama" - IS a palindrome!
7. "noon" - IS a palindrome!
8. "kayak" - IS a palindrome!
-------------------------------------------------------------------------------------------

Welcome To Paul's Palindrome Parsing Palace and Purveyors of Premium Palindrical Passages
-------------------------------------------------------------------------------------------
Perhaps perchance you'd pass your peepers over possible paths?
1. Provide a palindrome for perusal?
2. Peruse potential palindromes?
3. Exit, passing plainly into palindrome paradise
-------------------------------------------------------------------------------------------
1
Presently Passing Through Palindrome Place!
Enter a possible palindrome here:
place a person

Testing: "place a person"
Result: NOT a palindrome. Perhaps practice more?

Welcome To Paul's Palindrome Parsing Palace and Purveyors of Premium Palindrical Passages
-------------------------------------------------------------------------------------------
Perhaps perchance you'd pass your peepers over possible paths?
1. Provide a palindrome for perusal?
2. Peruse potential palindromes?
3. Exit, passing plainly into palindrome paradise
-------------------------------------------------------------------------------------------
3
Parting pleasantly! Palindrome paradise awaits!

C:\Users\randy\Documents\GitHub\CS121-04-REPO\CS132-LAB7\x64\Debug\CS132-LAB7.exe (process 31972) exited with code 0 (0x0).
Press any key to close this window . . .

*/