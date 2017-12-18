#ifndef TLIST_H
#define TLIST_H
#include "Octahedron.h"

struct Item {
    Octahedron data;
    Item* next;
};

class TList {
private:
    Item *head;
    int size;
public:

    TList();
    bool Empty();
    int Size();
    Octahedron Fetch(const int index);
    void Insert(const int index, const Octahedron value);
    void PushBack(const Octahedron value);
    void Delete(int ind);

    friend std::ostream& operator <<(std::ostream& os, const TList& array);

    virtual ~TList();
};
#endif
