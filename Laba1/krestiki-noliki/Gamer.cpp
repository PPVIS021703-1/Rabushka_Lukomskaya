#include "Gamer.h"

void Gamer::SetField(GamerStatus mode, int m) //проверяем в каком режиме
{
	if (mode == 0)
	{
		status = Computer;
	}
	if (mode == 1)
	{
		status = Player;
	}
	if (mode == 2)
	{
		status = Player1;
	}
	else status = Player2;

	mark = m;// метка (1 - крестики/ 2 - нолики)
}

