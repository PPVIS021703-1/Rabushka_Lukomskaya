#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Singleton {
private:
	string data;
	static Singleton* _instance;

protected:
	Singleton() {
		data = " ";
	}
	

public:
	//проверка, не создан ли экземпляр
	static Singleton* instance() {
		if (_instance == nullptr) { //если нет
			_instance = new Singleton();
			return _instance;
		}
		else return nullptr;
	}

	void SingletonOperation(string s, bool status) {
		time_t now = time(0);
		tm* t = new tm;
		localtime_s(t, &now);

		ofstream record("log.txt", ios::app);
		if (record) {
			record << "Operation type: " << s << endl;

			record << "Дата: ";
			if (t->tm_mday < 10) record << "0" << t->tm_mday << ".";
			else record << t->tm_mday << ".";
			record << 1 + t->tm_mon << "." << 1900 + t->tm_year << endl;

			record << "Время: ";
			if (t->tm_hour < 10) record << "0" << t->tm_hour << ":";
			else record << t->tm_hour << ":";
			if (t->tm_min < 10) record << "0" << t->tm_min << ":";
			else record << t->tm_min << ":";
			if (t->tm_sec < 10) record << "0" << t->tm_sec << endl;
			else record << t->tm_sec << endl;

			if (status) record << "Status:" << "\tSuccess" << endl << endl;
			else record << "Status:" << "\tFail" << endl << endl;
		}

		record.close();
	}

	template <typename T>
	void SingletonOperation(string s, bool status, T) {
		time_t now = time(0);
		tm* t = new tm;
		localtime_s(t, &now);

		ofstream record("log.txt", ios::app);
		if (record) {
			record << "Operation type: " << s << endl;

			record << "Дата: ";
			if (t->tm_mday < 10) record << "0" << t->tm_mday << ".";
			else record << t->tm_mday << ".";
			record << 1 + t->tm_mon << "." << 1900 + t->tm_year << endl;

			record << "Время: ";
			if (t->tm_hour < 10) record << "0" << t->tm_hour << ":";
			else record << t->tm_hour << ":";
			if (t->tm_min < 10) record << "0" << t->tm_min << ":";
			else record << t->tm_min << ":";
			if (t->tm_sec < 10) record << "0" << t->tm_sec << endl;
			else record << t->tm_sec << endl;

			record << T << endl;

			if (status) record << "Status:" << "\tSuccess" << endl << endl;
			else record << "Status:" << "\tFail" << endl << endl;
		}

		record.close();
	}

	//деструктор
	~Singleton() {
		delete _instance;
	}
};

