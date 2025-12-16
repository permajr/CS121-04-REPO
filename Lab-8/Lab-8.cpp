/***************************************************************************

FILE NAME: LAB*_DRIVER.CPP
PROGRAMMER: RANDY DEVLIN-SOUTER
CLASS: CS121-04
PROFESSOR: DUTTA

THIS PROGRAM READS DATA FROM A FILE AND OUTPUTS TO ANOTHER FILE
***************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
void bubbleSort(int[], int);//bubble sort algorithm
void swap(int&, int&);//swaps numbers based on value
string get_input_fileName(string&);//prompts user for file to read from
string get_output_fileName(string&);//prompts user for file to print to
int display_sorted_array(int nums[]);//displays sorted data
string inputname;//name of file going in
string outputname;//name of file going out
int nums[500];//integer array

int main()
{
    //opening input stream and setting looping variables, as well as a counter for number of swaps
    ifstream infile;
    bool file = false;
    int counter = 0;
    string looper;
    //while the file variable is false this is our main body
   while (!file)
   {
       //intro to the program
        cout << "*****************************************************************************************\n";
        cout << "Welcome to Kyle's Flying File Filing Open Door On-the-Floor Sorter!\n";
        //asks for filename and opens the input file checking for errors
        get_input_fileName(inputname);
        infile.open(inputname);
        if (!infile)
        {
            cout << "Whoopsie! Why don't we go back and try to enter in a new filename\n";
            file = false;
        }
        //on successful open, sorts the file
        else
        {
            cout << "Thanks! We're gonna look through your file and try and sort out the numbers you've got.\n";
            while (counter < 500 && infile >> nums[counter])
                counter++;
            bubbleSort(nums, counter);

            cout << "****************************************************************************************\n";
            cout << "Looks like all your info is sorted! We're gonna go ahead and output it all to a file.\n";
            //opens output stream and gets filename from user
            ofstream outfile;
            get_output_fileName(outputname);
            if (!outfile)
            {
                cout << "Uh Oh! Gonna have to try that one again hoss.\n";
                file = false;

            }
            //on successful open, resets counter and outputs up until the 498th run, then outputs the number of times it ran as well as final integer
            else 
            {
                counter = 0;
                while (counter < 500)
                {
                    if (counter < 499)
                    {
                        outfile << nums[counter] << endl;
                    }
                    else
                    {
                        outfile << nums[counter] << endl << counter;
                    }
                    counter++;
                }
                //closes both filestreams
                infile.close();
                outfile.close();
                //sets up exit loop
                bool loop2 = false;
                while (!loop2) 
                {
                    cout << "Your data has been printed! Enter 1 to run another file, 2 to display your data, or 3 to quit.";
                    cin.clear();
                    cin >> looper;
                    cin.clear();
                    if (looper == "1")
                    {
                        loop2 = true;
                        file = false;
                    }
                    else if (looper == "2")
                    {
                        display_sorted_array(nums);
                     
                    }
                    else if (looper == "3")
                    {
                        file = true;
                        loop2 = true;
                        return 0;
                    }
                    else
                    {
                        cout << "Uh Oh! Let's try that again!";
                        loop2 = false;

                    }
                }
            }

        }

   }
        
}

//bubble sorting algorithm
void bubbleSort(int nums[], int size)
{
    int i, j;
    bool swapped = false;

    for (i = 0; i < size; i++)    //passes through he array                                                                    
    {
        for (j = 0; j < size - i - 1; j++)  // one pass                          
        {
            if (nums[j] > nums[j + 1])
            {
                swap(nums[j], nums[j + 1]);
                swapped = true;
            }
        }
    
    if (swapped)
        swapped = false;
    else
        break;
    }
}



 //swaps integers based on their value
void swap(int& num1, int& num2)
{
        int temp;      //any temporary variable
        temp = num1;
        num1 = num2;
        num2 = temp;
}

//gets input file name as well as checks for errors
string get_input_fileName(string& inputname) 
{
    string yesno;
    bool yeno = false;
    while(!yeno)
    {
        cout << "******************************************************************************************\n";
        cout << "Enter in the full path, with quotation marks, of the file you'd like to swap.\n";
        cout << "And remember, here at Kyle's, we use two slashes to indicate the next part of a filepath.\n";
        cout << "******************************************************************************************\n";
        cin.clear();
        cin >> inputname;
        cin.clear();
        cout << "You entered: " << inputname << ". Is this correct? Y/N\n";
        cin >> yesno;
        if (yesno == "y" || yesno == "Y")
        {
            break;
        }
        else if (yesno == "n" || yesno == "N")
        {
            bool yeno = false;
        }
        else
        {
            cout << "Incorrect answer. Please try again!\n";
            bool yeno = false;
        }
    }

    return inputname;
}

//same as above but for output
string get_output_fileName(string& outputname)
{
    bool input = false;
    string yesno;
    while (!input)
    {
        cout << "We just need to know what to call it!\n Enter the file, and the filepath you want, here!\n";
        cout << "****************************************************************************************\n";
        cin.clear();
        cin >> outputname;
        cout << "You entered: " << outputname << "! Is this correct? Y/N\n";
        cin >> yesno;
        if (yesno == "y" || yesno == "Y")
        {
            break;
        }
        else if (yesno == "n" || yesno == "N")
        {
            bool input = false;
        }
        else
        {
            cout << "Incorrect answer. Please try again!\n";
            bool input = false;
        }
    }
    return outputname;
}

//displays the final array after sorting
int display_sorted_array(int nums[]) 
{
    for (int i = 0; i < 500; i++)
        cout << nums[i] << " ";
    cout << endl;
    return nums[200];
}