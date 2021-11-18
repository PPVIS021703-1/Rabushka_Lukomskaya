#include "GameForm.h"
#include "StartForm.h"

using namespace std;

enum GameMode {
    PvP = 0, //����� ������ ������
    PvE //����� ������ �����
} gameMode;

//����� ������ 
GameMap map;
Gamer player1;
Gamer player2;
GamerStatus currentPlayer;
Field2 selectedCellPlayer;

//������
bool canPlay;
bool endGame;

//��� �����
vector<Field2> allMoves;//��� ��������� ����
int currentMoves; //���������� �����

// ������ ����
System::Void Krestikinoliki::GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    //������������� ����������
    if (selectedGameMode == 0) {
        gameMode = PvP;
    }
    else {
        gameMode = PvE;
    }

    NewGame();
}

void Krestikinoliki::GameForm::GameLogic()
{
    //��������� ����� ����
    if (gameMode == PvE) {
        //���� ��� �����
        if (currentPlayer == Computer) {
            StepAI(); //������ ���
        }
        Update();
    }
}

void Krestikinoliki::GameForm::Update()
{
    //��������� ��������� �������� ����(������� �� ���-��)
    int state_game = map.CheckWinner();
    if (endGame) return;

    if (state_game == 1) {
        if (gameMode == PvP) {
            UpdateGameGrid();
            MessageBox::Show("����������� ������1 � �������!", "������!");
        }
        else {
            UpdateGameGrid();
            MessageBox::Show("������������ �� ��������!! � �������, �����!", "������!");
        }
        //UpdateGameGrid();

        endGame = true;  //������ ���� ����� ��������
    }
    else if (state_game == 2) {
        if (gameMode == PvP) {
            UpdateGameGrid();
            MessageBox::Show("����������� ������2 � �������!!", "������!");
        }
        else {
            UpdateGameGrid();
            MessageBox::Show("������������� ��������� �������!! ������������ ��� �� ��.", "������, ������!");
        }
       // UpdateGameGrid();

        endGame = true; //����� ����
    }
    else if (state_game == 3) {
        MessageBox::Show("������������ � ������������� ��������� ���� �� ������, ��� �����!", "������� ��� �������� ���������� ���� �����");
        UpdateGameGrid();

        endGame = true;
    }

    if (endGame) {
        if (MessageBox::Show("������ ��������� ����� ����?", "��������?", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
            NewGame();
        }
        return;//������� �� ������
    }

    //��� AI
    if (gameMode == PvE) {
        if (currentPlayer == Computer) { //���� ����� ����, �� ������ ����� �����
            status->Text = "���: �����!";
            currentPlayer = Player;
            return;
        }
        else {
            status->Text = "���: ���������!";
            currentPlayer = Computer;

            GameLogic();
            UpdateGameGrid();
            return;
        }
    }
    else {
        if (currentPlayer == Player1) {
            status->Text = "���: 0";//�����
            currentPlayer = Player2;
        }
        else {
            status->Text = "���: �"; //�������
            currentPlayer = Player1;
        }
    }

    GameLogic();
    UpdateGameGrid();
}

void Krestikinoliki::GameForm::NewGame()
{
    //������������� ������
    map.SetMap(rows, columns, length);
    rand = gcnew Random();
    endGame = false;

    CreateGameGrid(map.GetSize());

    //������������� ���� ��������� ����� AI
    currentMoves = 0;
    allMoves.clear();
    Field2 buf;
    for (int i = 0; i < map.GetSize().x; i++) {
        for (int j = 0; j < map.GetSize().x; j++) {
            buf.x = i;
            buf.y = j;

            allMoves.push_back(buf);//���������� ���� �����, ���� ��������
        }
    }

    //������������ ��� ���� ��������� ���
    //����� �� ������ � ���� � �� �� �����
    int num_mixing = rand->Next(1, 10);
    for (int i = 0; i < num_mixing; i++) {
        random_shuffle(allMoves.begin(), allMoves.end());
    }
    //��������� ����������� � �����
    int state_game = rand->Next(1, 3); //������ ��������� ����� ��  1 �� 2
    if (state_game == 1) {
        if (gameMode == PvE) {
            player1.SetField(Player, 1); //��������
            player2.SetField(Computer, 2); //������

            status->Text = "���: �����!";

            currentPlayer = Player;
        }
        else {
            player1.SetField(Player1, 1);
            player2.SetField(Player2, 2);

            status->Text = "���: �!";

            currentPlayer = Player1;
        }
    }
    else if (state_game == 2) {
        if (gameMode == PvE) {
            player1.SetField(Player, 1); //��������
            player2.SetField(Computer, 2); //������

            status->Text = "���: ���������!";

            currentPlayer = Computer;

            GameLogic();
            UpdateGameGrid();
        }
        else {
            player1.SetField(Player1, 1);
            player2.SetField(Player2, 2);

            status->Text = "���: 0!";

            currentPlayer = Player2;
        }
    }
    else {
        MessageBox::Show("������ ��������� ��������������� ������ ������!", "������!");
        return;
    }
}

void Krestikinoliki::GameForm::StepAI()
{
    //���������, ���� �� ��� ����
    if (currentMoves < allMoves.size()) {
        //��������� ������� ���
        if (map.IsEmpty(allMoves[currentMoves])) {
            //���� ������ ��������, ������ ���
            map.SetPosition(allMoves[currentMoves], player2.GetMark());
            currentMoves++;
        }
        else {
            //���� ������ ������, ��������� �� ������
            currentMoves++;
            StepAI();
        }
    }
}

void Krestikinoliki::GameForm::UpdateGameGrid()
{
    for (int i = 0; i < map.GetSize().x; i++) {
        for (int j = 0; j < map.GetSize().y; j++) {
            if (!map.IsEmpty(i, j)) {
                if (map.GetValue(i, j) == 1) {
                    dataGridView->Rows[i]->Cells[j]->Value = "X";
                }
                else {
                    dataGridView->Rows[i]->Cells[j]->Value = "0";
                }
            }
        }
    }
}

void Krestikinoliki::GameForm::CreateGameGrid(Field2 size)
{
    //������� �������
    dataGridView->Rows->Clear();
    dataGridView->Columns->Clear();

    //������� �������
    for (int i = 0; i < size.x; i++) {
        DataGridViewButtonColumn^ column = gcnew DataGridViewButtonColumn();
        column->HeaderCell->Value = Convert::ToString(i + 1);
        column->Name = "column" + i;
        column->Width = 50;

        dataGridView->Columns->Add(column);
    }

    //������� ������
    for (int j = 0; j < size.y; j++) {
        dataGridView->Rows->Add();
        dataGridView->Rows[j]->HeaderCell->Value = Convert::ToString(j + 1);
        dataGridView->Rows[j]->Height = 50;
    }
}

System::Void Krestikinoliki::GameForm::SetPositionPlayer(Field2 cell)
{
    //��������� ����� ����
    if (gameMode == PvE) {
        //��������� ����������� ������
        if (currentPlayer == Player) {
            //������ ���
            if (!map.SetPosition(cell, player1.GetMark())) {
                MessageBox::Show("������ ������� ������!", "��������!");
                return;
            }
        }
        else {
            MessageBox::Show("��� �� ���� �������!", "��������!");
            return;
        }
    }
    else {//���� �� � PvP ������
        //����������, ��� �����
        if (currentPlayer == Player1) {
            //������ ���
            if (!map.SetPosition(cell, player1.GetMark())) {
                MessageBox::Show("������ ������� ������!", "��������!");
                return;
            }
        }
        else {
            //������ ���
            if (!map.SetPosition(cell, player2.GetMark())) {
                MessageBox::Show("������ ������� ������!", "��������!");
                return;
            }
        }
    }

    Update();
}


System::Void Krestikinoliki::GameForm::����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void Krestikinoliki::GameForm::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show("����������?", "��������!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
        NewGame();
    }
}

System::Void Krestikinoliki::GameForm::���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show("����������?", "��������!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
        StartForm^ form = gcnew StartForm();
        form->Show();
        this->Hide();
    }
}

System::Void Krestikinoliki::GameForm::�����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show("����������� ����� �� ����?", "��������!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
        Application::Exit();
    }
}

System::Void Krestikinoliki::GameForm::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    auto senderGrid = (DataGridView^)sender; //����������� ���������� ������ � �������

    //���������� ������� ��������� ������
    selectedCellPlayer.x = e->RowIndex;
    selectedCellPlayer.y = e->ColumnIndex;

    //������ ���
    SetPositionPlayer(selectedCellPlayer);
}