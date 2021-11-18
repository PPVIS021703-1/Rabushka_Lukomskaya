#include <iostream>
#include "CardSessions.h"
#include <Windows.h>
#include <string>
#include "Statement.h"
#include "Exception.h"

using namespace std;

// пауза
void CardSessions::PauseF() {
	cout << "\t. ";
	Sleep(1000);
	cout << "\t. ";
	Sleep(1000);
	cout << "\t. ";
	Sleep(1000);
	cout << endl;
}

// снять деньги с карточки
void GiveMoney::MoneyOut(Card& card, Singleton* log) {
	double money;
	card.CopyData();
	//ofstream record_("card.txt");

	
	cout << "\tВведите сумму выдачи: ";
	cin >> money;
	try {
		if (money > card.GetBalance() || money < 0) {
			log->SingletonOperation("Выдача наличных", 0);
			throw Exception("Некорректно введенные данные", "Выдача наличных");
		}
		else {

			double new_money = card.GetBalance() - money;

			/*if (record_) {
				record_ << card.GetNumber() << endl;
				record_ << card.GetCardData() << endl;
				record_ << card.GetHolder() << endl;
				record_ << card.GetCardPin() << endl;
				record_ << card.GetCardCvv() << endl;
				record_ << new_money << endl;
				card.SetBalance(new_money);
			}*/


			string card_number = "no";
			string card_holder = "no";
			string card_data = "no";
			int card_pin = 0;
			int card_cvv = 0;
			double card_balance;
			string empty;
			int k1 = 0, l = card.GetCardChosen() - 1;
			//cout << l << endl;
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
					//cout << k1 << endl;
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


			log->SingletonOperation("Выдача наличных", 1);
			PauseF();
			cout << endl << "\tЗаберите ваши деньги!" << endl;
			PauseF();
			cout << endl << "\tЖелаете забрать чек? " << endl;
			cout << "\t1 - Да" << endl << "\t2 - Нет" << endl;
			int k;
			cin >> k;
			switch (k) {
			case 1: {
				log->SingletonOperation("Выдача чека", 1);
				time_t now = time(0);
				tm* t = new tm;
				localtime_s(t, &now);

				cout << "\tЗаберите ваш чек!" << endl << endl;
				cout << "\t--------------------" << endl;
				cout << "\tКод операции: 002" << endl;
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
		ofstream record("card.txt");
		if (record) {
			record << card.GetNumber() << endl;
			record << card.GetCardData() << endl;
			record << card.GetHolder() << endl;
			record << card.GetCardPin() << endl;
			record << card.GetCardCvv() << endl;
			record << card.GetBalance() << endl;
		}
		record.close();
	}

	ToFileFrom(card, money);
	
	//remove("newcard.txt");
}

// положить деньги на карточку
void GetMoney::MoneyIn(Card& card, Singleton* log) {
	double money;
	cout << "\tВставьте купюру: ";
	cin >> money;
	//ofstream record("card.txt");
	double new_money = card.GetBalance() + money;

	/*if (record) {
		record << card.GetNumber() << endl;
		record << card.GetCardData() << endl;
		record << card.GetHolder() << endl;
		record << card.GetCardPin() << endl;
		record << card.GetCardCvv() << endl;
		record << new_money << endl;
		card.SetBalance(new_money);
	}*/



	string card_number = "no";
	string card_holder = "no";
	string card_data = "no";
	int card_pin = 0;
	int card_cvv = 0;
	double card_balance;
	string empty;
	int k1 = 0, l = card.GetCardChosen() - 1;
	//cout << l << endl;
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
			//cout << k1 << endl;
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

	cout << endl;
	PauseF();
	cout << "\tОдобрено! Операция выполнена успешно!" << endl;
	//record.close();
	ToFileIn(card, money);
	log->SingletonOperation("Перевод средств на карточку", 1);
}

// оплата с карточки на счёт за услуги
void Payement::Pay(Card& card, Bankomat& bank) {
	double money;
	bank.CopyAccount();
	card.CopyData();
	ofstream record("ac.txt");
	cout << "\tВведите пин-код: ";
	int pin;
	cin >> pin;
	for (int i = 3; i >= 1; i--) {
		if (i - 1 == 0) break;
		else {
			if (pin != card.GetCardPin()) {
				cout << pin << endl;
			}
			else if(pin == card.GetCardPin()) {
				cout << "\tВведите сумму перевода: ";
				cin >> money;
				try {

					if (money < 0) {
						throw Exception("Неверный формат ввода", "Оплата услуг");
					}
					else {
						card.CopyData();
						ofstream record_("card.txt");
						ifstream read("newac.txt");
						
						double new_money = card.GetBalance() - money;

						/*if (record_) {
							record_ << card.GetNumber() << endl;
							record_ << card.GetCardData() << endl;
							record_ << card.GetHolder() << endl;
							record_ << card.GetCardPin() << endl;
							record_ << card.GetCardCvv() << endl;
							record_ << new_money << endl;
							card.SetBalance(new_money);
							ToFileFrom(card, money);
						}*/


						string card_number = "no";
						string card_holder = "no";
						string card_data = "no";
						int card_pin = 0;
						int card_cvv = 0;
						double card_balance;
						string empty;
						int k1 = 0, l = card.GetCardChosen() - 1;
						//cout << l << endl;
						//cout << l;
						//system("pause");
						//cout << chosen << endl;
						ifstream from_card("newcard.txt");
						ofstream record_1("card.txt");


						if (from_card) {
							if (record_1) {
								from_card >> k1;
								record_1 << k1 << endl;
								getline(from_card, empty);
								//cout << k1 << endl;
								for (int i = 0; i < k1; i++) {
									if (i == l) {

										record_1 << card.GetNumber() << endl;
										record_1 << card.GetCardData() << endl;
										record_1 << card.GetHolder() << endl;
										record_1 << card.GetCardPin() << endl;
										record_1 << card.GetCardCvv() << endl;
										card.SetBalance(new_money);
										record_1 << new_money << endl;
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


										record_1 << card_number << endl;
										record_1 << card_data << endl;
										record_1 << card_holder << endl;
										record_1 << card_pin << endl;
										record_1 << card_cvv << endl;
										record_1 << card_balance << endl;
									}
								}
							}
						}
						from_card.close();
						record_1.close();

						if (read) {
							if (record) {
								string acc_number, acc_holder;
								int acc_bal;
								getline(read, acc_number);
								record << acc_number << endl;
								getline(read, acc_holder);
								record << acc_holder << endl;
								read >> acc_bal;
								record << acc_bal + money << endl;
								bank.SetBalance(acc_bal + money);
								ToFileIn(bank, money);
								

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
									cout << "\tКод операции: 001" << endl;
									cout << "Дата: ";
									if (t->tm_mday < 10) cout << "0" << t->tm_mday << ".";
									else cout << t->tm_mday << ".";
									cout << 1 + t->tm_mon << "." << 1900 + t->tm_year << endl;

									cout << "Время: ";
									if (t->tm_hour < 10) cout << "0" << t->tm_hour << ":";
									else cout << t->tm_hour << ":";
									if (t->tm_min < 10) cout << "0" << t->tm_min << ":";
									else cout << t->tm_min << ":";
									if (t->tm_sec < 10) cout << "0" << t->tm_sec << endl;
									else cout << t->tm_sec << endl;

									cout << "\tСчет получателя: " << acc_number << endl;
									cout << "\tСумма перевода: " << money << endl;
									cout << "\t--------------------" << endl;
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
						record_.close();
						read.close();
					}
				}
				catch (Exception& exception) {
					cerr << exception.what() << endl;
					ofstream record("card.txt");
					if (record) {
						record << card.GetNumber() << endl;
						record << card.GetCardData() << endl;
						record << card.GetHolder() << endl;
						record << card.GetCardPin() << endl;
						record << card.GetCardCvv() << endl;
						record << card.GetBalance() << endl;
					}
				}
			}
			break;
		}
	}
	
	record.close();
	//system("cls");
}

// сменить пароль на карточке
void ChangePin::ChangeCardPin(Card& card, int old, Singleton* log) {
	bool flag;
	for (int i = 3; i >= 1; i--)
	{
		cout << "\tВведите старый пин-код: ";
		int old_pin, new_pin;
		cin >> old_pin;

		if (old == old_pin) {
			flag = true;
			card.CopyData();
			/*ifstream read("newcard.txt");
			ofstream record("card.txt");*/
			cout << "\tВведите новый пин-код: ";
			try {
				cin >> new_pin;
				if (new_pin > 9999) {
					throw Exception("Неверный ввод пин-код", "Смена пин-код");
				}
				card.SetCardPin(new_pin);
				cout << "\tОперация выполнена успешно!" << endl;
			}
			catch (Exception& exception) {
				cerr << exception.what() << endl;
			}

			/*if (read) {
				if (record) {
					record << card.GetNumber() << endl;
					record << card.GetCardData() << endl;
					record << card.GetHolder() << endl;
					record << card.GetCardPin() << endl;
					record << card.GetCardCvv() << endl;
					record << card.GetBalance() << endl;
				}
			}
			read.close();
			record.close();
			remove("newcard.txt");*/


			string card_number = "no";
			string card_holder = "no";
			string card_data = "no";
			int card_pin = 0;
			int card_cvv = 0;
			double card_balance;
			string empty;
			int k1 = 0, l = card.GetCardChosen() - 1;
			//cout << l << endl;
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
							record_ << card.GetBalance() << endl;
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

			log->SingletonOperation("Смена пин-код", 1);
			break;
		}

		else {
			flag = 0;
			if (i - 1 == 0) break;
			else {
				log->SingletonOperation("Попытка смены пин-код", 0);
				cout << "\tНеверный пин-код! Попробуйте ещё раз! Осталось попыток: " << i - 1 << endl;
			}
		}
	}
	if (flag == 0) {
		log->SingletonOperation("Смена пин-код", 0);
		cout << "\tНеверный пин-код. Попробуйте позже!" << endl;
	}
	cout << endl;
}
