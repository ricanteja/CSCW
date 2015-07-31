#include <iostream>
#include <cmath>

using namespace std;

/**************** Function Decleration ****************/
void printTitle();
//		Pre cond:	None
//		Post cond:	Prints the title

bool getAnswer();
//		Pre cond:	None
//		Post cond:	Returns true or false depending on yes or no answer
//					Validates for upper and lowercase Y and N

double getNumber();
//		Pre cond:	None
//		Post cond:	Returns a number from the user
//					Does NOT crash on non-numeric input
//					Clears the input stream

double getPosNumber();
//		Pre cond:	None
//		Post cond:	Returns a positive number
//					Does NOT crash on non-numeric input
//					Clears the input stream

double calculateArea(double radius);
//		Pre cond:	radius > 0
//		Post cond:	Returns the area of a circle given the radius

double calculateArea(double width, double length);
//		Pre cond:	width > 0; length > 0
//		Post cond:	Returns the area of a rectangle given the width and length

double calculateArea(double a, double b, double c);
//		Pre cond:	The sides A, B and C must make a valid triangle
//		Post cond:	Returns the are of a triangle give the sides A, B and C
