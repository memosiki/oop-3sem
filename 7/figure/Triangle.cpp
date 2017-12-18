#include <cstdlib>
#include <cmath>
#include <iostream>
#include "Triangle.h"

Triangle::Triangle() :
		Triangle(0, 0, 0) {
}

Triangle::Triangle(size_t i, size_t j, size_t k) :
		side_a(i), side_b(j), side_c(k) {
}

Triangle::Triangle(std::istream &is) {
	is >> side_a;
	if (!is) {
		side_a = 0;
		is.clear();
		is.ignore();
	}
	is >> side_b;

	if (!is) {
		side_b = 0;
		is.clear();
		is.ignore();
	}
	is >> side_c;

	if (!is) {
		side_c = 0;
		is.clear();
		is.ignore();
	}
}

Triangle::Triangle(const Triangle& orig) {
	side_a = orig.side_a;
	side_b = orig.side_b;
	side_c = orig.side_c;
}

double Triangle::Square() const {
	double p = double(side_a + side_b + side_c) / 2.0;
	return sqrt(
			p * (p - double(side_a)) * (p - double(side_b))
					* (p - double(side_c)));

}

void Triangle::Print(std::ostream& os) const {
	os << "{Triangle ";
	os << side_a << "," << side_b << "," << side_c << " (" << Square() << ")}";
}
std::ostream& operator <<(std::ostream& os, const Triangle& triangle) {
	triangle.Print(os);
	return os;
}
char Triangle::getType() const {
	return 't';
}
Triangle::~Triangle() {
}
