/*
 * Agency.cpp
 *
 *  Created on: Mar 26, 2018
 *      Author: Alexandra
 */

#include "Agency.h"

#define NOCiF 57//number of city files

using namespace std;

Agency::Agency() {

	readFromClientFile();
	readFromCityFiles();
	readFromTripFiles();

	introMenu();

}

Agency::~Agency() {}

void Agency::readFromCityFiles(){

	string assets = "./assets/Cities/"; //This is used to pre append to rest of path
	string cityName, hotelName, attractionName;
	string ID, temp;
	unsigned int x, y, hotelNumber, numberDestinies, cityID, cityPrice, cityTime, numberAttractions;
	float price;

	ifstream in;

	for(int i = 1; i <= NOCiF; i ++) { //For each file --> cities

		string fich = assets + to_string(i) + ".txt";
		const char *nomeFich;
		nomeFich = fich.c_str();
		in.open(nomeFich);
		if (!in.fail()) {

			vector<Hotel *> hotels;
			vector<int> destinations;
			vector<string> attractions;
			getline(in, cityName);
			getline(in, ID);
			getline(in, temp, ',');
			x = stoi(temp.c_str());
			getline(in, temp);
			y = stoi(temp.c_str());

			Coordinates c = Coordinates(x, y);

			getline(in, temp);
			hotelNumber = atoi(temp.c_str());

			for (unsigned int i = 0; i < hotelNumber; i++) {

				getline(in, hotelName);
				getline(in, temp);
				price = stof(temp.c_str());

				Hotel *hotel = new Hotel(hotelName, price);
				hotels.push_back(hotel);

			}

			getline(in, temp);
			numberDestinies = stoi(temp.c_str());

			for (unsigned int i = 0; i < numberDestinies; i++) {

				getline(in, temp);
				cityID = atoi(temp.c_str());
				getline(in, temp);
				cityPrice = atoi(temp.c_str());
				getline(in, temp);
				cityTime = atoi(temp.c_str());

				destinations.push_back(cityID);
				destinations.push_back(cityPrice);
				destinations.push_back(cityTime);

			}

			getline(in, temp);
			numberAttractions = stoi(temp.c_str());

			for(unsigned int i = 0; i < numberAttractions; i++){
				getline(in, attractionName);

				attractions.push_back(attractionName);


			}

			City city(stoi(ID), cityName, c, hotels, destinations, attractions);

			City *city1 = new City(stoi(ID), cityName, c, hotels, destinations, attractions);

			graph.addVertex(city);

			vec.push_back(city1);

			in.close();

		} else
			cout << "reading from city files failed" << endl;
	}

	cout << " Finished loading Cities!\n";
}

void Agency::calculatePathAcorddingToDistance(){

		for(int k = 0; k < graph.getNumVertex(); k++){ //For each Vertex goes through vector possibleDestinations
			for(unsigned int l = 0; l < 3; l++){
				Vertex<City>* destVertex =  this->graph.findVertexID(this->graph.getVertexSet()[k]->getInfo().getIDDestinies(l));
				this->graph.addEdge(
						this->graph.getVertexSet()[k]->getInfo(),
						destVertex->getInfo(),
						calculateDist(graph.getVertexSet()[k], destVertex));
			}
		}
}

void Agency::calculatePathAcorddingToCost(){

		for(int k = 0; k < graph.getNumVertex(); k++){ //For each Vertex goes through vector possibleDestinations
			for(unsigned int l = 0; l < 3; l++){
				Vertex<City>* destVertex =  this->graph.findVertexID(this->graph.getVertexSet()[k]->getInfo().getIDDestinies(l));
				this->graph.addEdge(
						this->graph.getVertexSet()[k]->getInfo(),
						destVertex->getInfo(),
						calculateCost(graph.getVertexSet()[k], destVertex));
			}
		}
}

