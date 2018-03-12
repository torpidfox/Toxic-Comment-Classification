#include <iostream>

#include "includes\json.hpp"
#include "Cores\Core.h"


using json = nlohmann::json;

/**
@brief Точка входа в программу
*/
int main(void) {
	json j;

	j["title"] = "First text";
	j["text"] = "It is my text. Read it!";

	tcc::RandomCore *cor = new tcc::RandomCore(100);
	cor->run(j);
	delete cor;

	std::cout << "JSON format:" << std::endl;
	std::cout << j << std::endl << std::endl;

	std::cout << "Version C++:" << __cplusplus << std::endl;
	std::cout << "Input any for exit..." << std::endl;

	char c;
	std::cin >> c;
	return 0;
}
