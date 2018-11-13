
#include "Coordinates.h"

Coordinates::Coordinates(){}

Coordinates::Coordinates(int x, int y){

	this->x = x;
	this->y = y;

}

Coordinates::~Coordinates() {
}

int Coordinates::getX(){

	return this->x;
}

int Coordinates::getY(){

	return this->y;
}

void Coordinates::setX(int x){

	this->x = x;
}

void Coordinates::setY(int y){

	this->y = y;
}

void Coordinates::setCoordinates(int x, int y){

	this->x = x;
	this->y = y;
}
