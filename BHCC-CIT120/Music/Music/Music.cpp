#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "Functions.h"

using namespace std;

int main()
{
	const int SIZE_ARRAY = 10;

	string arraySongTitle[SIZE_ARRAY];
	string arraySongArtist[SIZE_ARRAY];
	int arraySongLength[SIZE_ARRAY];

	int lgSize;
	int choice;
	int totalDuration;
	int indexLongest;
	int indexShortest;

	ifstream myFile;
	string myFileName;

	//Print the title and the menu
	printTitle();
	printMenu();

	//Get the users choice
	choice = getIntInRange(1, 2);

	switch (choice)
	{
		//We want to open the standard file
		case 1:
			myFileName = "my songs.txt";
			myFile.open(myFileName);
			
			if (!(myFile))
			{
				cout << "Failed to open the input file.\n";
				system("pause");

				return 0;
			}
			break;
		//We want to open our own file
		case 2:
			cout << "\nWhat file contains your song collection?\n"
				 << "\tI will remove any initial or trailing white space: ";

			myFileName = getName();
			myFile.open(myFileName);

			while (!(myFile))
			{
				cout << "Could not open input file \"" << myFileName << "\".\n"
					<< "I will try the same file name with a \".txt\" extension.\n";

				myFileName += ".txt";
				myFile.open(myFileName);

				if (!(myFile))
				{
					cout << "Could not open input file \"" << myFileName << "\" either.\n\n"
						 << "\tPlease provide a different file name: ";

					myFileName = getName();
					myFile.open(myFileName);
				}
			}
			break;
	}

	//Opening the file was successful
	cout << "\n\n\t\t###################################################\n\n"
		<< "File \"" << myFileName << "\" was successfully connected!\n";

	//Get the logical size of the music library and parse the file into various arrays
	lgSize = parseSongLibraryFile(myFile, arraySongTitle, arraySongArtist, arraySongLength, SIZE_ARRAY);

	if (lgSize > 0)
	{
		cout << "\nYou own " << lgSize << " song" << (lgSize != 1 ? "s." : ".") << "\n"
			<< "\nHere they are:\n";

		//Print the library
		printSongLibrary(arraySongTitle, arraySongArtist, arraySongLength, lgSize);


		//Calculate the total length of the library in seconds
		totalDuration = calculateTotalLibraryTime(arraySongLength, lgSize);
		//Print it in seconds and then in standard form
		cout << "\n\nRaw total duration is: " << totalDuration << "\n"
			<< "The total duration of all the songs in your library is " << convertToStandardTime(totalDuration) << "\n\n";


		//Find the index of the longest song in the library
		indexLongest = findLongestSong(arraySongLength, lgSize);
		//... and print it's name and it's artist
		cout << "The longest song is " << arraySongTitle[indexLongest] << " by " << arraySongArtist[indexLongest] << ".\n";

		//Find the index of the shortest song in the library
		indexShortest = findShortestSong(arraySongLength, lgSize);
		//... and print it's name and it's artist
		cout << "The shortest song is " << arraySongTitle[indexShortest] << " by " << arraySongArtist[indexShortest] << ".\n\n";
	}
	else
		cout << "\nYou do not own any songs.\n\n";

	system("pause");
}