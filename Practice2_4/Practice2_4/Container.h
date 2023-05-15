#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class TContainer
{
private:
	int size;//реальный размер
	int n;//всего можно
	const int sizestep = 5;
	T* data;
public:
	TContainer(int _n = 2)
	{
		n = _n;
		size = 0;
		data = new T[n];
	}
	TContainer(const T& container)
	{
		n = container.n;
		data = new T[n];
		for (int i = 0; i < n; i++)
			data[i] = container.data[i];
	}
	~TContainer()
	{
		delete[] data;
	}

	int Find(const T& el)
	{
		int nom = -1;
		int i = 0;
		while (i < size && nom == -1)
		{
			if (data[i] == el)
				nom = i;
			else
				i++;
		}
		return nom;
	};
	void resize(int dsize = 0)
	{
		if (dsize == 0)
			dsize = sizestep;
		n += dsize;
		T* tmp = new T[n];
		for (int i = 0; i < size; i++)
			tmp[i] = data[i];
		delete[] data;
		data = tmp;
	};
	void add(T value)
	{
		int k;
		if (Find(value) == -1)
		{
			if (size == n)
				resize();
			cout << "Enter the quantity of the product: ";
			cin >> k;
			value.count = k;
			value.sum = value.sum * k;
			data[size++] = value;
		}
		else
		{
			cout << "Enter the quantity of the product: ";
			cin >> k;
			int pos = Find(value);
			data[pos].count += k;
			data[pos].sum += value.sum * k;
		}
	};
	void add_before(T value, int ind)
	{
		int ind_ = ind - 1;
		if (ind > -1 && ind < size + 1)
		{
			if (size == n)
				resize();
			for (int i = size - 1; i >= ind_; i--)
				data[i + 1] = data[i];
			int k;
			cout << "Enter the quantity of the product: ";
			cin >> k;
			value.count = k;
			value.sum = value.sum * k;
			data[ind_] = value;
			size++;
			cout << "Successfully" << endl;
		}
		else
			cout << "Error, position not found" << endl;;
	};
	void add_after(T value, int ind)
	{
		int k;
		int ind_ = ind;
		if (ind > 0 && ind < size + 1)
		{
			if (size == n)
				resize();

			for (int i = size - 1; i >= ind_; i--)
				data[i + 1] = data[i];
			cout << "Enter the quantity of the product: ";
			cin >> k;
			value.count = k;
			value.sum = value.sum * k;
			data[ind_] = value;
			size++;
			cout << "Successfully" << endl;
		}
		else
			cout << "Error, position not found" << endl;
	};
	void remove(const T& value)
	{
		int num;
		for (int i = 0; i < size; ++i)
		{
			if (data[i] == value)
			{
				cout << "Enter how much you want to delete: ";
				cin >> num;
				if (num > data[i].count)
				{
					cout << "Error, the quantity of products in the receipt is more than you entered" << endl;
					break;
				}
				data[i].count -= num;
				data[i].sum -= value.sum * num;
				cout << "Successfully" << endl;
				break;
			}
		}
	};
	void remove_ind(int ind)
	{
		if (ind > -1 && ind < n)
			for (int i = ind; i < n - 1; i++)
				data[i] = data[i + 1];
		size--;
		cout << "Successfully" << endl;
	};
	const int& Size() const { return size; }
	int& N() { return n; }
	const int& Stepsize() { return sizestep; }

	double total_sum()
	{
		double s = 0;
		for (int i = 0; i < size; i++)
			s += data[i].sum;
		return s;
	}

	TContainer& operator[](int index)
	{
		if ((index < 0) || (index > n))
			throw "Error";
		return data[index];
	};
	friend ostream& operator<<(ostream& out, const TContainer& data)
	{
		out << "<===========================================================>" << endl;
		for (int i = 0; i < data.Size(); i++)
			out << data.data[i] << endl;
		out << "<===========================================================>" << endl;
		return out;
	};
};
#endif // !CONTAINER_H