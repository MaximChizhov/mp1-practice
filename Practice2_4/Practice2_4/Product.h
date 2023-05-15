#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
using namespace std;

class TProduct
{
private:
	long code;
	string name;
	double price;
	int count;
public:
	TProduct();
	TProduct(long code, string name, double price, int cout);

	void set_product(const long& code, const string& name, const double& price, const int& cout);
	int get_code() { return code; }
	string get_name() { return name; }
	double get_price() { return price; }

	bool operator==(const TProduct& _p);
	friend ostream& operator<<(ostream& out, const TProduct& p);
};
struct Receiptline
{
	int count = 0;
	double sum = 0;
	TProduct product;
	bool operator==(const Receiptline& _p);
	friend ostream& operator<<(ostream& out, const Receiptline& r);
};
#endif // !PRODUCT_H