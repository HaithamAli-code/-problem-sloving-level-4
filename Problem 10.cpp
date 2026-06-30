#include<iostream>	
using namespace std;

short ReadNumber(string Message) {
	short Number;
	cout << "\n" << Message;
	cin >> Number;
	return Number;
}

bool IsLeapYear(short Year) {
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month , short Year) {
	short DayInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : DayInMonth[Month - 1];
}

short CountDayFromBeginOfTheYear(short Day , short Month , short Year) {
	short Count = 0;
	for (short i = 1; i <= Month - 1; i++)
	{
		Count += NumberOfDaysInMonth(i, Year);
	}
	Count += Day;
	return Count;
}

int main() {
	short Year, Month, Day;
	Day = ReadNumber("Enter A Day : ");
	Month = ReadNumber("Enter A Month : ");
	Year = ReadNumber("Enter A Year : ");

	cout << "\n\nNumber of Days from the begining of the year is " << CountDayFromBeginOfTheYear(Day, Month, Year);
}