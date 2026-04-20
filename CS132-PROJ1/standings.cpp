
///////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : standings.cpp
//
// This file declares the methods for the derived class called  standings
//
// Programmer        : Randy Devlin-Souter with contibutions from B.J. Streller 
//
// Date created      : In the past
//
// Date last revised : 3/19/2026
//
///////////////////////////////////////////////////////////////////////////////////////////

#include "standings.h"

#include<iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ios;


#include<fstream>
using std::ostream;
using std::istream;
using std::ifstream;
using std::ofstream;

#include<string>
using std::string;

#include<iomanip>
using std::ios;
using std::setw;
using std::setfill;
using std::ws;


#include <list>

#include<algorithm>
using std::find;



/////////////////////////////////////////////////////////////////////////////////
//
// function name      : getInputFileName
//
// purpose            : Gets name of .tsv file from user.
//
// input parameters   : String with fully qualified file path, ending in .tsv
//
// output parameters  : No output.
//
// return value       : void
//
/////////////////////////////////////////////////////////////////////////////////


void standings::getInputFileName(ifstream& inFile)
{
  string inFileName;

  cout << " \n Please enter the fully qualified name of the \n"
       << " input text file, including the path: ";
  cin >> inFileName;

  cout << endl;

  inFile.open(inFileName.c_str());                     //try to open


  if (!inFile)                                         //test if open
    {
      cerr << " cannot open file: " << inFileName << endl << endl;
      exit(-1);
    }

}

/////////////////////////////////////////////////////////////////////////////////
//
// function name      : standingsOutFileName
//
// purpose            : Get name of file to be saved by user.
//
// input parameters   : File name input from user, ending in .tsv
//
// output parameters  : A .tsv file
//
// return value       : Void
//
/////////////////////////////////////////////////////////////////////////////////

void standings::standingsOutFileName(ofstream& outFile)
{
  string   outFileName;                                //complete file name

  cout << " Please enter the name of your output file, ending in .tsv: ";
  cin >> outFileName;
  cout << endl;

  outFile.open(outFileName.c_str());                   //try to open

  if (!outFile)                                        //test if open
    {
      cerr << " cannot open file: " << outFileName << endl << endl;
      exit(-3);
    }



}
/////////////////////////////////////////////////////////////////////////////////
//
// function name      : readFileToList
//
// purpose            : Reading data from a .tsv file into a list.
//
// input parameters   : Information separated by whitespace characters.
//
// output parameters  : A std::list storing data from the file.
//
// return value       : Void
//
/////////////////////////////////////////////////////////////////////////////////


void standings::readFileToList(ifstream& inFile)
{
    string headerDate;
    getline(inFile, headerDate);  // Read the header line (date)

    // Display the date header
    cout << "Processing standings from: " << headerDate << endl;
  TEAM ateam;
  while (inFile >> ws && !inFile.eof()) // while reading, grab info from infile and put it into ateam, then move ateam to a new
    {
      inFile >> ateam;
      push_back(ateam);
    }
  inFile.clear();
  inFile.close();

}


/////////////////////////////////////////////////////////////////////////////////
//
// function name      : listToOutFile
//
// purpose            : Printing information from a std::list to a file.
//
// input parameters   : std::list with a whole bunch of values.
//
// output parameters  : One clean, well formatted .tsv file.
//
// return value       : void
//
/////////////////////////////////////////////////////////////////////////////////


void standings::listToOutFile(ofstream& outFile)
{
  if (empty())
    cout << " list is empty ";

  else 
    {
      for (std::list<TEAM>::iterator j = begin(); j != end(); j++) // take info from outfile to the team list 
        {
          outFile << *j;
        }
    }

  outFile.close();

}//end listTo...


/////////////////////////////////////////////////////////////////////////////////
//
// function name      : standings(constructor)
//
// purpose            : Calls a new object that is derived from the TEAM struct.
//
// input parameters   : TEAM struct.
//
// output parameters  : Default values.
//
// return value       : A new team!
//
/////////////////////////////////////////////////////////////////////////////////


standings::standings()
{ 
    ateam.name = "";
    ateam.win = 0;
    ateam.lost = 0;
    ateam.votes = 0;
    ateam.currentRank = "";
    ateam.previousRank = "";
}




/////////////////////////////////////////////////////////////////////////////////
//
// function name      : ~standings(destructor)
//
// purpose            : Frees up memory used by whichever team is currently being called.
//
// input parameters   : Memory with information.
//
// output parameters  : Free memory.
//
// return value       : Free memory!
//
/////////////////////////////////////////////////////////////////////////////////

standings::~standings()
{ 
    cout << "\nBoo!! The destructor has been called!\n";
    this->clear();
}




/////////////////////////////////////////////////////////////////////////////////
//
// function name      : clearList()
//
// purpose            : Clears out information in a list.
//
// input parameters   : A list with information.
//
// output parameters  : A list without information.
//
// return value       : void
//
/////////////////////////////////////////////////////////////////////////////////
void standings::clearList()
{
  if (!empty())
    {
      erase(begin(), end());
      cout << " cleared list" << endl;
    }

}



/////////////////////////////////////////////////////////////////////////////////
//
// function name      : displayStandings
//
// purpose            : Display all teams in the standings list with formatted output
//
// input parameters   : Information from a .tsv file provided by user.
//
// output parameters   : Console output.
//
// return value       : void
//
/////////////////////////////////////////////////////////////////////////////////

