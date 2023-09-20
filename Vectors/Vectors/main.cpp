#include <iostream>
#include "header.h"

using namespace std;

int main()
{
	TVector v1, v2, v3;
	cout << "Enter the coordinates of the first vector" << endl;
	cin >> v1;
	cout << "Enter the coordinates of the second vector" << endl;
	cin >> v2;
	float res;
	while (true)
	{
		cout << "choose an action: or enter '0'" << endl;
		cout << "1: add two vectors" << endl;
		cout << "2: subtract two vectors" << endl;
		cout << "3: calculate the scalar product" << endl;
		cout << "4: find the cosine between two vectors" << endl;
		int num;
		cin >> num;
		switch (num)
		{
		case 1:
		{
			v3 = v1 + v2;
			cout << v3 << endl;
			break;
		}
		case 2:
		{
			v3 = v1 - v2;
			cout << v3 << endl;
			break;
		}
		case 3:
		{
			res = v1 * v2;
			cout << res << endl;
			break;
		}
		case 4:
		{
			float cosine = v1.Cos(v2);
			cout << cosine << endl;
			break;
		}
		}
		if (num == 0)
			break;
	}

	return 0;
}