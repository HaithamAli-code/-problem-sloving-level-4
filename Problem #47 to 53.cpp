
#include<iostream>
using namespace std;

struct sDate 
{
	int Day = 1;
	int Month = 1;
	int Year = 0;
};

sDate ReadStructDate() 
{
	sDate Date;
	cout << "\n";
	cout << "\nEnter A Day : ";
	cin >> Date.Day;
	cout << "Enter A Month : ";
	cin >> Date.Month;
	cout << "Enter A Year : ";
	cin >> Date.Year;
	return Date;
}

int DayOfWeekOrder(int Day , int Month , int Year) {
	int a = (14 - Month) / 12;
	int y = Year - a;
	int n = Month + 12 * a - 2;

	int DayOfWeek = (Day + y + y / 4 - y / 100 + y / 400 + (31 * n) / 12) % 7;
	return DayOfWeek;
}

int DayOfWeekOrder(sDate Date)
{
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

string CastringDayFromNumberToString(int IndixOfDay)
{
	string NameDay[] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
	};
	return NameDay[IndixOfDay];
}

bool EndOfWeek(sDate Date) 
{
	int IndixOfDay = DayOfWeekOrder(Date);
	return IndixOfDay == 6;
}

bool IsWeekEnd(sDate Date)
{
	int IndixOfDay = DayOfWeekOrder(Date);
	if (IndixOfDay == 6 || IndixOfDay == 5)
	{
		return true;
	}
	return false;
}

bool IsBusinessDay(sDate Date)
{
	//int IndixOfDay = DayOfWeekOrder(Date);
	//if (IndixOfDay == 5 || IndixOfDay == 6)
	//{
	//	return false;
	//}
	//return true;
	return !IsWeekEnd(Date);
}

int DaysUntilTheEndOfWeek(sDate Date)
{
	return 6 - DayOfWeekOrder(Date);
}

bool IsLeaYear(int Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

int NumberOfDaysInMonth(sDate Date)
{
	if (Date.Month < 1 || Date.Month > 12)
		return 0;
	int NumberOfDay[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Date.Month == 2) ? (IsLeaYear(Date.Year) ? 29 : 28) : NumberOfDay[Date.Month - 1];
}

bool DateOneBeforeDateTwo(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false :false;
}

void SwapDate(sDate &Date1, sDate &Date2)
{
	sDate SwapDate;
	
	SwapDate = Date1;
	Date1 = Date2;
	Date2 = SwapDate;
}

bool LastDaYInMonth(sDate Date) {
	return NumberOfDaysInMonth(Date) == Date.Day;
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

int GetDifferenceInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
	int Count = 0 , SwapFlageValue = 1;


	if (!DateOneBeforeDateTwo(Date1, Date2))
	{
		SwapDate(Date1, Date2);
		SwapFlageValue = -1;
	}

	while (DateOneBeforeDateTwo(Date1, Date2))
	{
		Count++;
		Date1 = IncreaseDateByOneDay(Date1);
	}

	return IncludeEndDay ? ++Count * SwapFlageValue : Count * SwapFlageValue;
}

int DaysUntilTheEndOfMonth(sDate Date)
{
	sDate EndOfMonth;
	EndOfMonth.Day = NumberOfDaysInMonth(Date);
	EndOfMonth.Month = Date.Month;
	EndOfMonth.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfMonth, true);
}

int DaysUntilTheEndOfYear(sDate Date)
{
	sDate EndOfYear;
	EndOfYear.Day = 31;
	EndOfYear.Month = 12;
	EndOfYear.Year = Date.Year;

	return GetDifferenceInDays(Date, EndOfYear , true);
}

void PrintScreen(sDate Date)
{
	cout << "\nToday is " << CastringDayFromNumberToString(DayOfWeekOrder(Date)) << " ," << Date.Day << "/" << Date.Month << "/" << Date.Year;
	//---------------------------------
	cout << "\n\nIs It End Of Week ?";
	if (EndOfWeek(Date))
		cout << "\nYes It Is End Of Week.";
	else
		cout << "\nNo Not End Of Week.";
	//---------------------------------
	cout << "\n\nIs It Week End ?";
	if (IsWeekEnd(Date))
		cout << "\nYes It Is A Week End.";
	else
		cout << "\nNo Not Week End.";
	//---------------------------------
	cout << "\n\nIs It Business Day ?";
	if (IsBusinessDay(Date))
		cout << "\nYes It Is Business Day.";
	else
		cout << "\nNo It Is Not Business Day.";
	//---------------------------------
	cout << "\n\nDays Until The End Of Week : " << DaysUntilTheEndOfWeek(Date) << " Day(s).";
	cout << "\nDays Until The End Of Month : " << DaysUntilTheEndOfMonth(Date) << " Day(s).";
	cout << "\nDays Until The End Of Year : "<< DaysUntilTheEndOfYear(Date) << " Day(s).";
}

int main()
{
	sDate Date = ReadStructDate();
	PrintScreen(Date);
	cout << "\n\n\n\n";
	system("pause");
}