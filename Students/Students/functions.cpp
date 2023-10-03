#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include "header.h"

using namespace std;


Group::Group(int count, int size)
{
	this->count = count;
	this->size = size;
	st = new Student * [size];
	for (int i = 0; i < size; i++)
		st[i] = nullptr;
}

Group::~Group()
{
	for (int i = 0; i < count; i++) {
		delete st[i];
	}
	delete[] st;
}

void Group::setStudents(Student** students)
{
	for (int i = 0; i < count; i++) {
		st[i] = new Student();
		st[i]->surname = students[i]->surname;
		st[i]->name = students[i]->name;
		st[i]->patronymic = students[i]->patronymic;
		st[i]->date.day = students[i]->date.day;
		st[i]->date.month = students[i]->date.month;
		st[i]->date.year = students[i]->date.year;
		st[i]->num_phone = students[i]->num_phone;
	}
}
Group::Group(const Group& g)
{
	count = g.count;
	size = g.count;
	st = new Student * [size];
	for (int i = 0; i < count; i++)
		st[i] = g.st[i];
}

void Group::resize()
{
	size += 2;
	Student** tmp = new Student * [size];
	for (int i = 0; i < count; i++)
		tmp[i] = st[i];
	delete[] st;
	st = tmp;
}

void Group::add(const Student& student)
{
	if (count == size)
		resize();
	st[count] = new Student();
	st[count]->surname = student.surname;
	st[count]->name = student.name;
	st[count]->patronymic = student.patronymic;
	st[count]->date.day = student.date.day;
	st[count]->date.month = student.date.month;
	st[count]->date.year = student.date.year;
	st[count]->num_phone = student.num_phone;
	count++;
}

void read(Student** st, int n, string& f)
{

	fstream file;
	file.open(f);
	if (!file.is_open())
		throw "File open error";
	string  surname, name, patronymic, num_phone;
	int day = 0;
	int month = 0;
	int year = 0;
	for (int i = 0; i < n; i++)
	{
		string str = "";
		int flag = 0;
		while ((getline(file, str, ';')) && (flag < 6))
		{
			switch (flag)
			{
			case 0:
			{
				if (i != 0)
					removeFirstN(str, 1);
				surname = str;
				break;
			}
			case 1:
			{
				name = str;
				break;
			}
			case 2:
			{
				patronymic = str;
				break;
			}
			case 3:
			{
				day = stoi(str);
				break;
			}
			case 4:
			{
				month = stoi(str);
				break;
			}
			case 5:
			{
				year = stoi(str);
				break;
			}
			}
			flag++;
		}
		num_phone = str;
		st[i] = new Student();
		st[i]->surname = surname;
		st[i]->name = name;
		st[i]->patronymic = patronymic;
		st[i]->date.day = day;
		st[i]->date.month = month;
		st[i]->date.year = year;
		st[i]->num_phone = num_phone;


	}
	file.close();
};

int cntStruct(string& f)
{
	fstream file;
	file.open(f);
	char* str = new char[1024];
	int i = 0;
	if (!file.is_open())
		throw "File open error";
	while (!file.eof())
	{
		file.getline(str, 1024, '\n');
		i++;
	}
	delete[]str;
	file.close();
	return i;
}

void removeFirstN(string& str, int n)
{
	str.erase(0, n);
}

void Group::printStudents(int i)
{
	cout << "<===========================================>" << endl;
	cout << "FIO: " << st[i]->surname << " " << st[i]->name << " " << st[i]->patronymic << endl;
	cout << "Date: " << setfill('0') << setw(2) << st[i]->date.day << '.' << setfill('0') << setw(2) << st[i]->date.month << '.' << st[i]->date.year << endl;
	cout << "Phone number: " << st[i]->num_phone << endl;

}
ostream& operator<<(ostream& out, const Group& gr)
{
	for (int i = 0; i < gr.count; i++)
	{
		out << "<===========================================>" << endl;
		out << "FIO: " << gr.st[i]->surname << " " << gr.st[i]->name << " " << gr.st[i]->patronymic << endl;
		out << "Date: " << setfill('0') << setw(2) << gr.st[i]->date.day << '.' << setfill('0') << setw(2) << gr.st[i]->date.month << '.' << gr.st[i]->date.year << endl;
		out << "Phone number: " << gr.st[i]->num_phone << endl;
	}

	return out;
}

