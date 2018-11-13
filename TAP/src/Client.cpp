
#include "Client.h"


	Client::Client(string n,int ID, int pn) {

	this->name = n;
	this->id = ID;
	this->phoneNumber = pn;

	}

	Client::~Client() {}

	int Client::getID(){

	return this->id;
	}

	int Client::getPhoneNumber(){

	return this->phoneNumber;
	}

	string Client::getName(){

	return this->name;
	}

	void Client::setID(int id){

	this->id = id;
	}

	void Client::setPhoneNumber(int pn){

	this->phoneNumber = pn;
	}

	void Client::setName(string n){

	this->name = n;
	}
