#include <iostream>
#include <iomanip>
#include "Functions.h"

using namespace std;

int main()
{
	const int SCORE_SIZE = 30;
	int scoreSize = 0;
	double scoreArray[SCORE_SIZE];

	printTitle();

	while(true)
	{
		cout << "Enter the students' score. Enter a negative value to stop.\n\n";
		scoreSize = fillArrayScore(scoreArray, SCORE_SIZE);

		cout << "\n\n\tDone loading the scores\n\tLogical size is: " << scoreSize << "\n\n";
		system("pause");

		cout << "\n\nNow printing the scores and stats:";
		if(scoreSize > 0)
		{
			printArray(scoreArray, scoreSize);
			cout << "\n\n\t*** The highest score is: " << scoreArray[getIndexHighest(scoreArray, scoreSize)];
			cout << "\n\t*** The lowest  score is: " << scoreArray[getIndexLowest(scoreArray, scoreSize)];
			cout << "\n\t*** The average score is: " << getArrayAverage(scoreArray, scoreSize);
		}
		else
			cout << "\n\tThe array is empty!";

		cout << "\n\t\t---------------------------------\n\n\n";
		system("pause");
	}

	return 0;
}