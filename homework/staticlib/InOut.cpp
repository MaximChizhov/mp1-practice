#include <iostream>
#include "InOut.h"

using namespace std;

void Enter(int* arr, int N)
{
	int num;
	for (int i = 0; i < N; i++)
	{
		num = rand() % 20 + 1;
		arr[i] = num;
	}
}

void Input(int* arr, int N)
{
	float a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		arr[i] = a;
	}
}

void Print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}