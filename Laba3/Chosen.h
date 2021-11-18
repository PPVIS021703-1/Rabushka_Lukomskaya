#pragma once
class Chosen
{
private:
	int chosen = 0;

public:
	Chosen() {
		chosen = 0;
	}

	void SetChosen(int);

	int GetChosen();

	void Operation();
};

