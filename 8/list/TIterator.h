#ifndef TITERATOR_H_
#define TITERATOR_H_

#include <memory>
#include <iostream>
template<class T>
class TIterator {
public:
	TIterator(std::shared_ptr<T> n) {
		node_ptr = n;
	}

	std::shared_ptr<T> operator *() {
		return node_ptr;
	}

	std::shared_ptr<T> operator ->() {
		return node_ptr;
	}

	void operator ++() {
		node_ptr = node_ptr->GetNext();
	}

	TIterator operator ++(int) {
		TIterator iter(*this);
		++(*this);
		return iter;
	}

	bool operator ==(TIterator const& i) {
		return node_ptr == i.node_ptr;
	}

	bool operator !=(TIterator const& i) {
		return !(*this == i);
	}

private:
	std::shared_ptr<T> node_ptr;
};

#endif /* TITERATOR_H_ */
