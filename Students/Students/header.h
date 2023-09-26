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

struct Student
{
	string surname;
	string name;
	string patronymic;
	Date date;
	string num_phone;
};

class Group
{
private:
	int count;
	Student** st;
public:

	Group(int count);
	~Group();
	void remove(int ind);
	void add(Student student);
	void resize();
	void setStudents(Student** students);
	Student** getStudent()
	{
		return st;
	}
	int getCount()
	{
		return count;
	}
	void printStudents(int i);

};

void read(Student** st, int n, string& f);
int cntStruct(string& f);
void removeFirstN(string& str, int n);
int Search(Student** st, int i, int* mas);
int SearchBySurname(Student** st, int n, int* mas);
int SearchByName(Student** st, int n, int* mas);
int SearchByYear(Student** st, int n, int* mas);
Group* Delete(Group* gr);
Group* Add(Group* gr);
#endif // !_PERSON_H
