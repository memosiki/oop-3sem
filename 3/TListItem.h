#ifndef TLISTITEM_H_
#define TLISTITEM_H_

#include <memory>

#include "Figure.h"

class TListItem {
private:
    std::shared_ptr<TListItem> next;
    std::shared_ptr<Figure> figure;
public:

    TListItem();
    TListItem(const std::shared_ptr<Figure> &);
    std::shared_ptr<Figure> GetValue();
    std::shared_ptr<TListItem> GetNext();
    void SetNext(const std::shared_ptr<TListItem>& obj);
    friend std::ostream& operator <<(std::ostream& os, TListItem& obj);

    virtual ~TListItem();
};

#endif /* TLISTITEM_H_ */
