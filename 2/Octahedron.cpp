#include "Octahedron.h"
#include <cmath>

Octahedron::Octahedron() :
        Octahedron(0) {
}

Octahedron::Octahedron(size_t i) :
        side(i) {
    std::cout << "Octahedron created: " << side << std::endl;
}

Octahedron::Octahedron(std::istream &is) {
    is >> side;
    if (!is) {
        side = 0;
        is.clear();
        is.ignore();
    }
}


double Octahedron::Square() {
    return 2 * side * side * (1 + sqrt(2));

}

void Octahedron::Print() {
    std::cout << "a=" << side << std::endl;

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

std::ostream& operator <<(std::ostream& os, const Octahedron& octahedron) {
    os << "Octahedron: ";
    os << "a=" << octahedron.side << std::endl;
    return os;
}

std::istream& operator >>(std::istream& is, Octahedron& octahedron) {
    std::cout << "Enter sides of octahedron: ";
    is >> octahedron.side;
    if (!is) {
        octahedron.side = 0;
        is.clear();
        is.ignore();
    }
    return is;
}
Octahedron::~Octahedron() {
    std::cout << "Octahedron deleted" << std::endl;

}
