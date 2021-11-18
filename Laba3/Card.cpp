#include <iostream>
#include "Card.h"

//конструктор -----  ввод данных о карточке из файлика
Card::Card(int n) {
	int chosen = n;
	string card_number = "no";
	string card_holder = "no";
	string card_data = "no";
	int card_pin = 0;
	int card_cvv = 0;
	double card_balance;
	string empty;
	int k = 0, l = chosen - 1;
	//cout << l;
	//system("pause");
	//cout << chosen << endl;
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
				SetCardCvv(card_cvv);
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


// вывод данных о карточке
void Card::Print(Singleton* log) {
	cout << "\t-------------------------" << endl;
	cout << "\t     Данные карты: " << endl;
	cout << "\t-------------------------" << endl;
	
	cout << "\tНомер карточки: ";// << GetNumber() << endl;
	Secret(GetNumber());
	cout << "\tВладелец карточки: " << GetHolder() << endl;
	cout << "\tСрок эксплутации: " << GetCardData() << endl;
	cout << "\tДоступные средства: " << GetBalance() << endl;
	log->SingletonOperation("Данные банковской карточки", 1);
}

void Card::Secret(string s) {
	int space = 0;
	
	for (int i = 0; i < s.size(); i++) {
		if (space == 3) {
			cout << s[i] << s[i + 1] << s[i + 2] << s[i + 3] << endl;
			break;
		}
		else {
			if (s[i] == ' ') { cout << " "; space++; }
			else cout << "*";
		}
	}
}
