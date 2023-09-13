#include <iostream>
#include "InOut.h"
#include "header2.h"

using namespace std;

int main()
{
	int N;
	do {
		cout << "Enter a number" << endl;
		cin >> N;
	} while (N % 2 != 0);

	float* arr;
	arr = new float[N];

	Enter(arr, N);
	Input(arr, N);
	Print(arr, N);
	Replace(arr, N);
	Print(arr, N);

	delete[] arr;
	return 0;
}