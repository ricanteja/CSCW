#include "Function.h"

/***********************Function Definition***********************/
/******************************************************************/

void printTitle(ostream &stream)
{
	stream << "\n          Basketball Players and Stats Program               \n"
		   << "     includes files, arrays and ofcourse input validation      \n"
		   << "                      by Ricardo Tejada                    \n\n\n";
}

string getLine(istream &stream)
{
	int position = static_cast<int>(stream.tellg());
	int counter = 0;
	char junk;
	string line;
	

	stream >> junk;
	stream.putback(junk);
	getline(stream, line);

	for (unsigned int i = 0; i < line.size(); i++)
		counter = line[i] == ' ' ? counter + 1 : 0;

	line.resize(line.size() - counter);
	stream.seekg(position);
	return line;
}

string parseName(istream &file)
{
	string name;

	for (char c = file.get(); c != '{' && !file.eof(); c = file.get());

	for (char c = file.get(); c != '}' && !file.eof(); c = file.get())
		name += c;

	return name;
}

int parseInt(istream &file)
{
	int number;

	file >> number;

	return number;
}

int loadArrays(ifstream &file, string sArrayNames[], string sArrayTeams[], int iArrayShotsTried[], int iArrayShotsMade[], double dArraySuccessRate[], int lgSize)
{
	int logicalSize;

	for (logicalSize = 0; logicalSize < lgSize && !file.eof() && getLine(file).size() > 0; logicalSize++)
	{
		sArrayNames[logicalSize] = parseName(file);
		sArrayTeams[logicalSize] = parseName(file);
		iArrayShotsTried[logicalSize] = parseInt(file);
		iArrayShotsMade[logicalSize] = parseInt(file);
		dArraySuccessRate[logicalSize] = (static_cast<double>(iArrayShotsMade[logicalSize]) / iArrayShotsTried[logicalSize]) * 100;

		for (char c = file.get(); c != '\n' && c != '{' && !file.eof(); c = file.get())
		{

		}
	}

	return logicalSize;
}

int getIndexHighestMade(int iArray[], int lgSize)
{
	int index = 0;

	for (int i = 0; i < lgSize; i++)
	{
		if (iArray[i] > iArray[index])
			index = i;
	}

	return index;
}

int getIndexLowestRate(double dArray[], int lgSize)
{
	int index = 0;

	for (int i = 0; i < lgSize; i++)
	{
		if (dArray[i] < dArray[index])
			index = i;
	}

	return index;
}

void printArrays(const string sArrayNames[], const string sArrayTeams[], const int iArrayShotsTried[], const int iArrayShotsMade[], const double dArraySuccessRate[], int lgSize, ostream &stream)
{
	stream << "          Name                 Team         Attempts      Made     Success Rate\n"
		   << "===============================================================================\n";

	for (int i = 0; i < lgSize; i++)
	{
		stream << setw(18) << right << sArrayNames[i]
			   << setw(22) << right << sArrayTeams[i]
			   << setw(10) << right << iArrayShotsTried[i]
			   << setw(12) << right << iArrayShotsMade[i]
			   << setw(12) << setprecision(2) << fixed << right << dArraySuccessRate[i] << "%\n";
	}

	stream << "\n\n\n";
}