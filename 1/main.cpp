#include <cstdlib>
#include <iostream>
#include <cmath>
#include "Triangle.h"
#include "Octahedron.h"
#include "Foursquare.h"
int main(int argc, char** argv) {
	char num='0';
	Figure *ptr;
	while(true){
		std::cout << std::endl << "Menu: " << std::endl;
		std::cout << "1) Triangle" << std::endl; 
		std::cout << "2) Octahedron" << std::endl;
		std::cout << "3) Square" << std::endl;
		std::cout << "4) Exit" << std::endl;
		std::cin >> num;
		if(num=='4')
			break;
		switch(num){
			case '1':{
				std::cout <<"Enter sides of Triangle"<< std::endl;
				ptr = new Triangle(std::cin);
				std::cout << "Triangle: ";
				ptr->Print();
				std::cout << "Square of Triangle: ";
				std::cout << ptr->Square() << std::endl;
				delete ptr;
				break;
			}
			case '2':{
				std::cout <<"Enter side of Octahedron"<< std::endl;
				ptr = new Octahedron(std::cin);
				std::cout << "Octahedron: ";
				ptr->Print();
				std::cout << "Square of Octahedron: ";
				std::cout << ptr->Square() << std::endl;
				delete ptr;
				break;
			}
			case '3':{
				std::cout <<"Enter side of Square"<< std::endl;
				ptr = new Foursquare(std::cin);
				std::cout << "Square: ";
				ptr->Print();
				std::cout << "Square of Square: ";
				std::cout << ptr->Square() << std::endl;
				delete ptr;
				break;
			}
			default:{
				std::cout << "Unknown option" << std::endl;;
				break;
			}
		}
	
	}
	return 0;
}