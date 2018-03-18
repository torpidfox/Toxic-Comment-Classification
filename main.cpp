#include <iostream>


#include "Cores\Core.h"
#include "DataProviders\DataProvider.h"
#include "includes\json.hpp"
#include "DataConsumers\StreamDataWriter.h"



/**
@brief Точка входа в программу
*/
int main(int argc, char* argv[]) {
	tcc::StreamDataWriter buf = tcc::StreamDataWriter("data\\test_wr.csv");
	json j;
	std::string path = "data\\test.csv";
	auto test = tcc::KaggleDataProvider(path);
	auto data = test.get_data();
	buf << data;
	std::cout << static_cast<int> (buf.state());

	j["title"] = "First text";
	j["text"] = "It is my text. Read it!";

	tcc::RandomCore *cor = new tcc::RandomCore(100);
	cor->run(j);
	delete cor;

	std::cout << "Input any for exit..." << std::endl;
	char c;
	std::cin >> c;
	return 0;
}
