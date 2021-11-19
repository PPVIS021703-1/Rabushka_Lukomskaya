#include <iostream>
#include "MainScreen.h"
#include "CardSessions.h"
#include "Exception.h"
#include "Singleton.h"
#include "Chosen.h"
#include <string>

using namespace std;

// заствака главного экрана
MainScreen::MainScreen(Singleton* log) {

	log->SingletonOperation("Принятие карточки", 1);

	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t\t-----------------------" << endl;
	cout << "\t\t\t\t\t     Вставьте карту!" << endl;
	cout << "\t\t\t\t\t-----------------------" << endl << endl << endl << endl;
	system("pause");
	system("cls");
}

bool MainScreen::CheckStr(char* s, int old) {
	char p[33] = { 'а','б','в','г','д','е','ё','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ч','ш','щ','ъ','ы','ь','э','я' };


	bool flag = false;
	int i = 0;
	if (sizeof(s) >= 5) flag = 0;
	else {
		while (s[i] != '\n') {
			if (s[i] == p[i]) {
				flag = false;
				break;
			}
			i++;
		}
		if (old == atoi(s)) flag = true;
	}
	return flag;
}


// проверка на правильность введенного пин-кода карточки 
bool MainScreen::CheckPin(Singleton* log, int k, Card& card) {

	system("cls");
	//Card card(k);
	int old = card.GetCardPin();
	cout << old << endl;
	//system("pause");
	bool flag = 0;
	bool next;

	for (int i = 3; i >= 1; i--)
	{
		//int new_pin;
		char new_p[6];
		cout << endl << endl << endl << endl << endl << endl << endl << endl << "\t\t\t\t\tВведите пин-код: ";
		//cin >> new_pin;
		//getline(cin, new_p);
		//system("pause");
		cin.ignore();
		cin.getline(new_p, 6, '\n');
		cout << endl << endl;
		bool flag_new = CheckStr(new_p, old);

		try {
			if (atoi(new_p) > 9999 || flag_new == false) {
				throw Exception("Недопустимый ввод пин-код", "Ввод пин-код");
			}

		}
		catch (Exception& exception) {
			cerr << exception.what() << endl;
		}


		if (old == atoi(new_p)) {
			log->SingletonOperation("Проверка пин-код", 1);
			flag = true;
			next = true;
			system("cls");
			break;
		}

		else {
			flag = 0;
			if (i - 1 == 0) break;
			else {
				system("cls");
				log->SingletonOperation("Проверка пин-код - попытка", 0);
				cout << endl << endl << "\t\t\tНеверный пин-код! Попробуйте ещё раз! Осталось попыток: " << i - 1 << endl;
			}
		}


	}

	if (flag == 0) {
		system("cls");
		log->SingletonOperation("Проверка пин-код", 0);
		cout << endl << endl << endl << endl << endl << endl << endl << endl << "\t\t\t\t\tНеверный пин-код. Попробуйте позже!" << endl;
		next = false;
	}
	cout << endl;
	return next;
	system("pause");
	system("cls");

}
