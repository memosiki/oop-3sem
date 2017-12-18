#include "TList.h"

TList::TList() {
    head = nullptr;
    size = 0;
}

bool TList::Empty() {
    return size == 0;
}

int TList::Size() {
    return size;
}

Octahedron TList::Fetch(const int index) {
    if (index < 0 || index > size - 1) {
        std::cerr << "Invalid index" << std::endl;
        return head->data;
    }

    Item* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    };
    return current->data;
}

void TList::Insert(const int index, const Octahedron value) {
    //idea
    //find pair and insert element between them
    //element stands on position of second one from pair
    //exceptional situations with no pair:
    //element last or first
    if (index == size) {
        //if element is last
        //no need to shift anything
        PushBack(value);
        return;
    }
    else if (index < 0 || index > size) {
        std::cerr << "Invalid index" << std::endl;
        return;
    }
    else {
        if (index == 0) {
            //element become new head
            Item* shifted = head;
            head = new Item;
            head->next = shifted;
            head->data = value;
            size++;
            return;
        }
        /*excessive
         *
         *  if (size <= 2) {
         //there is only 2 elements
         PushBack(value);
         size++;
         return;
         }*/
        Item* current = head;
        for (int i = 1; i < index; ++i) {
            current = current->next;
        };
        Item* prev = current;
        Item* shifted = prev->next;

        current = new Item;
        prev->next = current;
        current->next = shifted;
        current->data = value;
        size++;
    }
    return;
}

void TList::PushBack(const Octahedron value) {

    Item* item = new Item;

    Item* current = head;
    //running thru all list
    for (int i = 1; i < size; ++i) {
        current = current->next;
    }
    //if list empty
    //item is new head
    if (size == 0) {
        current = item;
        head = current;
    }
    else {
        //stands after previous last element
        current->next = item;
    }
    //ext to last is head
    //for cyclic list
    item->next = head;
    item->data = value;
    size++;
    return;
}

void TList::Delete(int ind) {
    if (ind < 0 || ind > size - 1) {
        std::cerr << "Invalid index" << std::endl;
        return;
    }
    else {
        if (ind == 0) {
            Item* second = head->next;
            delete head;
            head = second;
            size--;
            return;
        }
        Item* current = head;
        for (int i = 1; i < ind; ++i) {
            current = current->next;
        }
        Item* aftercur = current->next->next;
        delete current->next;
        current->next = aftercur;
        size--;
    }
    return;
}

std::ostream& operator <<(std::ostream& os, const TList& list) {
    if (list.size == 0)
        os << "Empty" << std::endl;
    Item* current = list.head;
    for (int i = 0; i < list.size; ++i) {
        os << current->data;
        current = current->next;
    }
    return os;
}

TList::~TList() {
    for (int i = 0; i < size; ++i)
        Delete(0);
    size = 0;
}
