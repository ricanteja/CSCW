// This program plays with arrays and loops a lot
// arrayloops.exe
// Ricardo Tejada
// November 25 2014

#include <iostream>
#include <fstream>
#include <string>
#include "Function.h"

using namespace std;


/***************** Main Function ****************/
int main()
{
	ofstream myFile;
	string myFileName;

	const int SIZE_FIVE = 139;
	const int SIZE_EVEN = 90;
	const int SIZE_ODD = 100;
	const int SIZE_SQUARES = 42;
	const int SIZE_PRIME = 120;

	int arrayOfFive[SIZE_FIVE];
	int arrayOfEven[SIZE_EVEN];
	int arrayOfOdd[SIZE_ODD];
	int arrayOfSquares[SIZE_SQUARES];
	int arrayOfPrime[SIZE_PRIME];

	printTitle();
	
	//////    
	cout << "\n\nI am about to call loadArrayFive() ...\n";
	loadArrayFive(arrayOfFive, SIZE_FIVE);
	cout << "Finished loading arrayOfFive ...\n";
	cout << "I am about to call printArray() (with the default value for the perLine) ...\n";
	printArray(arrayOfFive, SIZE_FIVE);
	cout << "\n\n";
	system("pause");

	///////
	cout << "\n\nI am about to call loadArrayEven() ...\n";
	loadArrayEven(arrayOfEven, SIZE_EVEN);
	cout << "Finished loading arrayOfEven ...\n";
	cout << "I am about to call printArray() (with 4 perLine) ...\n";
	printArray(arrayOfEven, SIZE_EVEN, 4);
	cout << "\n\n";
	system("pause");

	cout << "\n\nI am about to call loadArrayOdd() ...\n";
	loadArrayOdd(arrayOfOdd, SIZE_ODD);
	cout << "Finished loading arrayOfOdd ...\n";
	cout << "I am about to call printArray() (with 3 perLine) ...\n";
	printArray(arrayOfOdd, SIZE_ODD, 3);
	cout << "\n\n";
	system("pause");

	cout << "\n\nI am about to call loadArraySquares() ...\n";
	loadArraySquares(arrayOfSquares, SIZE_SQUARES);
	cout << "Finished loading arrayOfSquares ...\n";
	cout << "I am about to call printArray() (with 1 perLine) ...\n";
	printArray(arrayOfSquares, SIZE_SQUARES, 1);
	cout << "\n\n";
	system("pause");

	cout << "\n\nI am about to call loadArrayPrime() ...\n";
	loadArrayPrime(arrayOfPrime, SIZE_PRIME);
	cout << "Finished loading arrayOfPrime ...\n";
	cout << "I am about to call printArray() (with 2 perLine) ...\n";
	printArray(arrayOfPrime, SIZE_PRIME, 2);
	cout << "\n\n";
	system("pause");

	cout << "\n\n\nDo you want to output the arrays to a file? ";

	if(getYesNo())
	{
		cout << "\n\nTo what file do you want to output the array? ";
		getline(cin, myFileName);

		myFile.open(myFileName);

		myFile << "\n     This is a lab on completely filled arrays        \n"
			   << "                 by Ricardo Tejada                  \n\n\n";

		myFile << "Here are the first 139 elements of the arrayOfFive two per line:";  // use the const
		printArray(arrayOfFive, SIZE_FIVE, 2, myFile);
		myFile << "\n\n\t**************************************************\n\n";

		myFile << "Here are the first 90 even numbers two per line:";
		printArray(arrayOfEven, SIZE_EVEN, 2, myFile);
		myFile << "\n\n\t**************************************************\n\n";

		myFile << "Here are the first 100 odd number three per lines:";
		printArray(arrayOfOdd, SIZE_ODD, 3, myFile);
		myFile << "\n\n\t**************************************************\n\n";

		myFile << "Here are the first 42 perfect squares number three per lines:";
		printArray(arrayOfSquares, SIZE_SQUARES, 3, myFile);
		myFile << "\n\n\t**************************************************\n\n";

		myFile << "Here are the first 120 prime numbers one per line:";
		printArray(arrayOfPrime, SIZE_PRIME, 1, myFile);

		myFile.close();
	}

	system("pause");
}
