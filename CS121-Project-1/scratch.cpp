/*#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() 
{
    int patsize = 5;
	for (int rows = patsize; rows >= 1; --rows)
	{
		for (int frontcol = 1; frontcol <= rows; ++frontcol)
		{
			cout << "$";
		}
		cout << patsize;
		for (int backcol = patsize; backcol >= rows + 1; --backcol)
		{
			cout << "$";
		}
		cout << endl;
	}

}
*/