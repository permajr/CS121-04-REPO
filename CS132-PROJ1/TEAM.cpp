
///////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : TEAM.cpp
//
// This file declares the attribute of the base class which is a user defined data type, a
// struct, called "TEAM"
//
// Programmer        : Randy Devlin-Souter with contibutions from B.J. Streller 
//
// Date created      : In the past
//
// Date last revised : 3/19/25
//
///////////////////////////////////////////////////////////////////////////////////////////


#include "TEAM.h"

#include<iomanip>
using std::ios;
using std::setw;
using std::setfill;
using std::endl;
using std::ios;
using std::ws;


#include<string>
using std::string;

#include<iostream>
using std::ostream;
using std::istream;
using std::cout;




/////////////////////////////////////////////////////////////////////////////////
//
// function name      : Extraction operator.
//
// purpose            : Grabs data from ateam list and displays it to the screen.
//
// input parameters   : List with numerous parameters (name, currentRank, win, lost, votes, previousRank)
//
// output parameters  : Console output.
//
// return value       : output to console.
//
/////////////////////////////////////////////////////////////////////////////////

ostream& operator<<(ostream& out, TEAM& ateam)
{
  out.setf(ios::left);
  out << setw(5) << setfill(' ');
  out << (ateam).currentRank;
  out.unsetf(ios::left);

  out.setf(ios::left);
  out << setw(22)  << setfill(' ');
  out << ateam.name;
  out.unsetf(ios::left);

  out << ateam.win;
  out << "-";
  out << ateam.lost;
  out << "  ";

  out << setw(5) << setfill(' ');
  out << ateam.votes;
  out << "  ";

  out << setw(4) << setfill(' ');
  out << ateam.previousRank;

  out << endl;

  return out;

}



/////////////////////////////////////////////////////////////////////////////////
//
// function name      : Insertion operator.
//
// purpose            : Grabs data from file and inserts it into ateam list.
//
// input parameters   : .tsv file with parameters (name, currentRank, win, lost, votes, previousRank) separated by whitespace characters
//
// output parameters  : List with TEAM datatype and assosciated values.
//
// return value       : Input from file to list.
//
/////////////////////////////////////////////////////////////////////////////////

istream& operator>>(istream& in, TEAM& ateam)
{
  in >> ateam.currentRank;

  //now read team name char by char then stuff into team's name
  char ch;
  string s;
  in.get(ch);
  while(true)
    {
      if (ch != '\t')
        s.push_back(ch);
      ch= in.peek();
      if (isdigit(ch))
        break;
      in.get(ch);
    }
  ateam.name = s;

  //read rest of data
  in >> ateam.win;
  in.get();
  in >> ateam.lost;
  in >> ateam.votes;
  in >> ateam.previousRank;

  return in;

}




/////////////////////////////////////////////////////////////////////////////////
//
// function name      : Equality operator.
//
// purpose            : Determines equality of two teams' names.
//
// input parameters   : Two team names.
//
// output parameters  : Boolean.
//
// return value       : Boolean value.
//
/////////////////////////////////////////////////////////////////////////////////

bool operator==(const TEAM& t1, const TEAM& t2)
{
  return ((t1.name) == (t2.name)) ? true : false;
}



/////////////////////////////////////////////////////////////////////////////////
//
// function name      : Less than operator.
//
// purpose            : Comaparator used in sort algorithm which determines descending value of two team parameters.
//
// input parameters   : Two teams.
//
// output parameters  : Higher / Lower
//
// return value       : Boolean
//
/////////////////////////////////////////////////////////////////////////////////

bool operator<(const TEAM& t1, const TEAM& t2)
{
    // Compare by votes first (higher votes = better)
    if (t1.votes != t2.votes)
        return t1.votes > t2.votes;

    // If votes are equal, compare by current rank (lower rank = better)
    if (t1.currentRank != t2.currentRank)
        return t1.currentRank < t2.currentRank;

    // If current rank is equal, compare by previous rank (lower rank = better)
    if (t1.previousRank != t2.previousRank)
        return t1.previousRank < t2.previousRank;

    // If all else is equal, compare by name (alphabetically)
    return t1.name < t2.name;
}


