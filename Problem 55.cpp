#include<iostream>
using namespace std;

struct sDate
{
	short Day = 1;
	short Month = 1;
	short Year = 0;

};

sDate ReadDate()
{
	sDate Date;
	cout << "Enter a Day : ";
	cin >> Date.Day;
	cout << "Enter a Month : ";
	cin >> Date.Month;
	cout << "Enter a Year : ";
	cin >> Date.Year;

	return Date;
}

short DayOfWeekOrder(short Day , short Month , short Year)
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

string ShortNameDays(sDate Date)
{
	string DayName[] = {"Sun" , "Mon" ,"Tue" , "Wed" , "Thu" , "Fri" , "Sat"};
	return DayName[DayOfWeekOrder(Date)];
}

bool IsWeekEnd(sDate Date)
{
	short OrderDay = DayOfWeekOrder(Date);
	return (OrderDay == 5) || (OrderDay == 6);
}

bool IsBeusinessDays(sDate Date)
{
	return !IsWeekEnd(Date);
}

bool DateOneBeforeDateTwo(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false : false;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Month , short Year)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}
	short DayOfMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
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


sDate CalculateVacationReturnDate(sDate Date , short VacationDays)
{
	short WeekEnd = 0;
	while (IsWeekEnd(Date))
	{
		Date = IncreaseDateByOneDay(Date);
	}
	for (short i = 1; i <= VacationDays + WeekEnd; i++)
	{
		if (IsWeekEnd(Date))
			WeekEnd++;
		Date = IncreaseDateByOneDay(Date);
	}
	while (IsWeekEnd(Date))
	{
		Date = IncreaseDateByOneDay(Date);
	}
	return Date;
}

int main() 
{
	cout << "\nVacation Starts : \n";
	sDate VacationStart = ReadDate();

	cout << "\nPlease Enter a Vacation Days : ";
	short VacationDays;
	cin >> VacationDays;

	VacationStart = CalculateVacationReturnDate(VacationStart, VacationDays);
	cout << "\n\nReturn Date : " << ShortNameDays(VacationStart) << " , " << VacationStart.Day << "/" << VacationStart.Month << "/" << VacationStart.Year;


	cout << endl << system("pause");
	return 0;
}