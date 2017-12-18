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

bool Octahedron::operator==(const Octahedron& other) {
	return side == other.side;
}
Octahedron& Octahedron::operator=(const Octahedron& right) {
	if (this == &right)
		return *this;
	std::cout << "Octahedron copied" << std::endl;
	side = right.side;
	return *this;
}
bool Octahedron::operator<(const Figure& other) {
	return (double) (*this) < (double) (other);
}
bool Octahedron::operator>(const Figure& other) {
	return double(*this) > double(other);
}
bool Octahedron::operator<=(const Figure& other) {
	return double(*this) <= double(other);
}
bool Octahedron::operator>=(const Figure& other) {
	return double(*this) >= double(other);
}
Octahedron::operator double() const {
	return Square();
}

double Octahedron::Square() const {
	return 2 * side * side * (1 + sqrt(2));

}

void Octahedron::Print(std::ostream& os) const {
	os << "{Octahedron " << side << " (" << Square() << ")}";

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
