#include <iostream>
#include "InOut.h"
#include "header3.h"

using namespace std;

int main()
{
	int N;
	cin >> N;
	int* arr;
	int* arr2;
	arr = new int[N];

	//Enter(arr, N);
	//Input(arr, N);
	//Print(arr, N);

	int count = Count(arr, N);
	cout << count << endl;
	arr2 = new int[count];
	//Enter(arr2, count);
	NewArr(arr, arr2, count, N);
	//Print(arr2, count);

	delete[] arr;
	return 0;
}