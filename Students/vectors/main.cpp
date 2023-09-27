#include "header.h"
#include <iostream>
using namespace std;

int main()
{
    // Создание пустых векторов
    cout << "Enter the size: ";
    int size;
    cin >> size;
    TVector<int> vector1(size);
    TVector<int> vector2(size);

    // Ввод элементов первого вектора
    cout << "Enter the elements of the first vector: ";
    cin >> vector1;

    // Ввод элементов второго вектора
    cout << "Enter the elements of the second vector: ";
    cin >> vector2;

    // Вывод векторов
    cout << "The first vector: " << vector1 << endl;
    cout << "The second vector: " << vector2 << endl;

    // Выполнение операций с векторами
    TVector<int> sum = vector1 + vector2;
    cout << "Sum of vectors: " << sum << endl;

    TVector<int> difference = vector1 - vector2;
    cout << "Vector difference: " << difference << endl;

    double dotProduct = vector1 * vector2;
    cout << "Scalar product of vectors: " << dotProduct << endl;

    if (vector1 == vector2)
        cout << "operator ==: The vectors are equal" << endl;
    else
        cout << "operator ==: The vectors are not equal" << endl;

    if (vector1 != vector2)
        cout << "operator !=: The vectors are not equal" << endl;
    else
        cout << "operator !=: The vectors are equal" << endl;

    TVector<int> assignedVector = vector1;
    cout << "Assigned vector: " << assignedVector << endl;

    double length = vector1.Length();
    cout << "Length of the first vector: " << length << endl;
    double length2 = vector2.Length();
    cout << "Length of the second vector: " << length2 << endl;

    return 0;
}