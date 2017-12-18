#include <iostream>
#include "list/TList.h"
#include "list/TList.cpp"
#include "figure/Figure.h"
#include "figure/Foursquare.h"
#include "figure/Octahedron.h"
#include "figure/Triangle.h"
void menu() {
	std::cout << "Menu:" << std::endl;
	std::cout << "1) Add figure at index" << std::endl;
	std::cout << "2) Delete figure at index" << std::endl;
	std::cout << "3) Fetch figure at index" << std::endl;
	std::cout << "4) Print" << std::endl;
	std::cout << "5) Print size" << std::endl;
	std::cout << "0) Quit" << std::endl;
}
int main() {
	TList<Figure> list;
	std::shared_ptr<Figure> fig;
	int action;
	while (true) {
		menu();
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

			int dIndex;
			std::cout << "Enter index: ";
			std::cin >> dIndex;
			switch (figure_type) {
			case 't': {
				std::cout << "Enter sides of triangle" << std::endl;
				fig = std::make_shared<Triangle>(std::cin);
				list.Insert(dIndex, fig);
				break;
			}
			case 's': {

				std::cout << "Enter side of square" << std::endl;
				fig = std::make_shared<Foursquare>(std::cin);
				list.Insert(dIndex, fig);
				break;
			}
			case 'o': {
				std::cout << "Enter side of octahedron" << std::endl;
				fig = std::make_shared<Octahedron>(std::cin);
				list.Insert(dIndex, fig);
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
			int dIndex;
			std::cout << "Enter index: ";
			std::cin >> dIndex;
			list.Delete(dIndex);

			break;
		}

		case 3: {
			int dIndex;
			std::cout << "Enter index: ";
			std::cin >> dIndex;
			std::cout<<*(list.Fetch(dIndex));
			break;
		}
		case 4: {
			for (auto i : list)
				std::cout << *i << std::endl;
			break;
		}
		case 5: {
			std::cout << list.Size() << std::endl;
			break;
		}

		default:
			std::cout << "Invalid action" << std::endl;
			break;
		}
	}

	return 0;
}
