#pragma once
#include <iostream>
#include <fstream>

using namespace std;


class Exception
{
private:
	string error_str; 
	string error_type; 

public:
	Exception(string error) :error_str(error) {};
	Exception(string error, string type) :error_str(error), error_type(type) {};

	const char* what() const noexcept {

		time_t now = time(0);
		tm* t = new tm;
		localtime_s(t, &now);


		ofstream record("log.txt", ios::app);
		if (record) {
			record << "Error: " << error_type << endl;
			record << "Äàòà: ";
			if (t->tm_mday < 10) record << "0" << t->tm_mday << ".";
			else record << t->tm_mday << ".";
			record << 1 + t->tm_mon << "." << 1900 + t->tm_year << endl;

			record << "Âðåìÿ: ";
			if (t->tm_hour < 10) record << "0" << t->tm_hour << ":";
			else record << t->tm_hour << ":";
			if (t->tm_min < 10) record << "0" << t->tm_min << ":";
			else record << t->tm_min << ":";
			if (t->tm_sec < 10) record << "0" << t->tm_sec << endl;
			else record << t->tm_sec << endl;

			record << "Error type: " << error_str << endl << endl;
		}
		record.close();

		return error_str.c_str();
	}
};

