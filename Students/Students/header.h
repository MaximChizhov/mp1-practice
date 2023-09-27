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
	int size;
	int count;
	Student** st;
public:

	Group(int count, int size);
	~Group();
	void remove(int ind);
	void add(const Student& student);
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
	int Search(int* mas);
	int SearchBySurname( int* mas);
	int SearchByName(int* mas);
	int SearchByYear(int* mas);
	void printStudents(int i);
	//friend ostream& operator<<(ostream& out, const Student& st);

};

void read(Student** st, int n, string& f);
int cntStruct(string& f);
void removeFirstN(string& str, int n);
Group* Delete(Group* gr);
Group* Add(Group* gr);
#endif // !_PERSON_H
