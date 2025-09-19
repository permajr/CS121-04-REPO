//including necessary library files
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const double SALE_TAX = 0.0875;// declare and initialize constant
	double wholePrice, markupRate, salePrice, totalPrice; //declare variables
	cout << setprecision(2) << fixed << showpoint;//decimal formatting
	cout << "Enter your price:" << endl;//prompt for item price
	cin >> wholePrice; // updates variable wholePrice
	cout << "Wanna mark it up a bit? " << endl;//prompt for markup rate
	cin >> markupRate;//updates markupRate
	markupRate /= 100;//makes markupRate into percentage
	totalPrice= wholePrice + SALE_TAX * wholePrice;//calculates whole price with sales tax
	cout << "Your price before tax is: " << wholePrice * markupRate + wholePrice << endl;//reports price without tax
	cout << "Your total price is:" << totalPrice;// reports price with tax




}