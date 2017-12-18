#include "TListItem.h"

template<class T>
TListItem<T>::TListItem() {
	value = nullptr;
	next = nullptr;

}
template<class T>
TListItem<T>::TListItem(const std::shared_ptr<T> fig) {
	value = fig;
	next = nullptr;
}

template<class T>
void TListItem<T>::SetNext(const std::shared_ptr<TListItem<T>> fig) {
	next = fig;
	return;
}
template<class T>
std::shared_ptr<TListItem<T>> TListItem<T>::GetNext() const {
	return next;
}
template<class T>
std::shared_ptr<T> TListItem<T>::GetValue() const {
	return value;
}
template<class T>
std::ostream& operator <<(std::ostream& os, TListItem<T>& item) {
	if (item.value)
		os << *(item.value);
	return os;
}
template<class T>
TListItem<T>::~TListItem() {
}
