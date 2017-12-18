#include "Octahedron.h"
#include <cmath>

Octahedron::Octahedron() :
		Octahedron(0) {
}

Octahedron::Octahedron(size_t i) :
		side(i) {
}

Octahedron::Octahedron(std::istream &is) {
	is >> side;
	if (!is) {
		side = 0;
		is.clear();
		is.ignore();
	}
}

Octahedron::Octahedron(const Octahedron& orig) {
	side = orig.side;
}

double Octahedron::Square() const {
	return 2 * side * side * (1 + sqrt(2));

}

void Octahedron::Print(std::ostream& os) const {
	os << "{Octahedron " << side << " (" << Square() << ")}";

}

Octahedron& Octahedron::operator =(const Octahedron& right) {
	if (this == &right)
		return *this;
	side = right.side;
	return *this;
}

bool Octahedron::operator==(const Octahedron& right) {
	return side == right.side;
}

char Octahedron::getType() const {
	return 'o';
}

std::ostream& operator <<(std::ostream& os, const Octahedron& octahedron) {
	octahedron.Print(os);
	return os;
}

std::istream& operator >>(std::istream& is, Octahedron& octahedron) {
	is >> octahedron.side;
	if (!is) {
		octahedron.side = 0;
		is.clear();
		is.ignore();
	}
	return is;
}
Octahedron::~Octahedron() {
}
