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
    Group group(n, n);
    read(students, n, f);
    group.setStudents(students);

    for (int i = 0; i < n; i++)
        group.printStudents(i);
        //cout << *(students[i]) << endl;

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
            int k = group.Search(mas);
            if (k == 0)
                cout << "Not found" << endl;
            else
            {
                for (int j = 0; j < k; j++)
                {
                    int l = mas[j];
                    group.printStudents(l);
                    //cout << *(students[l]) << endl;
                }
                    
            }
            break;
        }
        case 2:
        {
            Add(&group);
            n = group.getCount();
            for (int i = 0; i < n; i++)
                group.printStudents(i);
                //cout << &students[i] << endl;
            break;
        }
        case 3:
        {
            Delete(&group);
            n = group.getCount();
            for (int i = 0; i < n; i++)
                group.printStudents(i);
                //cout << &students[i] << endl;
            break;
        }
        }
    }
    delete[] mas;
    return 0;
}