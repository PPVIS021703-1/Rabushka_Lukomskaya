#pragma once
#include <iostream>

using namespace std;







class Field {
private:
	int x, y;
	int status;
	
public:
	Field();
	Field(int, int, int);
	~Field();

	/*int& operator[](int index) {
		return status;
	}*/

	int getStatus() {
		return status;
	}

	void setStatus(int s) {
		status = s;
	}

};

Field::Field() {
	x = 0;
	y = 0;
	status = 0;
}

Field::Field(int x, int y, int status) {
	this->x = x;
	this->y = y;
	this->status = status;
}

Field::~Field() {
	x = 0;
	y = 0;
	status = 0;
}




class Map {
private:
	Field* mas = new Field[100];
	int i = 0;
public:

	void Add(Field cell) {

		mas[i] = cell;
		i++;
	}


	int operator[](int index) {
		return mas[index].getStatus();
	}

	
};