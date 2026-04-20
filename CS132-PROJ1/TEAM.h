
///////////////////////////////////////////////////////////////////////////////////////////
//
// File name         : TEAM.h
//
// This file declares the attribute of the base class which is a user defined data type, a
// struct, called "TEAM"
//
// Programmer        : B.J. Streller
//
// Date created      : In the past
//
// Date last revised :
//
///////////////////////////////////////////////////////////////////////////////////////////


#ifndef TEAM_h
#define TEAM_h


#include<string>
using std::string;

#include<iostream>
using std::ostream;
using std::istream;


struct TEAM                                           		//declare a struct called TEAM
{
public:
  string        name;                                       //team's name
  int           win = 0;                                        //team's wins
  int           lost = 0;                                       //team's losses
  int           votes = 0;
  string        currentRank;
  string		previousRank;

  friend ostream& operator<<(ostream& out, TEAM& ateam);	//overloaded extraction for TEAM
  friend istream& operator>>(istream& in, TEAM& ateam);	    //overloaded insertion for TEAM
  friend bool operator==(const TEAM& t1, const TEAM& t2);	//overloaded equality for TEAM
  friend bool operator<(const TEAM& t1, const TEAM& t2);	//overloaded less than for TEAM

};



#endif



///////////////////////////////////////////////////////////////////////////////////////////
