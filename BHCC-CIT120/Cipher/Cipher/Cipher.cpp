#include <iostream>
using namespace std;

int main()
{
	int value;
	char array[80];

	while (true)
	{
		cout << "What is the cipher value: ";
		cin >> value; cin.ignore(80, '\n');
		cout << "Give me a phrase to decypher :";
		cin.getline(array, 80);

		for (int c = 0; array[c] != '\0'; c++)
			array[c] = array[c] + value;

		cout << "The decoded phrase is: \"" << array << "\"\n\n\n";
	}
}