int Group::Search(int* mas)
{
	int num;
	int j = 0;
	cout << "1) search by surname" << endl;
	cout << "2) search by name" << endl;
	cout << "3) search by date" << endl;
	do {
		cout << "Choose a method: ";
		cin >> num;
	} while (num < 0 || num>3);
	if (num == 1)
		j = SearchBySurname(mas);
	if (num == 2)
		j = SearchByName(mas);
	if (num == 3)
		j = SearchByYear(mas);

	return j;
}

int Group::SearchBySurname(int* mas)
{
	int j = 0;
	string str;
	cout << "Enter a surname: ";
	cin >> str;
	for (int i = 0; i < count; i++)
		if (st[i]->surname == str)
		{
			mas[j] = i;
			j++;
		}
	return j;
}
int Group::SearchByName(int* mas)
{
	int j = 0;
	string str;
	cout << "Enter a name: ";
	cin >> str;
	for (int i = 0; i < count; i++)
		if (st[i]->name == str)
		{
			mas[j] = i;
			j++;
		}
	return j;
}
int Group::SearchByYear(int* mas)
{
	int j = 0;
	int str;
	cout << "Enter a year: ";
	cin >> str;
	for (int i = 0; i < count; i++)
		if (st[i]->date.year == str)
		{
			mas[j] = i;
			j++;
		}
	return j;
}
void Group::remove(int ind)
{
	if (ind > -1 && ind < count)
		for (int i = ind; i < count - 1; i++)
			st[i] = st[i + 1];
	count--;
	cout << "Successfully" << endl;
}

Group* Delete(Group* gr)
{
	int c = gr->getCount();
	Student** st = gr->getStudent();
	int* mas = new int[c];
	for (int s = 0; s < c; s++)
		mas[s] = 0;
	int k = gr->SearchBySurname(mas);
	if (k == 1)
		gr->remove(mas[0]);
	else
	{
		for (int j = 0; j < k; j++)
			gr->printStudents(mas[j]);
		int m = gr->SearchByName(mas);
		gr->remove(mas[0]);
	}
	delete[] mas;
	return gr;
}

Group* Add(Group* gr)
{
	Student newStudent;
	cout << "Enter a surname: ";
	cin >> newStudent.surname;
	cout << "Enter a name: ";
	cin >> newStudent.name;
	cout << "Enter a patronymic: ";
	cin >> newStudent.patronymic;
	cout << "Enter a date: ";
	if (scanf("%d.%d.%d", &newStudent.date.day, &newStudent.date.month, &newStudent.date.year) == NULL)
		throw "Date scanning error";
	cout << "Enter a number of phone: ";
	cin >> newStudent.num_phone;

	gr->add(newStudent);

	return gr;
}

bool isValidDate(int day, int month, int year)
{
	if (year <= 1930 || year >= 2010)
		return false;

	if (month < 1 || month > 12)
		return false;


	// Проверяем количество дней в месяце
	int daysInMonth;
	switch (month)
	{
	case 2: // Февраль
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
			daysInMonth = 29; // Високосный год
		else
			daysInMonth = 28;
		break;
	case 4: // Апрель
	case 6: // Июнь
	case 9: // Сентябрь
	case 11: // Ноябрь
		daysInMonth = 30;
		break;
	default: // Для остальных месяцев
		daysInMonth = 31;
		break;
	}
	if (day < 1 || day > daysInMonth)
		return false;

	return true;
}