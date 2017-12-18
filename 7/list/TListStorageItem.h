#ifndef TLISTSTORAGEITEM_H_
#define TLISTSTORAGEITEM_H_
#include <memory>

template<class T>
class TListStorageItem {
private:
	std::shared_ptr<TListStorageItem<T>> next;
	std::shared_ptr<T> value;
public:
	TListStorageItem();
	std::shared_ptr<T> GetValue() const;
	std::shared_ptr<TListStorageItem<T>> GetNext() const;
	void SetNext(std::shared_ptr<TListStorageItem<T>> next);
	void PushBack(std::shared_ptr<TListStorageItem<T>> next);
	virtual ~TListStorageItem();
};

#endif /* TLISTSTORAGEITEM_H_ */
