
#ifndef SRC_CITY_H_
#define SRC_CITY_H_

#include "Coordinates.h"
#include "Hotel.h"
#include <vector>
#include <iostream>


class City {
private:
	int id;
	string name;
	Coordinates coord;
	vector<Hotel*> hotels;
	vector<int> possibleDestinations;//{id1,cost1,flightDuration1,...}
	vector<string> touristAttraction;


public:
	City(int id, string n, Coordinates c, vector<Hotel*> ht, vector<int> pd, vector <string> ta);
	City();
	virtual ~City();

	int getID();
	string getName();
	Coordinates getCoordinates();
	vector<Hotel*> getHotels();
	vector<int> getPossibleDestinations();
	int getIDDestinies(int n);
	int getPlaneTicket(int n);
	vector<string> getTouristAttractions();

	void setID(int id);
	void setName(string n);
	void setCoordinates(Coordinates c);
	void setHotels(vector<Hotel*> h);
	void setTouristAttractions(vector<string> ta);
	void setDestinations(vector<int> pd);

	bool operator==(const City &other) { return id==other.id;}
};

#endif /* SRC_CITY_H_ */
