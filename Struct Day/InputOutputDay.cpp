#include "InputOutput.h"
#include "Date.h"
void inputDate(Date& d) {
	cout << "Day: ";
	cin >> d.day;
	cout << "Month: ";
	cin >> d.month;
	cout << "Year: ";
	cin >> d.year;
}

void inputIncreaseK(int &k) {
	do {
		cout << "K = ";
		cin >> k;
	} while (k < 0);
}

void outputDate(Date d) {
	cout << setfill('0');
	cout << setw(4) << right << d.year << "-";
	cout << setw(2) << right << d.month << "-";
	cout << setw(2) << right << d.day << endl;
}

void outputCompare(int t) {
	if (t == -1) cout << t << endl;
	else if (t == 1) cout << t << endl;
	else cout << t << endl;
}

void outputDay(int count) {
	cout << count << endl;
}

void output8(int s) {
	switch (s)
	{
	case 0: cout << "Thursday" << endl; break;
	case 1: cout << "Friday" << endl; break;
	case 2: cout << "Saturday" << endl; break;
	case 3: cout << "Sunday" << endl; break;
	case 4: cout << "Monday" << endl; break;
	case 5: cout << "Tuesday" << endl; break;
	case 6: cout << "Wednesday" << endl; break;
	default:
		break;
	}
}