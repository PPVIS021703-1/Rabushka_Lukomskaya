#pragma once

#include <iostream>
#include <string>
#include "CardSessions.h"

using namespace std;

// CHANGE CURRENCY CLASS

class Currency: public GiveMoney, public virtual Bank {
private:
	double kazah = 174, kvacha = 7, kirgiz = 35, ukrain = 11, myanma = 777;
	string kazah_t = ".00 (������������� �����)", kvacha_t = ".00 (���������� �����)", kirgiz_t = ".00 (���������� ����)", ukrain_t = ".00 (���������� ������)", myanma_t = ".00 (����������� ����)";

public:
	static double GetKaz() {
		return 174;
	}
	// ����� �� �����
	static void Print(Singleton*);
	// ��� �������� �� ��������
	static void MoneyOut(Card&, double, Singleton*);
	//����� ������
	static double Choice();

	static void ToFileFrom(Card&, double);
};
