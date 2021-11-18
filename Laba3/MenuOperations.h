#pragma once
#include <iostream>
#include "Card.h"
#include "CardSessions.h"
#include "Bankomat.h"
#include "Currency.h"
#include "Statement.h"


using namespace std;

// MENU OPERATIONS CLASS
class MenuOperations: public Statement{
private:
	int k;
public:
	//основное меню программы
	MenuOperations();
	static void Print(Singleton*, Card&);
}; 