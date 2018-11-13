
#ifndef COORDINATES_H_
#define COORDINATES_H_

class Coordinates {
private:
	int x;
	int y;

public:

	Coordinates();
	Coordinates(int x, int y);
	virtual ~Coordinates();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void setCoordinates(int x, int y);
};

#endif /* COORDINATES_H_ */
