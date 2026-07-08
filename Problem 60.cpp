#include<iostream>
using namespace std;

struct sDate
{
	short Day = 1;
	short Month= 1;
	short Year = 0;
};

struct sPeriod
{
	sDate Start;
	sDate End;
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

	cout << "\n";
	return Date;
}

sPeriod ReadPeriod()
{
	sPeriod Period;
	Period.Start = ReadDate();
	Period.End = ReadDate();
	return Period;
}

bool DateOneBeforDateTwo(sDate DateOne , sDate DateTwo)
{
	return (DateOne.Year < DateTwo.Year) ? true : (DateOne.Year == DateTwo.Year) ? (DateOne.Month < DateTwo.Month) ? true : (DateOne.Month == DateTwo.Month) ? (DateOne.Day < DateTwo.Day) : false : false;
}

bool DateOneEqualDateTwo(sDate DateOne, sDate DateTwo)
{
	return (DateOne.Year == DateTwo.Year) && (DateOne.Month == DateTwo.Month) && (DateOne.Day == DateTwo.Day);
}

bool DateOneAfterDateOne(sDate DateOne, sDate DateTwo)
{
	return ((!DateOneBeforDateTwo(DateOne, DateTwo)) && (!DateOneEqualDateTwo(DateOne, DateTwo)));
}

enum enCompareDate
{
	Befor = -1,
	Equal = 0,
	After = 1,
};

enCompareDate CompareDate(sDate DateOne, sDate DateTwo)
{
	if (DateOneBeforDateTwo(DateOne, DateTwo))
		return enCompareDate::Befor;
	if (DateOneAfterDateOne(DateOne, DateTwo))
		return enCompareDate::After;
	if(DateOneEqualDateTwo(DateOne, DateTwo))
		return enCompareDate::Equal;
}


bool IsDateInPeriod(sDate Date , sPeriod Period)
{
	return !(CompareDate(Date, Period.End) == enCompareDate::After || CompareDate(Date, Period.Start) == enCompareDate::Befor);
}

int main()
{
	cout << "\nPeriod One :\n";
	sPeriod  PeriodOne = ReadPeriod();

	cout << "\n\nEnter Date To Check : \n";
	sDate DateToCheck = ReadDate();

	if(IsDateInPeriod(DateToCheck, PeriodOne))
		cout << "\nYes, Date is within period\n";
	else
		cout << "\nNo, Date is NOT within period\n";


	cout << "\n\n" << system("pause");
	return 0;
}