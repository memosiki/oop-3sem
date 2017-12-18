#include "TListStorage.h"
template<class T>
TListStorage<T>::TListStorage() :
		head(nullptr) {
}
template<class T>
void TListStorage<T>::RemoveSubitem(TRemoveCriteria<T>* criteria) {
	std::shared_ptr<TList<T>> list = nullptr;
	for (auto item : *this) {
		list = item->GetValue();
		for (int i = 0; i < list->Size(); ++i) {
			std::shared_ptr<T> value = list->Fetch(i);
			if (criteria->isIt(value)) {
				list->Delete(i);
				i--;
			}
		}
	}
	Optimize();
}
template<class T>
void TListStorage<T>::Optimize() {
	if (!head)
		//empty
		return;
	std::shared_ptr<TListStorageItem<TList<T>>> curr(head);
	std::shared_ptr<TListStorageItem<TList<T>>> next(head->GetNext());

	std::shared_ptr<TList<T>> list1 = curr->GetValue();
	std::shared_ptr<TList<T>> list2(nullptr);
	std::shared_ptr<T> fig;

	while (next) {
		list2 = next->GetValue();
		if (list2->Size() > 0)
			if (list1->Size() < maxAtWrapper) {
				fig = list2->Fetch(0);
				list1->Insert(list1->Size(), fig);
				list2->Delete(0);
			} else {
				curr = curr->GetNext();
				list1 = curr->GetValue();
				if (curr == next)
					next=next->GetNext();
			}
		else
			next = next->GetNext();
	}
	int emptyCount = 0;
	for (auto item : *this)
		if (item->GetValue()->Size() == 0)
			emptyCount++;

	for (int i = 0; i < emptyCount; ++i)
		RemoveWrapper();
}

template<class T>
void TListStorage<T>::Insert(std::shared_ptr<T> obj) {

	std::shared_ptr<T> popped = nullptr;
	std::shared_ptr<TList<T>> list = nullptr;
	popped = obj;
	double square = obj->Square();
	bool inserted = false;
	for (auto item : *this) {
		list = item->GetValue();
		if (!inserted) {
			int i = 0;
			for (auto elem : *(list))
				if (elem->GetValue()->Square() >= square) {
					if (list->Size() == maxAtWrapper) {
						popped = list->Fetch(maxAtWrapper - 1);
						list->Delete(maxAtWrapper - 1);
					} else
						popped = nullptr;

					list->Insert(i, obj);
					inserted = true;
					break;
				} else
					i++;
			if (i < maxAtWrapper && !inserted){
				list->Insert(list->Size(), obj);
				popped = nullptr;}
		} else {
			if (list->Size() == maxAtWrapper) {
				list->Insert(0, popped);
				popped = list->Fetch(maxAtWrapper);
				list->Delete(maxAtWrapper);
			} else {
				list->Insert(0, popped);
				popped = nullptr;
			}
		}
	}
	if (popped != nullptr) {
		PushBackWrapper(
				std::shared_ptr<TListStorageItem<TList<T>>>(
						new TListStorageItem<TList<T>>));

		for (auto item : *this) {

			list = item->GetValue();
			if (list->Size() < maxAtWrapper)
				list->Insert(list->Size(), popped);
		}

	}

}

template<class T>
TIterator<TListStorageItem<TList<T>>> TListStorage<T>::begin() const {
	return TIterator<TListStorageItem<TList<T>>>(this->head);
}

template<class T>
TIterator<TListStorageItem<TList<T>>> TListStorage<T>::end() const {
	return TIterator<TListStorageItem<TList<T>>>(nullptr);
}

template<class T>
void TListStorage<T>::PushBackWrapper(
		std::shared_ptr<TListStorageItem<TList<T>>>&& value) {
	if (!head)
		head = value;
	else {
		head->PushBack(value);
	}
}
template<class T>
void TListStorage<T>::RemoveWrapper() {
	if (!head)
		//empty
		return;
	std::shared_ptr<TListStorageItem<TList<T>>> item = head;
	std::shared_ptr<TListStorageItem<TList<T>>> prev = nullptr;

	while (item->GetNext()) {
		prev = item;
		item = item->GetNext();
	}
	if (!prev)
		head = nullptr;
	else
		prev->SetNext(nullptr);
}
template<class T>
std::ostream& operator <<(std::ostream& os, const TListStorage<T>& storage) {
	std::shared_ptr<TList<T>> list;
	if (!storage.head)
		os << "Empty" << std::endl;
	for (auto item : storage) {
		list = item->GetValue();
		os << '[' << *list << ']' << std::endl;
	}
	return os;
}
template<class T>
TListStorage<T>::~TListStorage() {
	std::cout << "#Storage deleted" << std::endl;
}
