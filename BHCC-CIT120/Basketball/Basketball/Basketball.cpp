#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Function.h"

using namespace std;

int main()
{
	int choice;
	int index;
	
	const int ARRAY_SIZE = 6;
	string sArrayNames[ARRAY_SIZE];
	string sArrayTeams[ARRAY_SIZE];
	int iArrayShotsTried[ARRAY_SIZE];
	int iArrayShotsMade[ARRAY_SIZE];
	double dArraySuccessRate[ARRAY_SIZE];
	int logicalSize;

	string myFileName;
	ifstream myFile;


	printTitle();

	cout << "The physical size of the parallel arrays is " << ARRAY_SIZE << ".\n\n";

	for (choice = 1; choice <= 5; choice++)
	{
		switch (choice)
		{
			case 1: myFileName = "Input File 1.txt"; break;
			case 2: myFileName = "This file does not exist.txt"; break;
			case 3: myFileName = "Random Names.txt"; break;
			case 4: myFileName = "Empty.txt"; break;
			case 5: myFileName = "One Player.txt"; break;
		}

		cout << "\nI will get the data from \"" << myFileName << "\"\n";
		myFile.open(myFileName);

		if (!myFile)
			cout << "\tFailed to open the input file.\n\n";
		else
		{
			cout << "\tFile \"" << myFileName << "\" was successfully connected!\n";
			logicalSize = loadArrays(myFile, sArrayNames, sArrayTeams, iArrayShotsTried, iArrayShotsMade, dArraySuccessRate, ARRAY_SIZE);

			if (logicalSize > 0)
			{
				cout << "There " << (logicalSize == 1 ? "is " : "are ") << logicalSize << " player" << (logicalSize == 1 ? " " : "s ")
					 << "that I was able to read from that file.\n\n";

				cout << "Here they are: \n\n";
				printArrays(sArrayNames, sArrayTeams, iArrayShotsTried, iArrayShotsMade, dArraySuccessRate, logicalSize);

				index = getIndexHighestMade(iArrayShotsTried, logicalSize);
				cout << "The player with the most attempts is " << sArrayNames[index] << "\n"
					 << "\tand he played for the " << sArrayTeams[index] << ".\n";

				index = getIndexLowestRate(dArraySuccessRate, logicalSize);
				cout << "The player with the lowest success rate is " << sArrayNames[index] << "\n"
					 << "\tand he played for the " << sArrayTeams[index] << " and his success rate is " << dArraySuccessRate[index] << ".\n";
			}
			else
			{
				cout << "\nThere are no players in \"" << myFileName << "\".\n";
			}
		}

		myFile.close();
		myFile.clear();

		cout << "\n\t###########################################################\n\n";
		system("pause");
	}

	cout << "\n\nFinished testing 5 input files.\n\n";

	cout << "Hit ENTER to end the program.";
	cin.get();

	return 0;
}