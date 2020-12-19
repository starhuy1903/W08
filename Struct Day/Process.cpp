#include "Date.h"
#include "InputOutput.h"
int numberDay(Date d) {
	int t;
	switch (d.month) {
	case 2:
	{
		if ((d.year % 400 == 0) || ((d.year % 4 == 0) && (d.year % 100 != 0))) {
			t = 29;
		}
		else t = 28;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
		t = 30; break;
	default: t = 31;
	}
	return t;
}
int numberDayofYear(Date d){
	if ((d.year % 400 == 0) || ((d.year % 4 == 0) && (d.year % 100 != 0))) return 366;
	return 365;
}

Date tomorrow(Date d) {
	Date r;
	int t = numberDay(d);
	r.day = d.day + 1;
	if (r.day > t) {
		r.day = 1;
		r.month = d.month + 1;
		if (r.month > 12) {
			r.month = 1;
			r.year = d.year + 1;
		}
		else r.year = d.year;
	}
	else {
		r.month = d.month;
		r.year = d.year;
	}
	return r;
}
void mainTomorrow() {
	Date d;
	inputDate(d);
	Date r = tomorrow(d);
	outputDate(r);
}

Date yesterday(Date d) {
	Date r; 
	int t = numberDay(d);
	r.day = d.day - 1;
	if (r.day == 0) {
		r.day = t;
		r.month = d.month - 1;
		if (r.month == 0) {
			r.month = 12;
			r.year = d.year - 1;
		}
		else r.year = d.year;
	}
	else {
		r.month = d.month;
		r.year = d.year;
	}
	return r;
}
void mainYesterday() {
	Date d;
	inputDate(d);
	Date r = yesterday(d);
	outputDate(r);
}

int compareDay(Date a, Date b) {
	if (a.year < b.year) return -1;
	else if (a.year > b.year) return 1;
	else {
		if (a.month < b.month) return -1;
		else if (a.month > b.month) return 1;
		else {
			if (a.day < b.day) return -1;
			else if (a.day > b.day) return 1;
			else return 0;
		}
	}
}
void mainCompare() {
	Date a, b;
	int r;
	inputDate(a);
	inputDate(b);
	r = compareDay(a, b);
	outputCompare(r);
}

void increaseDay(Date &d, int k) {
	int t;
	for (int i = d.day + k; ; i = d.day) {
		t = numberDay(d);
		if (i > t) {
			d.day = i - t;
			d.month++;
			if (d.month > 12) {
				d.month = 1;
				d.year++;
			}
		}
		else {
			d.day = i;
			break;
		}
	}
}
void mainIncreaseDay() {
	Date d; 
	int k;
	inputDate(d);
	inputIncreaseK(k);
	increaseDay(d, k);
	outputDate(d);
}

int computeDay(Date d, Date h) {
	int count = 0;
	for (h.year; h.year > d.year; h.year--) {
		if (h.month <= d.month && h.year == d.year + 1) break;
		else count += numberDayofYear(h);
	}
	count += h.day;

	for (h.month -= 1; h.month > 0; h.month--) {
			count += numberDay(h);
		}
	if (h.year > d.year) {
			count += numberDay(d) - d.day;
			for (d.month += 1; d.month <= 12; d.month++) {
				count += numberDay(d);
			}
		}
	
	return count - 1;
}

void main5() {
	Date h; 
	inputDate(h);
	Date d;
	d.day = 1;
	d.month = 1;
	d.year = h.year;
	int s = computeDay(d, h);
	outputDay(s);
}
void main6() {
	Date d = { 1, 1, 1970 };
	Date h;
	inputDate(h);
	int s = computeDay(d, h);
	outputDay(s);
}

void main7() {
	Date d, h;
	inputDate(d);
	inputDate(h);
	int s = computeDay(d, h);
	outputDay(s);
}
void main8() {
	Date d = { 1, 1, 1970 };
	Date h;
	inputDate(h);
	int s = computeDay(d, h) % 7;
	output8(s);
}