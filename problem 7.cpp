// Day Name
#include<iostream>
using namespace std;

int ReadNumber(string Message)
{
	int Number;
	cout << Message;
	cin >> Number;
	return	Number;
}

short DayOfWeekOrder(short Year , short Month , short Day)
{
	short a = (14 - Month) / 12;
	short Y = Year - a;
	short M = Month + 12 * a - 2;
	
	short DayOfWeek = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + (31 * M / 12)) % 7;
	return DayOfWeek;
}

string DayShortName(short IndexOfDay)
{
	string DaysOfWeek[] = {"Sunday" , "Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday"  "Saturday"};

	return DaysOfWeek[IndexOfDay];
}

void PrintScreen(short Year, short Month, short Day)
{
	cout << "\nDate: " << Day << "/" << Month << "/" << Year;

	short IndexOfDay = DayOfWeekOrder(Year, Month, Day);

	cout << "\nDay Order: " << IndexOfDay;
	cout << "\nIs: " << DayShortName(IndexOfDay);
}

int main()
{
	short Year = ReadNumber("\nEnter Year: ");
	short Month = ReadNumber("\nEnter Month: ");
	short Day = ReadNumber("\nEnter Day: ");

	PrintScreen(Year, Month, Day);
}

