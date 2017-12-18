#include "TListSimple.h"
template<class T>
TListSimple<T>::TListSimple() :
		head(nullptr), size(0) {
}

template<class T>
bool TListSimple<T>::Empty() const {
	return size == 0;
}

template<class T>
int TListSimple<T>::Size() const {
	return size;
}

template<class T>
T TListSimple<T>::Fetch(const int index) const {
	if (index < 0 || index > size - 1) {
		std::cerr << "Invalid index" << std::endl;
		return this->head;
	}
	Item* current = head;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	};
	return current->data;
}

template<class T>
void TListSimple<T>::Insert(int index, T obj) {
	//idea
	//find pair and insert element between them
	//element stands on position of second one from pair
	//exceptional situations with no pair:
	//element last or first

	if (index < 0 || index > size) {
		std::cerr << "Invalid index" << std::endl;
		return;
	}
	if (index == 0) {
		//element become new head
		Item* shifted = head;
		head = (Item*) malloc(sizeof(Item));
		head->next = shifted;
		head->data = obj;
		size++;
		return;
	}
	Item* prev = head;
	for (int i = 1; i < index; ++i) {
		prev = prev->next;
	};
	Item* shifted = prev->next;
	Item* current = new Item;
	prev->next = current;
	current->next = shifted;
	current->data = obj;
	size++;
	return;
}

template<class T>
void TListSimple<T>::Delete(int ind) {
	if (ind < 0 || ind > size - 1) {
		std::cerr << "Invalid index" << std::endl;
		return;
	}

	if (ind == 0) {
		Item* item = head->next;
		delete head;
		head = item;
		size--;
		return;
	}
	Item* current = head;
	for (int i = 1; i < ind; ++i) {
		current = current->next;
	}
	Item*aftercur = current->next->next;
	delete current->next;
	current->next = aftercur;
	size--;

	return;
}

template<class T>
std::ostream& operator <<(std::ostream& os, const TListSimple<T>& list) {
	if (list.size == 0)
		os << "Empty" << std::endl;
	for (int i = 0; i < list.size; ++i) {
		os << *list.Fetch(i);
	}
	return os;
}

template<class T>
TListSimple<T>::~TListSimple() {
	int count = this->Size();
	for (int i = 0; i < count; ++i) {
		Delete(0);
	}
	size = 0;
}
