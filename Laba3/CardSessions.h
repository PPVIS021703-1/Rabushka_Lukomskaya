#pragma once
#include <string>
#include "Bank.h"
#include "Card.h"
#include "Statement.h"
#include "Singleton.h"

//  SESSIONS CLASS
class CardSessions {

public:
	
	static void PauseF();
};


// GIVE MONEY CLASS (FROM CARD)
class GiveMoney : public CardSessions, public Statement {
public:
	static void MoneyOut(Card&, Singleton*);
};

// CHANGE CARD PIN CLASS
class ChangePin : public Bank{
public:
	
	static void ChangeCardPin(Card&, int, Singleton*);
};

// GET MONEY CLASS (TO CARD)
class GetMoney : public CardSessions, public Statement {
public:
	static void MoneyIn(Card&, Singleton*);
};

// PAYEMENT (FROM CARD)
class Payement : public CardSessions, public Statement {
public:
	static void Pay(Card&, Bankomat&);
};
