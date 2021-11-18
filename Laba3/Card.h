#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Bank.h"

using namespace std;

//CARD CLASS
class Card : virtual public Bank, public Chosen {

public:
	//конструктор --- ввод данных из файлика
	Card() {
		int s = 0;
	}
	Card(int);

	// вывод на экран
	void Print(Singleton*) override;
	void Secret(string);
};