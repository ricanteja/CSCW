#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

/***********************Function Decleration***********************/
/******************************************************************/
void printTitle(ostream &stream = cout);
//		Pre cond:	None
//		Post cond:	Prints the title to the output stream

string getLine(istream &stream = cin);
//		Pre cond:	The input stream must be open for reading
//		Post cond:	Returns the line and removes initial and trailing white space

string parseName(istream &file);
//		Pre cond:	The input file must be open for reading
//		Post cond:	Returns a string containing the whole name including white space
//					File pointer moves after reading from file

int parseInt(istream &file);
//		Pre cond:	The input file must be open for reading
//		Post cond:	Returns an integer read from the file
//					File pointer moves after reading from file

int loadArrays(ifstream &file, string sArrayNames[], string sArrayTeams[], int iArrayShotsTried[], int iArrayShotsMade[], double dArraySuccessRate[], int lgSize);
//		Pre cond:	The input file must be open for reading
//					lgSize must be <= the physical size of the arrays
//		Post cond:	Returns the logical size of the array
//					The arrays are populated with the appropriate data from the file
//					File pointer moves after reading from file

int getIndexHighestMade(int iArray[], int lgSize);
//		Pre cond:	lgSize must be <= the physical size of the array
//		Post cond:	Returns the index to the highest number in the array

int getIndexLowestRate(double dArray[], int lgSize);
//		Pre cond:	lgSize must be <+ the physical size of the array
//		Post cond:	Returns the index to the lowest number in the array

void printArrays(const string sArrayNames[], const string sArrayTeams[], const int iArrayShotsTried[], const int iArrayShotsMade[], const double dArraySuccessRate[], int lgSize, ostream &stream = cout);
//		Pre cond:	lgSize must be <= the physical size of the arrays
//		Post cond:	Prints the arrays nicely formated to the out stream