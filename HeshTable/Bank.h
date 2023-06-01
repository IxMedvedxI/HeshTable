#include <ostream>
#include <iostream>
#include <fstream>
using namespace std;

class Order{
public:
	int payerAcc;
	int benAcc;
	int transfAmount;
	int number;
	Order(){
		payerAcc = 0;
		benAcc = 0;
		transfAmount = 0;
		number = -1;
	}
	Order(int payerAcc,int benAcc,int transfAmount,int number) {
		this->payerAcc = payerAcc;
		this->benAcc = benAcc;
		this->transfAmount = transfAmount;
		this->number = number;
	}
};

class Bank
{
private:

	Order* arr;
	int m;
	int count;
	int keygen(int payerAcc) {
		return payerAcc % m;
	}
	//Order* create(int payerAcc, int benAcc, int transfAmount,int number) {
	//	Order* buf = new Order(payerAcc, benAcc, transfAmount, number);
	//	return buf;
	//}
public:
	Bank();
	Bank(int payerAcc, int benAcc, int transfAmount);
	void set(int payerAcc, int benAcc, int transfAmount);
	Order find(int payerAcc);
	int findNumber(int payerAcc);
	void read(string fileName);
	void writeBean(ofstream& os);
	Bank readBean(ifstream& is, int n);
	friend ostream& operator<<(ostream& os, const Bank& b);
	friend istream& operator>>(istream& is, Bank& b);
};

