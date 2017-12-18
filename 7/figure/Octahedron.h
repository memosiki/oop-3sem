#ifndef OCTAHEDRON_H
#define OCTAHEDRON_H

#include <iostream>
#include "Figure.h"

class Octahedron: public Figure {
public:
    Octahedron();
    Octahedron(size_t i);
    Octahedron(std::istream &is);
    Octahedron(const Octahedron& orig);

    double Square() const override;
    void Print(std::ostream& os) const override;
    char getType() const override;
    Octahedron& operator=(const Octahedron& right);
    bool operator==(const Octahedron& right);

    friend std::ostream& operator <<(std::ostream& os,
            const Octahedron& Octahedron);
    friend std::istream& operator >>(std::istream& is, Octahedron& Octahedron);

    ~Octahedron();

private:
    size_t side;
};

#endif
