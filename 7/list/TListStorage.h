#ifndef TLISTSTORAGE_H_
#define TLISTSTORAGE_H_

#include "TListStorageItem.h"
#include "TListStorageItem.cpp"
#include "TIterator.h"
#include "TList.h"
#include "TList.cpp"
#include "TRemoveCriteria.h"
#include <memory>

template<class T>
class TListStorage {
private:
	std::shared_ptr<TListStorageItem<TList<T>>> head;
	const int maxAtWrapper = 5;
public:

	TListStorage();
	//std::shared_ptr<TListItem<T1, T2, T3>> Fetch(const int index) const;
	void Insert(std::shared_ptr<T> obj);
	void RemoveSubitem(TRemoveCriteria<T>* criteria);
	void Optimize();
	void PushBackWrapper(std::shared_ptr<TListStorageItem<TList<T>>>&& value);
	void RemoveWrapper();
	size_t Size();

	TIterator<TListStorageItem<TList<T>>> begin() const;
	TIterator<TListStorageItem<TList<T>>> end() const;

	template<class TT>
	friend std::ostream& operator <<(std::ostream& os,
			const TListStorage<TT>& list);
	virtual ~TListStorage();
};
#endif /* TLISTSTORAGE_H_ */
