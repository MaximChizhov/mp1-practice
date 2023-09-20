#include "header.h"
#include <cmath>


TVector::TVector()
{
	x = 0.0;
	y = 0.0;
	z = 0.0;
};

TVector::TVector(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
};

TVector::TVector(const TVector& v)
{
	x = v.x;
	y = v.y;
	z = v.y;
};

TVector TVector::operator +(const TVector& v)
{
	TVector res;
	res.x = x + v.x;
	res.y = y + v.y;
	res.z = z + v.z;
	return res;
};

TVector TVector::operator -(const TVector& v)
{
	TVector res;
	res.x = x - v.x;
	res.y = y - v.y;
	res.z = z - v.z;
	return res;
};

float TVector::operator *(const TVector& v) const
{
	float res;
	res = x * v.x + y * v.y + z * v.z;
	return res;
};

istream& operator>>(istream& in, TVector& v)
{
	cout << "enter the coordinate x: ";
	in >> v.x;
	cout << "enter the coordinate y: ";
	in >> v.y;
	cout << "enter the coordinate z: ";
	in >> v.z;
	return in;
};

ostream& operator<<(ostream& out, const TVector& v)
{
	out << v.x << " " << v.y << " " << v.z << endl;
	return out;
};

float TVector::Lenght() const
{
	float len;
	len = sqrt(x * x + y * y + z * z);
	return len;
};

float TVector::Cos(TVector& v) const
{
	return (*this) * v /( Lenght() * v.Lenght());
}

