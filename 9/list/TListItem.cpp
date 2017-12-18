#include "TListItem.h"

template<class T>
TListItem<T>::TListItem(const std::shared_ptr<T> fig,
		std::recursive_mutex *parent) {
	value = fig;
	next = nullptr;
	listMutex = parent;
}

template<class T>
void TListItem<T>::SetNext(const std::shared_ptr<TListItem<T>> fig) {
	std::unique_lock < std::recursive_mutex > lock(*listMutex);
	next = fig;
	return;
}
template<class T>
std::shared_ptr<TListItem<T>> TListItem<T>::GetNext() const {
	std::lock_guard < std::recursive_mutex > lock(*listMutex);
	return next;
}
template<class T>
std::shared_ptr<T> TListItem<T>::GetValue() const {
	std::unique_lock < std::recursive_mutex > lock(*listMutex);
	return value;
}
template<class T>
std::ostream& operator <<(std::ostream& os, TListItem<T>& item) {
	std::lock_guard < std::recursive_mutex > lock(*item.listMutex);
	if (item.value)
		os << *(item.value);
	return os;
}
template<class T>
TListItem<T>::~TListItem() {
}
