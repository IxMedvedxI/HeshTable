#include <iostream>
#include "Bank.h"
using namespace std;
int main()
{
    Bank bank(1, 2, 3);
    bank.set(0, 4, 2);
    bank.set(0, 10, 4);
    bank.set(5, 30, 2);
    ofstream filew("file.bin", ios::binary | ios::app);
    bank.writeBean(filew);
    ifstream file2("file.bin", ios::binary | ios::app);
    Bank tinkof;
    cout<<tinkof.readBean(file2,1);
    cout << bank.findNumber(5);
    cout << bank;
}

