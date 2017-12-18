#ifndef TLIST_H
#define TLIST_H
#include "TListItem.h"
#include <memory>


class TList {
private:
    std::shared_ptr<TListItem> head;
    int size;
public:

    TList();
    bool Empty()const;
    int Size()const;
    std::shared_ptr<Figure> Fetch(int index)const;
    void Insert(int index, std::shared_ptr<Figure>& obj);
    void Delete(int ind);

    friend std::ostream& operator <<(std::ostream& os, const TList& array);

    virtual ~TList();
};
#endif
