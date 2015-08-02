#include <iostream>
using namespace std;

/***************** Function Declerations ****************/
void printTitle(ostream &stream = cout);
//		Pre cond:	stream object must be open for writing (cout by default)
//		Post cond:	Prints the title to the stream object

char getYesNo();                        	//   DONE
//		Pre cond:	None
//		Post cond:	Returns  'Y', 'y', 'N' OR 'n'
//					Clears the input stream buffer

bool isPrime(int number);                        	//   DONE
//		Pre cond:	number >= 2
//		Post cond:	Returns true if number is prime or else returns false

void printArray(const int intArray[], int lg, int perLine = 5, ostream &stream = cout);
//		Pre cond:	perLine > 0
//					lg > 0
//					lg <= the physical size of the array
//					stream object must be open for writing (cout by default)
//		Post cond:	Prints the FIRST LG ELEMENT OF THE array intArray to the "stream"  by perLine per line

void loadArrayFive(int intArray[], int lg);
//		Pre cond:	lg > 0
//					lg <= the physical size of the array
//		Post cond:	Fills array with 5

void loadArrayEven(int intArray[], int lg);
//		Pre cond:	lg > 0
//					lg <= the physical size of the array
//		Post cond:	Fills array with even numbers

void loadArrayOdd(int intArray[], int lg);
//		Pre cond:	lg > 0
//					lg <= the physical size of the array
//		Post cond:	Fills array with odd numbers

void loadArraySquares(int intArray[], int lg);
//		Pre cond:	lg > 0
//					lg <= the physical size of the array
//		Post cond:	Fills array with square numbers

void loadArrayPrime(int intArray[], int lg);
//		Pre cond:	lg > 0
//					lg must be less than the physical size of the array
//		Post cond:	Fills array with prime numbers
