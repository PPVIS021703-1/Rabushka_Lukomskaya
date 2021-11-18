#pragma once

#include <iostream>
#include "Card.h"
#include "CardSessions.h"
#include "Singleton.h"

using namespace std;

class MainScreen : public Card, public CardSessions, public Chosen {
public:
	// �����������
	MainScreen(Singleton*);

	bool CheckStr(char*, int);
	void Operation() {
		Chosen::Operation();
	}
	// �������� ���-���� ��� ����� � ��������
	bool CheckPin(Singleton*, int, Card&);
};