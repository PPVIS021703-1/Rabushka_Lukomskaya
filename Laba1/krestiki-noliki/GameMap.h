#pragma once
#include <vector>
#include <algorithm>

using namespace std;

struct Field2 {//���������� � �����������
	int x, y;
};

class GameMap
{
private:
	int** map;//������� - ����� ����
	Field2 size;//������ ����

	int length;//����� ���������� ����������

public:
	GameMap(); //�����������
	GameMap(Field2, int);
	GameMap(int, int, int);
	~GameMap();  //����������

	bool SetPosition(Field2, int); //������ �������
	bool SetPosition(int, int, int);
	bool IsEmpty(Field2); //�������� �������� �� �������
	bool IsEmpty(int, int);  //�������� �� ��������� ������
	void SetMap(Field2, int);
	void SetMap(int, int, int);  //�������� ��������� �������� �����
	int GetValue(int, int);
	int GetValue(Field2); //�������� ��������
	Field2 GetSize() {
		return size;
	}
	int CheckList(vector<int> a); //�������� ��� �������
	int CheckWinner(); //������� ��� ���
	bool CanMove(); //���� �� ����
};

