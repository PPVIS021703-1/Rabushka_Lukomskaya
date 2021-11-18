#include <iostream>
#include "Author.h"
#include "Book.h"



using namespace std;
using namespace bookSpace;
//using namespace authorSpace;

int main() {

	setlocale(LC_ALL, "rus");
	
	//АВТОР
	British A_brit;
	A_brit.SetAuthorName("Артутр Конан Дойл");
	A_brit.SetAuthorYear(1859);

	//КНИГА
	Detective B_det;
	B_det.SetBookName("Этюд в багровых тонах");
	B_det.SetBookYear(1887);
	B_det.SetBookAuthor(A_brit.GetAuthorName());

	A_brit.SetBookName(B_det.GetBookName());
	PrintInfo(B_det);
	A_brit.PrintInfo();

	//АВТОР
	American A_amer("Джек Лондон");
	A_amer.SetAuthorYear(1876);

	//КНИГА
	Roman B_rom("Мартин Иден");
	B_rom.SetBookYear(1909);
	B_rom.SetBookAuthor(A_amer.GetAuthorName());
	A_amer.SetBookName(B_rom.GetBookName());
	PrintInfo(B_rom);
	A_amer.PrintInfo();


	//КНИГА
	Historical B_his;
	B_his.SetBookYear(1978);
	B_his.SetBookName("Капитанская дочка");
	//АВТОР
	Russian A_rus("Пушкин А.С.", 1799);
	A_rus.SetBookName(B_his.GetBookName());
	SetAuthorName(B_his, A_rus.GetAuthorName());
	A_rus.PrintInfo();
	PrintInfo(B_his);
	

	//КНИГА
	Roman_His B_rh;
	B_rh.SetBookName("Ещё одна из рода Болейн");
	B_rh.SetBookYear(2001);

	//АВТОР
	British A_brit1("Филиппа Грегори", 1954);
	A_brit1.SetBookName(B_rh.GetBookName());
	SetAuthorName(B_rh, A_brit1.GetAuthorName());
	A_brit1.PrintInfo();
	PrintInfo(B_rh);

	//АВТОР
	American A_amer1("Стивен Кинг", 1947);

	//КНИГА
	Horror B_h1;
	B_h1.SetBookName("Сияние");
	B_h1.SetBookYear(1977);
	SetAuthorName(B_h1, A_amer1.GetAuthorName());
	A_amer1.SetBookName(B_h1.GetBookName());
	A_amer1.PrintInfo();
	PrintInfo(B_h1);

	//КНИГА
	Hor_Det B_hr("Меловой человек", 2018);
	B_hr.Horror::SetBookAuthor(A_amer1.GetAuthorName());
	B_hr.PrintInfo();

	return 0;
}