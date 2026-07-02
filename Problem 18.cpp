#pragma warning(disable : 4996)

#include<iostream>
using namespace std;

struct sDate {
	int day = 0;
	int month = 0;
	int year = 0;
};

sDate ReadDate() {
	sDate date;
	cout << "\n\nPlease Enter Your Date of Birth : \n\n";
	cout << "\nEnter day: ";
	cin >> date.day;
	cout << "\nEnter month: ";
	cin >> date.month;
	cout << "\nEnter year: ";
	cin >> date.year;
	return date;
}

sDate GetSystemDate() {
	sDate date;
	time_t t = time(0); // get time now
	tm* now = localtime(&t);
	date.day = now->tm_mday;
	date.month = now->tm_mon + 1;
	date.year = now->tm_year + 1900;
	return date;
}

bool Date1FBeforeDate2(sDate Date1, sDate Date2) {
	return (Date1.year < Date2.year) || (Date1.year == Date2.year && Date1.month < Date2.month) || (Date1.year == Date2.year && Date1.month == Date2.month && Date1.day < Date2.day);
}

bool IsLeeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short NumberOfDayInMonth(int month, int year) {
	short NumberOfDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };	
	if (month < 1 && month > 12)
		return 0;
	return (month == 0) ? (IsLeeapYear(year) ? 29 : 28) : NumberOfDays[month - 1];
}

bool IsLastDayInMonth(sDate Date) {
	return NumberOfDayInMonth(Date.month, Date.year) == Date.day;
}

bool IsLastMonth(int Month) {
	return Month == 12;
}

sDate IncreaseDateByOneDay(sDate date) {
	if (IsLastDayInMonth(date))
	{
		if (IsLastMonth(date.month))
		{
			date.day = 1;
			date.month = 1;
			date.year++;
		}
		else
		{
			date.day = 1;
			date.month++;

		}
	}
	else
	{
		date.day++;
	}
	return date;
}

int GetDifferenceInDays(sDate date1, sDate date2) {
	int CountNumber = 0;
	while (Date1FBeforeDate2(date1, date2)) {
		CountNumber++;
		date1 = IncreaseDateByOneDay(date1);
	}
	return CountNumber;
}


int main() {
	
	sDate Date_1 = ReadDate();
	sDate Date_2 = GetSystemDate();
	int MyiBirthDay = GetDifferenceInDays(Date_1, Date_2);

	cout << "\n\nYour Age in Days is: " << MyiBirthDay << endl;

	system("pause");
	return 0;
}