#include "header.h"
#include <cmath>

float TVector::Lenght()
{
	float len;
	len = sqrt(x * x + y * y + z * z);
	return len;
};

float Cos(TVector& v1, TVector& v2)
{
	float len1 = v1.Lenght();
	float len2 = v2.Lenght();

	float scal = v1 * v2;

	float cosine = scal / (len1 * len2);
	return cosine;
}

