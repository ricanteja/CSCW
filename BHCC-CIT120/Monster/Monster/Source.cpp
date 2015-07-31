// This program is a monster (or so I've heard)
// monster.exe
// Ricardo Tejada
// November 14 2014

#include "Function.h"

int main()   //   main is DONE
{
	int choice = 0;
	int integer1;
	char letter;
	double number1, number2, result;

	while (choice != 8)
	{
		printTitle();
		printMenu();

		choice = getIntInRange(1, 8);

		switch (choice)
		{
			case 1:           //    DONE
				result = getAverage();
				if (result > 0)
					cout << "The average of the number is " << result;
				else
					cout << "There is no data to get the average of.";
				cout << "\n\n\n\n\n";
				break;
			case 2:         //    DONE
				cout << "Start?: ";
				number1 = getNum();
				cout << "End?: ";
				number2 = getNumGreater(number1);
				result = getInRange(number1, number2);
				cout << "Your number is " << result;
				break;
			case 3:         //    DONE
				cout << "Please enter a letter of the alphabet: ";
				letter = getLetter();
				cout << "Your letter is " << letter;
				break;
			case 4:         //    DONE
				cout << "Please enter an integer: ";
				integer1 = getInt();
				cout << "Your number is " << integer1;
				break;
			case 5:        //    DONE
				cout << "Please enter a prime number: ";
				integer1 = getPrime();
				cout << integer1 << " is prime";
				break;
			case 6:       //    DONE
				cout << "Please enter a number: ";
				integer1 = getIntGreater(0);
				cout << integer1 << " is ";
				switch(classifyNumber(integer1))
				{
					case 0: cout << "perfect"; break;
					case -1: cout << "deficient"; break;
					case 1: cout << "abundant"; break;
				}
				break;
			case 7:        //    DONE
				cout << "How many characters would you like to print per line? [1, 4]: ";
				integer1 = getIntInRange(1, 4);
				printASCII(integer1);
				break;
			case 8:        //    DONE
				cout << "\nThank you for using our program.";
				break;
		}
		cout << "\n\n";
		system("pause");
		system("cls");
	}

	return 0;
}