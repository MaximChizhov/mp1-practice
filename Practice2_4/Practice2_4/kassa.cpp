#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Receipt.h"
#include "Container.h"
#include "DateTime.h"
#include "Product.h"
using namespace std;

TProduct::TProduct()
{
	code = 0;
	name = "";
	price = 0.0;
	count = 0;
}
TProduct::TProduct(long code, string name, double price, int count)
{
	this->code = code;
	this->name = name;
	this->price = price;
	this->count = count;
}

void TProduct::set_product(const long& p_code, const string& p_name, const double& p_price, const int& p_count)
{
	code = p_code;
	name = p_name;
	price = p_price;
	count = p_count;
}

bool TProduct::operator==(const TProduct& _p)
{
	if (code == _p.code)
		return true;
	return false;
}

ostream& operator<<(ostream& out, const TProduct& p)
{
	out << setprecision(2) << std::fixed;
	out << p.code << " " << p.name << " " << p.price;
	return out;
}

bool Receiptline::operator==(const Receiptline& _p)
{
	if (product == _p.product)
		return true;
	return false;
}

ostream& operator<<(ostream& out, const Receiptline& r)
{
	out << r.product << " " << r.count << " " << r.sum;
	return out;
}

double Receipt::Total_sum()
{
	double s = products.total_sum();
	return s;
}

int Receipt::Find(const Receiptline line)
{
	int ind = products.Find(line);
	return ind;
}
void Receipt::Add(const Receiptline line)
{
	products.add(line);
}

void Receipt::Add_B(const Receiptline line, int ind)
{
	products.add_before(line, ind);
}

void Receipt::Add_A(const Receiptline line, int ind)
{
	products.add_after(line, ind);
}

void Receipt::Remove(const Receiptline line)
{
	products.remove(line);
}

void Receipt::Remove_Ind(int ind)
{
	products.remove_ind(ind);
}

ostream& operator<<(ostream& out, const Receipt& p)
{
	out << p.products;
	return out;
}

void Receipt::Print()
{
	cout << date_ << " " << time_ << endl;
}

void read(TProduct** p, int cntStr, string& f)
{
	fstream file;
	file.open(f);
	if (!file.is_open())
		throw "File open error";
	long code;
	string name;
	double price;
	int count;
	for (int i = 0; i < cntStr; i++)
	{
		string str = "";
		int flag = 0;
		while ((getline(file, str, ';')) && (flag < 3))
		{
			if (flag == 0)
			{
				if (i != 0)
					removeFirstN(str, 1);
				code = stol(str);
			}
			if (flag == 1)
				name = str;
			if (flag == 2)
				price = stod(str);
			flag++;
		}
		count = stoi(str);
		p[i] = new TProduct();
		p[i]->set_product(code, name, price, count);
	}
	file.close();
}

void Enter(TProduct** p, int cntStr)
{
	Receipt rep;
	Receiptline line;
	int code, ind;
	int num = 0;
	int num_r = 0;
	int num_i = 0;
	int num_a = 0;
	cout << "Enter the code or '0' to generate a receipt: ";
	cin >> code;
	while (code != 0)
	{

		for (int i = 0; i < cntStr; i++)
		{
			if (code == p[i]->get_code())
			{

				line.product = *p[i];
				line.count = 1;
				line.sum = p[i]->get_price();
				cout << line << endl;
			A:
				do {
					cout << "Do you want add or remove the product? " << endl;
					cout << "1. add" << endl;
					cout << "2. remove" << endl;
					cin >> num;
				} while (num < 1 || num > 3);
				if (num == 1)
				{
				B:
					do
					{
						cout << "Where do you want to insert?" << endl;
						cout << "1. At the end" << endl;
						cout << "2. By position" << endl;
						cout << "3. Return" << endl;
						cin >> num_a;
					} while (num_a < 1 || num_a > 3);

					if (num_a == 1)
					{
						rep.Add(line);
						cout << "Successfully" << endl;
						cout << rep;;
					}
					if (num_a == 2)
					{
						do
						{
							cout << "1. Before position" << endl;
							cout << "2. After position" << endl;
							cout << "3. Return" << endl;
							cin >> num_i;
						} while (num_i < 1 || num_i > 3);

						if (num_i == 1)
						{
							cout << "Enter position: ";
							cin >> ind;
							rep.Add_B(line, ind);
							cout << rep;
						}
						if (num_i == 2)
						{
							cout << "Enter position: ";
							cin >> ind;
							rep.Add_A(line, ind);
							cout << rep;
						}
						if (num_i == 3)
							goto B;
					}
					if (num_a == 3)
						goto A;
				}
				if (num == 2)
				{
					do {
						cout << "Do you want remove position or count of product?" << endl;
						cout << "1. position" << endl;
						cout << "2. count" << endl;
						cout << "3. return" << endl;
						cin >> num_r;
					} while (num_r < 1 || num_r > 3);
					if (num_r == 1)
					{
						int in = rep.Find(line);
						if (in == -1)
						{
							cout << "Error, no such product was found in your receipt" << endl;
							cout << rep;
							break;
						}
						rep.Remove_Ind(in);
						cout << "Successfully" << endl;
						cout << rep;
					}
					if (num_r == 2)
					{
						int in = rep.Find(line);
						if (in == -1)
						{
							cout << "Error, no such product was found in your receipt" << endl;
							cout << rep;
							break;
						}
						rep.Remove(line);
						cout << rep;
					}
					if (num_r == 3)
						goto A;
				}
				break;
			}
			if (i == cntStr - 1)
				cout << "Error, no product was found in the warehouse" << endl;
		}
		cout << "Enter the code or '0' to generate a receipt: ";
		cin >> code;
	}
	system("cls");
	double s = rep.Total_sum();
	cout << endl << "Your receipt:" << endl;
	cout << rep;
	cout << "To be paid: " << s << endl;
	rep.Print();
}

int cntStruct(string& f)
{
	fstream file;
	file.open(f);
	char* str = new char[1024];
	int i = 0;
	if (!file.is_open())
		throw "File open error";
	while (!file.eof())
	{
		file.getline(str, 1024, '\n');
		i++;
	}
	delete[]str;
	file.close();
	return i;
}

void removeFirstN(string& str, int n)
{
	str.erase(0, n);
}