# include <iostream>
using namespace std;
int main()
{
	cout << " We are computing bits and bytes of the primitive data types \n ";
	cout << endl << endl;
	cout << "Number of bytes in a short integer = " << sizeof(short) << "\nnumber of bits = " << sizeof(short) * 8 << "\n\n";
	cout << "Number of bytes in an unsigned short integer = " << sizeof(unsigned short) << "\nnumber of bits = " << sizeof(unsigned short) * 8 << "\n\n";
	cout << "Number of bytes in an integer = " << sizeof(int) << "\n number of bits = " << sizeof(int) * 8 << "\n\n";
	cout << "Number of bytes in an unsigned integer = " << sizeof(unsigned) << "\nnumber of bits = " << sizeof(unsigned) * 8 << "\n\n";
	cout << "Number of bytes in a long integer = " << sizeof(long) << "\n number of bits = " << sizeof(long) * 8 << "\n\n";
	cout << "Number of bytes in an unsigned long integer = " << sizeof(unsigned long) << "\nnumber of bits = " << sizeof(unsigned long) * 8 << "\n\n";
	cout << "Number of bytes in a character = " << sizeof(char) << "\nnumber of bits = " << sizeof(char) * 8 << "\n\n";
	cout << "Number of bytes in a float = " << sizeof(float) << "\nnumber of bits = " << sizeof(float) * 8 << "\n\n";
	cout << "Number of bytes in a double = " << sizeof(double) << "\nnumber of bits = " << sizeof(double) * 8 << "\n\n";

}