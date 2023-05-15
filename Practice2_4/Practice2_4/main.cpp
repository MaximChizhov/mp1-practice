#include <iostream>
#include <fstream>
#include <string>
#include "Receipt.h"
using namespace std;


int main()
{
    int cntStr;
    string f = "products.txt";
    cntStr = cntStruct(f);
    TProduct** p = new TProduct * [cntStr];

    read(p, cntStr, f);
    for (int i = 0; i < cntStr; i++)
        cout << *(p[i]) << endl;
    Enter(p, cntStr);

    for (int i = 0; i < cntStr; i++)
        delete p[i];
    delete[]p;

    return 0;
}