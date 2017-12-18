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
	};
	virtual ~Figure() {};
};

#endif

