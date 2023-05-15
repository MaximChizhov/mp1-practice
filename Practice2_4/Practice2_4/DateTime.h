# ifndef DATETIME_H
#define DATETIME_H
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

struct TDate
{
	int d = 0;
	int m = 0;
	int y = 0;

	void CurrentDay() {
		time_t t = time(nullptr);
		tm* ltm = localtime(&t);
		y = ltm->tm_year + 1900;
		m = ltm->tm_mon + 1;
		d = ltm->tm_mday;
	}
	friend ostream& operator<<(ostream& out, TDate& date) {
		date.CurrentDay();
		out << date.d << '/' << date.m << '/' << date.y;
		return out;
	}
};

struct TTime
{
	int h = 0;
	int m = 0;
	int s = 0;

	void CurrentTime() {
		time_t t = time(nullptr);
		tm* ltm = localtime(&t);
		h = ltm->tm_hour;
		m = ltm->tm_min;
		s = ltm->tm_sec;
	}
	friend ostream& operator<<(ostream& out, TTime& time) {
		time.CurrentTime();
		out << time.h << ':' << time.m << ':' << time.s;
		return out;
	}
};
#endif // !DATETIME_H