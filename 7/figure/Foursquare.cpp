#include <cstdlib>
#include <iostream>
#include "Foursquare.h"

Foursquare::Foursquare() :
		Foursquare(0) {
}

Foursquare::Foursquare(size_t i) :
		side(i) {
}

Foursquare::Foursquare(std::istream &is) {
	is >> side;
	if (!is) {
		side = 0;
		is.clear();
		is.ignore();
	}
}

Foursquare::Foursquare(const Foursquare& orig) {
	side = orig.side;
}

double Foursquare::Square() const {
	return side * side;
}

void Foursquare::Print(std::ostream& os) const {
	os << "{Square " << side << " (" << Square() << ")}";
}

char Foursquare::getType() const {
	return 's';
}

std::ostream& operator <<(std::ostream& os, const Foursquare& foursquare) {
	foursquare.Print(os);
	return os;
}
Foursquare::~Foursquare() {
}
