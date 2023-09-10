#include "header.h"
#include <iostream>
#include <cmath>

using namespace std;

void Enter(float* arr, int N)
{
	int num, j;
	for (j = 0; j < N; j++)
	{
		num = rand() % 20 + 1;
		arr[j] = num;
	}
}
void Input(float* arr, int N)
{
	float a;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		arr[i] = a;
	}
}
void Change(float* arr, int N)
{
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > 10.0)
		{
			float tmp = sqrt(arr[i]);
			arr[i] = tmp;
		}
	}
}
void Out(float* arr, int N)
{
	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';
}