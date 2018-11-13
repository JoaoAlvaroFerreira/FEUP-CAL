
#ifndef SRC_TRIP_H_
#define SRC_TRIP_H_

#include <iostream>
#include <vector>
#include "Date.h"

class Trip {
private:

	int ID;
	Date departureDate;
	Date arrivalDate;
	string departureCity;
	string arrivalCity;
	string hotelName;
	double cost;
	double distance;

public:
	Trip();
	Trip(Date d, Date a);
	Trip(int id, Date d, Date a, string dpc, string ac, string hn, double c, double dc);
	virtual ~Trip();

	Date getDepartureDate();
	Date getArrivalDate();
	string getArrivalCity();
	string getDepartureCity();
	double getCost();
	double getDistance();
	int getID();
	string getHotel();

	void setID(int id);
	void setDepartureDate(Date d);
	void setArivalDate(Date a);
	void setArrivalCity(string ac);
	void setDepartureCity(string dc);
	void setCost(double c);
	void setDistance(double d);
	void setHotel(string ht);

};

#endif /* SRC_TRIP_H_ */
