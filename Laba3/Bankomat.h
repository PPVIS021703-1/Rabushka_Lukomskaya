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
	// ����������� 
	Bankomat();
	// ����� �� �����
	void Print(Singleton*) override;
};