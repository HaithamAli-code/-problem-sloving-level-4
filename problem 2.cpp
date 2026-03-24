// This program determines if a given year is a leap year or not.
#include<iostream>
using namespace std;

int ReadYear()
{
	int year;
	cout << "Enter a year: ";
	cin >> year;
	return year;
}

bool IsLeapYear(int Year)
{
	if(Year % 400 == 0)
		return true;
	else if(Year % 100 == 0)
		return false;
	else if(Year % 4 == 0)
		return true;
	else
		return false;
}

int main()
{
	int Year = ReadYear();

	if (IsLeapYear(Year))
		cout << "\nThe year " << Year << " is a leap year." << endl;
	else
		cout << "\nThe year " << Year << " is not a leap year." << endl;
}