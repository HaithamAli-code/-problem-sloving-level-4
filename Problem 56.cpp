#include<iostream>
using namespace std;

struct sDate
{
	short Day = 1;
	short Month = 1;
	short Year = 1;
};

sDate ReadDate()
{
	sDate Date;
	cout << "Enter a Day : ";
	cin >> Date.Day;
	cout << "Enter a Month : ";
	cin >> Date.Month;
	cout << "Enter a Year : ";
	cin >> Date.Year;

	return Date;
}

bool DateOneBeforeDateTwo(sDate Date1, sDate Date2)
{
	return (Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false : false;
}

bool DateOneEqualDateTwo(sDate Date1, sDate Date2)
{
	return ((Date1.Day == Date2.Day) && (Date1.Month == Date2.Month) && (Date1.Year == Date2.Year));
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
	return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool DateOneAfterDateTwo(sDate Date1, sDate Date2)
{
	return (!DateOneBeforeDateTwo(Date1, Date2) && !DateOneEqualDateTwo(Date1, Date2));
}

int main()
{
	cout << "\nEnter Date One : \n";
	sDate Date1 = ReadDate();
	cout << "\nEnter Date Two : \n";
	sDate Date2 = ReadDate();

	if (DateOneAfterDateTwo(Date1 , Date2))
	{
		cout << "\nYea Date One After Date Two.";
	}
	else
	{
		cout << "\nNo Date One Is Not After Date Two.";
	}
	cout << "\n\n" << system("pause");
	return 0;
}