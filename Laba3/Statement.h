#pragma once
#include <iostream>
#include "Bankomat.h"
#include "Card.h"
#include"Bank.h"

using namespace std;

// CARD STATEMENT CLASS
class Statement: public virtual Bank{
public:
	static void ToFileIn(Card&, double);
	static void ToFileFrom(Card&, double);
	static void ToFileIn(Bankomat&, double);

	static void Print(Singleton*);
};


