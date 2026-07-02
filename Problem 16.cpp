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

sDate IncreaseDateByOneDay(sDate Date) {
	if (LastMonth(Date))
	{
		if (LastDay(Date))
		{
			Date.day = 1;
			Date.month = 1;
			Date.year++;
		}
		else
		{
			Date.day++;
		}
	}
	else
	{
		if (LastDay(Date))
		{
			Date.day = 1;
			Date.month++;
		}
		else
		{
			Date.day++;
		}
	}
	return Date;
}

int main() {
	sDate Date = ReadDate();
	Date = IncreaseDateByOneDay(Date);
	cout << "\nNext date is: " << Date.day << "/" << Date.month << "/" << Date.year << endl;
	system("pause");
	return 0;
}