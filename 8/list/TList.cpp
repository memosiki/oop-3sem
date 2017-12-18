#include "TList.h"
template<class T>
TList<T>::TList() :
		head(nullptr), size(0) {
}

template<class T>
bool TList<T>::Empty() const {
	return size == 0;
}

template<class T>
int TList<T>::Size() const {
	return size;
}
template<class T>
std::shared_ptr<T> TList<T>::operator[](size_t i) {
	return Fetch(i);
}

template<class T>
void TList<T>::Sort() {
	if (Size() > 1) {
		std::shared_ptr<T> middle = Pop(0);
		TList<T> left, right;
		while (!Empty()) {
			std::shared_ptr<T> item = Pop(0);
			if (*item > *middle) {
				left.Insert(0, item);
			} else {
				right.Insert(0, item);
			}
		}
		left.Sort();
		right.Sort();
		while (!left.Empty())
			Insert(0, left.Pop(left.Size() - 1));
		Insert(0, middle);
		while (!right.Empty())
			Insert(0, right.Pop(right.Size() - 1));
	}
}
template<class T>
void TList<T>::SortParallel() {
	if (Size() > 1) {
		std::shared_ptr<T> middle = Pop(0);
		TList<T> left, right;
		while (!Empty()) {
			std::shared_ptr<T> item = Pop(0);
			if (*item > *middle)
				left.Insert(0, item);
			else
				right.Insert(0, item);

		}
		std::future<void> left_res = left.SortThreadTask();
		std::future<void> right_res = right.SortThreadTask();
		left_res.get();
		while (!left.Empty())
			Insert(0, left.Pop(left.Size() - 1));
		Insert(0, middle);
		right_res.get();
		while (!right.Empty())
			Insert(0, right.Pop(right.Size() - 1));
	}
}
template<class T>
std::future<void> TList<T>::SortThreadTask() {
	std::future<void> res = std::async(std::launch::async,
			&TList<T>::SortParallel, this);
	return res;
}
template<class T>
std::shared_ptr<T> TList<T>::Fetch(int index) const {
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
	//idea
	//find pair and insert element between them
	//element stands on position of second one from pair
	//exceptional situations with no pair:
	//element last or first
	std::shared_ptr<TListItem<T>> item(new TListItem<T>(obj));

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
	std::shared_ptr<T> res = Fetch(index);
	if (res)
		Delete(index);
	return res;
}

template<class T>
void TList<T>::Delete(int ind) {
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
TIterator<TListItem<T>> TList<T>::begin() {
	return TIterator<TListItem<T>>(head);
}

template<class T>
TIterator<TListItem<T>> TList<T>::end() {
	return TIterator<TListItem<T>>(nullptr);
}

template<class T>
std::ostream& operator <<(std::ostream& os, const TList<T>& list) {
	if (list.size == 0)
		os << "Empty" << std::endl;
	for (int i = 0; i < list.size; ++i) {
		os << *list.Fetch(i);
	}
	return os;
}

template<class T>
TList<T>::~TList() {
	for (int i = 0; i < size; ++i)
		Delete(0);
	size = 0;
}
