#ifndef OCTAHEDRON_H
#define	OCTAHEDRON_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"

class Octahedron : public Figure{
public:
    Octahedron();
    Octahedron(std::istream &is);
    Octahedron(size_t i);
    Octahedron(const Octahedron& orig);

    double Square() override;
    void   Print() override;

    virtual ~Octahedron();
private:
    size_t side;
};

#endif	/* OCTAHEDRON_H */