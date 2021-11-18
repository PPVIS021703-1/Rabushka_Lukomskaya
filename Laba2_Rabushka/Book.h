#pragma once
#include <iostream>
#include "Author.h"

using namespace std;

// BOOK CLASS 
class Book {
private:
	string book_name;
	int book_year = 0;
	string book_author;

public:
	
	void SetBookName(string name) {
		book_name = name;
	}
	string GetBookName() {
		return book_name;
	}
	void SetBookYear(int year) {
		book_year = year;
	}
	int GetBookYear() {
		return book_year;
	}
	void SetBookAuthor(string author) {
		book_author = author;
	}
	string GetBookAuthor() {
		return book_author;
	}

	virtual string GetBookGenre() = 0;
	
};


// жанр РОМАН
class Roman: public virtual Book {

public:
	Roman() {
		SetBookName("Нет информации");
		SetBookYear(0);
		SetBookAuthor("Нет информации");
	};
	Roman(string);
	Roman(string, int, string);

	string GetBookGenre() override{
		return "Роман";
	}
};

Roman::Roman(string name) {
	SetBookName(name);
}

Roman::Roman(string name, int year, string author) {
	SetBookName(name);
	SetBookYear(year);
	SetBookAuthor(author);
}

//жанр ИСТОРИЧЕСКИЙ
class Historical : public virtual Book {
public:
	Historical() {
		SetBookName("Нет информации");
		SetBookYear(0);
		SetBookAuthor("Нет информации");
	};
	Historical(string);
	Historical(string, int, string);

	string GetBookGenre() override {
		return "Исторический";
	}
};

Historical::Historical(string name) {
	SetBookName(name);
}

Historical::Historical(string name, int year, string author) {
	SetBookName(name);
	SetBookYear(year);
	SetBookAuthor(author);
}

//жанр ИСТОРИЧЕСКИЙ РОМАН
class Roman_His : public Roman, public Historical {
public:
	Roman_His() {
		SetBookName("Нет информации");
		SetBookYear(0);
		SetBookAuthor("Нет информации");
	};
	Roman_His(string);
	Roman_His(string, int, string);

	string GetBookGenre() override {
		return "Исторический детектив";
	}
};

Roman_His::Roman_His(string name) {
	SetBookName(name);
}

Roman_His::Roman_His(string name, int year, string author) {
	SetBookName(name);
	SetBookYear(year);
	SetBookAuthor(author);
}


//жанр ДЕТЕКТИВ
class Detective : public Book {
public:
	Detective() {
		SetBookName("Нет информации");
		SetBookYear(0);
		SetBookAuthor("Нет информации");
	};
	Detective(string);
	Detective(string, int, string);

	string GetBookGenre() override {
		return "Детектив";
	}
};

Detective::Detective(string name) {
	SetBookName(name);
}

Detective::Detective(string name, int year, string author) {
	SetBookName(name);
	SetBookYear(year);
	SetBookAuthor(author);
}

//жанр УЖАСЫ
class Horror: public Book {
public:
	
	Horror() {
		SetBookName("Нет информации");
		SetBookYear(0);
		SetBookAuthor("Нет информации");
	};
	Horror(string);
	Horror(string, int);
	Horror(string, int, string);

	string GetBookGenre() override {
		return "Ужасы";
	}
};

Horror::Horror(string name) {
	SetBookName(name);
}

Horror::Horror(string name, int year) {
	SetBookName(name);
	SetBookYear(year);
}

Horror::Horror(string name, int year, string author) {
	SetBookName(name);
	SetBookYear(year);
	SetBookAuthor(author);
}

//жанр ДЕТЕКТИВ УЖАСТИК
class Hor_Det : public Horror, public Detective{
public:
	Hor_Det() {
		Horror::SetBookName("Нет информации");
		Horror::SetBookYear(0);
		Horror::SetBookAuthor("Нет информации");
	};
	Hor_Det(string);
	Hor_Det(string, int);
	Hor_Det(string, int, string);

	string GetBookGenre() override {
		return "Ужастик Детектив";
	}

	void PrintInfo() {
		cout << "\t----- Книга -----" << endl;
		cout << "\tНазвание книги: " << Horror::GetBookName() << endl;
		cout << "\tИмя автора: " << Horror::GetBookAuthor() << endl;
		cout << "\tГод издания: " << Horror::GetBookYear() << endl;
		cout << "\tЖанр: " << GetBookGenre() << endl << endl;
	}


};
Hor_Det::Hor_Det(string name) {
	Horror::SetBookName(name);
}
Hor_Det::Hor_Det(string name, int year) {
	Horror::SetBookName(name);
	Horror::SetBookYear(year);
}
Hor_Det::Hor_Det(string name, int year, string author) {
	Horror::SetBookName(name);
	Horror::SetBookYear(year);
	Horror::SetBookAuthor(author);
}


//пространство имен для работы с книгами

namespace bookSpace {
	//вывод информации о книге на экран
	void PrintInfo(Book& book) {//указатель на базовый класс может принимать ссылки на любого своего наследника!!
		cout << "\t----- Книга -----" << endl;
		cout << "\tНазвание книги: " << book.GetBookName() << endl;
		cout << "\tИмя автора: " << book.GetBookAuthor() << endl;
		cout << "\tГод издания: " << book.GetBookYear() << endl;
		cout << "\tЖанр: " << book.GetBookGenre() << endl << endl;
	}


	//установка имени автора
	void SetAuthorName(Book& book, string a) {
		book.SetBookAuthor(a);
	}
}
