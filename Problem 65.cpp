#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct sDate {
	short Day = 1;
	short Month = 1;
	short Year = 1;
};

sDate ReadDate() {
	sDate Date;

	cout << "Enter a Day: ";
	cin >> Date.Day;
	cout << "Enter a Month: ";
	cin >> Date.Month;
	cout << "Enter a Year: ";
	cin >> Date.Year;

	return Date;
}

string ReadDateAsString() {
	string DateS;
	cout << "\nEnter a Date aAs String D/M/Y  ? ";
	getline(cin, DateS);
	return DateS;
}

vector<string> SplitString(string StringDate , string Delimt = "/") {
	short Pos = 0;
	string Word = "";
	vector<string> vDate;
	
	while ((Pos = StringDate.find(Delimt)) != (std::string::npos)) {
		Word = StringDate.substr(0, Pos);
		if (Word != "")
			vDate.push_back(Word);
		StringDate.erase(0, Pos + Delimt.length());
	}
	if (StringDate != "")
		vDate.push_back(StringDate);

	return vDate;
}

sDate ConvertDateFromStringToStructDate(string StringDate) {
	vector<string> vDate = SplitString(StringDate);
	sDate Date;

	Date.Day = stoi(vDate.at(0));
	Date.Month = stoi(vDate.at(1));
	Date.Year = stoi(vDate.at(2));

	return Date;
}

string ConvertDateFromStructToString(sDate Date) {
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

string ReplaceWordInString(string S1, string StringToReplace,string sRepalceTo)
{
	short pos = S1.find(StringToReplace);
	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(),sRepalceTo);
		pos = S1.find(StringToReplace);//find next
	}
	return S1;
}

string FormateDate(sDate Date, string DateFormat = "dd/mm/yyyy")
{
	string FormattedDateString = "";
	FormattedDateString = ReplaceWordInString(DateFormat, "dd",to_string(Date.Day));
	FormattedDateString = ReplaceWordInString(FormattedDateString,"mm", to_string(Date.Month));
	FormattedDateString = ReplaceWordInString(FormattedDateString,"yyyy", to_string(Date.Year));
	return FormattedDateString;
}

int main() {
	string DateToString = ReadDateAsString();
	sDate Date = ConvertDateFromStringToStructDate(DateToString);

	cout << "\n" << FormateDate(Date) << "\n";
	cout << "\n" << FormateDate(Date, "yyyy/dd/mm") << "\n";
	cout << "\n" << FormateDate(Date, "mm/dd/yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "mm-dd-yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "dd-mm-yyyy") << "\n";
	cout << "\n" << FormateDate(Date, "Day:dd, Month:mm,Year:yyyy") << "\n";


	cout << "\n\n" << system("pause");
	return 0;
}