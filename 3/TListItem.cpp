#include "TListItem.h"
#include <memory>
TListItem::TListItem() {
    this->figure = nullptr;
}
TListItem::TListItem(const std::shared_ptr<Figure> &figure) {
    this->figure = figure;
}


void TListItem::SetNext(const std::shared_ptr<TListItem>& obj) {
    this->next = obj;
    return;
}

std::shared_ptr<Figure> TListItem::GetValue() {
    return this->figure;
}

std::shared_ptr<TListItem> TListItem::GetNext() {
    return this->next;
}

std::ostream& operator <<(std::ostream& os, TListItem& item) {
    if(item.GetValue()!=nullptr)
        os<<*(item.GetValue());
    return os;
}
TListItem::~TListItem(){}
