#ifndef TLISTA_H
#define TLISTA_H
#include <memory>
#include <iostream>

template<class T>
class TListSimple {

public:
	struct Item {
		T data;
		Item* next;
	};
	TListSimple();
	bool Empty() const;
	int Size() const;
	T Fetch(const int index) const;
	void Insert(int index, T obj);
	void Delete(const int ind);


	template<class T2>
	friend std::ostream& operator <<(std::ostream& os, const TListSimple<T2>& array);

	virtual ~TListSimple();
private:
	Item* head;
	int size;
};

#endif //TLISTA_H
