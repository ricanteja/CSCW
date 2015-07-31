#include "Functions.h"

/**************** Function Definition ****************/
void printTitle()
{
	cout << "\n               Project on Designing Overloaded Functions                  \n"
		 << "             Find the area of a circle, rectangle or a triangle             \n"
		 << "                            by Ricardo Tejada                           \n\n\n";
}

bool getAnswer()
{
	char letter;

	cin >> letter;	cin.ignore(80, '\n');

	while ((letter != 'Y' && letter != 'y') && (letter != 'N' && letter != 'n'))
	{
		cout << "Please type Y or N. Try again: ";
		cin >> letter;	cin.ignore(80, '\n');
	}

	return (letter == 'Y' || letter == 'y') ? true : false;
}

double getNumber()
{
	double number;

	while (!(cin >> number))
	{
		cout << "Numbers only please. Try again: ";
		cin.clear();
		cin.ignore(80, '\n');
	}
	cin.ignore(80, '\n');

	return number;
}

double getPosNumber()
{
	double number = getNumber();
	
	while(number <= 0)
	{
		cout << "Positive numbers only please. Try again: ";
		number = getNumber();
	}

	return number;
}

double calculateArea(double radius)
{
	return (radius * radius) * 3.14159;
}

double calculateArea(double width, double length)
{
	return width * length;
}

double calculateArea(double a, double b, double c)
{
	double s = (a + b + c) / 2;
	
	return a + b > c && c + a > b && b + c > a ? sqrt(s * (s - a) * (s - b) * (s - c)) : -1;
}