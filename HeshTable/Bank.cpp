#include "Bank.h"

Bank::Bank()
{
	m = 50;
	arr = new Order[m];
	count = 0;
}

Bank::Bank(int payerAcc, int benAcc, int transfAmount)
{
	m = 50;
	arr = new Order[m];
	count = 1;
	arr[keygen(payerAcc)] = Order(payerAcc,benAcc,transfAmount,1);
}



void Bank::set(int payerAcc, int benAcc, int transfAmount)
{
		arr[keygen(payerAcc)] = Order(payerAcc, benAcc, transfAmount, ++count);
}

Order Bank::find(int payerAcc)
{
	return arr[keygen(payerAcc)];
}


int Bank::findNumber(int payerAcc)
{
	return arr[keygen(payerAcc)].number;
}

void Bank::read(string fileName)
{
	ifstream in(fileName); // окрываем файл для чтения
	if (in.is_open())
	{
		in >> *this;
	}
	in.close();
}

void Bank::writeBean(ofstream& os)
{
	int payerAcc;
	int benAcc;
	int transfAmount;
	for (int i = 0; i < m; i++) {
		if (arr[i].number != -1) {
			payerAcc = arr[i].payerAcc;
			benAcc = arr[i].benAcc;
			transfAmount = arr[i].transfAmount;
			os.write((char*)&payerAcc, sizeof(payerAcc));
			os.write((char*)&benAcc, sizeof(benAcc));
			os.write((char*)&transfAmount, sizeof(transfAmount));
		}
	}
}

Bank Bank::readBean(ifstream& is,int n)
{
	int payerAcc;
	int benAcc;
	int transfAmount;
	for (int i = 0; i < n; i++) {
		is.read((char*)&payerAcc, sizeof(payerAcc));
		is.read((char*)&benAcc, sizeof(benAcc));
		is.read((char*)&transfAmount, sizeof(transfAmount));
	}
	arr[keygen(payerAcc)] = Order(payerAcc, benAcc, transfAmount, ++count);
	return *this;
}

ostream& operator<<(ostream& os, const Bank& b)
{
	for (int i = 0; i < b.m; i++) {
		if (b.arr[i].number !=  -1) {
			os << endl << endl;
			os << "Payer current account :" << b.arr[i].payerAcc << endl;
			os << "Beneficiary current account :" << b.arr[i].benAcc << endl;
			os << "Transferred amount :" << b.arr[i].transfAmount << endl;
		}
	}
	return os;
}

istream& operator>>(istream& is, Bank& b)
{
	int payerAcc;
	int benAcc;
	int transfAmount;
	is >> payerAcc >> benAcc >> transfAmount;
	b.count++;
	b.arr[payerAcc/b.m] = Order(payerAcc, benAcc, transfAmount, b.count);
	return is;
}
