#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
class Figure {
public:
	virtual double Square() const = 0;
	virtual void Print(std::ostream& os) const = 0;
	friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
		fig.Print(os);
		return os;
	}

	virtual bool operator<(const Figure& other)= 0;
	virtual bool operator>(const Figure& other)= 0;
	virtual bool operator<=(const Figure& other)= 0;
	virtual bool operator>=(const Figure& other)= 0;
	Figure& operator=(const Figure& right){return *this;};
	virtual operator double() const= 0;
	virtual ~Figure() {
	}
	;
};

#endif

