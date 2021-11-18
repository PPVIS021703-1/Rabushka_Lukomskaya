#include <iostream>
#include "Bankomat.h"
#include "Card.h"
#include <fstream>
#include <string>

using namespace std;

Bankomat::Bankomat() {
	string bank_number = "no";
	string bank_holder = "no";
	double bank_balance = 0;

	ifstream from_acc("ac.txt");
	if (from_acc) {
		getline(from_acc, bank_number);
		SetNumber(bank_number);
		getline(from_acc, bank_holder);
		SetHolder(bank_holder);
		from_acc >> bank_balance;
		SetBalance(bank_balance);

	}
	from_acc.close();
}
void Bankomat::Print(Singleton* log) {
	cout << "\t-------------------------------------" << endl;
	cout << "\t     Данные банковского счета: " << endl;
	cout << "\t-------------------------------------" << endl;
	cout << "\tНомер счета: " << GetNumber() << endl;
	cout << "\tВладелец счета: " << GetHolder() << endl;
	cout << "\tДоступные средства: " << GetBalance() << endl;
}
