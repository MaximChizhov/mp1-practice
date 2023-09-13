#include "InOut.h"
#include "header.h"
#include <iostream>
using namespace std;

int main()
{
	int  N;
	cin >> N;
	float* arr;
	arr = new float[N];

	Enter(arr, N);
	Input(arr, N);
	Change(arr, N);
	Print(arr, N);

	delete[] arr;
	return 0;
}