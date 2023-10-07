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
	friend ostream& operator<<(ostream& out, const Student& st);
};

class Group
{
private:
	int size;
	int count;
	Student** st;
	void resize();
public:

	Group(int count, int size);
	Group(const Group& g);
	~Group();
	void remove(int ind);
	void add(const Student& student);
	void setStudents(Student** students);
	int Search(int* mas);
	int SearchBySurname(int* mas);
	int SearchByName(int* mas);
	int SearchByYear(int* mas);
	Student& operator[](int ind);
	Student** getStudent()
	{
		return st;
	}
	int getCount()
	{
		return count;
	}
	
	friend ostream& operator<<(ostream& out, const Group& gr);
};

void read(Student** st, int n, string& f);
int cntStruct(string& f);
void removeFirstN(string& str, int n);
bool isValidDate(int day, int month, int year);
Group* Delete(Group* gr);
Group* Add(Group* gr);
#endif // !_PERSON_H