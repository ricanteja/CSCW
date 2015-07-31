#include <iostream>

using namespace std;

/*****************************************************************/
//			Function Declerations
/*****************************************************************/

void printTitle();
//		Pre cond:	None
//		Post cond:	Prints the title to the screen

void printArray(const double dArray[], int lg, int perLine = 5);                    	//   DONE
//		Pre cond:	perLine > 0
//					0 < lg <= the physical size of the array
//					stream object must be open for writing (cout by default)
//		Post cond:	Prints the FIRST LG ELEMENT OF THE array intArray to the "stream"  by perLine per line

double getNum();
//		Pre cond:	None
//		Post cond:	Returns a number from the user
//					Will not crash on non numeric input
//					Clears the input stream object

double getScore();
//		Pre cond:	None
//		Post cond:	Returns a number less than 100
//					Will not crash on non numeric input
//					Clears the input stream object

int getIndexHighest(const double dArray[], int lg);
//		Pre cond:	0 < lg <= the physical size of the array
//		Post cond:	Returns the index of the highest value in the array

int getIndexLowest(const double dArray[], int lg);
//		Pre cond:	0 < lg <= the physical size of the array
//		Pre cond:	

double getArrayAverage(const double dArray[], int lg);
//		Pre cond:	0 < lg <= the physical size of the array
//		Post cond:	Returns the average of all the elements up to lg in the array

int fillArrayScore(double dArray[], int lg);
//		Pre cond:	0 < lg <= the physical size of the array
//		Post cond:	Returns the logical size of the array
//					Fills the array from index 0 to lg with user entered scores