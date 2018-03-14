#include <iostream>

#include "includes\json.hpp"
#include "Cores\Core.h"
#include "DataProviders\DataProvider.h"



/**
@brief Точка входа в программу
*/
int main(void) {
	json j;
	std::string path = "C:\\tmp\\test.csv";
	auto test = tcc::KaggleDataProvider(path);
	auto data = test.get_data();
	for (auto el : data) std::cout << j << el << std::endl;

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
