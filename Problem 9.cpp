#include<iostream>
using namespace std;

short ReadNumber(string message) {
	short Number;
	cout << "\n" << message;
	cin >> Number;
	return Number;
}

string CastingMonthFromNumberToString(short Month) {
	string Months[] = { "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , "Jul" , "Aug" , "Sep" ,"Oct" , "Nov" , "Dec" };
	return Months[Month - 1];
}

bool LeapYear(short Year) {
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short DaysOfMonth(short Year ,  short Month) {
	short Months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (LeapYear(Year) ? 29 : 28) : Months[Month - 1];
}

short DayOfWeek(short Day , short Month , short Year) {
	short a = (14 - Month) / 12;
	short Y = Year - a;
	short M = Month + 12 * a - 2;

	short DayOfWeek = (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + (31 * M / 12)) % 7;
	return DayOfWeek;
}

void PrintMonthCalendar(short Year , short Month) {
	short DayOfMonth = DaysOfMonth(Year, Month);
	short Current = DayOfWeek(1, Month, Year);
	printf("\n  _______________%s_______________\n\n" , CastingMonthFromNumberToString(Month).c_str());
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	short i;
	for (i = 0; i < Current; i++)
	{
		printf("     ");
	}

	for (short J = 1; J <= DayOfMonth; J++)
	{
		printf("%5d", J);

		if (++i == 7)
		{
			i = 0;
			cout << endl;
		}
	}
}

void PrintFullMonthOfYear(short Year, short Month = 1) {

	printf("\n  =================================");
	printf("\n               %d\n", Year );
	printf("\n  =================================\n\n\n");

	for (short i = 1; i <= 12; i++)
	{
		cout << "\a";
		PrintMonthCalendar(Year, Month++);
		cout << "\n\n\n";
	}
}

int main() {
	short Year, Month;
	Year = ReadNumber("Enter A Year : ");
	PrintFullMonthOfYear(Year);
}