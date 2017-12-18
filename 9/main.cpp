#include <iostream>
#include <future>
#include <functional>
#include <random>
#include <thread>
#include "list/TList.h"
#include "list/TList.cpp"
#include "figure/Figure.h"
#include "figure/Foursquare.h"
#include "figure/Octahedron.h"
#include "figure/Triangle.h"

int main() {
	typedef std::function<void(void)> command;
	TList<Figure> list;
	TList<command> cmd;
	std::shared_ptr<Figure> fig;

	command cmd_insert_tri = [&]() {
		std::cout << "Command: Create triangles" << std::endl;
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(1, 20);
		int side;
		for (int i = 0; i < 5; i++) {
			side = distribution(generator);
			list.Insert(0,std::make_shared<Triangle>(side, side, side));
		}
	};
	command cmd_insert_sq = [&]() {
		std::cout << "Command: Create foursquares" << std::endl;
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(1, 20);
		int side;
		for (int i = 0; i < 5; i++) {
			side = distribution(generator);
			list.Insert(0,std::make_shared<Foursquare>(side));
		}
	};
	command cmd_insert_oct = [&]() {
		std::cout << "Command: Create octahedrons" << std::endl;
		std::default_random_engine generator;
		std::uniform_int_distribution<int> distribution(1, 20);
		int side;
		for (int i = 0; i < 5; i++) {
			side = distribution(generator);
			list.Insert(0,std::make_shared<Octahedron>(side));
		}
	};

	command cmd_print = [&]() {
		std::cout << "Command: Print list" << std::endl;
		std::cout << list<<std::endl;
	};

	command cmd_delete = [&]() {
		std::cout << "Command: Delete square lower" << std::endl;
		for(int i=0;i<list.Size();++i) {
			if(list.Fetch(i)->Square()<20) {
				list.Delete(i);
				i--;
			}}
	};

	cmd.Insert(0, std::shared_ptr<command>(&cmd_insert_tri, [](command*) {})); // using custom deleter
	cmd.Insert(0, std::shared_ptr<command>(&cmd_insert_sq, [](command*) {})); // using custom deleter
	cmd.Insert(0, std::shared_ptr<command>(&cmd_print, [](command*) {})); // using custom deleter
	cmd.Insert(0, std::shared_ptr<command>(&cmd_delete, [](command*) {})); // using custom deleter
	cmd.Insert(0, std::shared_ptr<command>(&cmd_print, [](command*) {})); // using custom deleter

	while (!cmd.Empty()) {
		std::shared_ptr<command> com = cmd.Pop(cmd.Size()-1);
		std::future<void> ft = std::async(*com);
		ft.get();
	}

	return 0;
}
