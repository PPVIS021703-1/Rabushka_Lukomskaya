#pragma once
enum GamerStatus
{
	Computer = 0,
	Player,
	Player1,
	Player2
};

class Gamer
{
private: //никто не имеет доступа к этим полям
	GamerStatus status;
	int mark; //то, чем ходит игрок

public:
	Gamer() {}//конструктор
	~Gamer() {}//деструктор 

	void SetField(GamerStatus mode, int m); //задать поля: кто мы сейчас (игрок/компуктер), метка(крестик или нолик)
	int GetMark() //вернуть текущую метку, то кем ходит игрок
	{
		return mark;
	};
	GamerStatus GetStatus() { return status; }

};

