#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Bank.h"

using namespace std;

//CARD CLASS
class Card : virtual public Bank, public Chosen {

public:
	//����������� --- ���� ������ �� �������
	Card() {
		int s = 0;
	}
	Card(int);

	// ����� �� �����
	void Print(Singleton*) override;
	void Secret(string);
};