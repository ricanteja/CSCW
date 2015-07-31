#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

/****************************Function Declerations****************************/
void printTitle();             //  DONE
	// Pre cond:	None
	// Post cond:	Prints the title to the console

void printMenu();             //  DONE
	// Pre cond:	None
	// Post cond:	Prints the menu to the console

double getNum();                //  DONE
	// Pre cond:    None
	// Post cond:	Removes everything left in the input stream
	//				Does NOT crash if non-numeric input is entered

int getInt();             //  DONE
	// Pre cond:	None
	// Post cond:	Returns a valid integer
	//              Removes everything left in the input stream
	//				Does NOT crash if non-numeric input is entered

double getPos();             //  DONE
	// Pre cond:	NONE
	// Post cond:	Returns a positive number
	//				Removes everything left in the input stream
	//              will break the cin for non-numeric input

double getPosNum();             //  DONE
	// Pre cond:	None
	// Post cond:	Returns a positive number
	//				Removes everything left in the input stream
	//				Does NOT crash if non-numeric input is entered

double getNumGreater(double floor);             //  DONE
	// Pre cond:	None
	// Post cond:	Returns a number that is greater than floor and is inclusive
	//				Removes everything left in the input stream
	//				Does NOT crash if non-numeric input is entered

int getIntGreater(double floor);             //  DONE
	// Pre cond:	None
	// Post cond:	Returns an integer value greater than floor and is inclusive
	//				Removes everything left in the input stream
	//				Does NOT crash if non-numeric input is entered

int getMultOfNum(int multiple);
	// Pre cond:	'multiple' != 0
	// Post cond:	Returns an integer that is a multiple of the variable multiple
	//              Removes everything left in the input stream
	//				Does NOT crash if non-numeric input is entered

char getLetter();             //  DONE
	// Pre cond:	None
	// Post cond:	Returns a letter from the alphabet
	//				Removes everything left in the input stream

double getInRange(double start, double end);             //  DONE
	// Pre cond:	end > start 
	// Post cond:	Returns a double that is inside [start, end]
	//				Removes everything left in the input stream
	//				Does NOT crash if non-numeric input is entered

int getIntInRange(int start, int end);            //  DONE
	// Pre cond:	end > start
	// Post cond:	Returns the value that is inside the provided range from 'start' to 'end' inclusive
	//				Removes everything left in the input stream
	//				Does NOT crash if non-numeric input is entered

int getPrime();            //  DONE
	// Pre cond:	None
	// Post cond:	Returns a prime number
	//				Does not crash for non-numeric input
	//				Removes everything left in the input stream
	//				Does NOT crash if non-numeric input is entered

int classifyNumber(int number);
	// Pre cond:	Number entered must be a whole number
	// Post cond:	Return values: 0 = perfect, 1 = abundant, -1 = deficient
	//				Removes everything left in the input stream
	//				Does NOT crash if non-numeric input is entered

bool isPrime(int number);
	// Pre cond:	None
	// Post cond:	Returns true if the number entered is prime, otherwise returns false

int getPerfectSquare();            //  DONE
	// Pre cond:	None
	// Post cond:	Returns a perfect square
	//				Removes everything left in the input stream
	//				Does NOT crash if non-numeric input is entered

string getSuffix(int number);            //  DONE
	// Pre cond:	None
	// Post cond:	Returns the ordinal suffix of the number given

double getAverage();
	// Pre cond:	None
	// Post cond:	Returns the average of all the numbers entered by the user except values less than 0
	//				Removes everything left in the input stream
	//				Does NOT crash if non-numeric input is entered

void printASCII(int row);
	// Pre cond:	Variable row must be in the range (1, 4)
	// Post cond:	Prints the ASCII table 'row' per line