#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

int main()
{
	char ans1 = '1';
	bool ans = false;
	int rows = 9;
	char yesno;

	cout << "This is the Sphinx's Gambit. Press enter to continue." << endl;
	cin.ignore();

	cout << "Once there was a majestic pyramid, tall enough to reach the heavens." << endl;
	cin.ignore();

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
	cin.ignore();
	cout << "Unfortunately, the Sphinx Who Always Lies had some concerning results\non a CT scan during his last visit." << endl;
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

	cout << "As a result of his health complications, frustration from a lack of sympathy from the Sphinx Who Always Tells the Truth,\nand the growing distrust in their marriage as one Sphinx always tells lies,\nthe Pyramid they both resided in blew up. Exploded. Boomo." << endl;
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
	cin.ignore();
	cout << "As the local courier, the Sphinx Doctor has hired you to deliver the\nlatest news about the Sphix Who Always Lies's health." << endl;
	cin.ignore();
	cout << "You must remember three things:\n";
	cin.ignore();
	cout << "     1. The Sphinx Who Always Lies does not have cancer. It was a cotton ball\n";
	cout << "     2. The Sphinx Who Always Lies literally Always Lies.\n";
	cout << "     3. The Sphinx WHo Always Tells The Truth lacks empathy, because the truth can hurt.\n";
	cin.ignore();
	cout << "Will you proceed into the unknown, Or cower in fear of discovering\nwhat might lie within the pyramid's ruins? Perhaps you're afraid of discovering\nwhat lies within yourself, Y/N?" << endl;
	cin >> yesno;

		while (!ans)
		{
			if ((yesno == 'Y') || (yesno == 'y'))
			{
				{

					cout << "One of us tells the truth, the other always lies." << endl;
					cout << "The correct answer is 1" << endl;
					cout << "The correct answer is anything other than 1." << endl;
					cout << "1 - 1 + 1 = " << endl;
					cin >> ans1;
					cin.clear();
					//ans = false;

					if (ans1 == '1')
					{
						string riddle;
						cout << "Congrats, you acheived the first step." << endl;
						cin.ignore();
						cout << "Step 2 is coming soon." << endl;
						cin.ignore();
						cout << "Here is the riddle of the Sphinx." << endl;
						cin.ignore();
						cout << "The guy who always lies had a doctor's appointment. \nThey think it might be colon cancer. \nHe had to head out early so it'll just be me for now." << endl;
						cin.ignore();
						cout << "What has four legs in the morning, two legs during the day, and three legs in the evening?" << endl;
						cin.clear();
						cin >> riddle;

						if ((riddle == "man") || (riddle == "humans"))

						{
							cin.clear();
							cout << "Clever one, you are. I assume you have a message to deliver? Y/N" << endl;
							cin >> yesno;
							cin.clear();
							ans = false;

							if (yesno == 'Y' || yesno == 'y')
							{
								cin.ignore();
								string diag;
								string reason;
								string emp;
								cout << "Enter the message you were given by the doctor:\n";
								getline(cin, diag);
								cout << "You say " << diag << " ?\n";
								cout << "This is troubling news. I doubt he even went to Sphinx Hospital today. He's untrustworthy.\n";
								cin.ignore();
								cout << "Why would the Sphinx Who Always Lies tell an iconic Lie?\n";
								getline(cin, reason);
								cout << "Of course he always lies, that's why I chose him. We love each other unconditionally.\nFrom the day we were constructed he could never tell me he hated me, because that would have been a lie.\n";
								cin.ignore();
								cout << "I just can't understand why he was afraid. The truth is that we're sphinxes, and cancer doesn't really affect us.\nWe're rock guys.\n";
								cin.ignore();
								cout << "I think he's cheating on me. Lying about where he is, making up false daignoses, he LITERALLY always tells lies.\n";
								cin.ignore();
								cout << "I think I might want to leave him if this goes on for much longer. I know he can't control his lying, but he doesn't have to be an asshole about it.\n";
								cin.ignore();
								cout << "Am I being too hard on him?\n";
								getline(cin, emp);
								cout << "You're right.\n";
								cin.ignore();
								cout << "I guess I should call him.\n";
								cin.ignore();
								cout << "THE MAGIC OF LOVE HAS RESTORED THE PYRAMID!\n                #";
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
							}
							else
							{	
								string ouch;
								cin.clear();
								cout << "Very Well. I will eat you now. Type 'ouch' to get eaten! \n";
								cin >> ouch;

								if(ouch == "ouch")
								{
									return 0;
								}
							}
							cout << "Thanks for playing!" << endl;
							cout << "Press enter to exit." << endl;
							cin.ignore();
							return 0;
							ans = false;

						}
						else
						{
							cout << "You made it this far and couldn't figure it out? Bro...." << endl;
							cin.ignore();
							ans = false;
						}
					}
					else
					{
						cout << "Wrong. Do it again." << endl;
						cin.clear();
						ans = false;
					}
				}
				ans = false;
			}
			else
			{
				string exit;
				cout << "Surely some other courier will deliver the news." << endl;
				cout << "Type goodbye to exit.";
				cin >> exit;
				if (exit == "goodbye")
				{
					ans = false;
					return 0;
				}
			}
			//ans = false;
		}
		0;
}