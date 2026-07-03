#include<iostream>
using namespace std;

struct sDate {
	int Day = 1;
	int	Month = 1;
	int Year = 0;
};

int ReadPositiveNumber(string message) {
	int number = 0;
	do
	{
		cout << "\n" << message;
		cin >> number;
	} while (number < 1);
	return number;
}

sDate ReadDate() {
	sDate Date;
	Date.Day = ReadPositiveNumber("Enter Day: ");
	Date.Month = ReadPositiveNumber("Enter Month: ");
	Date.Year = ReadPositiveNumber("Enter Year: ");
	return Date;
}

bool DateOneBeforeDateTwo(sDate Date1, sDate Date2) {
	return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) ? true : false : false : false;
}

bool IsLeapYear(int Year) {
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInMonth(int Month, int Year) {
	if (Month < 1|| Month > 12)
	{
		return 0;
	}
	int DayInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return Month == 2? (IsLeapYear(Year) ? 29 : 28) : DayInMonth[Month - 1];
}

bool LastDaYInMonth(sDate Date) {
	return NumberOfDaysInMonth(Date.Month, Date.Year) == Date.Day;
}

bool LastMonthInYear(int Month) {
	return Month == 12;
}

sDate IncreaseDateByOneDay(sDate Date) {
	if (LastDaYInMonth(Date))
	{
		if (LastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

void SwapDates(sDate &Date1, sDate &Date2) {
	sDate Temp = Date1;
	Date1 = Date2;
	Date2 = Temp;
}

int DeffrenceBetweenTowDates(sDate Date1, sDate Date2 , bool includeEndDay) {
	int Day = 0;
	int SwapFlageValue = 1;
	bool Daet1BeforeDate2 = DateOneBeforeDateTwo(Date1, Date2);
	if (Daet1BeforeDate2 == false)
	{
		SwapDates(Date1, Date2);
		SwapFlageValue = -1;
	}
	while (DateOneBeforeDateTwo(Date1, Date2)) {
		Day++;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return includeEndDay ? ++Day * SwapFlageValue : Day * SwapFlageValue;
}

int main() {
	sDate Date1 = ReadDate();
	sDate Date2 = ReadDate();
	int Day = DeffrenceBetweenTowDates(Date1, Date2);
	cout << "Difference between the two dates is: " << Day << " days." << endl;
	system("pause");
}