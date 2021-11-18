#include <iostream>
#include "MainScreen.h"
#include "CardSessions.h"
#include "Exception.h"
#include "Singleton.h"
#include "Chosen.h"
#include <string>

using namespace std;

// �������� �������� ������
MainScreen::MainScreen(Singleton* log) {

	log->SingletonOperation("�������� ��������", 1);

	cout << endl << endl << endl << endl << endl << endl << endl;
	cout << "\t\t\t\t\t-----------------------" << endl;
	cout << "\t\t\t\t\t     �������� �����!" << endl;
	cout << "\t\t\t\t\t-----------------------" << endl << endl << endl << endl;
	system("pause");
	system("cls");
}

bool MainScreen::CheckStr(char* s, int old) {
	char p[33] = { '�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�' };


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


// �������� �� ������������ ���������� ���-���� �������� 
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
		cout << endl << endl << endl << endl << endl << endl << endl << endl << "\t\t\t\t\t������� ���-���: ";
		//cin >> new_pin;
		//getline(cin, new_p);
		//system("pause");
		cin.ignore();
		cin.getline(new_p, 6, '\n');
		cout << endl << endl;
		bool flag_new = CheckStr(new_p, old);

		try {
			if (atoi(new_p) > 9999 || flag_new == false) {
				throw Exception("������������ ���� ���-���", "���� ���-���");
			}

		}
		catch (Exception& exception) {
			cerr << exception.what() << endl;
		}


		if (old == atoi(new_p)) {
			log->SingletonOperation("�������� ���-���", 1);
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
				log->SingletonOperation("�������� ���-��� - �������", 0);
				cout << endl << endl << "\t\t\t�������� ���-���! ���������� ��� ���! �������� �������: " << i - 1 << endl;
			}
		}


	}

	if (flag == 0) {
		system("cls");
		log->SingletonOperation("�������� ���-���", 0);
		cout << endl << endl << endl << endl << endl << endl << endl << endl << "\t\t\t\t\t�������� ���-���. ���������� �����!" << endl;
		next = false;
	}
	cout << endl;
	return next;
	system("pause");
	system("cls");

}