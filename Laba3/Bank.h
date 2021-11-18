#pragma once
#include <iostream>
#include <string>
#include "Singleton.h"
#include "Chosen.h"

using namespace std;

// MAIN CLASS FOR ATM
class Bank: public Chosen {
private:
	int chosen;
	string number;
	string holder;
	string card_data;
	int card_pin = 0;
	double balance = 0;
	int card_cvv = 0;
	string empty;  //просто пустая строка, чтобы после считывания int можно было перейти на след строку

public:
	// конструктор
	Bank();

	//геттеры и сеттеры
	void SetNumber(string);
	void SetHolder(string);
	void SetCardPin(int);
	void SetCardData(string);
	void SetBalance(double);
	void SetCardChosen(int);
	void SetCardCvv(int);

	string GetNumber();
	string GetHolder();
	string GetCardData();
	int GetCardPin();
	double GetBalance();
	int GetCardCvv();
	int GetCardChosen();

	//  копирование данных карточки, чтобы можно было менять какое-то поле
	void CopyData();
	void CopyAccount();

	// вывод на экран данных
	virtual void Print(Singleton*) = 0;
};

