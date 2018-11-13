

#ifndef SRC_HOTEL_H_
#define SRC_HOTEL_H_

#include <iostream>
#include <string>

using namespace std;


class Hotel {
private:
	string name;
	float price;

public:

	Hotel();
	Hotel(string n, float p);
	virtual ~Hotel();

	string getName();
	float getPrice();

	void setName(string n);
	void setPrice(float p);

};

#endif /* SRC_HOTEL_H_ */
