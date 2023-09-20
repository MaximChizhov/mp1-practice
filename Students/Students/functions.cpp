#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include "header.h"
using namespace std;


Person::Person()
{
	surname = " ";
	name = " ";
	patronymic = " ";
	date.day = 0;
	date.month = 0;
	date.year = 0;
	num_phone = " ";
}

Person::Person(string surname, string name, string patronymic, int day,
	int month, int year, string num_phone)
{
	this->surname = surname;
	this->name = name;
	this->patronymic = patronymic;
	this->date.day = day;
	this->date.month = month;
	this->date.year = year;
	this->num_phone = num_phone;
}

void Person::set_info(const string& p_surname, const string& p_name, const string& p_patronymic,
	const int& p_day, const int& p_month,
	const int& p_year, const string& p_num_phone)
{
	surname = p_surname;
	name = p_name;
	patronymic = p_patronymic;
	date.day = p_day;
	date.month = p_month;
	date.year = p_year;
	num_phone = p_num_phone;
}

ostream& operator<<(ostream& out, const Person& p)
{
	out << "<===========================================>" << endl;
	out << "FIO: " << p.surname << " " << p.name << " " << p.patronymic << endl;
	out << "Date: " << p.date.day << "." << p.date.month << "." << p.date.year << endl;
	out << "Phone number: " << p.num_phone << endl;
	out << "<===========================================>" << endl;
	return out;
}
