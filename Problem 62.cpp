#include<iostream>
using namespace std;

struct sDate {
	short Day = 1;
	short Month = 1;
	short Year = 1;
};

sDate ReadDate() {
	sDate Date;

	cout << "Enter a Day: ";
	cin >> Date.Day;
	cout << "Enter a Month: ";
	cin >> Date.Month;
	cout << "Enter a Year: ";
	cin >> Date.Year;

	return Date;
}

bool IsLeapYear(short Year) {
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month , short Year) {
	if (Month < 1 || Month > 12)
		return 0;
	short Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : Days[Month - 1];
}

bool LastDayInMonth(sDate Date) {
	return (NumberOfDaysInMonth(Date.Month, Date.Year) == Date.Day);
}

bool ValideDateFunction(sDate Date) {
	
	if (Date.Day < 1 || Date.Day > 31)
		return false;

	if (Date.Month < 1 || Date.Month > 12)
		return false;

	if (Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
		return false;

	return true;
}

int main() {
	sDate Date = ReadDate();
}