#ifndef Vector_H
#define Vector_H
#include <iostream>
using namespace std;

class TVector
{
private:
	float x, y, z;
public:
	TVector()
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;
	};

	TVector(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	};

	TVector operator +(const TVector& v)
	{
		TVector res;
		res.x = x + v.x;
		res.y = y + v.y;
		res.z = z + v.z;
		return res;
	};
	TVector operator -(const TVector& v)
	{
		TVector res;
		res.x = x - v.x;
		res.y = y - v.y;
		res.z = z - v.z;
		return res;
	};
	float operator *(const TVector& v)
	{
		float res;
		res = x * v.x + y * v.y + z * v.z;
		return res;
	};


	friend istream& operator>>(istream& in, TVector& v)
	{
		cout << "enter the coordinate x: ";
		in >> v.x;
		cout << "enter the coordinate y: ";
		in >> v.y;
		cout << "enter the coordinate z: ";
		in >> v.z;
		return in;
	};

	friend ostream& operator<<(ostream& out, const TVector& v)
	{
		out << v.x << " " << v.y << " " << v.z << endl;
		return out;
	};

	float Lenght();
};

float Cos(TVector& v1, TVector& v2);
#endif // !Vector_H


