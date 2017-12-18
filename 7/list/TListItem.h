#ifndef TLISTITEM_H_
#define TLISTITEM_H_

#include "TAllocationBlock.h"

#include <memory>
#include <iostream>

template<class T> class TList;
template<class T>
class TListItem {
private:
	std::shared_ptr<TListItem> next;
	std::shared_ptr<T> value;
	static TAllocationBlock allocator;

	void SetNext(const std::shared_ptr<TListItem> obj);
public:
	friend class TList<T> ;
	TListItem();
	TListItem(std::shared_ptr<T>);
	std::shared_ptr<TListItem> GetNext() const;
	std::shared_ptr<T> GetValue() const;

	void * operator new(size_t size);
	void operator delete(void *p);

	template<class TT>
	friend std::ostream& operator <<(std::ostream& os, TListItem<TT>& obj);

	virtual ~TListItem();
};

#endif /* TLISTITEM_H_ */
