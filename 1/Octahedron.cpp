#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Octahedron.h"


Octahedron::Octahedron() : Octahedron(0) {
}

Octahedron::Octahedron(size_t i) : side(i) {
    std::cout << "Octahedron created: " << side << std::endl;
}

Octahedron::Octahedron(std::istream &is) {
    is >> side;
     if (!is){
        side=0;
        is.clear();
        is.ignore();
    }
}

Octahedron::Octahedron(const Octahedron& orig) {
    std::cout << "Octahedron copy created" << std::endl;
    side = orig.side;
}

double Octahedron::Square() {
    return 2*side*side*(1+sqrt(2));

}

void Octahedron::Print() {
    std::cout << "a=" << side  << std::endl;

}

Octahedron::~Octahedron() {
    std::cout << "Octahedron deleted" << std::endl;
}
