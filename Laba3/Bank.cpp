#include "Bank.h"
#include <fstream>
#include <string>
#include "Card.h"
using namespace std;

// конструктор
Bank::Bank() {
	
	//int chosen = GetChosen();
	chosen = 1111;
	//cout << chosen;
	string card_number = "no";
	string card_holder = "no";
	string card_data = "no";
	int card_pin = 0;
	int card_cvv = 0;
	double card_balance;
	string empty;
	int k = 0, l = chosen - 1;
	//cout << chosen;

	ifstream from_card("card.txt");
	if (from_card) {
		from_card >> k;
		getline(from_card, empty);
			
		for (int i = 0; i < k; i++) {
			if (i == l) {
				getline(from_card, card_number);
				SetNumber(card_number);
				getline(from_card, card_data);
				SetCardData(card_data);
				getline(from_card, card_holder);
				SetHolder(card_holder);
				from_card >> card_pin;
				getline(from_card, empty);
				SetCardPin(card_pin);
				from_card >> card_cvv;
				getline(from_card, empty);
				from_card >> card_balance;
				SetBalance(card_balance);
				getline(from_card, empty);
				break;
			}
			else {
				getline(from_card, card_number);
				getline(from_card, card_data);
				getline(from_card, card_holder);
				from_card >> card_pin;
				getline(from_card, empty);
				from_card >> card_cvv;
				getline(from_card, empty);
				from_card >> card_balance;
				getline(from_card, empty);
			}
		}

	}
	from_card.close();
}


//геттеры и сеттеры
string Bank::GetNumber() {
	return number;
}
string Bank::GetHolder() {
	return holder;
}
string Bank::GetCardData() {
	return card_data;
}
int Bank::GetCardPin() {
	return card_pin;
}
double Bank::GetBalance() {
	return balance;
}
int Bank::GetCardCvv() {
	return card_cvv;
}
int Bank::GetCardChosen() {
	return chosen;
}

void Bank::SetNumber(string number) {
	this->number = number;
}
void Bank::SetHolder(string holder) {
	this->holder = holder;
}
void Bank::SetCardPin(int pin) {
	this->card_pin = pin;
}
void Bank::SetCardData(string data) {
	this->card_data = data;
}
void Bank::SetBalance(double balance) {
	this->balance = balance;
}
void Bank::SetCardChosen(int n) {
	this->chosen = n;
}
void Bank::SetCardCvv(int n) {
	this->card_cvv = n;
}

// копирование данных о карточке
void Bank::CopyData() {
	ifstream from_card("card.txt");
	ofstream new_card("newcard.txt");

	string card_number = "no";
	string card_holder = "no";
	string card_data = "no";
	int card_pin = 0;
	int card_cvv = 0;
	double card_balance;
	string empty;
	int k;

	if (from_card) {
		if (new_card) {
			from_card >> k;
			getline(from_card, empty);
			new_card << k << endl;
			for (int i = 0; i < k; i++) {
				getline(from_card, card_number);
				new_card << card_number << endl;
				getline(from_card, card_data);
				new_card << card_data << endl;
				getline(from_card, card_holder);
				new_card << card_holder << endl;
				from_card >> card_pin;
				new_card << card_pin << endl;
				getline(from_card, empty);
				from_card >> card_cvv;
				new_card << card_cvv << endl;
				getline(from_card, empty);
				from_card >> card_balance;
				new_card << card_balance << endl;
				getline(from_card, empty);

			}
		}
	}
	from_card.close();
	new_card.close();
}

// копирование данных о счете в банке
void Bank::CopyAccount() {
	ifstream from_account("ac.txt");
	ofstream new_account("newac.txt");

	if (from_account) {
		if (new_account) {
			string ac_num, ac_hol;
			int na;
			getline(from_account, ac_num);
			new_account << ac_num << endl;

			getline(from_account, ac_hol);
			new_account << ac_hol << endl;

			from_account >> na;
			new_account << na << endl;
		}
	}
	from_account.close();
	new_account.close();
}
