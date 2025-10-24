
/****************************************************************************************
** File name: CS121-Proj1.cpp
** Course Name: CS121-04
** Instructor Name: Dutta
** Project#: 1
** This program asks the user for a pattern type and size then generates a pattern based
* off of that input
** Programmer: Randy Devlin-Souter
** Date created: 10-23-25
****************************************************************************************/



#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	//first variables for use later
	int patquit = 0;
	int patsize = 0;
	/*this boolean sets up the while loop which is the main body of the program.could be allowed but i
	dont remember if we did this already or not.*/
	bool quit = false;
	while (!quit)
	{
		//introduces and displays the menu, plus some formatting to make it all look *pretty*
		cout << "**********************************************************************************************************\n";
		cout << "Hi! Welcome to Pat's Pattern Depot. Please enter the number that corresponds with your favorite pattern!\n";
		cout << "**********************************************************************************************************\n";
		cout << "1. Pattern One.\n";
		cout << "2. Pattern Two.\n";
		cout << "3. Pattern Three.\n";
		cout << "4. Pattern Four.\n";
		cout << "5. Choose again.\n";
		cout << "6. Quit\n";
		cin >> patquit;
		cin.clear();

		//if the answer is any of the first four options, move to the pattern phase
		if (patquit == 1 || patquit == 2 || patquit == 3 || patquit == 4)
		{
			cout << "You chose pattern number " << patquit << endl;
			cout << "Please choose a size!";
			cin >> patsize;
			cin.clear();
			//i evaluate the pattern size before doing the actual patterns because no matter what, they all execute with the same size.
			//it's gotta be two or higher and 9 or lower.
			if (patsize >= 2 && patsize <= 9)
			{
				cout << "You chose a pattern size of " << patsize << "! Working some magic...\n\n\n";//just some flavor to make it less dry.
				//the first pattern basically prints the same as the third pattern, a half pyramid, but with a border in the middle of the patsize character.
				if (patquit == 1)
				{
					//lays out how many rows there will be and then the endl; makes the new row.
					for (int rows = patsize; rows >= 1; --rows)
					{
						//builds the first half of the pyramid.
						for (int frontcol = 0; frontcol < patsize - rows; ++frontcol) {
							cout << "$";
						}
						//draws the middle border.
						cout << patsize;
						//builds the back half of the pyramid.
						for (int backcol = rows; backcol <= 2 * rows - 1; ++backcol)
						{
							cout << "$";
						}
						cout << endl;
					}
					//just some flavor.
					cout << "\nWhaddaya think? Made it myself. I'm Pat by the way!\n\n";
					cin.clear();
				}
				//the same as pattern one but in reverse. used different variable names bc when writing i though the variables having different names messed it all up.
				else if (patquit == 2)
				{
					for (int rows = patsize; rows >= 1; --rows)
					{
						for (int a = 1; a <= rows; ++a)
						{
							cout << "$";
						}
						cout << patsize;
						for (int b = patsize; b >= rows + 1; --b)
						{
							cout << "$";
						}
						cout << endl;
					}
					cout << "\nWhaddaya think? Made it myself. I'm Pat by the way!\n\n";
					cin.clear();
				}
				//the same as pattern 1 but without the middle border.
				else if (patquit == 3)
				{
					for (int rows = patsize; rows >= 1; --rows)
					{
						for (int frontcol = 1; frontcol <= rows; ++frontcol)
						{
							cout << "$";
						}
						for (int backcol = patsize; backcol >= rows + 1; --backcol)
						{
							cout << patsize;
						}
						cout << endl;
					}
					cout << "\nWhaddaya think? Made it myself. I'm Pat by the way!\n\n";
					cin.clear();
				}
				//pattern 3 in reverse. slightly different math here because i was looking at a bunch of different examples.
				else if (patquit == 4)
				{
					for (int rows = patsize; rows >= 1; --rows)
					{
						for (int frontcol = 0; frontcol < patsize - rows; ++frontcol) 
						{
							cout << patsize;
						}
						for (int backcol = rows; backcol <= 2 * rows - 1; ++backcol)
						{
							cout << "$";
						}

						cout << endl;
					}
					cout << "\nWhaddaya think? Made it myself. I'm Pat by the way!\n\n";
					cin.clear();
				}
			}
			//only triggers when an input is the wrong size.
			else
			{
				cout << "\nInvalid input entered. Why don't we go back to the start?\n";
				cin.clear();
				bool quit = false;
			}
			cin.clear();
		}	
		//resets the loop
		else if (patquit == 5)
			bool quit = false;
		//quits the program.
		else if (patquit == 6)
			return 0;
		//only triggered if the user enters in an option that isnt any of those.
		else
		{
			cout << "\nInvalid input. Let's give that another shot!\n";
			bool quit = false;
		}
	}
}
