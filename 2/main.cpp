#include <iostream>
#include "TList.h"

int main() {
    TList* list = new TList();

    unsigned int action;

    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1) Add figure in the end" << std::endl;
        std::cout << "2) Add figure at index" << std::endl;
        std::cout << "3) Delete figure at index" << std::endl;
        std::cout << "4) Fetch figure at index" << std::endl;
        std::cout << "5) Print" << std::endl;
        std::cout << "6) Print size" << std::endl;
        std::cout << "0) Quit" << std::endl;
        std::cin >> action;

        if (action == 0) {
            break;
        }

        switch (action) {
        case 1: {
            Octahedron t;
            std::cin >> t;
            list->PushBack(t);
            break;
        }
        case 2: {
            int dIndex;
            std::cout << "Enter index: ";
            std::cin >> dIndex;
            Octahedron t;
            std::cin >> t;
            list->Insert(dIndex, t);
            break;
        }

        case 3: {
            int dIndex;
            std::cout << "Enter index: ";
            std::cin >> dIndex;
            list->Delete(dIndex);

            break;
        }

        case 4: {
            int dIndex;
            std::cout << "Enter index: ";
            std::cin >> dIndex;
            std::cout << list->Fetch(dIndex);
            break;
        }
        case 5: {
            std::cout << (*list);
            break;
        }
        case 6: {
            std::cout << list->Size() << std::endl;
            break;
        }

        default:
            std::cout << "Invalid action" << std::endl;
            break;
        }
    }

    delete list;
    return 0;
}