void standings::displayStandings()
{
    if (empty())
    {
        cout << "\nList is empty. No standings to display.\n";
    }
    else
    {

        cout << endl << endl;
        cout << "Standings as of: 03/02/2026" << endl;
        cout << setfill('-') << setw(85) << "-" << endl;
        cout << setfill(' ');
        cout << setw(5) << "Rank"
            << "\t" << setw(20) << "Team Name"
            << "\t" << setw(12) << "Record"
            << "\t" << setw(12) << "Prev Rank"
            << "\t" << setw(10) << "Votes" << endl;
        cout << setfill('-') << setw(85) << "-" << endl;
        cout << setfill(' ');

        for (std::list<TEAM>::iterator j = this->begin(); j != this->end(); j++)
        {
            cout << setw(5) << j->currentRank
                << "\t" << setw(20) << j->name
                << "\t" << setw(12) << j->win << "-" << j->lost
                << "\t" << setw(12) << j->previousRank
                << "\t" << setw(10) << j->votes << endl;
        }

        cout << setfill('-') << setw(85) << "-" << endl;
    }

    cout << endl << endl;
}

/////////////////////////////////////////////////////////////////////////////////
//
// function name      : teamSearch()
//
// purpose            : Searches for a team's name.
//
// input parameters   : Name of a team.
//
// output parameters  : None
//
// return value       : void
//
/////////////////////////////////////////////////////////////////////////////////

void standings::teamSearch()
{
    if (empty())
    {
        cout << "\nList is empty. No teams to search.\n";
        return;
    }

    string searchName;
    cout << "\nEnter the team name to search for: ";
    cin >> ws;
    getline(cin, searchName);

    bool found = false;
    std::list<TEAM>::iterator j;

    for (j = begin(); j != end(); j++)
    {
        if (j->name == searchName)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << "\nTeam found:\n";
        cout << *j;
    }
    else
    {
        cout << "\nTeam '" << searchName << "' not found in standings.\n";
    }
}


/////////////////////////////////////////////////////////////////////////////////
//
// function name      : teamUpdate
//
// purpose            : Update a team's information (wins, losses, votes, ranks)
//
// input parameters   : none (user input via cin)
//
// output parameters  : none
//
// return value       : void
//
/////////////////////////////////////////////////////////////////////////////////

void standings::teamUpdate()
{
    if (empty())
    {
        cout << "\nList is empty. No teams to update.\n";
        return;
    }

    string teamName;
    cout << "\nEnter the team name to update: ";
    cin >> ws;
    getline(cin, teamName);

    bool found = false;
    std::list<TEAM>::iterator j;

    for (j = begin(); j != end(); j++)
    {
        if (j->name == teamName)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        int choice;
        cout << "\nWhat would you like to update?\n";
        cout << "1. Wins\n";
        cout << "2. Losses\n";
        cout << "3. Votes\n";
        cout << "4. Current Rank\n";
        cout << "5. Previous Rank\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter new wins: ";
            cin >> j->win;
            cout << "Wins updated.\n";
            break;
        case 2:
            cout << "Enter new losses: ";
            cin >> j->lost;
            cout << "Losses updated.\n";
            break;
        case 3:
            cout << "Enter new votes: ";
            cin >> j->votes;
            cout << "Votes updated.\n";
            break;
        case 4:
            cout << "Enter new current rank: ";
            cin >> ws;
            getline(cin, j->currentRank);
            cout << "Current rank updated.\n";
            break;
        case 5:
            cout << "Enter new previous rank: ";
            cin >> ws;
            getline(cin, j->previousRank);
            cout << "Previous rank updated.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    }
    else
    {
        cout << "\nTeam '" << teamName << "' not found.\n";
    }
}


/////////////////////////////////////////////////////////////////////////////////
//
// function name      : addTeam
//
// purpose            : Add a new team to the standings list
//
// input parameters   : none (user input via cin)
//
// output parameters  : none
//
// return value       : void
//
/////////////////////////////////////////////////////////////////////////////////

void standings::addTeam()
{
    TEAM newTeam;
    string checkName;
    bool found = false;

    cout << "\n--- Add New Team ---\n";
    cout << "Enter team name: ";
    cin >> ws;
    getline(cin, newTeam.name);
    checkName = newTeam.name;

    for (std::list<TEAM>::iterator j = begin(); j != end(); j++)
    {
        if (j->name == checkName)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << "\nTeam '" << newTeam.name << "' already exists in standings.\n";
        return;
    }

    cout << "Enter wins: ";
    cin >> newTeam.win;

    cout << "Enter losses: ";
    cin >> newTeam.lost;

    cout << "Enter votes: ";
    cin >> newTeam.votes;

    cout << "Enter current rank: ";
    cin >> ws;
    getline(cin, newTeam.currentRank);

    cout << "Enter previous rank: ";
    cin >> ws;
    getline(cin, newTeam.previousRank);

    push_back(newTeam);
    cout << "\nTeam '" << newTeam.name << "' added successfully.\n";
}


/////////////////////////////////////////////////////////////////////////////////
//
// function name      : removeTeam
//
// purpose            : Remove a team from the standings list
//
// input parameters   : none (user input via cin)
//
// output parameters  : none
//
// return value       : void
//
/////////////////////////////////////////////////////////////////////////////////

void standings::removeTeam()
{
    if (empty())
    {
        cout << "\nList is empty. No teams to remove.\n";
        return;
    }

    string teamName;
    cout << "\nEnter the team name to remove: ";
    cin >> ws;
    getline(cin, teamName);

    bool found = false;
    std::list<TEAM>::iterator j;

    for (j = begin(); j != end(); j++)
    {
        if (j->name == teamName)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << "\nRemoving team: " << j->name << endl;
        erase(j);
        cout << "Team removed successfully.\n";
    }
    else
    {
        cout << "\nTeam '" << teamName << "' not found.\n";
    }
}





