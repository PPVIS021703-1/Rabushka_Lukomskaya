#include "GameForm.h"
#include "StartForm.h"

using namespace std;

enum GameMode {
    PvP = 0, //игрок против игрока
    PvE //игрок против компа
} gameMode;

//общие данные 
GameMap map;
Gamer player1;
Gamer player2;
GamerStatus currentPlayer;
Field2 selectedCellPlayer;

//флажки
bool canPlay;
bool endGame;

//для компа
vector<Field2> allMoves;//все возможные ходы
int currentMoves; //количество ходов

// щапуск игры
System::Void Krestikinoliki::GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    //инициализация параметров
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
    //проверяем режим игры
    if (gameMode == PvE) {
        //если ход компа
        if (currentPlayer == Computer) {
            StepAI(); //делаем ход
        }
        Update();
    }
}

void Krestikinoliki::GameForm::Update()
{
    //проверяем состояние игрового поля(победил ли кто-то)
    int state_game = map.CheckWinner();
    if (endGame) return;

    if (state_game == 1) {
        if (gameMode == PvP) {
            UpdateGameGrid();
            MessageBox::Show("Поздравляем Игрока1 с победой!", "Победа!");
        }
        else {
            UpdateGameGrid();
            MessageBox::Show("Человечество не потеряно!! С победой, Игрок!", "Победа!");
        }
        //UpdateGameGrid();

        endGame = true;  //теперь игра точно окончена
    }
    else if (state_game == 2) {
        if (gameMode == PvP) {
            UpdateGameGrid();
            MessageBox::Show("Поздравляем Игрока2 с победой!!", "Победа!");
        }
        else {
            UpdateGameGrid();
            MessageBox::Show("Искусственный интеллект победил!! Человечество уже не то.", "Машины, вперед!");
        }
       // UpdateGameGrid();

        endGame = true; //конец игры
    }
    else if (state_game == 3) {
        MessageBox::Show("Естественный и искусственный интеллект пока не решили, кто умнее!", "Десятки лет развития технологий ради этого");
        UpdateGameGrid();

        endGame = true;
    }

    if (endGame) {
        if (MessageBox::Show("Хотите запустить новую игру?", "Поиграем?", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
            NewGame();
        }
        return;//выходим из метода
    }

    //для AI
    if (gameMode == PvE) {
        if (currentPlayer == Computer) { //если ходил комп, то теперь ходит игрок
            status->Text = "Ход: Игрок!";
            currentPlayer = Player;
            return;
        }
        else {
            status->Text = "Ход: Компьютер!";
            currentPlayer = Computer;

            GameLogic();
            UpdateGameGrid();
            return;
        }
    }
    else {
        if (currentPlayer == Player1) {
            status->Text = "Ход: 0";//нолик
            currentPlayer = Player2;
        }
        else {
            status->Text = "Ход: Х"; //крестик
            currentPlayer = Player1;
        }
    }

    GameLogic();
    UpdateGameGrid();
}

void Krestikinoliki::GameForm::NewGame()
{
    //инициализация данных
    map.SetMap(rows, columns, length);
    rand = gcnew Random();
    endGame = false;

    CreateGameGrid(map.GetSize());

    //инициализация всех возможных ходов AI
    currentMoves = 0;
    allMoves.clear();
    Field2 buf;
    for (int i = 0; i < map.GetSize().x; i++) {
        for (int j = 0; j < map.GetSize().x; j++) {
            buf.x = i;
            buf.y = j;

            allMoves.push_back(buf);//координаты всех точек, куда походить
        }
    }

    //перемещиваем все ходы несколько раз
    //чтобы не прийти в одну и ту же точку
    int num_mixing = rand->Next(1, 10);
    for (int i = 0; i < num_mixing; i++) {
        random_shuffle(allMoves.begin(), allMoves.end());
    }
    //проверяем очередность и режим
    int state_game = rand->Next(1, 3); //выдаем рандомное число от  1 до 2
    if (state_game == 1) {
        if (gameMode == PvE) {
            player1.SetField(Player, 1); //крестики
            player2.SetField(Computer, 2); //нолики

            status->Text = "Ход: Игрок!";

            currentPlayer = Player;
        }
        else {
            player1.SetField(Player1, 1);
            player2.SetField(Player2, 2);

            status->Text = "Ход: Х!";

            currentPlayer = Player1;
        }
    }
    else if (state_game == 2) {
        if (gameMode == PvE) {
            player1.SetField(Player, 1); //крестики
            player2.SetField(Computer, 2); //нолики

            status->Text = "Ход: Компьютер!";

            currentPlayer = Computer;

            GameLogic();
            UpdateGameGrid();
        }
        else {
            player1.SetField(Player1, 1);
            player2.SetField(Player2, 2);

            status->Text = "Ход: 0!";

            currentPlayer = Player2;
        }
    }
    else {
        MessageBox::Show("Ошибка генерации первоначального выбора игрока!", "Ошибка!");
        return;
    }
}

void Krestikinoliki::GameForm::StepAI()
{
    //проверяем, есть ли ещё ходы
    if (currentMoves < allMoves.size()) {
        //проверяем текущий ход
        if (map.IsEmpty(allMoves[currentMoves])) {
            //если ячейка свободна, делаем ход
            map.SetPosition(allMoves[currentMoves], player2.GetMark());
            currentMoves++;
        }
        else {
            //если клетка занята, переходим на другую
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
    //очищаем таблицу
    dataGridView->Rows->Clear();
    dataGridView->Columns->Clear();

    //создаем столбцы
    for (int i = 0; i < size.x; i++) {
        DataGridViewButtonColumn^ column = gcnew DataGridViewButtonColumn();
        column->HeaderCell->Value = Convert::ToString(i + 1);
        column->Name = "column" + i;
        column->Width = 50;

        dataGridView->Columns->Add(column);
    }

    //создаем строки
    for (int j = 0; j < size.y; j++) {
        dataGridView->Rows->Add();
        dataGridView->Rows[j]->HeaderCell->Value = Convert::ToString(j + 1);
        dataGridView->Rows[j]->Height = 50;
    }
}

System::Void Krestikinoliki::GameForm::SetPositionPlayer(Field2 cell)
{
    //проверяем режим игры
    if (gameMode == PvE) {
        //проверяем очередность игрока
        if (currentPlayer == Player) {
            //делаем ход
            if (!map.SetPosition(cell, player1.GetMark())) {
                MessageBox::Show("Данная позиция занята!", "Внимание!");
                return;
            }
        }
        else {
            MessageBox::Show("Еще не ваша очередь!", "Внимание!");
            return;
        }
    }
    else {//если мы в PvP режиме
        //проверяяем, кто ходит
        if (currentPlayer == Player1) {
            //делаем ход
            if (!map.SetPosition(cell, player1.GetMark())) {
                MessageBox::Show("Данная позиция занята!", "Внимание!");
                return;
            }
        }
        else {
            //делаем ход
            if (!map.SetPosition(cell, player2.GetMark())) {
                MessageBox::Show("Данная позиция занята!", "Внимание!");
                return;
            }
        }
    }

    Update();
}


System::Void Krestikinoliki::GameForm::менюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void Krestikinoliki::GameForm::новаяИграToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show("Продолжить?", "Внимание!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
        NewGame();
    }
}

System::Void Krestikinoliki::GameForm::вернутьсяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show("Продолжить?", "Внимание!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
        StartForm^ form = gcnew StartForm();
        form->Show();
        this->Hide();
    }
}

System::Void Krestikinoliki::GameForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show("Подтвердить выход из игры?", "Внимание!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
        Application::Exit();
    }
}

System::Void Krestikinoliki::GameForm::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    auto senderGrid = (DataGridView^)sender; //преобразуем полученный объект в таблицу

    //запоминаем индексы выбранной ячейки
    selectedCellPlayer.x = e->RowIndex;
    selectedCellPlayer.y = e->ColumnIndex;

    //делаем ход
    SetPositionPlayer(selectedCellPlayer);
}
