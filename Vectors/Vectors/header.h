#ifndef Vector_H
#define Vector_H
#include <iostream>
using namespace std;

class TVector
{
private:
	float x, y, z;
public:
	TVector();
	TVector(float _x, float _y, float _z);
	TVector(const TVector& v);

	TVector operator +(const TVector& v);
	TVector operator -(const TVector& v);
	float operator *(const TVector& v) const;

	friend istream& operator>>(istream& in, TVector& v);
	friend ostream& operator<<(ostream& out, const TVector& v);

	float Lenght() const;
	float Cos(TVector& v) const;
};


#endif // !Vector_H


