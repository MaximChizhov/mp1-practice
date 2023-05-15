#ifndef KASSA_H
#define KASSA_H
#include <string>
#include <iostream>
#include "Container.h"
#include "DateTime.h"
#include "Product.h"
using namespace std;

class Receipt
{
private:
	TDate date_;
	TTime time_;
	TContainer<Receiptline> products;
public:
	double Total_sum();
	int Find(const Receiptline line);
	void Add(const Receiptline line);
	void Add_B(const Receiptline line, int ind);
	void Add_A(const Receiptline line, int ind);
	void Remove(const Receiptline line);
	void Remove_Ind(int ind);
	void Print();

	friend ostream& operator<<(ostream& out, const Receipt& p);
};

void read(TProduct** p, int cntStr, string& f);
void Enter(TProduct** p, int cntStr);
int cntStruct(string& f);
void removeFirstN(string& str, int n);
#endif // !KASSA_H
