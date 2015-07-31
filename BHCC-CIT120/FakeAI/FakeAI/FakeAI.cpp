// This program does things for the user. Good things.
// fakeai.exe
// Ricardo Tejada
// October 21 2014

#include <iostream>
using namespace std;

int main()
{
	bool flag = true;
	char input;
	int power;
	double number1, number2;

	cout << "\n";
	cout << "                   Fake AI Project       \n";
	cout << "                  Individual Project     \n";
	cout << "                  by Ricardo Tejada  \n\n\n";

	cout << "Please enter in English the arithmetic operation you wish to perform.\n";
	cout << "Type control Z or control C to end the program.";


	while (flag)
	{
		cout << "\n\n\tAction: ";

		cin >> input;

		if (input == 'e' || input == 'E')
		{
			flag = false;
			cin.ignore(80, '\n');
		}
		else
		{
			for (char trash; !(cin >> number1); trash = cin.get())
				cin.clear();

			for (char trash; !(cin >> number2); trash = cin.get())
				cin.clear();

			switch (input)
			{
				case ('A') : case('a') : cout << number1 << " + " << number2 << " = " << number1 + number2; break;
				case ('S') : case('s') : cout << number2 << " - " << number1 << " = " << number2 - number1; break;
				case ('M') : case('m') : cout << number1 << " * " << number2 << " = " << number1 * number2; break;
				case ('D') : case('d') : cout << number1 << " / " << number2 << " = " << number1 / number2; break;
				case ('R') : case('r') : 
				{
					power = number2;
					number2 = number1;
					cout << number1 << "^" << power << " = ";

					if (power != 0)
					{
						for (int counter = (power > 0 ? power : -power); counter > 1; counter--)
							number1 = number1 * number2;
						if (power < 0)
							number1 = 1 / number1;
					}
					else
						number1 = 1;

					cout << number1;

					break;
				}
				default : cout << "I do not know how to perform this action.";
			}
		}
	}

	cout << "\n\nAbout to exit. Hit ENTER to terminate.";
	cin.get();
}