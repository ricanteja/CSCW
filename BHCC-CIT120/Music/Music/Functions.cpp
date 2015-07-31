#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include "Functions.h"

using namespace std;

//******************* Function Definitions *******************//

void printTitle()
{
	cout << "                   Music Library and Stats program                   \n"
		 << "               includes files, switch as a menu, arrays              \n"
		 << "                    and ofcourse input validation                    \n"
		 << "                          by Ricardo Tejada                      \n\n\n";
}

void printMenu()
{
	cout << "Do you want to\n"
		 << "\t[1] open the default music list file or\n"
		 << "\t[2] you want to choose your own?\n"
		 << "\tPlease enter your choice: ";
}

double getNum()
{
	double number;
	
	while(!(cin >> number))
	{
		cout << "\tPlease no inappropriate characters!\n\tTry again: ";
		cin.clear();	cin.ignore(80, '\n');
	}
	cin.ignore(80, '\n');

	return number;
}

int getInt()
{
	double number = getNum();

	while(number != static_cast<int>(number))
	{
		cout << "\tYour number is not an integer!\n\tTry again: ";
		number = getNum();
	}

	return static_cast<int>(number);
}

int getIntInRange(int begin, int end)
{
	int number = getInt();

	while(number < begin && number > end)
	{
		if(number < begin)
			cout << "\tYour number must be greater than or equal to " << begin;
		else
			cout << "\tYour number must be less than or equal to " << end;
		
		cout << "\n\tTry again: ";
		number = getInt();
	}

	return number;
}

string getName(istream &stream, const char delimiter)
{
	char junk;
	int index = 0;
	string buffer;

	stream >> junk;	stream.putback(junk);
	getline(stream, buffer, delimiter);

	for(int i = 0; buffer[i] != '\0'; i++)
		index = buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '.' ? index + 1: 0;

	buffer.resize(buffer.size() - index);

	return buffer;
}

bool checkFileContains(istream &stream, const char delimiter)
{
	bool check = false;
	int curPos = stream.tellg();
	string buffer = getName(stream, '\0');
	
	for(int i = 0; buffer[i] != '\0' && check == false; i++)
		check = buffer[i] == delimiter ? true : false;

	stream.seekg(curPos);

	return check;
}

string parseSongNameData(ifstream &file)
{
	for(char c = file.get(); c != '{' && !file.eof(); c = file.get());

	return getName(file, '}');
}

int parseSongTimeData(ifstream &file)
{
	int time = 0;
	int total = 0;

	file >> time;
	total = 60 * time;

	for (char c = file.get(); c != ':' && !file.eof(); c = file.get());

	file >> time;
	total += time;

	return total;
}

int parseSongLibraryFile(ifstream &file, string sArrayTitle[], string sArrayArtist[], int iArrayLength[], int lg)
{
	int sizeLibrary = 0;

	for(int i = 0; i < lg && checkFileContains(file, '{'); i++)
	{
		sArrayTitle[i] = parseSongNameData(file);
		sArrayArtist[i] = parseSongNameData(file);
		iArrayLength[i] = parseSongTimeData(file);
		sizeLibrary++;
	}

	return sizeLibrary;
}

int calculateTotalLibraryTime(const int iArrayLength[], int lg)
{
	int total = 0;

	for(int i = 0; i < lg; i++)
		total += iArrayLength[i];

	return total;
}

string convertToStandardTime(int time)
{
	int hours;
	int minutes;
	stringstream stream;

	for(hours = 0; time > 3600; hours++)
		time -= 3600;

	for(minutes = 0; time > 60; minutes++)
		time -= 60;

	if(hours > 0)
		stream << setw(2) << setfill('0') << hours << ":";

	stream << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << time;

	return stream.str();
}

int findLongestSong(const int iArrayLength[], int lg)
{
	int index = 0;

	for(int i = 0; i < lg; i++)
		if(iArrayLength[i] > iArrayLength[index])
			index = i;

	return index;
}

int findShortestSong(const int iArrayLength[], int lg)
{
	int index = 0;

	for(int i = 0; i < lg; i++)
		if(iArrayLength[i] < iArrayLength[index])
			index = i;

	return index;
}

void printSongLibrary(const string sArrayTitle[], const string sArrayArtist[], const int iArrayLength[], int lg)
{
	cout << "               Title                     Artist              Duration\n"
		 << "=====================================================================\n";

	for(int i = 0; i < lg; i++)
	{
		cout << setw(26) << right << sArrayTitle[i];
		cout << setw(26) << right << sArrayArtist[i];
		cout << setw(16) << right << convertToStandardTime(iArrayLength[i]) << "\n";
	}
}