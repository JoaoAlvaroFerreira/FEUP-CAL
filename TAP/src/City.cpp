
#include "City.h"

	City::City(){

		this->id = 0;
		this->name = "";
		this->hotels = *(new vector<Hotel*>());
		this->coord = Coordinates();

	}

	City::City(int id, string n, Coordinates c, vector<Hotel*> ht, vector<int> pd, vector<string> ta) {

		this->id = id;
		this->name = n;
		this->hotels = ht;
		this->coord = c;
		this->possibleDestinations = pd;
		this->touristAttraction = ta;

	}

	int City::getID(){

		return this->id;
	}

	string City::getName(){

		return this->name;
	}

	Coordinates City::getCoordinates(){

		return coord;
	}

	vector<Hotel*> City::getHotels(){

		return this->hotels;
	}
	vector<int> City::getPossibleDestinations(){

		return this->possibleDestinations;
	}


	int City::getIDDestinies(int n){

		return possibleDestinations[n*3];
	}

	int City::getPlaneTicket(int n){

		return possibleDestinations[(n*3) + 1];
	}

	vector<string> City::getTouristAttractions(){

		return touristAttraction;
	}

	void City::setID(int id){

		this->id = id;
	}

	void City::setName(string n){

		this->name = n;
	}

	void City::setCoordinates(Coordinates c){

		this->coord = c;
	}

	void City::setHotels(vector<Hotel*> h){

		this->hotels = h;
	}

	void City::setDestinations(vector<int> pd){

		this->possibleDestinations = pd;
	}

	City::~City() {}
