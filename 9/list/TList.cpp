#include "TList.h"
template<class T>
TList<T>::TList() :
		head(nullptr), size(0) {
}

template<class T>
bool TList<T>::Empty() {
	std::lock_guard<std::recursive_mutex> lock(listMutex);
	return size == 0;
}

template<class T>
int TList<T>::Size() {
	std::lock_guard<std::recursive_mutex> lock(listMutex);
	return size;
}

template<class T>
std::shared_ptr<T> TList<T>::Fetch(int index){
	std::lock_guard<std::recursive_mutex> lock(listMutex);
	if (index < 0 || index > size - 1) {
		std::cerr << "Invalid index" << std::endl;
		return nullptr;
	}
	std::shared_ptr<TListItem<T>> current(head);
	for (int i = 0; i < index; ++i) {
		current = current->GetNext();
	};
	return current->GetValue();
}

template<class T>
void TList<T>::Insert(int index, std::shared_ptr<T> obj) {
	std::lock_guard<std::recursive_mutex> lock(listMutex);

	std::shared_ptr<TListItem<T>> item(new TListItem<T>(obj,&listMutex));

	if (index < 0 || index > size) {
		std::cerr << "Invalid index" << std::endl;
		return;
	} else if (index == 0) {
		item->SetNext(head);
		this->head = item;
	} else {
		std::shared_ptr<TListItem<T>> prev(head);
		for (int i = 0; i < index - 1; ++i)
			prev = prev->GetNext();

		std::shared_ptr<TListItem<T>> shifted(prev->GetNext());
		prev->SetNext(item);
		item->SetNext(shifted);
	}
	size++;
	return;
}

template<class T>
std::shared_ptr<T> TList<T>::Pop(int index) {
	std::lock_guard<std::recursive_mutex> lock(listMutex);
	std::shared_ptr<T> res = Fetch(index);
	if (res)
		Delete(index);
	return res;
}

template<class T>
void TList<T>::Delete(int ind) {
	std::lock_guard<std::recursive_mutex> lock(listMutex);
	if (ind < 0 || ind > size - 1) {
		std::cerr << "Invalid index" << std::endl;
		return;
	} else if (ind == 0) {
		head = head->GetNext();
	} else {
		std::shared_ptr<TListItem<T>> current = head;
		for (int i = 0; i < ind - 1; ++i)
			current = current->GetNext();
		std::shared_ptr<TListItem<T>> aftercur = current->GetNext()->GetNext();
		current->SetNext(aftercur);
	}
	size--;
	return;
}
template<class T>
TIterator<TListItem<T>> TList<T>::begin() const{
	return TIterator<TListItem<T>>(head);
}

template<class T>
TIterator<TListItem<T>> TList<T>::end() const{
	return TIterator<TListItem<T>>(nullptr);
}

template<class T>
std::ostream& operator <<(std::ostream& os, const TList<T>& list) {
	if (list.size == 0)
		os << "Empty";
	for (auto i : list) {
		os << *i << std::endl;
	}
	return os;
}

template<class T>
TList<T>::~TList() {
	for (int i = 0; i < size; ++i)
		Delete(0);
	size = 0;
}
