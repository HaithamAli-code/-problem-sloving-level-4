#include<iostream>
using namespace std;

struct sDate {
	int day = 0;
	int month = 0;
	int year = 0;
};

struct sPeriod {
	sDate Start;
	sDate End;
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

bool LastMonth(short Month) {
	return (Month == 12);
}

bool LastDay(sDate Date) {
	return (NumberOfDayInMonth(Date.month, Date.year) == Date.day);
}

bool Date1BeforeDate2(sDate Date_1, sDate Date_2) {
	return (Date_1.year < Date_2.year) ? true : (Date_1.year == Date_2.year) ? (Date_1.month < Date_2.month) ? true : (Date_1.month == Date_2.month) ? (Date_1.day < Date_2.day) : false : false;
}

sDate IncreaseDateByOneDay(sDate Date) {
	if (LastDay(Date))
	{
		if (LastMonth(Date.month))
		{
			Date.day = 1;
			Date.month = 1;
			Date.year++;
		}
		else
		{
			Date.day = 1;
			Date.month++;
		}
	}
	else
	{
		Date.day++;
	}
	return Date;
}

int GetDifferenceInDays(sDate Date_1, sDate Date_2, bool IncludeEndDay = false) {
	int DaysCount = 0;
	while (Date1BeforeDate2(Date_1, Date_2)) {
		DaysCount++;
		Date_1 = IncreaseDateByOneDay(Date_1);
	}
	return (IncludeEndDay) ? ++DaysCount : DaysCount;
}

int GetPeriodLengthInDay(sPeriod Period1)
{
	return GetDifferenceInDays(Period1.Start, Period1.End, true);
}

sPeriod ReadPeriod()
{
	sPeriod Period;
	Period.Start = ReadDate();
	Period.End = ReadDate();
	return Period;
}

int main() {

	cout << "\nPeriod One : \n";
	sPeriod Period1 = ReadPeriod();

	cout << "\n\n\n\nPeriod Length In Days :" << GetPeriodLengthInDay(Period1);

	system("\npause");
	return 0;
}