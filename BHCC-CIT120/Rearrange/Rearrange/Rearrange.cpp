// This program sorts numbers
// rearrange.exe
// Ricardo Tejada
// November 20 2014

#include <iostream>
using namespace std;

void printTitle();             //      DONE
//		Pre cond:	None
//		Post cond:	Prints the title

void swap(int &x, int &y);           ///   DONE
//		Pre cond:	None
//		Post cond:	Swaps the values of x and y

void rearrange(int &x, int &y, int &z);        ///    DONE
//		Pre cond:	None
//		Post cond:	Rearranges the values inside x, y and z in order from smallest to largest

void driver();              ///    DONE
//		Pre cond:	None
//		Post cond:	Tests the rearrange() function with different arguments

void smartDriver();       ///    DONE
//		Pre cond:	None
//		Post cond:	Tests the rearrange() function and prints a table of the values and results

int main()
{
	int x, y, z;

	printTitle();

	driver();

	system("pause");
	system("cls");

	cout << "\n\n\tBETTER way to test (using a for loop and a table format";
	smartDriver();

	system("pause");
}

void printTitle()       //   DONE
{
	cout << "\t    Lab on \"Driver testing the rearrange function\"		\n"
		 << "\t                   by Ricardo Tejada                       \n";
}

void swap(int &x, int &y)      //   DONE
{
	int temp = x;
	x = y;
	y = temp;
}

void rearrange(int &x, int &y, int &z)       ///    DONE
{
	if (x > y)
		swap(x, y);
	if (y > z)
		swap(y, z);
	if (x > y)
		swap(x, y);
}

void driver()       ///    DONE
{
	int x, y, z;

	x = 1, y = 2, z = 3;
	cout << "\nBefore the call:  x = " << x << "  y = " << y << "  z = " << z << "\n" << x << y << z;
	rearrange(x, y, z);
	cout << "\nAfter the call:  x = " << x << "  y = " << y << "  z = " << z << "\n" << x << y << z << endl;

	x = 1, y = 3, z = 2;
	cout << "\nBefore the call: x = " << x << "  y = " << y << "  z = " << z << "\n" << x << y << z;
	rearrange(x, y, z);
	cout << "\nAfter the call:  x = " << x << "  y = " << y << "  z = " << z << "\n" << x << y << z << endl;

	x = 2, y = 1, z = 3;
	cout << "\nBefore the call:  x = " << x << "  y = " << y << "  z = " << z << "\n" << x << y << z;
	rearrange(x, y, z);
	cout << "\nAfter the call:  x = " << x << "  y = " << y << "  z = " << z << "\n" << x << y << z << endl;

	x = 3, y = 1, z = 2;
	cout << "\nBefore the call:  x = " << x << "  y = " << y << "  z = " << z << "\n" << x << y << z;
	rearrange(x, y, z);
	cout << "\nAfter the call:  x = " << x << "  y = " << y << "  z = " << z << "\n" << x << y << z << endl;

	x = 2, y = 3, z = 1;
	cout << "\nBefore the call:  x = " << x << "  y = " << y << "  z = " << z << "\n" << x << y << z;
	rearrange(x, y, z);
	cout << "\nAfter the call:  x = " << x << "  y = " << y << "  z = " << z << "\n" << x << y << z << endl;

	x = 3, y = 2, z = 1;
	cout << "\nBefore the call:  x = " << x << "  y = " << y << "  z = " << z << "\n" << x << y << z;
	rearrange(x, y, z);
	cout << "\nAfter the call:  x = " << x << "  y = " << y << "  z = " << z << "\n" << x << y << z << endl;
}

void smartDriver()       ///    DONE
{
	int x, y, z;

	cout << "\n\tx\ty\tz"
		 << "\n\t=====================\n";

	for (int c = 1; c < 6; c++)
	{
		switch (c)
		{
			case 1: x = 1, y = 2, z = 3; break;
			case 2: x = 1, y = 3, z = 2; break;
			case 3: x = 2, y = 1, z = 3; break;
			case 4: x = 3, y = 1, z = 2; break;
			case 5: x = 2, y = 3, z = 1; break;
			case 6: x = 3, y = 2, z = 1; break;
		}

		cout << "Start:\t" << x << "\t" << y << "\t" << z << "\n";
		rearrange(x, y, z);
		cout << "End:\t" << x << "\t" << y << "\t" << z << "\n\n";
	}
}