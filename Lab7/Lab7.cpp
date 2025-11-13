#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	string sample;
	int num = 0;
	ifstream infile;
	infile.open("C:\\Users\\rdevl\\Documents\\GitHub\\CS121-04-REPO\\Lab7\\CS121-Lab7\\wake.txt");
	ofstream outfile;
	outfile.open("C:\\Users\\rdevl\\Documents\\GitHub\\CS121-04-REPO\\Lab7\\CS121-Lab7\\out.txt");

	infile >> sample;

	while (infile >> sample)
	{
		++num;
	}
	cout << num;
	outfile << num;
	infile.close();
	outfile.close();
}