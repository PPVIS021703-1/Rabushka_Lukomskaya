#include <iostream>
#include <string>
#include <cstdlib>
#include "Currency.h"
#include "Exception.h"

using namespace std;

// вывод на экран
void Currency::Print(Singleton* log) {
	cout << "\tКУРС ВАЛЮТ" << endl << endl;
	/*cout << "\t" << kazah << kazah_t << endl;
	cout << "\t" << kvacha << kvacha_t << endl;
	cout << "\t" << kirgiz << kirgiz_t << endl;
	cout << "\t" << ukrain << ukrain_t << endl;
	cout << "\t" << myanma << myanma_t << endl;*/
	
	log->SingletonOperation("Вывод курса валют", 1);
	system("pause");
	system("cls");
}

// обмен валют
double Currency::Choice() {
	int a;
	double value;
	cout << "\tВЫБЕРИТЕ ВАЛЮТУ" << endl << endl;
	cout << "\t1 - " << GetKaz() << endl << "\t*минимальная доступная сумма: 1740 тенге" << endl;
	/*cout << "\t2 - " << kvacha << kvacha_t << endl << "\t*минимальная доступная сумма: 70 квач" << endl;;
	cout << "\t3 - " << kirgiz << kirgiz_t << endl << "\t*минимальная доступная сумма: 350 сом" << endl;;
	cout << "\t4 - " << ukrain << ukrain_t << endl << "\t*минимальная доступная сумма: 110 гривен" << endl;;
	cout << "\t5 - " << myanma << myanma_t << endl << "\t*минимальная доступная сумма: 7770 кьят" << endl;*/
	cin >> a;
	cout << "\tВведите сумму, которую желаете снять (в выбранной валюте): " << endl;
	cin >> value;
	
	switch (a)
	{
	case 1: {

		if (value < 1740) {
			cout << "\tМинимальная доступная сумма: 1740 тенге. Попробуйте еще раз позже!" << endl << endl;
			value = 0;
			break;
		}
		value = value / Currency::GetKaz();

		break;
	}
	case 2: {
		if (value < 70) {
			cout << "\tМинимальная доступная сумма: 70 квач. Попробуйте еще раз позже!" << endl << endl;
			value = 0;
			break;
		}
		//value /= kvacha;
		break;
	}
	case 3: {
		if (value < 350) {
			cout << "\tМинимальная доступная сумма: 350 сом. Попробуйте еще раз позже!" << endl << endl;
			value = 0;
			break;
		}
		//value /= kirgiz;
		break;
	}
	case 4: {
		if (value < 110) {
			cout << "\tМинимальная доступная сумма: 110 гривен. Попробуйте еще раз позже!" << endl << endl;
			value = 0;
			break;
		}
		//value /= ukrain;
		break;
	}
	case 5: {
		if (value < 7770) {
			cout << "\tМинимальная доступная сумма: 7770 кьят. Попробуйте еще раз позже!" << endl << endl;
			value = 0;
			break;
		}
		//value /= myanma;
		break;
	}
	default:
		cout << "\tНеверный номер операции! Попробуйте еще раз." << endl << endl;
		break;
	}
	
	return value;
}

