#ifndef TLISTA_H
#define TLISTA_H
#include <memory>
#include <iostream>

template<class T>
class TLista {

public:
	struct Item {
		T data;
		Item* next;
	};
	TLista();
	bool Empty() const;
	int Size() const;
	T Fetch(const int index) const;
	void Insert(int index, T obj);
	void Delete(const int ind);


	template<class T2>
	friend std::ostream& operator <<(std::ostream& os, const TLista<T2>& array);

	virtual ~TLista();
private:
	Item* head;
	int size;
};

#endif //TLISTA_H
