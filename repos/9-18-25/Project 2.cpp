#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int num = 1;
	string riddle;
	bool ans = false;
	char usrin;

	cout << "This is the Sphinx's Gambit. Press enter to continue." << endl;
	cin.ignore();
	
	{
		while (!ans) {
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
				if (riddle == "Man", "Person",  "Human")
				{
					cout << "Great job, bro." << endl;
					cout << setfill('#');
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
		}
		return 0;
	}
}
