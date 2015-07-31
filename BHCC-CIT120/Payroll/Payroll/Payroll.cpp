// The purpose of this program is to take the hours worked and hourly rates of 5 employees and calculate their total pay
// payroll.exe
// Ricardo Antonio Tejada
// September 20 2014

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Variable declerations
	int hours1, hours2, hours3, hours4, hours5;
	double rate1, rate2, rate3, rate4, rate5;
	
	//Title
	cout << "\t" << "This program creates a nicely formatted table" << endl;
	cout << "\t\t\t" << "Solution by" << endl;
	cout << setw(38) << "Ricardo A. Tejada" << endl;

	//Padding
	cout << endl << endl;

	//Get Employee 1 numbers
	cout << "Hours worked Employee #1 [Only whole hours will be credited]: ";
	cin >> hours1; cin.ignore(80, '\n');
	cout << "Hourly pay rate for Employee #1 [not necessarily whole dollars]: ";
	cin >> rate1; cin.ignore(80, '\n');
	cout << endl;

	//Get Employee 2 numbers
	cout << "Hours worked Employee #2 [Only whole hours will be credited]: ";
	cin >> hours2; cin.ignore(80, '\n');
	cout << "Hourly pay rate for Employee #2 [not necessarily whole dollars]: ";
	cin >> rate2; cin.ignore(80, '\n');
	cout << endl;

	//Get Employee 3 numbers
	cout << "Hours worked Employee #3 [Only whole hours will be credited]: ";
	cin >> hours3; cin.ignore(80, '\n');
	cout << "Hourly pay rate for Employee #3 [not necessarily whole dollars]: ";
	cin >> rate3; cin.ignore(80, '\n');
	cout << endl;

	//Get Employee 4 numbers
	cout << "Hours worked Employee #4 [Only whole hours will be credited]: ";
	cin >> hours4; cin.ignore(80, '\n');
	cout << "Hourly pay rate for Employee #4 [not necessarily whole dollars]: ";
	cin >> rate4; cin.ignore(80, '\n');
	cout << endl;

	//Get Employee 5 numbers
	cout << "Hours worked Employee #5 [Only whole hours will be credited]: ";
	cin >> hours5; cin.ignore(80, '\n');
	cout << "Hourly pay rate for Employee #5 [not necessarily whole dollars]: ";
	cin >> rate5; cin.ignore(80, '\n');
	cout << endl;

	//Padding
	cout << endl;

	//Print Table
	cout << setw(16) << right << "Employee#";
	cout << "\t" << right << "Hours";
	cout << setw(16) << right << "Pay Rate";
	cout << setw(16) << right << "Total Pay" << endl;

	cout << setw(62) << right << "========================================================" << endl;

	//Print Employee 1
	cout << setw(12) << right << 1;
	cout << setw(16) << right << hours1;
	cout << setw(10) << right << "$ " << setw(7) << fixed << setprecision(2) << rate1;
	cout << setw(8) << right << "$ " << setw(8) << hours1 * rate1 << endl;

	//Print Employee 2
	cout << setw(12) << right << 2;
	cout << setw(16) << right << hours2;
	cout << setw(10) << right << "$ " << setw(7) << fixed << setprecision(2) << rate2;
	cout << setw(8) << right << "$ " << setw(8) << hours2 * rate2 << endl;

	//Print Employee 3
	cout << setw(12) << right << 3;
	cout << setw(16) << right << hours3;
	cout << setw(10) << right << "$ " << setw(7) << fixed << setprecision(2) << rate3;
	cout << setw(8) << right << "$ " << setw(8) << hours3 * rate3 << endl;

	//Print Employee 4
	cout << setw(12) << right << 4;
	cout << setw(16) << right << hours4;
	cout << setw(10) << right << "$ " << setw(7) << fixed << setprecision(2) << rate4;
	cout << setw(8) << right << "$ " << setw(8) << hours4 * rate4 << endl;

	//Print Employee 5
	cout << setw(12) << right << 5;
	cout << setw(16) << right << hours5;
	cout << setw(10) << right << "$ " << setw(7) << fixed << setprecision(2) << rate5;
	cout << setw(8) << right << "$ " << setw(8) << hours5 * rate5 << endl;
	
	//Print Total
	cout << setw(18) << right << "TOTAL/AVERAGE";
	cout << setw(10) << right << hours1 + hours2 + hours3 + hours4 + hours5;
	cout << setw(10) << right << "$ " << setw(7) << fixed << setprecision(2) << (rate1 + rate2 + rate3 + rate4 + rate5) / 5;
	cout << setw(8) << right << "$ " << setw(8) << (hours1 * rate1) + (hours2 * rate2) + (hours3 * rate3) + (hours4 * rate4) + (hours5 * rate5);
	
	//Padding
	cout << endl << endl;

	system("pause");

	return 0;
}