void Agency::readFromClientFile() {

	string assets = "./assets/Clients";
	ifstream in;

	string clientName, temp;
	unsigned int id, cellphone;

	string fich = assets + ".txt";
	const char *nomeFich;
	nomeFich = fich.c_str();

	in.open(nomeFich);

	while(!in.eof()){

		getline(in, clientName, ';');
		getline(in, temp, ';');
		id = stoi(temp.c_str());
		getline(in, temp);
		cellphone = stoi(temp.c_str());
		Client *client = new Client(clientName,id,cellphone);
		clientes.push_back(client);
	}

	cout << " Finished loading Clients!\n";
	in.close();
}

vector<City*> Agency::getCityVec() const{

	return vec;
}

void Agency::readFromTripFiles() {

	string assets = "./assets/Trips";
	ifstream in;

	int id;
	double cost, distance;
	string temp,departureDate, arrivalDate, departureCity, arrivalCity, hotelName;

	string fich = assets + ".txt";
	const char *nomeFich;
	nomeFich = fich.c_str();

	in.open(nomeFich);

	if(!in.eof()){

		getline(in,temp,';');
		id = stoi(temp.c_str());
		getline(in, departureDate,';');
		getline(in, arrivalDate,';');
		getline(in, departureCity,';');
		getline(in, arrivalCity,';');
		getline(in, hotelName,';');
		getline(in, temp,';');
		cost = stod(temp.c_str());
		getline(in, temp);
		distance = stod(temp.c_str());

		Date date1(departureDate);
		Date date2(arrivalDate);

		Trip *trip = new Trip(id, date1, date2, departureCity, arrivalCity, hotelName, cost, distance);
		trips.push_back(trip);

	}

	in.close();
}

void Agency::readToTripsFile(){

	ofstream file("assets/Trips.txt");

	file.clear();

	for(unsigned int i = 0; i < this->trips.size(); i++){

		int id = this->trips[i]->getID();
		string departureDate = this->trips[i]->getDepartureDate().getString();
		string arrivalDate = this->trips[i]->getArrivalDate().getString();
		string departureCity = this->trips[i]->getDepartureCity();
		string arrivalCity = this->trips[i]->getArrivalCity();
		string hotelName = this->trips[i]->getHotel();
		double cost = this->trips[i]->getCost();
		double distance = this->trips[i]->getDistance();

		if(this->trips.size() - 1 == i){

			file <<  id <<  ";" <<  departureDate << ";" << arrivalDate <<  ";" << departureCity << ";" << arrivalCity << ";" << hotelName << ";" << cost << ";" << distance;

		}

		else {

			file <<  id <<  ";" <<  departureDate << ";" << arrivalDate <<  ";" << departureCity << ";" << arrivalCity << ";" << hotelName << ";" << cost << ";" << distance << endl;
		}
	}

	file.close();

	cout << "Trips file saved successfully! \n";

}

void Agency::readToClientFile(){

	ofstream file("assets/Clients.txt");

	file.clear();

	for(unsigned int i = 0; i < this->clientes.size(); i++){

		int id = this->clientes[i]->getID();
		int cellphone = this->clientes[i]->getPhoneNumber();
		string name = this->clientes[i]->getName();

		if(this->clientes.size() - 1 == i){

			file << name << ";" << id << ";" << cellphone;
		}

		else {

			file << name << ";" << id << ";" << cellphone <<endl;
		}
	}

	file.close();

	cout << "Clients file saved successfully! \n";

}

void Agency::addClients(Client* cliente) {
	clientes.push_back(cliente);
}

void Agency::addTrips(Trip* viagem) {
	trips.push_back(viagem);
}

Graph<City> Agency::getGraph() {
	return graph;
}

double Agency::calculateDist(Vertex<City> *origin, Vertex<City> *destination) {

	double ret;

	double x = origin->getInfo().getCoordinates().getX();

	double y = origin->getInfo().getCoordinates().getY();

	ret = sqrt(x*x + y*y);

	return ret;
}

double Agency::calculateCost(Vertex<City> *origin, Vertex<City> *destination){

	int cheaper = 0;

	for(int i = 0; i < 2; i++){

	double firstCost = origin->getInfo().getPlaneTicket(i);
	double secondCost = origin->getInfo().getPlaneTicket(i+1);

	if(firstCost < secondCost)
		cheaper = firstCost;

	else
		cheaper = secondCost;
	}
	return cheaper;
}
