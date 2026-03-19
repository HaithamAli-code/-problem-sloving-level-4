// 

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

short NumberOfDaysInMonth(short Year , short Month)
{
	if (Month < 1 || Month > 12)
	{
		return 0;
	}

	if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}

	short Days31[7] = { 1,3,5,7,8,10,12 };
	for (short i = 0; i < 7 ; i++)
	{
		if (Month == Days31[i])
		{
			return 31;
		}
	}

	return 30;
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

void PrintMonth(int Year , int Month)
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

	PrintMonth(Years , Month);

}