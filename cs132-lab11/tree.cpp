#include <iostream>
#include <fstream>
#include "tree.h"
#include <string>
using namespace std;

tree<char> baseTree;
string baseString = "LTGSHXDEAIMUZJFVBP";
string remString = "MULES";
char tempChar;
void drawAllTraversal();

int main() 
{
	cout << "====================================================\n"
		<< "TIME TO TRY TRINA'S TREE TREATMENT!\n"
		<< "====================================================\n";

	for (int c = 0; c <= 17; c++)
	{
		tempChar = baseString.at(c);
		cout << "TRANSMITTING " << tempChar << " INTO A TOTAL TREE..." << endl;
		baseTree.insert(tempChar);
	}
	drawAllTraversal();
	for (int r = 0; r < 5; r++)
	{
		tempChar = remString.at(r);
		cout << "TAKING " << tempChar << " TO TRINA'S TREE TRASH TOMB..." << endl;
		baseTree.SearchAndDestroy(tempChar);
	}
	drawAllTraversal();
}	

void drawAllTraversal()
{
	cout << "====================================================\n"
		<< "TRINA'S TREE TREATMENT IS TRIANGULATING TRAVERSALS...\n"
		<< "====================================================\n";

	for (int t = 1; t <= 3; t++)
	{
		baseTree.writeTree(t);
		cout << endl << "---------------------------------------------------\n";
	}
};

/*
====================================================
TIME TO TRY TRINA'S TREE TREATMENT!
====================================================
TRANSMITTING L INTO A TOTAL TREE...
TRANSMITTING T INTO A TOTAL TREE...
TRANSMITTING G INTO A TOTAL TREE...
TRANSMITTING S INTO A TOTAL TREE...
TRANSMITTING H INTO A TOTAL TREE...
TRANSMITTING X INTO A TOTAL TREE...
TRANSMITTING D INTO A TOTAL TREE...
TRANSMITTING E INTO A TOTAL TREE...
TRANSMITTING A INTO A TOTAL TREE...
TRANSMITTING I INTO A TOTAL TREE...
TRANSMITTING M INTO A TOTAL TREE...
TRANSMITTING U INTO A TOTAL TREE...
TRANSMITTING Z INTO A TOTAL TREE...
TRANSMITTING J INTO A TOTAL TREE...
TRANSMITTING F INTO A TOTAL TREE...
TRANSMITTING V INTO A TOTAL TREE...
TRANSMITTING B INTO A TOTAL TREE...
TRANSMITTING P INTO A TOTAL TREE...
====================================================
TRINA'S TREE TREATMENT IS TRIANGULATING TRAVERSALS...
====================================================
LGDABEFHIJTSMPXUVZ
---------------------------------------------------
ABDEFGHIJLMPSTUVXZ
---------------------------------------------------
BAFEDJIHGPMSVUZXTL
---------------------------------------------------
TAKING M TO TRINA'S TREE TRASH TOMB...
TAKING U TO TRINA'S TREE TRASH TOMB...
TAKING L TO TRINA'S TREE TRASH TOMB...
TAKING E TO TRINA'S TREE TRASH TOMB...
TAKING S TO TRINA'S TREE TRASH TOMB...
====================================================
TRINA'S TREE TREATMENT IS TRIANGULATING TRAVERSALS...
====================================================
JGDABFHITPXVZ
---------------------------------------------------
ABDFGHIJPTVXZ
---------------------------------------------------
BAFDIHGPVZXTJ
---------------------------------------------------

C:\Users\randy\Documents\GitHub\CS121-04-REPO\cs132-lab11\x64\Debug\cs132-lab11.exe (process 44840) exited with code 0 (0x0).
*/