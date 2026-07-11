#include<iostream>
using namespace std;

struct sDate
{
	short Day = 1;
	short Month = 1;
	short Year = 1;
};

struct sPeriod {
	sDate Start;
	sDate End;
};

sDate ReadDate() {
	sDate Date;

	cout << "Enter a Day ? ";
	cin >> Date.Day;

	cout << "Enter a Month ? ";
	cin >> Date.Month;

	cout << "Enter a Year ? ";
	cin >> Date.Year;

	return Date;
}

short DayOfWeekOrder(short Day, short Month, short Year)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int n = Month + 12 * a - 2;

	int DayOfWeek = (Day + y + y / 4 - y / 100 + y / 400 + (31 * n) / 12) % 7;
	return DayOfWeek;
}

short DayOfWeekOrder(sDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string ShortNameDays(sDate Date) {
	string DayName[] = { "Sun" , "Mon" ,"Tue" , "Wed" , "Thu" , "Fri" , "Sat" };
	return DayName[DayOfWeekOrder(Date)];
}

bool DateOneBeforeDateTwo(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false : false;
}

bool IsWeekEnd(sDate Date) {
	short DayOfWeek0rder = DayOfWeekOrder(Date);
	return (DayOfWeek0rder == 5 || DayOfWeek0rder == 6);
}

bool IsBeusinessDays(sDate Date) {
	return !(IsWeekEnd(Date));
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month, short Year)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}
	short DayOfMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : DayOfMonth[Month - 1];
}

bool LastDay(sDate Date)
{
	return (NumberOfDaysInMonth(Date.Month, Date.Year) == Date.Day);
}

bool LastMonth(short Month)
{
	return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
	if (LastDay(Date))
	{
		if (LastMonth(Date.Month))
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

bool DateOneEqualDateTwo(sDate Date1, sDate Date2) {
	return ((Date1.Year == Date2.Year) && (Date1.Day == Date2.Day) && (Date1.Month == Date2.Month));
}

bool Date1AfterDate2(sDate Date1 , sDate Date2) {
	return (!DateOneBeforeDateTwo(Date1, Date2) && !DateOneEqualDateTwo(Date1, Date2));
}

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
	int Days = 0;
	while (DateOneBeforeDateTwo(Date1, Date2))
	{
		Days++;
		Date1 = IncreaseDateByOneDay(Date1);
	}
	return IncludeEndDay ? ++Days : Days;
}

short GetPeriodLength(sPeriod Period) {
	return GetDifferenceInDays(Period.Start, Period.End);
}

enum enCompareDate {
	Before = -1,
	Equal = 0,
	After = 1,
};

enCompareDate CompareDateFunction(sDate Date1 , sDate Date2) {
	if (DateOneEqualDateTwo(Date1, Date2))
		return enCompareDate::Equal;
	if (Date1AfterDate2(Date1, Date2))
		return enCompareDate::After;
	if (DateOneBeforeDateTwo(Date1 , Date2))
		return enCompareDate::Before;
}

bool IsOverLap(sPeriod Period1 , sPeriod Period2) {
	if (CompareDateFunction(Period2.Start,Period1.End) == enCompareDate::After || CompareDateFunction(Period2.End, Period1.Start) == enCompareDate::Before)
	{
		return false;
	}
	return true;
}

bool isDateInPeriod(sPeriod Period , sDate Date) {
	return !(CompareDateFunction(Date, Period.Start) == enCompareDate::Before
		||
		CompareDateFunction(Date, Period.End) == enCompareDate::After);
}

short CountOverLapDays(sPeriod Period_1 , sPeriod Period_2) {
	short LengthPer1 = GetPeriodLength(Period_1);
	short LengthPer2 = GetPeriodLength(Period_2);
	short Count = 0;
	
	if (!IsOverLap(Period_1, Period_2))
		return 0;

	if (LengthPer1 < LengthPer2) {
		while (DateOneBeforeDateTwo(Period_1.Start , Period_1.End)) {

			if (isDateInPeriod(Period_2, Period_1.Start))
				Count++;

			Period_1.Start = IncreaseDateByOneDay(Period_1.Start);
		}
	}
	else 
	{
		while (DateOneBeforeDateTwo(Period_2.Start , Period_2.End)) {
			
			if (isDateInPeriod(Period_1, Period_2.Start))
				Count++;

			Period_2.Start = IncreaseDateByOneDay(Period_2.Start);
		}
	}

	return Count;
}

sPeriod ReadPeriod() {
	sPeriod Period;
	cout << "\nStart Period :\n";
	Period.Start = ReadDate();
	cout << "\nEnd Period :\n";
	Period.End = ReadDate();
	return Period;
}

int main() {
	cout << "\nPeriod One :";
	sPeriod Period_1 = ReadPeriod();

	cout << "\nPeriod Two :";
	sPeriod Period_2 = ReadPeriod();

	cout << "\n\n\n" << CountOverLapDays(Period_1, Period_2);
}