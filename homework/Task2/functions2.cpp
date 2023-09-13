#include <iostream>
#include "header2.h"

using namespace std;

void Scan(float* arr, int n)
{
	int num;
	for (int i = 0; i < n; i++)
	{
		num = rand() % 20 + 1;
		arr[i] = num;
	}
}

void Enter(float* arr, int n)
{
	float a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		arr[i] = a;
	}
}

void Print(float* arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

void Replace(float* arr, int n)
{
	int N = n / 2;
	int j = n / 2;
	for (int i = 0; i < N; i++)
		while (j < n )
		{
			float tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			j++;
			break;
		}
}