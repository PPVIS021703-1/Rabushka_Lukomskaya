#pragma once

#include <iostream>
#include <string>
#include "CardSessions.h"

using namespace std;

// CHANGE CURRENCY CLASS

class Currency: public GiveMoney, public virtual Bank {

public:
	static double GetKaz() {
		return 174;
	}

	static double GetKvacha() {
		return 7;
	}

	static double GetKirgiz() {
		return 35;
	}

	static double GetUkrain() {
		return 11;
	}

	static double GetMyanma() {
		return 777;
	}

	// вывод на экран
	static void Print(Singleton*);
	// для перемены на карточке
	static void MoneyOut(Card&, double, Singleton*);
	//выбор валюты
	static double Choice();

	static void ToFileFrom(Card&, double);
};
