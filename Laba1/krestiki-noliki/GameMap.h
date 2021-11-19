#pragma once
#include <vector>
#include <algorithm>

using namespace std;

struct Field2 {//информация о координатах
	int x, y;
};

class GameMap
{
private:
	int** map;//матрица - карта поля
	Field2 size;//размер поля

	int length;//длина выигрышной комбинации

public:
	GameMap(); //конструктор
	GameMap(Field2, int);
	GameMap(int, int, int);
	~GameMap();  //деструктор

	bool SetPosition(Field2, int); //задать позицию
	bool SetPosition(int, int, int);
	bool IsEmpty(Field2); //проверка свободна ли позиция
	bool IsEmpty(int, int);  //проверка на свободную ячейку
	void SetMap(Field2, int);
	void SetMap(int, int, int);  //получаем некоторые значения карты
	int GetValue(int, int);
	int GetValue(Field2); //получить значения
	Field2 GetSize() {
		return size;
	}
	int CheckList(vector<int> a); //проверка кто победил
	int CheckWinner(); //выиграл или нет
	bool CanMove(); //есть ли ходы
};

