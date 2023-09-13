#include <iostream>
#include "header3.h"

using namespace std;

int main()
{
	int N;
	cin >> N;
	int* arr;
	int* arr2;
	arr = new int[N];

	Scan(arr, N);
	Enter(arr, N);
	Print(arr, N);

	int count = Count(arr, N);
	cout << count << endl;
	arr2 = new int[count];
	Scan(arr2, count);
	NewArr(arr, arr2, count, N);
	Print(arr2, count);

	delete[] arr;
	return 0;
}