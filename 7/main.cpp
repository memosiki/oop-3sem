#include <iostream>

#include "list/TListStorage.h"
#include "list/TListStorage.cpp"
#include "list/TRemoveCriteriaAll.h"
#include "list/TRemoveCriteriaByValue.h"
#include "list/TRemoveCriteriaByType.h"
#include "figure/Figure.h"
#include "figure/Foursquare.h"
#include "figure/Octahedron.h"
#include "figure/Triangle.h"

int main(int argc, char** argv) {
	TListStorage<Figure> list;
	unsigned int action;
	while (true) {
		std::cout<<"===================================="<<std::endl;
		std::cout << "Menu:" << std::endl;
		std::cout << "1) Add figure" << std::endl;
		std::cout << "2) Delete figures with square lower" << std::endl;
		std::cout << "3) Delete figures with type" << std::endl;
		std::cout << "4) Delete all figures" << std::endl;
		std::cout << "5) Print" << std::endl;
		std::cout << "0) Quit" << std::endl;
		std::cin >> action;
		if (action == 0) {
			break;
		}
		switch (action) {
		case 1: {
			char figure_type;
			std::cout
					<< "Enter figure type: t - triangle, s - foursquare, o - octahedron: ";
			std::cin >> figure_type;
			switch (figure_type) {
			case 't': {
				std::cout << "Enter sides of triangle" << std::endl;
				list.Insert(std::shared_ptr<Triangle>(new Triangle(std::cin)));
				break;
			}
			case 's': {
				std::cout << "Enter side of square" << std::endl;
				list.Insert(
						std::shared_ptr<Foursquare>(new Foursquare(std::cin)));
				break;
			}
			case 'o': {
				std::cout << "Enter side of octahedron" << std::endl;
				list.Insert(
						std::shared_ptr<Octahedron>(new Octahedron(std::cin)));
				break;
			}
			default: {
				std::cout << "Try more..." << std::endl;
				break;
			}
			}

			break;
		}
		case 2: {
			int square;
			std::cout << "Enter square: ";
			std::cin >> square;
			TRemoveCriteriaByValue<Figure> criteria(square);
			list.RemoveSubitem(&criteria);
			break;
		}
		case 3: {
			char figure_type;
			std::cout
					<< "Enter figure type: t - triangle, s - foursquare, o - octahedron: ";

			std::cin >> figure_type;
			TRemoveCriteriaByType<Figure> criteria(figure_type);
			list.RemoveSubitem(&criteria);
			break;
		}
		case 4: {
			TRemoveCriteriaAll<Figure> criteria;
			list.RemoveSubitem(&criteria);
			break;
		}
		case 5: {
			std::cout << list << std::endl;
			break;
		}

		default:
			std::cout << "Invalid action" << std::endl;
			break;
		}
	}

	return 0;
}
