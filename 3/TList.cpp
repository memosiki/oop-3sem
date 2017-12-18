#include "TList.h"
#include "TListItem.h"
#include <memory>
#include <iostream>
TList::TList() :
        head(nullptr), size(0) {
}

bool TList::Empty() const {
    return size == 0;
}

int TList::Size() const {
    return size;
}

std::shared_ptr<Figure> TList::Fetch(int index) const {
    if (index < 0 || index > size - 1) {
        std::cerr << "Invalid index" << std::endl;
        return nullptr;
    }
    std::shared_ptr<TListItem> current(head);
    for (int i = 0; i < index; ++i) {
        current = current->GetNext();
    };
    return current->GetValue();
}

void TList::Insert(int index, std::shared_ptr<Figure> &obj) {
    //idea
    //find pair and insert element between them
    //element stands on position of second one from pair
    //exceptional situations with no pair:
    //element last or first
    std::shared_ptr<TListItem> item(new TListItem(obj));

    if (index < 0 || index > size) {
        std::cerr << "Invalid index" << std::endl;
        return;
    } else if (index == 0) {
        item->SetNext(head);
        this->head = item;
    } else {
        std::shared_ptr<TListItem> prev(head);
        for (int i = 0; i < index - 1; ++i)
            prev = prev->GetNext();

        std::shared_ptr<TListItem> shifted(prev->GetNext());
        prev->SetNext(item);
        item->SetNext(shifted);
    }
    size++;
}


void TList::Delete(int ind) {
    if (ind < 0 || ind > size - 1) {
        std::cerr << "Invalid index" << std::endl;
        return;
    } else if (ind == 0) {
        head = head->GetNext();
    } else {
        std::shared_ptr<TListItem> current = head;
        for (int i = 0; i < ind - 1; ++i)
            current = current->GetNext();
        std::shared_ptr<TListItem> aftercur = current->GetNext()->GetNext();
        current->SetNext(aftercur);
    }
    size--;
    return;
}

std::ostream& operator <<(std::ostream& os, const TList& list) {
    if (list.size == 0)
        os << "Empty" << std::endl;
    for (int i = 0; i < list.Size(); ++i) {
        os << *(list.Fetch(i));
    }
    return os;
}

TList::~TList() {
    for (int i = 0; i < size; ++i)
        Delete(0);
    size = 0;
}
