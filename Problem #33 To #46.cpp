#include<iostream>
using namespace std;

struct sDate {
	int Day = 1;
	int	Month = 1;
	int Year = 0;
};

int ReadPositiveNumber(string message) {
	int number = 0;
	do
	{
		cout << "\n" << message;
		cin >> number;
	} while (number < 1);
	return number;
}

sDate ReadDate() {
	sDate Date;
	Date.Day = ReadPositiveNumber("Enter Day: ");
	Date.Month = ReadPositiveNumber("Enter Month: ");
	Date.Year = ReadPositiveNumber("Enter Year: ");
	return Date;
}

bool IsLastMonth(int Month) {
	return (Month == 12);
}

bool LeapYear(int Year) {
	return ((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0));
}

int NumberOfDayInMonth(int Month , int Year) {
	if (Month < 1 || Month > 12)
	{
		return 0;
	}
	int NomerOfDaYs[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (LeapYear(Year) ? 29 : 28) : NomerOfDaYs[Month - 1];
}

bool LastDayInMonth(sDate Date) {
	return (Date.Day == NumberOfDayInMonth(Date.Month, Date.Year)); 
}

sDate DecreaseDateByOneDay(sDate Date) {
	if (Date.Day == 1)
	{
		if (Date.Month ==1)
		{
			Date.Day = 31;
			Date.Month = 12;
			Date.Year--;

		}
		else
		{
			Date.Day = NumberOfDayInMonth(Date.Month - 1, Date.Year);
			Date.Month--;
		}
	}
	else
	{
		Date.Day--;
	}
	return Date;
}

sDate DecreaseDateByXDays(sDate Date, int XDays) {
	for (int i = 0; i < XDays; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

sDate DecreaseDateByOneWeek(sDate Date) {
	for (int i = 0; i < 7; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

sDate DecreaseDateByXWeek(sDate Date , int Weeks){
	for (int i = 0; i < Weeks; i++)
	{
		Date = DecreaseDateByOneWeek(Date);
	}
	return Date;
}

sDate DecreaseDateByOneMonth(sDate Date) {
	if (Date.Month ==1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}
	short NumberOfDaysInCurrentMonth = NumberOfDayInMonth(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}
	return Date;
}

sDate DecreaseDateByXMonth(sDate Date , int Month) {
	for (int i = 0; i < Month; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

sDate DecreaseDateByOneYear(sDate Date) {
	Date.Year--;
	return Date;
}

sDate DecreaseDateByXYear(sDate Date , int Year) {
	Date.Day = Date.Year - Year;
	return Date;
}

sDate DecreaseDateByOneDecade(sDate Date) {
	Date.Year -= 10;
	return Date;
}

sDate DecreaseDateByXDecade(sDate Date , int Decade) {
	Date.Year -= Decade * 10;
	return Date;
}

sDate DecreaseDateByOneCentury(sDate Date) {
	Date.Year -= 100;
	return Date;
}

sDate DecreaseDateByOneMillennium(sDate Date) {
	Date.Year -= 1000;
	return Date;
}

int main() {
	sDate Date1 = ReadDate();


	Date1 = DecreaseDateByOneDay(Date1);
	cout << "[1]-Decreased One Day: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseDateByXDays(Date1, 10);
	cout << "[2]-Decreased 10 Days: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseDateByOneWeek(Date1);
	cout << "[3]-Decreased One Week: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseDateByXWeek(Date1 , 10);
	cout << "[4]-Decreased 10 Week: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseDateByOneMonth(Date1);
	cout << "[5]-Decreased One Month: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseDateByXMonth(Date1, 5);
	cout << "[6]-Decreased 5 Month: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseDateByOneYear(Date1);
	cout << "[7]-Decreased One Year: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseDateByXYear(Date1 , 5);
	cout << "[8]-Decreased 5 Year: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseDateByOneDecade(Date1);
	cout << "[9]-Decreased Decaade: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseDateByXDecade(Date1, 10); 
	cout << "[10]-Decreased 10 Decaade: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseDateByOneCentury(Date1);
	cout << "[11]-Decreased One Century: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	Date1 = DecreaseDateByOneMillennium(Date1);
	cout << "[12]-Decreased One Millennium: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	system("pause");
	return 0;
}