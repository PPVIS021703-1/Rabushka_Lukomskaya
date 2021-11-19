#pragma once
#include <iostream>
#include "Book.h"

using namespace std;

// AUTHOR CLASS
class Author {
private:
	string author_name;
	int author_year = 0;
	string book_name;
	string author_nation;


public:

	virtual void PrintInfo() {
		cout << "\t-----  Автор -----" << endl;
		cout << "\tИмя автора: " << GetAuthorName() << endl;
		cout << "\tГод рождения: " << GetAuthorYear() << endl;
		cout << "\tКнига: " << GetBookName() << endl;
	};
	string GetAuthorName() {
		return author_name;
	}
	int GetAuthorYear() {
		return author_year;
	}
	string GetBookName() {
		return book_name;
	}
	void SetAuthorName(string n) {
		author_name = n;
	}
	void SetAuthorYear(int year) {
		author_year = year;
	}
	void SetBookName(string book) {
		this->book_name = book;
	}
	virtual string GetNation() = 0;  //чисто виртуальный метод для абстрактного класса
};


class British :public Author {

public:
	British(string, int, string);
	British(string, int);
	British(string);
	British() {
		SetAuthorName("Нет информации");
		SetAuthorYear(0);
		SetBookName("Нет информации");
	};

	void PrintInfo() override {
		Author::PrintInfo();
		cout << "\t----- " << "Английская литература" << " ------" << endl << endl;
	}

	virtual string GetNation() override {
		return "Английская литература";
	}
};

British::British(string name) {
	SetAuthorName(name);
}

British::British(string name, int year) {
	SetAuthorName(name);
	SetAuthorYear(year);
}

British::British(string name, int year, string book) {
	SetAuthorName(name);
	SetAuthorYear(year);
	SetBookName(book);
}






class American :private  Author {

public:
	American() {
		SetAuthorName("Нет информации");
		SetAuthorYear(0);
		SetBookName("Нет информации");
	};
	American(string);
	American(string, int);
	American(string, int, string);

	void PrintInfo() override {
		Author::PrintInfo();
		cout << "\t----- " << "Американская литература" << " ------" << endl << endl;
	}
	string GetNation() override {
		return "Американская литература";
	}

	string GetAuthorName() {
		return Author::GetAuthorName();
	}
	int GetAuthorYear() {
		return Author::GetAuthorYear();
	}
	string GetBookName() {
		return Author::GetBookName();
	}
	void SetAuthorName(string name) {
		Author::SetAuthorName(name);
	}
	void SetAuthorYear(int year) {
		Author::SetAuthorYear(year);
	}
	void SetBookName(string book) {
		Author::SetBookName(book);
	}
};

American::American(string name) {
	SetAuthorName(name);
}

American::American(string name, int year) {
	SetAuthorName(name);
	SetAuthorYear(year);
}

American::American(string name, int year, string book) {
	SetAuthorName(name);
	SetAuthorYear(year);
	SetBookName(book);
}




class Russian :protected Author {

public:
	Russian() {
		SetAuthorName("Нет информации");
		SetAuthorYear(0);
		SetBookName("Нет информации");
	};
	Russian(string);
	Russian(string, int);
	Russian(string, int, string); 

	void PrintInfo() override {
		Author::PrintInfo();
		cout << "\t----- " << "Русская литература" << " ------" << endl << endl;
	}

	string GetNation() override {
		return "Русская литература";
	}

	string GetAuthorName() {
		return Author::GetAuthorName();
	}
	int GetAuthorYear() {
		return Author::GetAuthorYear();
	}
	string GetBookName() {
		return Author::GetBookName();
	}
	void SetAuthorName(string name) {
		Author::SetAuthorName(name);
	}
	void SetAuthorYear(int year) {
		Author::SetAuthorYear(year);
	}
	void SetBookName(string book) {
		Author::SetBookName(book);
	}
};

Russian::Russian(string name) {
	SetAuthorName(name);
}

Russian::Russian(string name, int age) {
	SetAuthorName(name);
	SetAuthorYear(age);
}

Russian::Russian(string name, int age, string book) {
	SetAuthorName(name);
	SetAuthorYear(age);
	SetBookName(book);
}
