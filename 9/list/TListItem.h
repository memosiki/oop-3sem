#ifndef TLISTITEM_H_
#define TLISTITEM_H_

#include <memory>
#include <iostream>
#include <mutex>

template<class T> class TList;
template<class T>
class TListItem {
private:
	std::shared_ptr<TListItem> next;
	std::shared_ptr<T> value;
	std::recursive_mutex *listMutex;
	void SetNext(const std::shared_ptr<TListItem> obj);
public:
	friend class TList<T> ;
	TListItem(std::shared_ptr<T> item, std::recursive_mutex *parent);
	std::shared_ptr<TListItem> GetNext() const;
	std::shared_ptr<T> GetValue() const;

	template<class TT>
	friend std::ostream& operator <<(std::ostream& os, TListItem<TT>& obj);

	virtual ~TListItem();
};

#endif /* TLISTITEM_H_ */
