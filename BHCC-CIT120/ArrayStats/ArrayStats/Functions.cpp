#include <iostream>
#include <iomanip>
#include "Functions.h"

using namespace std;

/*****************************************************************/
//			Function Definition
/*****************************************************************/

void printTitle()
{
	cout << "           This program loads an array of doubles with students' score     \n"
		 << "                 using a negative value as the loop's sentinel             \n"
		 << "                           calculate basic statistics                      \n"
		 << "               setting physical size to 30 and default per line 5          \n"
		 << "                   setting physical size to 3 for easy testing             \n"
		 << "                                by Ricardo Tejada                      \n\n\n";
}

void printArray(const double dArray[], int lg, int perLine)	                         	//   DONE
{
	for (int c = 0; c < lg; c++)
		cout << (c % perLine == 0 ? "\n" : "") << setw(8) << right << dArray[c];
}

double getNum()
{
	double number;

	while (!(cin >> number))
	{
		cout << "No letters please! Try again: ";
		cin.clear(); cin.ignore(80, '\n');
		cin >> number;
	}
	cin.ignore(80, '\n');

	return number;
}

double getScore()
{
	double number = getNum();

	while (number > 100)
	{
		cout << "Invalid score. Score cannot be greater than 100. Try again: ";
		number = getNum();
	}

	return number;
}

int getIndexHighest(const double dArray[], int lg)
{
	double highest = 0;
	int index = 0;
	for(int i = 0; i < lg; i++)
		if(highest < dArray[i])
		{
			highest = dArray[i];
			index = i;
			i = 0;
		}

	return index;
}

int getIndexLowest(const double dArray[], int lg)
{
	double highest = 100;
	int index = 0;
	for(int i = 0; i < lg; i++)
		if(highest > dArray[i])
		{
			highest = dArray[i];
			index = i;
			i = 0;
		}

	return index;
}

double getArrayAverage(const double dArray[], int lg)
{
	double total = 0;

	for(int i = 0; i < lg; i++)
	{
		total += dArray[i];
	}

	return total / lg;
}

int fillArrayScore(double dArray[], int lg)
{
	double number;
	int i = 0;

	do
	{
		cout << "Enter score for student " << i + 1 << ": ";
		number = getScore();
		dArray[i] = number;
		i += number >= 0 ? 1 : 0;
	} while (number >= 0 && i < lg);

	if (i == lg)
		cout << "Array FULL! Cannot fit any more scores.";

	return i;
}