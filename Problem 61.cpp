#include<iostream>
using namespace std;

struct sDate {
	short Day = 1;
	short Month = 1;
	short Year = 1;
};

struct sPeriod
{
	sDate Start;
	sDate End;
};

sDate ReadDate() {
	sDate Date;
	cout << "Enterr a day : ";
	cin >> Date.Day;
	cout << "Enterr a month : ";
	cin >> Date.Month;
	cout << "Enterr a year : ";
	cin >> Date.Year;
	return Date;
}

sPeriod ReadPeriod() {
	sPeriod Period;
	cout << "\nVacation Starts:\n";
	Period.Start = ReadDate();
	cout << "\nVacation Ends:\n";
	Period.End = ReadDate();
	return Period;
}

short DayOfWeekOrder(short Day , short Month , short Year) {
	short A, Y, N , D;
	A = (14 - Month) / 12;
	Y = Year - A;
	N = Month + 12 * A - 2;

	D= (Day + Y + Y / 4 - Y / 100 + Y / 400 + (31 * N) / 12) % 7;
	return D;
}

short DayOfWeekOrder(sDate Date) {
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string ShortNameDays(sDate Date) {
	string NameDays[7] = {"Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat"};
	return NameDays[DayOfWeekOrder(Date)];
}

bool IsLeapYear(short Year) {
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDayInMonth(sDate Date) {
	if (Date.Month < 1 || Date.Month >12) {
		return 0;
	}
	short NumberOfDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	return (Date.Month == 2) ? (IsLeapYear(Date.Year) ? 29 : 28) : NumberOfDays[Date.Month - 1];
}

bool DateOneBeforeDateTwo(sDate Date1 , sDate Date2) {
	return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false : false;

}

bool IsWeekEnd(sDate Date) {
	short OrderDay = DayOfWeekOrder(Date);
	return (OrderDay == 5) || (OrderDay == 6);
}

bool IsBeusinessDays(sDate Date) {
	return !IsWeekEnd(Date);
}

bool LastDayInMonth(sDate Date) {
	return (NumberOfDayInMonth(Date) == Date.Day);
}

bool LastMonthInYear(short Month) {
	return (Month == 12);
}
sDate IncreaseDateByOneDay(sDate Date) {
	if (LastDayInMonth(Date))
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

bool DateOneEqualDateTwo(sDate Date1, sDate Date2) {
	return ((Date1.Day == Date2.Day) && (Date1.Month == Date2.Month) && (Date1.Year == Date2.Year));
}

bool DateOneAfterDateTwo(sDate Date1 ,sDate Date2) {
	return (!DateOneBeforeDateTwo(Date1, Date2) && !DateOneEqualDateTwo(Date1, Date2));
}

enum enCompareDate {
	Before = -1,
	Equal = 0,
	After= 1,
};

enCompareDate CompareDateFunction(sDate Date1 , sDate Date2) {
	if (DateOneBeforeDateTwo(Date1 , Date2)) {
		return enCompareDate::Before;
	}
	if (DateOneEqualDateTwo(Date1 , Date2)) {
		return enCompareDate::Equal;
	}
	if (DateOneAfterDateTwo(Date1, Date2)) {
		return enCompareDate::After;
	}
}

bool DateWithInPeriod(sPeriod Period , sDate Date) {
	//if (CompareDateFunction(Date , Period.Start) == enCompareDate::Before || CompareDateFunction(Date,Period.End) == enCompareDate::After) {
	//	return false;
	//}
	//return true;
	return !(CompareDateFunction(Date, Period.Start) == enCompareDate::Before || CompareDateFunction(Date, Period.End) == enCompareDate::After);
}

bool IsOverLap(sPeriod PeriodOne, sPeriod PeriodTwo)
{
	if (CompareDateFunction(PeriodTwo.End, PeriodOne.Start) == enCompareDate::Before || CompareDateFunction(PeriodTwo.Start, PeriodOne.End) == enCompareDate::After)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int LengthPeriod(sPeriod Period) {
	int CountDays = 0;
	while (DateOneBeforeDateTwo(Period.Start , Period.End)) {
		CountDays++;
		Period.Start = IncreaseDateByOneDay(Period.Start);
	}
	return CountDays;
}

short CountOverLapDays(sPeriod Per1 , sPeriod Per2) {
	int Count = 0;
	int LenthPer1 = LengthPeriod(Per1);
	int LenthPer2 = LengthPeriod(Per2);

	if (!IsOverLap(Per1 , Per2))
		return 0;

	if (LenthPer1 < LenthPer2)
	{
		while (DateOneBeforeDateTwo(Per1.Start , Per1.End)) {
			if (DateWithInPeriod(Per2 , Per1.Start))
			{
				Count++;
			}
			Per1.Start = IncreaseDateByOneDay(Per1.Start);
		}
	}
	else
	{
		while (DateOneBeforeDateTwo(Per2.Start  , Per2.End)) {
			if (DateWithInPeriod(Per1, Per2.Start))
			{
				Count++;
			}
			Per2.Start = IncreaseDateByOneDay(Per2.Start);
		}
	}

	return Count;
}

int main() {
	cout << "\nPeriod One :\n";
	sPeriod Per1 = ReadPeriod();
	cout << "\nPeriod Two :\n";
	sPeriod Per2 = ReadPeriod();

	cout << "\n\n\n" << CountOverLapDays(Per1, Per2);




	system("pause>0");
}