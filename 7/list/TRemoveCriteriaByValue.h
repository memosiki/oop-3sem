#ifndef LISTS_TREMOVECRITERIABYVALUE_H_
#define LISTS_TREMOVECRITERIABYVALUE_H_

#include "TRemoveCriteria.h"

template<class T>
class TRemoveCriteriaByValue: public TRemoveCriteria<T> {
public:
	TRemoveCriteriaByValue(double value) :
			_value(value) {
	}
	;
	bool isIt(std::shared_ptr<T>& obj) override {
		return _value > obj->Square();
	}
private:
	double _value;
};
#endif /* LISTS_TREMOVECRITERIABYVALUE_H_ */
