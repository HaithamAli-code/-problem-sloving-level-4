// 
#include<iostream>
#include<string>
using namespace std;

int ReadNumber(string message)
{
	int number;
	cout << message;
	cin >> number;
	return number;
}

string MonthShortName(short MonthNumber)
{
	string MonthNames[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return MonthNames[MonthNumber - 1];
}

short DayOfWeekOrder(short Year , short Month , short Day)
{
	short a = (14 - Month) / 12;
	short y = Year - a;
	short n = Month + 12 * a - 2;

	short DayOfWeek = (Day + y + y / 4 - y / 100 + y / 400 + (31 * n) / 12) % 7;
	return DayOfWeek;
}

bool IsLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Year , short Month)
{
	if (Month == 2)
		return IsLeapYear(Year) ? 29 : 28;

	int MonthEqual31[7] = { 1, 3, 5, 7, 8, 10, 12 };
	for (short i = 0; i < 7; i++)
	{
		if (Month == MonthEqual31[i])
			return 31;
	}

	return 30;	
}

void PrintMonthCalendar(short Year, short Month)
{
	short current = DayOfWeekOrder(Year, Month, 1);
	short numberOfDays = NumberOfDaysInMonth(Year, Month);

	printf("\n_________________%s_________________\n\n" , MonthShortName(Month));
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	short i;
	for (i = 0; i < current; i++)
		printf("     ");

	for (short j = 1; j <= numberOfDays; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}
}

int main()
{
	short Year = ReadNumber("\nEnter a Year: ");
	short Month = ReadNumber("\nEnter a Month: ");

	PrintMonthCalendar(Year, Month);
}