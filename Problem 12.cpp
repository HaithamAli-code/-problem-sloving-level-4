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

short CountDaysFromBeginningOfYear(short Day, short Month, short Year) {
	short TotleDays = 0;
	for (short i = 1; i <= Month - 1; i++)
	{
		TotleDays += NumberOfDayInMonth(i , Year);
	}
	TotleDays += Day;
	return TotleDays;

}

sDate DateAddDays(short DayAdd ,sDate Date) {
	short ReminderDays = DayAdd + CountDaysFromBeginningOfYear(Date.Day, Date.Month, Date.Year);
	short NumberOfDaysInMonth = 0;
	Date.Month = 1;
	
	while (true) {
		NumberOfDaysInMonth = NumberOfDayInMonth(Date.Month, Date.Year);
		if (ReminderDays > NumberOfDaysInMonth)
		{
			ReminderDays -= NumberOfDaysInMonth;
			Date.Month++;
			if (Date.Month > 12)
			{
				Date.Month = 1;
				Date.Year++;
			}
		}
		else
		{
			Date.Day = ReminderDays;
			break;
		}
	}
	return Date;
}

sDate ReadDate() {
	sDate Date;
	Date.Year = ReadNumer("Enter Year: ");
	Date.Month = ReadNumer("Enter Month: ");
	Date.Day = ReadNumer("Enter Day: ");
	return Date;
}

int main() {
	sDate Date = ReadDate();
	short NumberToAddDays = ReadNumer("Enter the number of days to add: ");

	sDate DateAfterAdding = DateAddDays(NumberToAddDays, Date);

	cout << "\n\n\nThe date after adding " << NumberToAddDays << " days to [" << Date.Day << "/" << Date.Month << "/" << Date.Year << "] is: [" 
		<< DateAfterAdding.Day << "/" << DateAfterAdding.Month << "/" << DateAfterAdding.Year << "]";

	system("pause>0");
}