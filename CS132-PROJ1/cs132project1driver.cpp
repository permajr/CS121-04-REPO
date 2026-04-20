
//////////////////////////////  cs132project1driver.cpp  //////////////////////////////////
//
// File name         : cs132project1driver.cpp
//
// This program reads from a given file a list of basketball teams.The file is pre
//-formatted to specifications. We create a list from this which allows for additions,
// removals and changes. One can also save the changes to a new file formatted the as 
// the input file
//
// Programmer        : B.J. Streller
//
// Date created      : In the past
//
// Date last revised :
//
///////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<fstream>
using std::ifstream;
using std::ofstream;

#include "TEAM.h"
#include "standings.h"



///////////////////////////////////////////////////////////////////////////////////////////



//  prototype  declarations


void greet();                                              //greets the user
void showMenu();                                           //displays the menu options
void menuOptions();                                        //processes the slected options



/////////////////////////////////////////////  main  //////////////////////////////////////


int main()
{
  greet();
  showMenu();
  menuOptions();
  return 0;

}//end main




////////////////////////////////// menuOptions ////////////////////////////////////////////
//
// function name      : menuOptions
//
// purpose            : contains all the methods which manipulate the standings
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
///////////////////////////////////////////////////////////////////////////////////////////


void menuOptions()
{
  ofstream outFile;
  ifstream inFile;

  standings s;

  int optionNum;

  cout << "please enter a menu number to manipulate the standings : ";


  do                                                            //loop for continued use
    {
      cin >> optionNum;

      switch (optionNum)
        {
        case 1:                                                 //get input file
          s.clearList();
          s.getInputFileName(inFile);
          s.readFileToList(inFile);
          break;
        case 2:                                                 //create output file
          s.standingsOutFileName(outFile);
          //s.teamSort();
          s.listToOutFile(outFile);
          break;
        case 3:                                                 //print the list
          s.teamSort();
          s.displayStandings();
          break;
        case 4:                                                 //modify a team
          s.teamUpdate();
          break;
        case 5:                                                 //add new team
          s.addTeam();
          break;
        case 6:                                                 //delete a team
          s.removeTeam();
          break;
        case 7:                                                 //display menu again
          showMenu();
          break;
        case 8:                                                 //exit program
          cout << " You are about to exit the program -- Have you saved your work ?\n\n";
          break;
        }


      if (optionNum == 8)
        cout << " THANK YOU\n\n";
      else
        cout << "enter the next menu number ( press 7 to see menu options ) :  ";


    }
  while (optionNum != 8);

}




/////////////////////////////////// showMenu //////////////////////////////////////////////
//
// function name      : showMenu
//
// purpose            : greets user and displays the menu
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
///////////////////////////////////////////////////////////////////////////////////////////


void showMenu()
{

  cout << "     Menu Number          Task Description \n";
  cout << "               1             RETRIVES file containing current standings \n";
  cout << "               2             SAVES your updates to a file for future use \n";
  cout << "               3             CURRENT STANDINGS display \n";
  cout << "               4             UPDATING tasks for requested team \n";
  cout << "               5             ADD a new team to the standings \n";
  cout << "               6             REMOVE a team from the standings \n";
  cout << "               7             VIEW menu again \n";
  cout << "               8             EXIT the program \n";
  cout << endl;

}


/////////////////////////////////// greet /////////////////////////////////////////////////
//
// function name      : greet
//
// purpose            : greets user and displays the menu
//
// input parameters   : none
//
// output parameters  : none
//
// return value       : none
//
///////////////////////////////////////////////////////////////////////////////////////////


void greet()
{
  cout << " \n WECOME TO THE NCAA BASKETBALL UPDATE STANDINGS PROGRAM " << endl << endl << endl;
  cout << "The options available to you to update the standings are : \n\n";
}

///////////////////////////////////////////////////////////////////////////////////////////


