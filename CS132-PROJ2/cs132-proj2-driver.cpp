#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include "solver.h"

using namespace std;
ifstream inFile;
string choice;
string filename;
int xpos, ypos = 0;
int a = 0, b = 0;
maze fullMaze(xpos, ypos);
maze startingPos(xpos, ypos);

void displayMaze();
void drawSolution(const maze&);
void readMaze(string);
string userPrompt(string&, string&);
int getStart(int&, int&);



int main() 
{
	cout << "------------------------------------------------------------------------------------------------------\n";
	cout << "MOST MAY MARKEDLY EMBRACE MARMADUKE'S MAGNIFICENT MAZE MANIPULATION, MASTERY, MARKING, AND AMUSEMENTS.\n";
	cout << "------------------------------------------------------------------------------------------------------\n";
	userPrompt(choice, filename);
	readMaze(filename);
}

void readMaze(string fileanme)
{
	if (inFile)
	{
		for (int y = 0; y < 12; y++)
		{
			for (int x = 0; x < 12; x++)
			{
				if (y == 0 || y == 11)
				{
					fullMaze.coordinates[x][y] = '#';
					fullMaze.visitedCells[x][y] = false;
				}
				else if (x == 0 || x == 11)
				{
					fullMaze.coordinates[x][y] = '#';
					fullMaze.visitedCells[x][y] = false;
				}
				else
				{
					fullMaze.coordinates[x][y] = inFile.get();
				}
			}
		}
	}
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 12; x++)
		{
			startingPos.coordinates[x][y] = fullMaze.coordinates[x][y];
			startingPos.visitedCells[x][y] = fullMaze.visitedCells[x][y];
		}
	}
	userPrompt(choice, filename);
}

string userPrompt(string &choice, string &filename)
{
	if (inFile)
		inFile.close();
	cout << "MASH EMTER MY MASTER, MUST MOVE ONWARD!\n";
	cin.ignore(10000, '\n');
	bool loop = false;
	cout << "MAYHAPS MUTTER A MENACING MATHETMATIC MONIKER?\n";
	while (!loop) 
	{
		cout << "----------------------------------------------------------\n"
			<< "MUMBER 1 - MENTION A MAZE'S MANOR\n"
			<< "MUMBER 2 - MAKE A MAZE MANIFEST ON YOUR MONITOR\n"
			<< "MUMBER 3 - ADMINISTER MAZE MASTERING ALGORITHMIC MAJESTY.\n"
			<< "MUMBER 4 - MIGRATE\n"
			<< "----------------------------------------------------------\n";
		getline(cin, choice);
		if (choice == "1")
		{
			cout << "MANY THANKS MY MASTER. MENTION THE MAZE'S FILE PATH\n";
			getline(cin, filename);
			inFile.open(filename);
			if (inFile)
			{
				cout << "MASTERFULLY MANIPULATED, MASTER\n";
				return(filename);
				loop = false;
			}
			else if (!inFile) 
			{
				cout << "MOST MISTAKES MAY MAKE MORE MERRIMENT. AGAIN\n";
				loop = false;
				userPrompt(choice, filename);
			}
			return(filename);
			loop = false;
		}
		else if (choice == "2")
		{
			cout << "MANY THANKS MY MASTER. MAY YOUR MONITOR MARKEDLY MATERIALIZE ON YOUR MONITOR NOW.\n";
			displayMaze();
			loop = true;
		}
		else if (choice == "3")
		{
			cout << "MANY THANKS MY MASTER. MAKE KNOWN MY MASTER'S MOST CAREFUL X & Y STARTING POSITION:\n";
			getStart(xpos, ypos);
			if (solveMaze(startingPos, xpos, ypos)) 
			{
				drawSolution(startingPos);
				loop = false;
			}
			else
			{
				//drawSolution(startingPos);
				cout << "\n";
				cout << "   ================================================\n";
				cout << "   ||            HELP. I REMAIN CAGED.            ||\n";
				cout << "   ================================================\n";
				cout << "\n";
				userPrompt(choice, filename);
			}
		}
		else if (choice == "4")
		{
			cout << "MARCH MORE MASTER. MAY YOUR MYRIAD MAPS & MAZES FILL MORE HURRIEDLY\n";
			loop = true;
			exit(0);
		}
		else
		{
			cout << "MOST MISTAKES MAY MAKE MORE MERRIMENT. AGAIN\n";
			userPrompt(choice, filename);
			return(filename);
		}
		return(filename);
	}
	return(filename);
}

void displayMaze()
{
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 12; x++)
			cout << fullMaze.coordinates[x][y] << " ";
		cout << endl;
	}
	userPrompt(choice, filename);
}

int getStart(int& xpos, int& ypos)
{
	cout << "X POSITION: ";
	cin >> xpos;
	cin.ignore(10000, '\n');
	cout << endl << "Y POSITION: ";
	cin >> ypos;
	cin.ignore(10000, '\n');
	startingPos.coordinates[xpos][ypos] = fullMaze.coordinates[xpos][ypos];
	//doesn't like symbols or letters no sir
	//dont overflow max 32 bit int
	if (startingPos.coordinates[xpos][ypos] == '#' || startingPos.coordinates[xpos][ypos] == '1')
	{
		cout << "try again, slime" << endl << startingPos.coordinates[xpos][ypos] << endl;
		getStart(xpos, ypos);
	}
	else
	{
		cout << "good coords" <<endl;
	}
	return(xpos, ypos);
}

void drawSolution(const maze& m) {

	// Print the maze in the original grid format
	for (int y = 0; y < 12; y++) {
		cout << "   ";
		for (int x = 0; x < 12; x++) {
			char cell = m.coordinates[x][y];
			cout << cell << " ";
		}
		cout << "\n";
	}

	cout << "\n";
	cout << "   ================================================\n";
	cout << "   ||                  I AM FREE                 ||\n";
	cout << "   ================================================\n";
	cout << "\n";

	// Print Legend
	cout << "\n   Legend:\n";
	cout << "   # = Wall / Border\n";
	cout << "   0  = Empty Space\n";
	cout << "   *  = Solved Path\n";
	cout << "   E  = Exit\n";
	cout << "\n";
	userPrompt(choice, filename);
}