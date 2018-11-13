
#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <sstream>
#include <ctime>
#include <string>

	using namespace std;

class Date {
private:
	unsigned int day;
	unsigned int month;
	unsigned int year;

public:
	Date();
	Date(string dataStr);
	string getString() const;
	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;
	Date operator=(Date assignee);

};


#endif
