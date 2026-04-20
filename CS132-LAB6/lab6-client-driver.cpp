#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <list>
using namespace std;

fstream infile;
string fname;

struct student
{
	char firstnm[20],
		lastnm[20];
	int id,
		grade;
	friend ostream& operator<< (ostream& out, const student& d);
	friend istream& operator>> (istream& in, student& d);
	friend bool operator< (const student& lStud, const student& rStud);
};

string getInputFileName(string& fname);
void readFileToList();
void addToList();
void printer();
list <student> studList;







int main()
{
	cout << "Welcome to Sam's School for Silly Students Some Would Say Survive in Celluloid Sketches!\n";
	getInputFileName(fname);
	readFileToList();
	printer();
	addToList();
	cout << "Sorting Sam's Silly Students Soon!\n";
	studList.sort();
	printer();


}
string getInputFileName(string& fname)
{
	bool errCheck = false;
	cout << "Scratch a super sufficient file name, be sure to schlep the full path!  \n";
	while (!errCheck)
	{
		cin >> fname;
		infile.open(fname);
		if (!infile)
		{
			cout << "Shucks! Someone screwed someting surely!\n";
			errCheck = false;

		}
		else
		{
			cout << "Showing Sam's Super Silly Student shortly!\n";
			errCheck = true;
		}
	}
	return fname;
}

void readFileToList()
{
	student tempStud;
	int disCount = 0;

	
	while (infile >> tempStud)
	{
		if (disCount == 0)
		{
			studList.push_front(tempStud);
		}
		else
		{

			studList.push_back(tempStud);
		}
		disCount++;
	}
}

void addToList()
{
	student newStud;

	cout << "\nSay a solid student to superimpose somewhere substantial:\n";
	cout << "First Name: ";
	cin >> newStud.firstnm;
	cout << "Last Name: ";
	cin >> newStud.lastnm;
	cout << "ID: ";
	cin >> newStud.id;
	cout << "Grade: ";
	cin >> newStud.grade;

	studList.push_back(newStud);
	cout << "Added: \n" << newStud << endl;
}

ostream& operator<< (ostream& out, const student& d)
{
	out << setw(15) << d.firstnm << setw(15) << d.lastnm << setw(10) << d.id << setw(5) << d.grade;
	return out;
}

istream& operator>> (istream& in, student& d)
{
	in >> d.firstnm >> d.lastnm >> d.id >> d.grade;
	return in;
}

bool operator< (const student& lStud,const student&  rStud) 
{

	return (lStud.id < rStud.id);
}

void printer()
{
	cout << "Slavishly study this substantial showing of super silly, solid, serious, somewhat suspicious surprising students!\n";
	cout << "--------------------------------------------------------------------------\n";
	for (student& tempStud : studList)
	{
		cout << tempStud << "\n";
	}
	cout << "--------------------------------------------------------------------------\n";
}

/*
Welcome to Sam's School for Silly Students Some Would Say Survive in Celluloid Sketches!
Scratch a super sufficient file name, be sure to schlep the full path!
disneyin2.txt
Showing Sam's Super Silly Student shortly!
Slavishly study this substantial showing of super silly, solid, serious, somewhat suspicious surprising students!
--------------------------------------------------------------------------
		  Hewey           Duck       123   90
		  Daffy           Duck       342   92
		  Wiley         Coyote       432   89
		  Goofy            Dog       654   95
		  Daisy           Duck       145   92
	  Sylvester       PuddyCat       775   86
		 Tweety           Bird       221   87
		 Mickey          Mouse       666   66
--------------------------------------------------------------------------

Say a solid student to superimpose somewhere substantial:
First Name: Randy
Last Name: Devlin-Souter
ID: 1337
Grade: 100
Added:
		  Randy  Devlin-Souter      1337  100
Sorting Sam's Silly Students Soon!
Slavishly study this substantial showing of super silly, solid, serious, somewhat suspicious surprising students!
--------------------------------------------------------------------------
		  Hewey           Duck       123   90
		  Daisy           Duck       145   92
		 Tweety           Bird       221   87
		  Daffy           Duck       342   92
		  Wiley         Coyote       432   89
		  Goofy            Dog       654   95
		 Mickey          Mouse       666   66
	  Sylvester       PuddyCat       775   86
		  Randy  Devlin-Souter      1337  100
--------------------------------------------------------------------------

C:\Users\randy\Documents\GitHub\CS121-04-REPO\CS132-LAB6\x64\Debug\CS132-LAB6.exe (process 27940) exited with code 0 (0x0).
Press any key to close this window . . .
*/