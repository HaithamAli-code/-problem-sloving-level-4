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

sDate Increase10Days(sDate Date) {
	for (short i = 0; i < 10; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

sDate IncreaseOneWeek(sDate Date) {
	for (short i = 0; i < 7; i++)
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

sDate IncreaseDateXWeek(int Weeks , sDate Date) {
	for (short i = 0; i < Weeks; i++)
	{
		Date = IncreaseOneWeek(Date);
	}
}

sDate IncreaseOneMonth(sDate Date) {
	if (Date.Month == 12)
	{
		Date.Day = 1;
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}
	int DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
	if (Date.Day > DaysInMonth)
	{
		Date.Day = DaysInMonth;
	}
	return Date;
}

sDate IncreaseDateXMonth(int Months, sDate Date) {
	for (short i = 0; i < Months; i++)
	{
		Date = IncreaseOneMonth(Date);
	}
	return Date;
}

sDate IncreaseOneYear(sDate Date) {
	Date.Year++;
	return Date;
}

sDate IncreaseDateXYear(int Years, sDate Date) {
	for (short i = 0; i < Years; i++)
	{
		Date = IncreaseOneYear(Date);
	}
	return Date;
}

sDate IncreaseOneDecade(sDate Date) {
	return IncreaseDateXYear(10, Date);
}

sDate IncreaseXDecade(int decades, sDate Date) {
	for (short i = 0; i < decades; i++)
	{
		Date = IncreaseOneDecade(Date);
	}
	return Date;
}

void PrintDate(sDate Date) {
	Date = IncreaseDateByOneDay(Date);
	cout << "[1]-Adding One Day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = Increase10Days(Date);
	cout << "[2]-Adding Ten Days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseOneWeek(Date);
	cout << "[3]-Adding One Week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateXWeek(10, Date);
	cout << "[4]-Adding Ten Weeks is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseOneMonth(Date);
	cout << "[5]-Adding One Month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateXMonth(10, Date);
	cout << "[6]-Adding Ten Months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseOneYear(Date);
	cout << "[7]-Adding One Year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseDateXYear(10, Date);
	cout << "[8]-Adding Ten Years is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseOneDecade(Date);
	cout << "[9]-Adding One Decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
	Date = IncreaseXDecade(10, Date);
	cout << "[10]-Adding Ten Decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

int main() {
	sDate Date1 = ReadDate();
	PrintDate(Date1);
}