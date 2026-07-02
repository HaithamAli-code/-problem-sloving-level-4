#include<iostream>
using namespace std;

struct sDate {
	int day = 0;
	int month = 0;
	int year = 0;
};

sDate ReadDate() {
	sDate date;
	cout << "Enter day: ";
	cin >> date.day;
	cout << "Enter month: ";
	cin >> date.month;
	cout << "Enter year: ";
	cin >> date.year;
	return date;
}

short IsLeapYear(short year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

short NumberOfDayInMonth(short month, short year) {
	if (month < 1 || month > 12)
		return 0;
	short daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (month == 2 && IsLeapYear(year)) ? 29 : daysInMonth[month - 1];
}

bool LastDay(sDate date) {
	return (NumberOfDayInMonth(date.month, date.year) == date.day);
}

bool LastMonth(sDate date) {
	return (date.month == 12);
}

int main() {
	sDate date = ReadDate();

	if (LastDay(date))
		cout << "\n\nIt's the last day of the month.";
	else
		cout << "\n\nIt's not the last day of the month.";

	if(LastMonth(date))
		cout << "\n\nIt's the last month of the year.";
	else
		cout << "\n\nIt's not the last month of the year.";

	return 0;
}