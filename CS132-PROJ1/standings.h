
///////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : standings.h
//
// This file declares the methods for the derived class called standings
//
// Programmer        : B.J. Streller
//
// Date created      : In the past
//
// Date last revised :
//
///////////////////////////////////////////////////////////////////////////////////////////



#ifndef standings_h
#define standings_h


#include<fstream>
using std::ifstream;
using std::ofstream;

#include <list>

#include "TEAM.h"



class standings : protected std::list<TEAM>
{

public:

  void getInputFileName(ifstream& inFile);       //gets in file name
  void standingsOutFileName(ofstream& outFile);  //gets out file name
  void readFileToList(ifstream& inFile);         //reads infile to the list class <list>TEAM
  void listToOutFile(ofstream& outFile);         //reads the object <list>TEAM to the out file

  standings();                                   //constructor
  ~standings();                                  //destructor

  void teamSort()
  {
    sort();  									 //sorts <list>TEAM
  }
  void teamSearch();                             //searches <list>Team for a match
  void teamUpdate();                             //updates a member of <list>TEAM
  void addTeam();                                //adds  a member to <list>TEAM
  void removeTeam();                             //removes a member of <list>TEAM;
  void clearList();                              //empties <list>TEAM for another use
  void displayStandings();                       //prints the Current<list>TEAM

private:

  TEAM  ateam;                                   //data member of standings
};



#endif




