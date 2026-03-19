// Leap Year(One Line Of Code)
#include<iostream>
using namespace std;

int ReadYear(){

	int year;
	cout << "Enter a year: ";
	cin >> year;
	return year;
}

bool IsLeapYear(int Year){

	return (Year % 4 == 0 || Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDays(int Year){

	return IsLeapYear(Year) ? 366 : 365;
}

int NumberOfHours(int Year) {

	return NumberOfDays(Year) * 24;
}

int NumberOfMinutes(int Year) {

	return NumberOfHours(Year) * 60;
}

int NumberOfSeconds(int Year) {

	return NumberOfMinutes(Year) * 60;
}

int main()
{
	int Year = ReadYear();

	cout << "\nNumber Of Days : " << NumberOfDays(Year);

	cout << "\nNumber Of Hours : " << NumberOfHours(Year);

	cout << "\nNumber Of Minutes : " << NumberOfMinutes(Year);

	cout << "\nNumber Of Seconds : " << NumberOfSeconds(Year);

	system("pause>0");
	return 0;
}