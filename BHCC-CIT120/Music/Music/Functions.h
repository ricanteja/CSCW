#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//******************* Function Declerations *******************//

void printTitle();
//		Pre cond:	None
//		Post cond:	Prints the title to the screen

void printMenu();
//		Pre cond:	None
//		Post cond:	Prints the menu to the screen

double getNum();
//		Pre cond:	None
//		Post cond:	Returns a number from the user
//					Will not crash on non-numeric input
//					Clears the input stream buffer

int getInt();
//		Pre cond:	None
//		Post cond:	Returns a whole number from the user
//					Will not crash on non-numeric input
//					Clears the input stream buffer

int getIntInRange(int begin, int end);
//		Pre cond:	end > begin
//		Post cond:	Returns a whole number in the range [begin, end]
//					Will not crash on non-numeric input
//					Clears the input stream buffer

string getName(istream &stream = cin, const char delimiter = '\n');
//		Pre cond:	stream must be open for reading
//		Post cond:	Returns a string containing all the individual words from the input stream buffer
//					Ignores initial and trailing white space
//					Moves the file pointer if using files

bool checkFileContains(istream &stream, const char delimiter);
//		Pre cond:	stream must be open for reading
//		Post cond:	Returns true if the file contains the delimiter
//					Does not move the file pointer

string parseSongNameData(ifstream &file);
//		Pre cond:	file must be open for reading
//		Post cond:	Reads and returns the name from the input file
//					Ignores '{' and '}' characters from the name
//					Moves the file pointer

int parseSongTimeData(ifstream &file);
//		Pre cond:	file must be open for reading
//		Post cond:	Reads and returns the length of a song from the input file in seconds
//					Moves the file pointer

int parseSongLibraryFile(ifstream &file, string sArrayTitle[], string sArrayArtist[], int iArrayLength[], int lg);
//		Pre cond:	file must be open for reading
//					0 < lg <= physical size
//		Post cond:	Returns the logical size of the song library
//					sArrayTitle will be populated with the song title data
//					sArrayArtist will be populated with the artist name data
//					sArrayLength will be populated with the duration of the songs in seconds
//					Moves the file pointer

int calculateTotalLibraryTime(const int iArrayLength[], int lg);
//		Pre cond:	0 < lg <= physical size
//		Post cond:	Returns the total sum of the times stored in the array in seconds

string convertToStandardTime(int totalTime);
//		Pre cond:	None
//		Post cond:	Returns the string representing totalTime in standard form

int findLongestSong(const int iArrayLength[], int lg);
//		Pre cond:	0 < lg <= physical size
//		Post cond:	Returns the index to the longest song in the array sArrayLength

int findShortestSong(const int iArrayLength[], int lg);
//		Pre cond:	0 < lg <= physical size
//		Post cond:	Returns the index to the shortest song in the array sArrayLength

void printSongLibrary(const string sArrayTitle[], const string sArrayArtist[], const int iArrayLength[], int lg);
//		Pre cond:	0 < lg <= physical size
//		Post cond:	Prints the whole library (song title, song artist, song duration) up to index lg
//					Song duration is converted to a string in standard form when printed
