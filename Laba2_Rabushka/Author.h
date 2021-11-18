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
		cout << "\t-----  ����� -----" << endl;
		cout << "\t��� ������: " << GetAuthorName() << endl;
		cout << "\t��� ��������: " << GetAuthorYear() << endl;
		cout << "\t�����: " << GetBookName() << endl;
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
	virtual string GetNation() = 0;  //����� ����������� ����� ��� ������������ ������
};


class British :public Author {

public:
	British(string, int, string);
	British(string, int);
	British(string);
	British() {
		SetAuthorName("��� ����������");
		SetAuthorYear(0);
		SetBookName("��� ����������");
	};

	void PrintInfo() override {
		Author::PrintInfo();
		cout << "\t----- " << "���������� ����������" << " ------" << endl << endl;
	}

	virtual string GetNation() override {
		return "���������� ����������";
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
		SetAuthorName("��� ����������");
		SetAuthorYear(0);
		SetBookName("��� ����������");
	};
	American(string);
	American(string, int);
	American(string, int, string);

	void PrintInfo() override {
		Author::PrintInfo();
		cout << "\t----- " << "������������ ����������" << " ------" << endl << endl;
	}
	string GetNation() override {
		return "������������ ����������";
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
		SetAuthorName("��� ����������");
		SetAuthorYear(0);
		SetBookName("��� ����������");
	};
	Russian(string);
	Russian(string, int);
	Russian(string, int, string); 

	void PrintInfo() override {
		Author::PrintInfo();
		cout << "\t----- " << "������� ����������" << " ------" << endl << endl;
	}

	string GetNation() override {
		return "������� ����������";
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
