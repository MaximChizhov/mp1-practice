#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    int n;
    string f;
    cout << "Enter filename or path: ";
    cin >> f;
    n = cntStruct(f);
    Student** students = new Student * [n];
    int* mas = new int[n];
    for (int s = 0; s < n; s++)
        mas[s] = 0;
    Group group(n);
    read(students, n, f);
    group.setStudents(students);

    for (int i = 0; i < n; i++)
        group.printStudents(i);

    int num = -1;
    while (num != 0)
    {
        do {
            cout << endl;
            cout << "1) Student search" << endl;
            cout << "2) Adding a student" << endl;
            cout << "3) Deleting a student" << endl;
            cout << "enter 0 to exit" << endl;
            cout << "Choose an action: ";
            cin >> num;
        } while (num < 0 || num > 3);
        switch (num)
        {
        case 1:
        {
            int k = Search(students, n, mas);
            if (k == 0)
                cout << "Not found" << endl;
            else
            {
                for (int j = 0; j < k; j++)
                    group.printStudents(mas[j]);
            }
            break;
        }
        case 2:
        {
            Add(&group);
            students = group.getStudent();
            n = group.getCount();
            for (int i = 0; i < n; i++)
                group.printStudents(i);
            break;
        }
        case 3:
        {
            Delete(&group);
            students = group.getStudent();
            n = group.getCount();
            for (int i = 0; i < n; i++)
                group.printStudents(i);
            break;
        }
        }
    }
    delete[] mas;
    return 0;
}