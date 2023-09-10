#include <iostream>
#include "header3.h"

using namespace std;

void Scan(int* arr, int n)
{
	int num;
	for (int i = 0; i < n; i++)
	{
		num = rand() % 20 + 1;
		arr[i] = num;
	}
}

void Enter(int* arr, int n)
{
	float a;
	for (int i = 0; i < n; i++)
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

int Count(int* arr, int n)
{
	int k = 1;
	for (int i = 1; i < n; i++)
	{
		int t = Search(arr, i);
		if (t == 0)
			k++;
	}
	return k;
}

int Search(int* arr, int ind)
{
	int k = 0;
	for (int i = 0; i < ind; i++)
		if (arr[ind] == arr[i])
		{
			k = 1;
			break;
		}
	return k;
}

void NewArr(int* arr, int* arr2, int count, int n)
{
	arr2[0] = arr[0];
	int j = 1;
	for (int i = 1; i < count; i++)
		while (j < n)
		{
			int t = Search(arr, j);
			if (t == 0)
			{
				arr2[i] = arr[j];
				j++;
				break;
			}
			else
				j++;
		}
}