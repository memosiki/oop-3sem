#ifndef TLIST_H
#define TLIST_H

#include <memory>
#include <iostream>
#include <future>
#include <mutex>
#include <functional>
#include "TListItem.h"
#include "TListItem.cpp"
#include "TIterator.h"

template<class T>
class TList {
private:
	std::shared_ptr<TListItem<T>> head;
	int size;
	std::recursive_mutex listMutex;
public:
	TList();
	bool Empty() ;
	int Size() ;
	std::shared_ptr<T> Fetch(int index);
	std::shared_ptr<T> Pop(int index);
	void Insert(int index, std::shared_ptr<T> obj);
	void Delete(const int ind);
	TIterator<TListItem<T>> begin() const;
	TIterator<TListItem<T>> end()const;

	template<class TT>
	friend std::ostream& operator <<(std::ostream& os, const TList<TT>& list);

	virtual ~TList();
};
#endif
