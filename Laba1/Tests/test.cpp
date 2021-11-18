#include "pch.h"
#include "../Krestiki-noliki/GameMap.cpp"

TEST(GameMapTest, Test1) { //проверяем, что наша матрица пустая
	GameMap Map(3, 3, 3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			EXPECT_EQ(Map.GetValue(i, j), 0);
		}
	}
}

TEST(GameMapTest, Test2) {//проверяем, есть ли свободные клетки
	GameMap Map(3, 3, 3);
	Map.SetPosition(0, 1, 2);
	Map.SetPosition(1, 2, 2);
	Map.SetPosition(2, 0, 1);
	EXPECT_EQ(Map.CanMove(), 1);
}

TEST(GameMapTest, Test3) {//проверяем, что в позици [0][0] действительно значение 2
	GameMap Map(3, 3, 3);

	Map.SetPosition(0, 0, 2);
	EXPECT_EQ(Map.GetValue(0, 0), 2);
}

TEST(GameMapTest, Test4) { //проверяем работает ли проверка на победу
	GameMap Map(3, 3, 3);
	Map.SetPosition(0, 0, 1);                 //[0] [X] [X]
	Map.SetPosition(1, 1, 1);                 //[ ] [0] [ ]
	Map.SetPosition(2, 2, 1);                 //[X] [ ] [0]
	Map.SetPosition(0, 1, 2);                 
	Map.SetPosition(2, 0, 2);
	Map.SetPosition(0, 2, 2);
	
	EXPECT_EQ(Map.CheckWinner(), 1);
}

TEST(GameMapTest, Test5) { //проверка на ничью
	GameMap Map(3, 3, 3);
	Map.SetPosition(0, 0, 2);                 //[X] [0] [X]
	Map.SetPosition(1, 0, 1);                 //[0] [X] [X]
	Map.SetPosition(2, 0, 1);                 //[0] [X] [0]
	
	Map.SetPosition(0, 1, 1);
	Map.SetPosition(1, 1, 2);
	Map.SetPosition(2, 1, 2);

	Map.SetPosition(0, 2, 2);
	Map.SetPosition(1, 2, 2);
	Map.SetPosition(2, 2, 1);

	//EXPECT_EQ(Map.CheckWinner(), 1);
	EXPECT_EQ(Map.CheckWinner(), 3);
}