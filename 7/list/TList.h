#ifndef TLIST_H
#define TLIST_H

#include <memory>
#include <iostream>

#include "TListItem.h"
#include "TListItem.cpp"
#include "TIterator.h"

template<class T>
class TList {
private:
	std::shared_ptr<TListItem<T>> head;
	int size;
public:
	TList();
	bool Empty() const;
	int Size() const;
	std::shared_ptr<T> Fetch(int index) const;
	void Insert(int index, std::shared_ptr<T>& obj);
	void Delete(const int ind);

	TIterator<TListItem<T>> begin();
	TIterator<TListItem<T>> end();

	template<class TT>
	friend std::ostream& operator <<(std::ostream& os,
			const TList<TT>& list);

	virtual ~TList();
};
#endif
