#include <iostream>
#include "MenuOperations.h"
#include "CardSessions.h"
#include "Singleton.h"
#include "MainScreen.h"

using namespace std;

// ����� ���� �����
void MenuOperations::Print(Singleton* log, Card& card) {

	while (true) {
		cout << "\t�������� ��������:" << endl;
		cout << "\t1 - ������ ���������� �����" << endl;
		cout << "\t2 - ������ ��������" << endl;
		cout << "\t3 - �������� ��������" << endl;
		cout << "\t4 - ����� ���-����" << endl;
		cout << "\t5 - �������� �������� �� ��������" << endl;
		cout << "\t6 - ��������� �������� �� ���� � �����" << endl;
		cout << "\t7 - ������ ����������� �����" << endl;
		cout << "\t8 - ������������ �������" << endl;
		cout << "\t0 - ������� ����� � ��������� ������" << endl;
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
				cout << "\t�������� ��������:" << endl;
				cout << "\t1 - ���� ������" << endl;
				cout << "\t2 - ������ �������� ����������� ������" << endl;
				cout << "\t0 - ��������� � ������� ����" << endl;
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
					cout << "\t�������� ����� ��������! ���������� ��� ���." << endl;
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
			cout << "\t\t �������: " << endl;
			Statement::Print(log);
			break;
		}
		case 0: {
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t\t �������� ���� �����!" << endl;
			log->SingletonOperation("���������� ������", 1);
			CardSessions::PauseF();
			system("cls");
			cout << endl << endl << endl << endl << endl << endl << endl;
			cout << "\t\t\t\t �������, ��� ��������������� ����� ����������!" << endl;
			cout << endl << endl << endl << endl << endl << endl << endl;
			exit(0);
		}
		}
	}
}

