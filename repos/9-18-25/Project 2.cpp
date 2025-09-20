#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int num = 1;
	string riddle;
	bool ans = false;
	int rows = 9;
	char yesno;

	cout << "This is the Sphinx's Gambit. Press enter to continue." << endl;
	cin.ignore();

	cout << "Once there was a majestic pyramid, tall enough to reach the heavens." << endl;

	cout << "                #";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 2 * (rows - i) - 1; j++) {
			printf(" ");
		}
		for (int k = 0; k < 1 * i + i; k++) {
			printf("# ");
		}
		printf("\n");
	}

	cout << "But one day, a Sphinx couple moved in.\nThey were a couple of tricksters. They liked to play tricks on unsuspecting adventurers." << endl;
	cout << "Unfortunately, the Sphinx Who Always Lies had some concerning results\na CT scan during his last visit." << endl;
	cout << "Press enter to continue." << endl;
	cin.ignore();


	rows = 6;

	cout << "    #";
	for (int i = 0; i < rows; i++)//if i is less than total number of rows, increment
	{
		for (int j = 0; j < 1 * (rows - i) - 1; j++)
		{
			printf(" ");//the code runs when j is less than 2. subtract the value of i from the number of rows, then print that many spaces. increment
		}
		for (int k = 0; k < 2 * i + i; k++)
		{
			printf("# ");//the code runs every time k is less than 1. add i to itself, then print that many pound symbols. increment.
			cout << "  ";
		}
		printf("\n");
	}


	cout << "As a result of his health complications,  frustration over insurance,\nand the growing distrust in their marriage as one Sphinx always tells lies,\nthe Pyramid they both resided in blew up. Exploded. Boomo." << endl;
	cout << "Press enter to continue." << endl;
	cin.ignore();

	rows = 3;

	for (int i = 0; i < rows; i++)//if i is less than total number of rows, increment
	{
		cout << "# # # # # # # # # # # # #";
		for (int k = 0; k < 1 * i; k++) {
			printf(" #");
		}
		cout << "\n";
	}

	rows = 9;
	int columns = 1;
	for (int i = 0; i < rows; i++)
	{
		cout << "# # # #           # # # # # # #";
		for (int k = 0; k < 1 * i; k++)
		{
			cout << " #";
		}
		cout << "\n";

	}

	cout << "You stand at the precipice of darkness. Your goal is to deliver a missive." << endl;
	cout << "As the local courier, the Sphinx Doctor has hired you to deliver the\nlatest news about the Sphix Who Always Lies's health." << endl;
	cout << "\n";
	cout << "Will you proceed into the unknown? Or cower in fear of discovering\nwhat might lie within the pyramid's ruins. Perhaps you're afraid of discovering\nwhat lies within yourself, Y/N?" << endl;
	cin >> yesno;
	cin.clear();

	while (!ans)
	{
		if (yesno == 'Y')
		{
			{

				cout << "One of us tells the truth, the other always lies." << endl;
				cout << "The correct answer is 1" << endl;
				cout << "The correct answer is anything other than 1." << endl;
				cout << "1 - 1 + 1 = " << endl;
				cin >> num;

				if (num == 1)
				{
					cin.ignore(2, '\n');
					cout << "Congrats, you acheived the first step." << endl;
					cout << "Step 2 is coming soon." << endl;
					cout << "Here is the riddle of the Sphinx." << endl;
					cout << "The guy who always lies has a doctor's appointment. \nThey think it might be colon cancer. \nHe has to head out early so it'll just be me for now." << endl;
					cout << "What has four legs in the morning, two legs during the day, and three legs in the evening?" << endl;
					cin >> riddle;
					cin.ignore(100000, '\n');
					if (riddle == "Man")
					{
						cout << "Great job, bro." << endl;
						int rows = 9;
						cout << "                #";
						for (int i = 0; i < rows; i++)
						{
							for (int j = 0; j < 2 * (rows - i) - 1; j++) {
								printf(" ");
							}
							for (int k = 0; k < 1 * i + i; k++) {
								printf("# ");
							}
							printf("\n");
						}
						cout << "\nYou blew up the Sphinx, and its magic restored the pyramid." << endl;
						cout << "Thanks for playing!" << endl;
						cout << "Press enter to exit." << endl;
						cin.ignore();
						return 0;

					}
					else
						cout << "You made it this far and couldn't figure it out? Bro...." << endl;
				}

				else
					cout << "Wrong. Do it again." << endl;

				return 0;
			}
		}
		else
		{
			string exit;
			cout << "Surely some other courier will deliver the news." << endl;
			cout << "Type 'goodbye' to exit." << endl;
			cin >> exit;
			if (exit == "goodbye")
			{
				return 0;
			}
			return 0;
		}
		return 0;
	}
	return 0;
}