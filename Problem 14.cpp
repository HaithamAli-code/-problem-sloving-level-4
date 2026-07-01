#include<iostream> 
using namespace std;

struct sDate {
	short Day = 0;
	short Month = 0;
	short Year = 0;
};

short ReadNumer(string Message) {
	short Number;
	cout << "\n" << Message;
	cin >> Number;
	return Number;
}

bool IsLeapYear(short Year) {
	return (Year % 4 == 0 && Year % 100 != 0 || Year % 400 == 0);
}

short NumberOfDayInMonth(short Month, short Year) {
	short NumberOfDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return (Month == 2 && IsLeapYear(Year)) ? 29 : NumberOfDays[Month - 1];
}

bool Date_One_Equal_Date_Two(sDate Date_1, sDate Date_2)
{
	return (Date_1.Year == Date_2.Year) && (Date_1.Month == Date_2.Month) && (Date_1.Day == Date_2.Day);
}

sDate ReadDate() {
	sDate Date;
	Date.Year = ReadNumer("Enter Year: ");
	Date.Month = ReadNumer("Enter Month: ");
	Date.Day = ReadNumer("Enter Day: ");
	return Date;
}

int main() {
	sDate Date_One = ReadDate();
	sDate Date_Two = ReadDate();

	if (Date_One_Equal_Date_Two(Date_One, Date_Two))
	{
		cout << "\nDate One is equal to Date Two";
	}
	else
	{
		cout << "\nDate One is not equal to Date Two";
	}

	system("pause>0");
}