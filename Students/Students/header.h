#ifndef _PERSON_H
#define _PERSON_H
#include <string>
using namespace std;



struct Date
{
	int day;
	int month;
	int year;
};

class Person
{
private:
	string surname;
	string name;
	string patronymic;
	Date date;
	string num_phone;
public:

	Person();
	Person(string surname, string name, string patronymic,int day, 
		int month, int year, string num_phone);
	void set_info(const string& p_surname, const string& p_name, const string& p_patronymic,
		const int& p_day,const int& p_month, const int& p_year, const string& p_num_phone);
	string get_surname()
	{
		return surname;
	}
	string get_name()
	{
		return name;
	}
	friend ostream& operator<<(ostream& out, const Person& p);
};

#endif // !_PERSON_H