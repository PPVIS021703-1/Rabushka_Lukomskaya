#include "Statement.h"
#include "Card.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>


using namespace std;


// выписка о пополнении средств карточки
void Statement::ToFileIn(Card& card, double money) {
	ofstream record("statement.txt", ios::app);

	time_t now = time(0);
	tm* t = new tm;
	localtime_s(t, &now);

	if (record) {
		record << "\t--------------------------------" << endl;
		record << "\tПополнение средств:" << endl;

		record << "\tДата: ";
		if (t->tm_mday < 10) record << "0" << t->tm_mday << ".";
		else record << t->tm_mday << ".";
		record << 1 + t->tm_mon << "." << 1900 + t->tm_year << endl;

		record << "\tВремя: ";
		if (t->tm_hour < 10) record << "0" << t->tm_hour << ":";
		else record << t->tm_hour << ":";
		if (t->tm_min < 10) record << "0" << t->tm_min << ":";
		else record << t->tm_min << ":";
		if (t->tm_sec < 10) record << "0" << t->tm_sec << endl;
		else record << t->tm_sec << endl;

		record << "\tНомер карты: " << card.GetNumber() << endl;
		record << "\tСумма операции: " << money << endl;
		record << "\tДоступные средства: " << card.GetBalance() << endl;
		record << "\t--------------------------------" << endl;
	}

	record.close();
}

// выписка о снятии средств с карточки
void Statement::ToFileFrom(Card& card, double money) {
	ofstream record("statement.txt", ios::app);
	time_t now = time(0);
	tm* t = new tm;
	localtime_s(t, &now);
	if (record) {
		record << "\t--------------------------------" << endl;
		record << "\tСнятие средств:" << endl;

		record << "\tДата: ";
		if (t->tm_mday < 10) record << "0" << t->tm_mday << ".";
		else record << t->tm_mday << ".";
		record << 1 + t->tm_mon << "." << 1900 + t->tm_year << endl;

		record << "\tВремя: ";
		if (t->tm_hour < 10) record << "0" << t->tm_hour << ":";
		else record << t->tm_hour << ":";
		if (t->tm_min < 10) record << "0" << t->tm_min << ":";
		else record << t->tm_min << ":";
		if (t->tm_sec < 10) record << "0" << t->tm_sec << endl;
		else record << t->tm_sec << endl;

		record << "\tНомер карты : " << card.GetNumber() << endl;
		record << "\tСумма операции: " << money << endl;
		record << "\tОстаток средств: " << card.GetBalance() << endl;
		record << "\t--------------------------------" << endl;
	}

	record.close();
}

//выписка о пополнении счета в банке
void Statement::ToFileIn(Bankomat& bank, double money) {
	ofstream record("statement.txt", ios::app);
	time_t now = time(0);
	tm* t = new tm;
	localtime_s(t, &now);
	if (record) {
		record << "\t--------------------------------" << endl;
		record << "\tПополнение счета:" << endl;

		record << "\tДата: ";
		if (t->tm_mday < 10) record << "0" << t->tm_mday << ".";
		else record << t->tm_mday << ".";
		record << 1 + t->tm_mon << "." << 1900 + t->tm_year << endl;

		record << "\tВремя: ";
		if (t->tm_hour < 10) record << "0" << t->tm_hour << ":";
		else record << t->tm_hour << ":";
		if (t->tm_min < 10) record << "0" << t->tm_min << ":";
		else record << t->tm_min << ":";
		if (t->tm_sec < 10) record << "0" << t->tm_sec << endl;
		else record << t->tm_sec << endl;

		record << "\tСчет получателя: " << bank.GetNumber() << endl;
		record << "\tСумма операции: " << money << endl;
		record << "\tДоступные средства: " << bank.GetBalance() << endl;
		record << "\t--------------------------------" << endl;
	}

	record.close();
}

// вывод выписки
void Statement::Print(Singleton* log) {
	ifstream read("statement.txt");

	if (read) {
		while (!read.eof()) {
			string str;
			getline(read, str);
			cout << str << endl;
		}
	}

	read.close();
	log->SingletonOperation("Предоставление выписки", 1);
}

