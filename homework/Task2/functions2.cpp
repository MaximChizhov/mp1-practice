#include <iostream>
#include "header2.h"

using namespace std;


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