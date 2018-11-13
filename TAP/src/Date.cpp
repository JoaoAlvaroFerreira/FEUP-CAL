#include "Date.h"


    Date::Date()
    {
        time_t now;
        now = time(NULL); //Number os secs since 1st of January 1970

        tm* ltmP = localtime(&now); //Initialises the struct

        day = ltmP->tm_mday;
        month = 1 + ltmP->tm_mon;
        year = 1900 + ltmP->tm_year;
    }

    Date::Date(string dataStr) {

    string fragment;
    istringstream iss;

    iss.str(dataStr);
    getline(iss, fragment, '/');
    day = stoi(fragment);

    getline(iss, fragment, '/');
    month = stoi(fragment);

    getline(iss, fragment);
    year = stoi(fragment);
}

    string Date::getString() const {
    ostringstream iss;
    iss << day << "/" << month <<"/" <<year;
    return iss.str();
    }

    unsigned int Date::getDay() const {

    	return this->day;
    }

    unsigned int Date::getMonth() const {

    	return this->month;
    }

    unsigned int Date::getYear() const {

    	return this->year;
    }

    Date Date::operator=(Date assignee)  {
    	this->day = assignee.getDay();
    	this->month = assignee.getMonth();
    	this->year = assignee.getYear();

		return *this;
    	}
