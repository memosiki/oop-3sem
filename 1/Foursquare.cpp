#include <cstdlib>
#include <iostream>
#include "Foursquare.h"


Foursquare::Foursquare() : Foursquare(0) {
}

Foursquare::Foursquare(size_t i) : side(i) {
    std::cout << "Foursquare created: " << side << std::endl;
}

Foursquare::Foursquare(std::istream &is) {
    is >> side;
    if (!is){
        side=0;
        is.clear();
        is.ignore();
    }
}

Foursquare::Foursquare(const Foursquare& orig) {
    std::cout << "Foursquare copy created" << std::endl;
    side = orig.side;
}

double Foursquare::Square() {
    return side*side;

}

void Foursquare::Print() {
    std::cout << "a=" << side  << std::endl;

}

Foursquare::~Foursquare() {
    std::cout << "Foursquare deleted" << std::endl;
}
