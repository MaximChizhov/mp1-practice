#ifndef Header_H
#define Header_H
#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
class TVector
{
private:
	T* vec;
	int size;
public:
	//TVector();
	TVector(int _size);
	TVector(const TVector<T>& obj);
	~TVector();

	TVector<T> operator +(const TVector<T>& obj);
	TVector<T> operator -(const TVector<T>& obj);
	double operator *(const TVector<T>& obj);
	bool operator ==(const TVector<T>& obj) const;
	bool operator !=(const TVector<T>& obj) const;
	const TVector<T>& operator =(const TVector<T>& obj);
	friend istream& operator >>(istream& in, TVector<T>& obj)
	{
		for (int i = 0; i < obj.size; i++)
			in >> obj.vec[i];
		return in;
	};
	friend ostream& operator <<(ostream& out, const TVector<T>& obj)
	{
		for (int i = 0; i < obj.size; i++)
			out << obj.vec[i] << " ";
		return out;
	};

	double Length() const;
};

/*template <class T>
TVector<T>::TVector()
{
	size = 0;
	vec = nullptr;
};*/
template <typename T>
TVector<T>::TVector(int _size)
{
	if (_size <= 0)
		throw "error";
	size = _size;
	vec = new T[size];
};
template <typename T>
TVector<T>::TVector(const TVector<T>& obj)
{
	size = obj.size;
	vec = new T[size];
	for (int i = 0; i < size; i++)
		vec[i] = obj.vec[i];
};
template <typename T>
TVector<T>::~TVector()
{
	delete[] vec;
};
template <typename T>
TVector<T> TVector<T>::operator +(const TVector<T>& obj)
{
	if (size != obj.size)
		throw "Error";
	TVector<T> res(size);
	for (int i = 0; i < size; i++)
		res.vec[i] = vec[i] + obj.vec[i];
	return res;
};
template <typename T>
TVector<T> TVector<T> ::operator -(const TVector<T>& obj)
{
	if (size != obj.size)
		throw "Error";
	TVector<T> res(size);
	for (int i = 0; i < size; i++)
		res.vec[i] = vec[i] - obj.vec[i];
	return res;
};
template <typename T>
double TVector<T>::operator *(const TVector<T>& obj)
{
	if (size != obj.size)
		throw "Error";
	double res = 0.0;
	for (int i = 0; i < size; i++)
		res += vec[i] * obj.vec[i];
	return res;
};
template <typename T>
bool TVector<T>::operator==(const TVector<T>& obj) const
{
	if (size != obj.size)
		return false;
	for (int i = 0; i < size; i++)
		if (vec[i] != obj.vec[i])
			return false;
	return true;
};
template <typename T>
bool TVector<T>::operator!=(const TVector<T>& obj) const
{
	return !((*this) == obj);
};
template <typename T>
const TVector<T>& TVector<T>::operator=(const TVector<T>& obj)
{
	if (this == obj)
		return (*this);
	if (size != obj.size)
	{
		delete[] vec;
		size = obj.size;
		vec = new T[size];
	}
	for (int i = 0; i < size; i++)
		vec[i] = obj.vec[i];
	return (*this);
};
template <typename T>
double TVector<T>::Length() const
{
	double len = 0.0;
	for (int i = 0; i < size; i++)
		len += vec[i] * vec[i];
	double res = sqrt(len);
	return res;
};

#endif

