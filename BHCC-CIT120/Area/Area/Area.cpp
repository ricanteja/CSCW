// This program gets the area of a circle, rectangle and triangle
// area.exe
// Program by Ricardo Tejada
// November 24 2014

#include <iostream>
#include <cmath>
#include "Functions.h"

using namespace std;

/**************** Main Function ****************/
int main()
{
	double x, y, z;

	printTitle();
	cout << "Do you want to test the program? ";

	while(getAnswer())
	{
		//The area of a circle
		cout << "\nGive me the radius of a circle: ";
		x = getPosNumber();
		cout << "\tThe area of the circle is " << calculateArea(x) << "\n";

		//The area of a rectangle
		cout << "\nGive me the length of a rectangle: ";
		x = getPosNumber();
		cout << "...and the width: ";
		y = getPosNumber();
		cout << "\tThe area of the rectangle is " << calculateArea(x, y) << "\n";

		//The area of a triangle
		cout << "\nGive me the lengths of the sides of a triangle.\n";
		cout << "Side 1: ";	x = getPosNumber();
		cout << "Side 2: ";	y = getPosNumber();
		cout << "Side 3: ";	z = getPosNumber();

		while (calculateArea(x, y, z) < 0)
		{
			cout << "The sum of the two sides of a triangle must be greater than the third side.\nTry again. ";
			cout << "Side 1: ";	x = getPosNumber();
			cout << "Side 2: ";	y = getPosNumber();
			cout << "Side 3: ";	z = getPosNumber();
		}

		cout << "\tThe area of the triangle is " << calculateArea(x, y, z) << "\n";

		cout << "\n\t*****************\n\n";
		cout << "Would you like to test the program again? ";
	}

	cout << "\nDon't you love Geometry?\n";
	system("pause");
}