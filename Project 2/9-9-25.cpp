#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double rad, area, circ;
	const double PI = 3.1415926535897932384626433832795028841972;

	cout << "Enter radius, fool: ";
	cin >> rad;
	area = PI * pow(rad, 2);
	circ = 2 * PI * rad; 
	cout << setprecision(60) << showpoint << fixed;
	cout << "Area is " << area << ", fool." << "\nCircumference is," << circ << " fool.";

}