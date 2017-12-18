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
std::shared_ptr<T> TList<T>::Fetch(int index)const {
	if (index < 0 || index > size - 1) {
		std::cerr << "Invalid index" << std::endl;
		return head->GetValue();
	}
	std::shared_ptr<TListItem<T>> current(head);
	for (int i = 0; i < index; ++i) {
		current = current->GetNext();
	};
	return current->GetValue();
}

template<class T>
void TList<T>::Insert(int index, std::shared_ptr<T>& obj) {
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
//
//template<class T>
//void TList<T>::Insert(int index, std::shared_ptr<T2> &&obj) {
//	//idea
//	//find pair and insert element between them
//	//element stands on position of second one from pair
//	//exceptional situations with no pair:
//	//element last or first
//
//	if (index < 0 || index > size) {
//		std::cerr << "Invalid index" << std::endl;
//		return;
//	}
//	if (size == 0) {
//
//		std::shared_ptr<TListItem<T>> item(new TListItem<T>(obj));
//		head = item;
//		head->SetNext(nullptr);
//		size = 1;
//		return;
//	}
//	if (index == 0) {
//		//element become new head
//		std::shared_ptr<TListItem<T>> item(new TListItem<T>(obj));
//
//		item->SetNext(head);
//		this->head = item;
//		size++;
//		return;
//	}
//	std::shared_ptr<TListItem<T>> prev(head);
//	for (int i = 1; i < index; ++i) {
//		prev = prev->GetNext();
//	};
//	std::shared_ptr<TListItem<T>> shifted(prev->GetNext());
//
//	std::shared_ptr<TListItem<T>> current(new TListItem<T>(obj));
//	prev->SetNext(current);
//	current->SetNext(shifted);
//	size++;
//
//	return;
//}
//
//template<class T>
//void TList<T>::Insert(int index, std::shared_ptr<T3> &&obj) {
//	//idea
//	//find pair and insert element between them
//	//element stands on position of second one from pair
//	//exceptional situations with no pair:
//	//element last or first
//
//	if (index < 0 || index > size) {
//		std::cerr << "Invalid index" << std::endl;
//		return;
//	}
//	if (size == 0) {
//
//		std::shared_ptr<TListItem<T>> item(new TListItem<T>(obj));
//		head = item;
//		head->SetNext(nullptr);
//		size = 1;
//		return;
//	}
//	if (index == 0) {
//		//element become new head
//		std::shared_ptr<TListItem<T>> item(new TListItem<T>(obj));
//
//		item->SetNext(head);
//		this->head = item;
//		size++;
//		return;
//	}
//	std::shared_ptr<TListItem<T>> prev(head);
//	for (int i = 1; i < index; ++i) {
//		prev = prev->GetNext();
//	};
//	std::shared_ptr<TListItem<T>> shifted(prev->GetNext());
//
//	std::shared_ptr<TListItem<T>> current(new TListItem<T>(obj));
//	prev->SetNext(current);
//	current->SetNext(shifted);
//	size++;
//
//	return;
//}
//

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
