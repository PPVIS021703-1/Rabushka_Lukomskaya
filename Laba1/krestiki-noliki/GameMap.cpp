#include "GameMap.h"

GameMap::GameMap()
{
	size.x = 0;
	size.y = 0;

	length = 0;  //длина выигрышной комбинации

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++) {
		map[i] = new int[size.y];
	}
}

GameMap::GameMap(Field2 f_size, int l)
{
	size = f_size;
	length = l; //устанавливаем размер выигрышной цепочки

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++) {
		map[i] = new int[size.y];
	}

	//обнуляем элементы поля
	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.y; j++) {
			map[i][j] = 0;
		}
	}
}

GameMap::GameMap(int i, int j, int l)
{
	size.x = i;
	size.y = j;
	length = l; //устанавливаем размер выигрышной цепочки

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++) {
		map[i] = new int[size.y];
	}

	//обнуляем элементы поля
	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.y; j++) {
			map[i][j] = 0;
		}
	}
}

GameMap::~GameMap()
{
	//очищаем матрицу
	for (int i = 0; i < size.x; i++) {
		delete[] map[i];
	}
	delete[] map;
}

bool GameMap::SetPosition(Field2 cell, int c)//данные нашей ячейки/ то кем мы ходим
{
	if (IsEmpty(cell)) {  //если свободна
		map[cell.x][cell.y] = c; //запонимаем, что походили
		return true;
	}
	else {
		return false; //если занята
	}
}

bool GameMap::SetPosition(int i, int j, int c)//данные нашей ячейки/ то кем мы ходим
{
	if (IsEmpty(i, j)) {  //если свободна
		map[i][j] = c; //запонимаем, что походили
		return true;
	}
	else {
		return false; //если занята
	}
}

bool GameMap::IsEmpty(Field2 cell)//узнаем свободна ли ячейка
{
	if (map[cell.x][cell.y] == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool GameMap::IsEmpty(int i, int j) //узнаем свободна ли ячейка через координаты
{
	if (map[i][j] == 0) {
		return true;
	}
	else {
		return false;
	}
}

void GameMap::SetMap(Field2 f_size, int l) //задаёт карту(как конструктор с параметрами)
{
	size = f_size;
	length = l; //устанавливаем размер выигрышной цепочки

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++) {
		map[i] = new int[size.y];
	}

	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.y; j++) {
			map[i][j] = 0;
		}
	}
}

void GameMap::SetMap(int i, int j, int l)
{
	size.x = i;
	size.y = j;
	length = l; //устанавливаем размер выигрышной цепочки

	map = new int* [size.x];
	for (int i = 0; i < size.x; i++) {
		map[i] = new int[size.y];
	}

	//обнуляем матрицу
	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.y; j++) {
			map[i][j] = 0;
		}
	}
}

int GameMap::GetValue(int i, int j)
{
	return map[i][j];
}

int GameMap::GetValue(Field2 cell)
{
	return map[cell.x][cell.y];
}

int GameMap::CheckList(vector<int> a)
{
	if (a.size() < length) {
		return 0;
	}

	//флажки победы игроков
	bool winPlayer1 = false;
	bool winPlayer2 = false;

	int count1 = 0, count2 = 0;

	//считаем баллы
	
	for (int i = 0; i < a.size(); i++) {
		for (int j = i; j < i + length; j++) {
			if (j < a.size()) {
				if (a[j] == 1) count1++;
			}
			else break;
		}

		if (count1 == length) {
			winPlayer1 = true;
			break;
		}

		count1 = 0;
	}

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < i + length; j++) {
			if (j < a.size()) {
				if (a[j] == 2) {
					count2++;
				}
				else break;
			}
		}

		if (count2 == length) {
			winPlayer2 = true;
			break;
		}

		count2 = 0;

	}

	//высчитываем результат
	if (winPlayer1 && winPlayer2) {
		return 3; //ничья
	}
	else if (!winPlayer1 && winPlayer2) {
		return 2;//выиграл второй игрок
	}
	else if (winPlayer1 && !winPlayer2) {
		return 1; //выиграл первый игрок
	}
	else return 0;
}

int GameMap::CheckWinner()
{
	//проходим по карте в поиске последвательности для выигрыша
	int state = 0;
	vector<int> check;

	/*
	[][][]
	[][][]
	[][][]
	*/

	//1 ----- проходим по всем горизонталям
	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.y; j++) {
			check.push_back(map[i][j]);
		}

		//проверяем
		state = CheckList(check);
		check.clear();

		if (state == 3) {
			return 3;//ничья
		}
		else if (state == 2) {
			return 2;//второй игрок
		}
		else if (state == 1) {
			return 1;//первый игрок
		}
	}

	//2 ----- проходим по всем вертикалям
	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.y; j++) {
			check.push_back(map[j][i]);
		}

		//проверяем
		state = CheckList(check);
		check.clear();

		if (state == 3) {
			return 3;
		}
		else if (state == 2) {
			return 2;
		}
		else if (state == 1) {
			return 1;
		}
	}

	//3 ------проходим по левым диагоналям
	//главная и над ней
	for (int i = 0; i < size.x; ++i)
	{
		for (int j = 0; i + j < size.y; ++j) {
			check.push_back(map[j][i + j]);
		}


		state = CheckList(check);
		check.clear();

		if (state == 3) {
			return 3;//ничья
		}
		else if (state == 2) {
			return 2;//победил 2
		}
		else if (state == 1) {
			return 1;//победил 1
		}
	}

	//под главной
	for (int i = 1; i < size.x; ++i)
	{
		for (int j = 0; i + j < size.y; ++j) {
			check.push_back(map[i + j][j]);
		}


		state = CheckList(check);
		check.clear();

		if (state == 3) {
			return 3;//ничья
		}
		else if (state == 2) {
			return 2;//игрок 2
		}
		else if (state == 1) {
			return 1;//игрок 1
		}
	}

	//4. -----проходим по правой диагонали
	//и над ней
	for (int j = size.y; j > 0; --j) {
		for (int i = 0; i < size.x; ++i)
		{
			if (size.x - j - i >= 0) {
				check.push_back(map[i][size.x - j - i]);
			}
		}


		state = CheckList(check);
		check.clear();

		if (state == 3) {
			return 3;//ничья
		}
		else if (state == 2) {
			return 2;//игрок 2
		}
		else if (state == 1) {
			return 1;//игрок 1
		}
	}

	//под ней
	for (int j = 0; j < size.y; ++j) {
		for (int i = 0; i < size.x; ++i)
		{
			if (size.x + j - i < size.x) {
				check.push_back(map[i][size.x + j - i]);
			}
		}


		state = CheckList(check);
		check.clear();

		if (state == 3) {
			return 3;//ничья
		}
		else if (state == 2) {
			return 2;//игрок 2
		}
		else if (state == 1) {
			return 1;//игрок 1
		}
	}

	if (CanMove())
	{
		return 0;//нет победителя
	}
	else
	{
	return 3;
	}
	
	return 0;
}

bool GameMap::CanMove()
{
	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.y; j++) {
			if (map[i][j] == 0) {
				return true; //ячейка пустая
			}
		}
	}

	return false; 
}
