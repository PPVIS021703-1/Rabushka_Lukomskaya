#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Bank.h"

using namespace std;

// BANK CLASS
class Bankomat: virtual public Bank
{
public:
	// конструктор 
	Bankomat();
	// вывод на экран
	void Print(Singleton*) override;
};