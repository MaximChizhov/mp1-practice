#include "header.h"
#include <iostream>
#include <cmath>

using namespace std;



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
