#include <iostream>
#include "MenuOperations.h"
#include "CardSessions.h"
#include "Singleton.h"
#include "MainScreen.h"

using namespace std;

// метод всей проги
void MenuOperations::Print(Singleton* log, Card& card) {

	while (true) {
		cout << "\tВыберите операцию:" << endl;
		cout << "\t1 - Данные банковской карты" << endl;
		cout << "\t2 - Выдача наличных" << endl;
		cout << "\t3 - Валютные операции" << endl;
		cout << "\t4 - Смена пин-кода" << endl;
		cout << "\t5 - Добавить средства на карточку" << endl;
		cout << "\t6 - Перевести средства на счет в банке" << endl;
		cout << "\t7 - Данные банковского счета" << endl;
		cout << "\t8 - Предоставить выписку" << endl;
		cout << "\t0 - Забрать карту и закончить работу" << endl;
		int k;
		//cout << card.GetHolder();
		cin >> k;
		//int n = Chosen::GetChosen();
		//cout << "Chosen " << n << endl;
		//Card card(3);
		
		Bankomat bank;
		//system("pause");
		//Bankomat bank;

		switch (k) {
		case 1: {
			system("cls");
			card.Print(log);
			cout << endl;
			break;
		}
		case 2: {
			system("cls");
			GiveMoney::MoneyOut(card, log);
			break;
		}
		case 3: {
			system("cls");
			int a;
			while (true) {
				cout << "\tВыберите операцию:" << endl;
				cout << "\t1 - Курс валюты" << endl;
				cout << "\t2 - Выдача наличных иностранной валюты" << endl;
				cout << "\t0 - Вернуться в главное меню" << endl;
				cin >> a;
				switch (a)
				{
				case 1: {
					Currency::Print(log);
					break;
				}
				case 2: {
					double i = Currency::Choice();
					if (i != 0) {
						Currency::MoneyOut(card, i, log);
					}
					break;
				}
				case 0: {
					break;
				}
				default:
					cout << "\tНеверный номер операции! Попробуйте еще раз." << endl;
					break;
				}
				break;
			}
			break;
		}
		case 4: {
			system("cls");
			ChangePin::ChangeCardPin(card, card.GetCardPin(), log);
			break;
		}
		case 5: {
			system("cls");
			GetMoney::MoneyIn(card, log);
			cout << endl;
			break;
		}
		case 6: {
			system("cls");
			Payement::Pay(card, bank);
			break;
		}
		case 7: {
			system("cls");
			bank.Print(log);
			cout << endl;
			break;
		}
		case 8: {
			system("cls");
			cout << "\t\t Выписка: " << endl;
			Statement::Print(log);
			break;
		}
		case 0: {
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t Заберите вашу карту!" << endl;
			log->SingletonOperation("Завершение сессии", 1);
			CardSessions::PauseF();
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t Спасибо, что воспользовались нашим банкоматом!" << endl;
			cout << endl << endl << endl << endl << endl << endl << endl;
			exit(0);
		}
		}
	}
}

