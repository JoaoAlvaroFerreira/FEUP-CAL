
#ifndef SRC_AGENCY_H_
#define SRC_AGENCY_H_

#include "City.h"
#include "Client.h"
#include "Coordinates.h"
#include "StringAlgorithms.h"
#include "Date.h"
#include "Graph.h"
#include "Hotel.h"
#include "Trip.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Math.h"


class Agency {
private:
	Graph<City> graph;
	vector<Client*> clientes;
	vector<Trip*> trips;
	vector<City*> vec;

public:
	Agency();
	virtual ~Agency();
	void readFromCityFiles();
	void readFromClientFile();
	void readToClientFile();
	void readFromTripFiles();
	void readToTripsFile();
	Graph<City> getGraph();
	void printShortestPath(const City origin, const City destiny);

	//ADD METHODS
	void addClients(Client* cliente);
	void addTrips(Trip* viagem);

	//GET METHODS
	vector<Client*> getClientes() { return clientes; }
	vector<Trip*> getTrips() { return trips; }
	vector<City*> getCityVec() const;

	//MENUS
	void introMenu();
	void menuCliente();
	void menuTrip();
	void menuSave();
	void menuViagem();
	void menuViagem2();

	void adicionaCliente();
	void removeCliente();
	void listClients();

	void adicionaTrip();
	void addFlightsTrip(Trip viagem);
	void removeTrip();
	void destinationsList();
	void tripList();
	void escolheDireto();
	void escolheGeral();
	void destinosCidade();

	//UTIL
	void map();
	float setSeason(Date date);
	string searchInYourDestinations(vector<string> destinos, vector<string> locals);
	vector<string> searchInAllDestinations(vector<string> destinos, string local);
	void calculateMultiplePaths(Date date, vector<string> locals);
	string aproxSearchInYourDestinations(vector<string> destinos, vector<string> locals);
	vector<string> aproxSearchInAllDestinations(vector<string> destinos, string local);


	void calculatePathAcorddingToDistance();
	void calculatePathAcorddingToCost();
	double calculateDist(Vertex<City> *origin, Vertex<City> *destination);
	double calculateCost(Vertex<City> *origin, Vertex<City> *destination);
};

#endif /* SRC_AGENCY_H_ */
