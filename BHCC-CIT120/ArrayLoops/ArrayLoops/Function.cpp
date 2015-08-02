#include <iostream>
#include "Function.h"

using namespace std;

/***************** Function Definitions ****************/
void printTitle(ostream &stream)	                                      	//   DONE
{
	stream << "\n\t  This is a lab on  completely filled arrays     \n"
		<< "\t                by Ricardo Tejada                 \n";
}

char getYesNo()	                                     	//   DONE
{
	char choice;

	cin >> choice;	cin.ignore(80, '\n');

	while ((choice != 'Y' && choice != 'y') && (choice != 'N' && choice != 'n'))
	{
		cout << "Please type Y or N. Try again: ";
		cin >> choice;	cin.ignore(80, '\n');
	}

	return choice;
}

bool isPrime(int number)                                 	//   DONE
{
	for (int j = 2; j < number - 1; j++)
		if (number % j == 0)
			return false;
		
	return true;
}

void printArray(const int intArray[], int lg, int perLine, ostream &object)	                         	//   DONE
{
	for (int c = 0; c < lg; c++)
		object << (c % perLine == 0 ? "\n" : "\t") << intArray[c];
}

void loadArrayFive(int intArray[], int lg)	                         	//   DONE
{
	for (int c = 0; c < lg; c++)
		intArray[c] = 5;
}

void loadArrayEven(int intArray[], int lg)                        	//   DONE
{
	for (int c = 0; c < lg; c++)
		intArray[c] = c + c + 2;
}

void loadArrayOdd(int intArray[], int lg)                            	//   DONE
{
	for (int c = 0; c < lg; c++)
		intArray[c] = c + c + 1;
}

void loadArraySquares(int intArray[], int lg)                            	//   DONE
{
	for (int c = 0; c < lg; c++)
		intArray[c] = (c + 1) * (c + 1);
}

void loadArrayPrime(int intArray[], int lg)                            	//   DONE
{
	for (int c = 0, i = 2; c < lg; i++)
		if (isPrime(i))
		{
			intArray[c] = i;
			c++;
		}
}