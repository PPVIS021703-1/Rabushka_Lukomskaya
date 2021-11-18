#include <iostream>
#include <string>
#include <cstdlib>
#include "Currency.h"
#include "Exception.h"

using namespace std;

// ����� �� �����
void Currency::Print(Singleton* log) {
	cout << "\t���� �����" << endl << endl;
	/*cout << "\t" << kazah << kazah_t << endl;
	cout << "\t" << kvacha << kvacha_t << endl;
	cout << "\t" << kirgiz << kirgiz_t << endl;
	cout << "\t" << ukrain << ukrain_t << endl;
	cout << "\t" << myanma << myanma_t << endl;*/
	
	log->SingletonOperation("����� ����� �����", 1);
	system("pause");
	system("cls");
}

// ����� �����
double Currency::Choice() {
	int a;
	double value;
	cout << "\t�������� ������" << endl << endl;
	cout << "\t1 - " << GetKaz() << endl << "\t*����������� ��������� �����: 1740 �����" << endl;
	/*cout << "\t2 - " << kvacha << kvacha_t << endl << "\t*����������� ��������� �����: 70 ����" << endl;;
	cout << "\t3 - " << kirgiz << kirgiz_t << endl << "\t*����������� ��������� �����: 350 ���" << endl;;
	cout << "\t4 - " << ukrain << ukrain_t << endl << "\t*����������� ��������� �����: 110 ������" << endl;;
	cout << "\t5 - " << myanma << myanma_t << endl << "\t*����������� ��������� �����: 7770 ����" << endl;*/
	cin >> a;
	cout << "\t������� �����, ������� ������� ����� (� ��������� ������): " << endl;
	cin >> value;
	
	switch (a)
	{
	case 1: {

		if (value < 1740) {
			cout << "\t����������� ��������� �����: 1740 �����. ���������� ��� ��� �����!" << endl << endl;
			value = 0;
			break;
		}
		value = value / Currency::GetKaz();

		break;
	}
	case 2: {
		if (value < 70) {
			cout << "\t����������� ��������� �����: 70 ����. ���������� ��� ��� �����!" << endl << endl;
			value = 0;
			break;
		}
		//value /= kvacha;
		break;
	}
	case 3: {
		if (value < 350) {
			cout << "\t����������� ��������� �����: 350 ���. ���������� ��� ��� �����!" << endl << endl;
			value = 0;
			break;
		}
		//value /= kirgiz;
		break;
	}
	case 4: {
		if (value < 110) {
			cout << "\t����������� ��������� �����: 110 ������. ���������� ��� ��� �����!" << endl << endl;
			value = 0;
			break;
		}
		//value /= ukrain;
		break;
	}
	case 5: {
		if (value < 7770) {
			cout << "\t����������� ��������� �����: 7770 ����. ���������� ��� ��� �����!" << endl << endl;
			value = 0;
			break;
		}
		//value /= myanma;
		break;
	}
	default:
		cout << "\t�������� ����� ��������! ���������� ��� ���." << endl << endl;
		break;
	}
	
	return value;
}

// ����� � �������� 
void Currency::MoneyOut(Card& card,double money, Singleton* log) {
	card.CopyData();
	
	try {
		if (money > card.GetBalance() || money < 0) {
			throw Exception("������������ ��� �����", "����� �����");
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
			log->SingletonOperation("������ ��������: ����� �����", 1);
			PauseF();
			cout << "\t�������� ���� ������!" << endl << endl;
			PauseF();
			cout << endl << "\t������� ������� ���? " << endl;
			cout << "\t1 - ��" << endl << "\t2 - ���" << endl;
			int k;
			cin >> k;
			switch (k) {
			case 1: {
				time_t now = time(0);
				tm* t = new tm;
				localtime_s(t, &now);

				cout << "\t�������� ��� ���!" << endl << endl;
				cout << "\t--------------------" << endl;
				cout << "\t��� ��������: 003" << endl;
				cout << "\t����: ";
				if (t->tm_mday < 10) cout << "0" << t->tm_mday << ".";
				else cout << t->tm_mday << ".";
				cout << 1 + t->tm_mon << "." << 1900 + t->tm_year << endl;

				cout << "\t�����: ";
				if (t->tm_hour < 10) cout << "0" << t->tm_hour << ":";
				else cout << t->tm_hour << ":";
				if (t->tm_min < 10) cout << "0" << t->tm_min << ":";
				else cout << t->tm_min << ":";
				if (t->tm_sec < 10) cout << "0" << t->tm_sec << endl;
				else cout << t->tm_sec << endl;
				cout << "\t����� ������: " << money << endl;
				cout << "\t--------------------" << endl;
				log->SingletonOperation("������ ����", 1);
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
		log->SingletonOperation("������ ��������: ����� �����", 0);
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

// ������ � �������
void Currency::ToFileFrom(Card& card, double money) {
	ofstream record("statement.txt", ios::app);

	if (record) {
		time_t now = time(0);
		tm* t = new tm;
		localtime_s(t, &now);

		record << "\t--------------------------------" << endl;
		record << "\t������ �������:" << endl;

		record << "����: ";
		if (t->tm_mday < 10) record << "0" << t->tm_mday << ".";
		else record << t->tm_mday << ".";
		record << 1 + t->tm_mon << "." << 1900 + t->tm_year << endl;

		record << "�����: ";
		if (t->tm_hour < 10) record << "0" << t->tm_hour << ":";
		else record << t->tm_hour << ":";
		if (t->tm_min < 10) record << "0" << t->tm_min << ":";
		else record << t->tm_min << ":";
		if (t->tm_sec < 10) record << "0" << t->tm_sec << endl;
		else record << t->tm_sec << endl;

		record << "\t����� ����� : " << card.GetNumber() << endl;
		record << "\t����� ��������: " << money << endl;
		record << "\t������� �������: " << card.GetBalance() << endl;
		record << "\t--------------------------------" << endl;
	}

	record.close();
}