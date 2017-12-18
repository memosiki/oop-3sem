#include "TListStorageItem.h"

template<class T>
TListStorageItem<T>::TListStorageItem() :
		next(nullptr) {
	value = std::shared_ptr<T>(new T);

}
template<class T>
std::shared_ptr<T> TListStorageItem<T>::GetValue() const {
	return value;
}

template<class T>
void TListStorageItem<T>::PushBack(std::shared_ptr<TListStorageItem> value) {
	if (!next) {
		next = value;
	} else {
		next->PushBack(value);
	}
}

template<class T>
std::shared_ptr<TListStorageItem<T>> TListStorageItem<T>::GetNext() const {
	return next;
}

template<class T>
void TListStorageItem<T>::SetNext(std::shared_ptr<TListStorageItem<T>> next) {
	this->next = next;
}

template<class T>
TListStorageItem<T>::~TListStorageItem() {
}
;
