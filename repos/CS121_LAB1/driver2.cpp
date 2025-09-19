# include <iostream>
# include <climits>
# include <cfloat>
using namespace std;
int main()
{
	cout << "Hi there \n We are computing the minimum and maximum "<< "values for the primitive data types";
	cout << endl << endl;
	cout << "The minimum short value is " << SHRT_MIN << " and the maximum short value is " << SHRT_MAX << "\n\n";
	cout << "The minimum unsigned short value is " << 0 << " and the maximum unsigned short value is " << USHRT_MAX << "\n\n";
	cout << "The minimum integer value is " << INT_MIN << " and the maximum integer value is " << INT_MAX << "\n\n";
	cout << "The minimum unsigned integer value is " << 0 << " and the maximum unsigned integer value is " << UINT_MAX << "\n\n";
	cout << "The minimum long integer value is " << LONG_MIN << " and the maximum long integer value is " << LONG_MAX << "\n\n";
	cout << "The minimum unsigned long integer value is " << 0 << " and the maximum unsigned long integer value is " << ULONG_MAX << "\n\n";
	cout << "The minimum float value is " << FLT_MIN << " and the maximum float value is " << FLT_MAX << "\n\n";
	cout << "The minimum double value is " << DBL_MIN << " and the maximum double value is " << DBL_MAX << "\n\n";
	return 0;
}