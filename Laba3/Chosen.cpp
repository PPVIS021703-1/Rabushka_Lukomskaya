#include "Chosen.h"
#include <iostream>

using namespace std;

void Chosen::SetChosen(int n) {
	chosen = n;
}

void Chosen::Operation() {
	cout << "\tВыберите карточку:" << endl;
	cout << "\t1 - RABUSHKA ALESIA" << endl;
	cout << "\t2 - LUKOMSKAYA ELIZAVETA" << endl;
	cout << "\t3 - IVANOVA EKATERINA" << endl;
	cout << "\t4 - PETROV ALEKSEY" << endl;
	cout << "\t5 - DAVYDOV PETR" << endl;

	int n;
	cin >> n;
	int chosen = 0;
	switch (n) {
	case 1: {
		chosen = 1;
		SetChosen(chosen);
		break;
	}
	case 2: {
		chosen = 2;
		SetChosen(chosen);
		break;
	}
	case 3: {
		chosen = 3;
		SetChosen(chosen);
		break;
	}
	case 4: {
		chosen = 4;
		SetChosen(chosen);
		break;
	}
	case 5: {
		chosen = 5;
		SetChosen(chosen);
		break;
	}
	}
}

int Chosen::GetChosen() {
	return chosen;
}