#include "Function.h"

/****************************Function Definitions****************************/

void printTitle()              //    DONE
{
	cout << "\n"
		 << "\t        Monster Function Lab (while, for, switch)     \n"
		 << "\t           includes review of switch as a menu        \n"
		 << "\t      function reusability and \"slave\" functions    \n"
		 << "\t                    by Ricardo Tejada               \n\n";
}

void printMenu()             //    DONE
{
	cout << "\n"
		 << "\t1] Average a set of non-negative numbers\n"
		 << "\t2] Enter a number in a given range\n"
		 << "\t3] Enter a letter\n"
		 << "\t4] Enter an integer\n"
		 << "\t5] Enter a prime number\n"
		 << "\t6] Classify a number as deficient, perfect, or abundant\n"
		 << "\t7] Print the ASCII table\n"
		 << "\t8] End the program\n\n"
		 << "Please enter your choice: ";
}

double getNum()            //    DONE
{
	double number;

	while (!(cin >> number))
	{
		cin.clear(); cin.ignore(80, '\n');
		cout << "\tPlease no inapropriate characters!\n\tTry again: ";
	}

	cin.ignore(80, '\n');

	return number;
}

int getInt()                      //    DONE
{
	double number = getNum();

	while (number != static_cast<int>(number))
	{
		cout << "\tYour number is not an integer!\n\tTry again: ";
		number = getNum();
	}

	return static_cast<int>(number);
}

double getPos()                          //    DONE
{
	double number;

	cin >> number;   cin.ignore(80, '\n');

	while (number < 0)
	{
		cout << "Please enter a positive number: ";
		cin >> number;   cin.ignore(80, '\n');
	}

	return number;
}

double getPosNum()                 //    DONE
{
	double number = getNum();

	while (number < 0)
	{
		cout << "Please enter a positive number: ";
		number = getNum();
	}

	return number;
}

double getNumGreater(double floor)             //    DONE
{
	double number = getNum();

	while (number < floor)
	{
		cout << "\tNumber must be greater than " << floor << "\n\tTry again: ";
		number = getNum();
	}

	return number;
}

int getIntGreater(double floor)             //    DONE
{
	int number = getInt();

	while(number < floor)
	{
		cout << "\tNumber must be greater than " << floor << "\n\tTry again: ";
		number = getInt();
	}

	return number;
}

int getMultOfNum(int factor)                     //    DONE
{
	double number = getNum();

	while ( static_cast<int>(number) % factor != 0 || number != static_cast<int>(number))
	{
		cout << "Please enter a multiple of " << factor << ": ";
		number = getNum();
	}

	return static_cast<int>(number);
}

char getLetter()                           //    DONE
{
	char letter;

	cin >> letter; cin.ignore(80, '\n');

	while ((letter < 'A' || letter > 'Z') && (letter < 'a' || letter > 'z'))
	{
		cout << letter << " is not a letter!\nPlease enter a letter: ";
		cin >> letter; cin.ignore(80, '\n');
	}

	return letter;
}

double getInRange(double start, double end)           //    DONE
{
	cout << "Please enter a number between " << start << " and " << end << ": ";
	double number = getNum();

	while (number < start || number > end)
	{
		if(number > end)
			cout << "\tYour number must be less than or equal to " << end << "\n";
		else
			cout << "\tYour number must be greater than or equal to " << start << "\n";
		
		cout << "\tTry again: ";
		number = getNum();
	}

	return number;
}

int getIntInRange(int start, int end)             //    DONE
{
	int number = getInt();

	while (number < start || number > end)
	{
		if(number > end)
			cout << "\tYour number must be less than or equal to " << end << "\n";
		else
			cout << "\tYour number must be greater than or equal to " << start << "\n";

		cout << "\tTry again: ";
		number = getInt();
	}

	return number;
}

bool isPrime(int number)             //    DONE
{
	for (int i = 2; i < number - 1; i++)
		if (number % i == 0)
			return false;

	return true;
}

int getPrime()                //    DONE
{
	int number = getIntGreater(2);

	while (!isPrime(number))
	{
		cout << number << " is not prime. Try again: ";
		number = getIntGreater(2);
	}

	return number;
}

int classifyNumber(int number)             //    DONE
{
	int sum = 0;

	for(int i = 1; i < number; i++)
		if(number % i == 0)
			sum += i;


	return number == sum ? 0 : number < sum ? 1 : -1;
}

int getPerfectSquare()             //    DONE
{
	double number = getIntGreater(0);

	while (sqrt(number) != static_cast<int>(sqrt(number)))
	{
		cout << number << " is NOT a perfect square. Try again: ";
		number = getNum();
	}

	return static_cast<int>(number);
}

string getSuffix(int number)
{
	if (number % 100 < 10 || number % 100 > 20)
		return (number % 10 == 1 ? "st" : number % 10 == 2 ? "nd" : number % 10 == 3 ? "rd" : "th");
	else
		return "th";
}

double getAverage()
{
	double number, total = 0;
	int count = 0;

	cout << "Please enter the " << count << getSuffix(count) << " number: ";
	number = getNum();

	while (number > 0)
	{
		total += number;
		count++;

		cout << "Please enter the " << count << getSuffix(count) << " number: ";
		number = getNum();
	}

	return count < 1 ? -1 : total /= count;
}

void printASCII(int row)                                       // DONE
{
	for (unsigned int c = 0; c < 256; c++)
	{
		cout << (c % row == 0 ? "\n" : "\t||") << setw(4) << c << "\t";

		switch (c)
		{
			case '\0': cout << "NULL"; break;
			case '\a': cout << "\\a"; break;
			case '\b': cout << "\\b"; break;
			case '\t': cout << "\\t"; break;
			case '\n': cout << "\\n"; break;
			case '\v': cout << "\\v"; break;
			case '\r': cout << "\\r"; break;
			default: cout << static_cast<char>(c);
		}
	}
}
