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

struct sDate {
	short Day = 0;
	short Month = 0;
	short Year = 0;
};

sDate GetDateFromOrderInYear(short OrderInYear , short Year) {

	short RemainingDays = OrderInYear;
	short MonthDaays = 0;

	sDate Date;
	Date.Year = Year;
	Date.Month = 1;

	while (true) {
		MonthDaays = NumberOfDaysInMonth(Date.Month, Year);
		if (RemainingDays > MonthDaays)
		{
			RemainingDays -= MonthDaays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}
	return Date;
}
int main() {
	short Year, Month, Day;
	Day = ReadNumber("Enter A Day : ");
	Month = ReadNumber("Enter A Month : ");
	Year = ReadNumber("Enter A Year : ");
	short OrderInYear = CountDayFromBeginOfTheYear(Day, Month, Year);

	cout << "\n\nNumber of Days from the begining of the year is " << OrderInYear;

	sDate Date;
	Date = GetDateFromOrderInYear(OrderInYear, Year);

	cout << "\n\nDate For[" << OrderInYear << "] is : " << Date.Day << "/" << Date.Month << "/" << Date.Year;
}