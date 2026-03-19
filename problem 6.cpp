// Number of Days In a Month Short Logic e
#include<iostream>
using namespace std;

int ReadNumber(string Message)
{
	cout << Message;

	int Number;
	cin >> Number;
	return Number;
}

bool IsLeapYear(int Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short NumberOfDaysInMonth(short Year, short Month)
{
	if (Month < 1 || Month > 12)
		return 0;

	short NumberOfDays[] = { 31 , 28 , 31,30 ,31,30, 31, 31, 30, 31, 30, 31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}

short NumberOfHoursInMonth(int Year, int Month)
{
	return NumberOfDaysInMonth(Year, Month) * 24;
}

int NumberOfMinutes(int Year, int Month)
{
	return NumberOfHoursInMonth(Year, Month) * 60;
}

int NumberOfSeconds(int Year, int Month)
{
	return NumberOfMinutes(Year, Month) * 60;
}

void PrintMonth(int Year, int Month)
{
	cout << "Number Of Days In Month: " << NumberOfDaysInMonth(Year, Month) << endl;
	cout << "Number Of Hours In Month: " << NumberOfHoursInMonth(Year, Month) << endl;
	cout << "Number Of Minutes In Month: " << NumberOfMinutes(Year, Month) << endl;
	cout << "Number Of Seconds In Month: " << NumberOfSeconds(Year, Month) << endl;
}

int main()
{
	int Years = ReadNumber("Please Enter Year To Check: ");
	int Month = ReadNumber("Please Enter Month To Check: ");

	PrintMonth(Years, Month);
	system("pause>0");
	return 0;
}