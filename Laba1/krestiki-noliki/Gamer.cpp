#include "Gamer.h"

void Gamer::SetField(GamerStatus mode, int m) //��������� � ����� ������
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

	mark = m;// ����� (1 - ��������/ 2 - ������)
}