// снять с карточки 
void Currency::MoneyOut(Card& card,double money, Singleton* log) {
	card.CopyData();
	
	try {
		if (money > card.GetBalance() || money < 0) {
			throw Exception("Недопустимый вид ввода", "Обмен валют");
		}
		else {

			double new_money = card.GetBalance() - money;

			/*if (record_) {
				record_ << card.GetNumber() << endl;
				record_ << card.GetCardData() << endl;
				record_ << card.GetHolder() << endl;
				record_ << card.GetCardPin() << endl;
				record_ << card.GetCardCvv() << endl;
				card.SetBalance(new_money);
				record_ << new_money << endl;
			}*/

			
			string card_number = "no";
			string card_holder = "no";
			string card_data = "no";
			int card_pin = 0;
			int card_cvv = 0;
			double card_balance;
			string empty;
			int k1 = 0, l = card.GetCardChosen() - 1;
			cout << l << endl;
			//cout << l;
			//system("pause");
			//cout << chosen << endl;
			ifstream from_card("newcard.txt");
			ofstream record_("card.txt");


			if (from_card) {
				if (record_) {
					from_card >> k1;
					record_ << k1 << endl;
					getline(from_card, empty);
					cout << k1 << endl;
					for (int i = 0; i < k1; i++) {
						if (i == l) {
							
							record_ << card.GetNumber() << endl;
							record_ << card.GetCardData() << endl;
							record_ << card.GetHolder() << endl;
							record_ << card.GetCardPin() << endl;
							record_ << card.GetCardCvv() << endl;
							card.SetBalance(new_money);
							record_ << new_money << endl;
							//break;
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

							
							record_ << card_number << endl;
							record_ << card_data << endl;
							record_ << card_holder << endl;
							record_ << card_pin << endl;
							record_ << card_cvv << endl;
							record_ << card_balance << endl;
						}
					}
				}
			}
			from_card.close();
			record_.close();

			cout << "" << endl;
			log->SingletonOperation("Выдыча наличных: обмен валют", 1);
			PauseF();
			cout << "\tЗаберите ваши деньги!" << endl << endl;
			PauseF();
			cout << endl << "\tЖелаете забрать чек? " << endl;
			cout << "\t1 - Да" << endl << "\t2 - Нет" << endl;
			int k;
			cin >> k;
			switch (k) {
			case 1: {
				time_t now = time(0);
				tm* t = new tm;
				localtime_s(t, &now);

				cout << "\tЗаберите ваш чек!" << endl << endl;
				cout << "\t--------------------" << endl;
				cout << "\tКод операции: 003" << endl;
				cout << "\tДата: ";
				if (t->tm_mday < 10) cout << "0" << t->tm_mday << ".";
				else cout << t->tm_mday << ".";
				cout << 1 + t->tm_mon << "." << 1900 + t->tm_year << endl;

				cout << "\tВремя: ";
				if (t->tm_hour < 10) cout << "0" << t->tm_hour << ":";
				else cout << t->tm_hour << ":";
				if (t->tm_min < 10) cout << "0" << t->tm_min << ":";
				else cout << t->tm_min << ":";
				if (t->tm_sec < 10) cout << "0" << t->tm_sec << endl;
				else cout << t->tm_sec << endl;
				cout << "\tСумма выдачи: " << money << endl;
				cout << "\t--------------------" << endl;
				log->SingletonOperation("Выдача чека", 1);
				PauseF();
				cout << endl;
				break;

			}
			case 2: {
				break;
			}
			}
		}
	}
	catch (Exception& exception) {
		cerr << exception.what() << endl << endl;
		log->SingletonOperation("Выдыча наличных: обмен валют", 0);
		ofstream record("card.txt");
		ifstream read("newcard.txt");

		string card_number = "no";
		string card_holder = "no";
		string card_data = "no";
		int card_pin = 0;
		int card_cvv = 0;
		double card_balance;
		string empty;

		if (record) {
			int k;
			read >> k;
			getline(read, empty);
			record << k << endl;
			for (int i = 0; i < k; i++) {
				getline(read, card_number);
				record << card_number << endl;
				getline(read, card_data);
				record << card_data << endl;
				getline(read, card_holder);
				record << card_holder << endl;
				read >> card_pin;
				record << card_pin << endl;
				getline(read, empty);
				read >> card_cvv;
				record << card_cvv << endl;
				getline(read, empty);
				read >> card_balance;
				record << card_balance << endl;
				getline(read, empty);

			}
		}
		record.close();
		read.close();
	}

	ToFileFrom(card, money);
	
}

// запись в выписку
void Currency::ToFileFrom(Card& card, double money) {
	ofstream record("statement.txt", ios::app);

	if (record) {
		time_t now = time(0);
		tm* t = new tm;
		localtime_s(t, &now);

		record << "\t--------------------------------" << endl;
		record << "\tСнятие средств:" << endl;

		record << "Дата: ";
		if (t->tm_mday < 10) record << "0" << t->tm_mday << ".";
		else record << t->tm_mday << ".";
		record << 1 + t->tm_mon << "." << 1900 + t->tm_year << endl;

		record << "Время: ";
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