#pragma once

#include "Message.h"
#include <vector>

/**
 *
 */
class DataProvider {
	virtual Message get_data() const = 0;
	virtual bool save_data(const Message& msg) const = 0;
};

/**
 *
 */
class FileDataProvider : public DataProvider {
private:
	std::vector<char> _input_file;
	std::vector<char> _output_file;

public:
	FileDataProvider(std::vector<char> input_file, std::vector<char> output_file)
		: _input_file(input_file), _output_file(output_file)
	{};

	Message get_data() const override;
	bool save_data() const override;
};

/*
class SQLProvider : public DataProvider {
	Message get_data() const override;
	bool save_data(const Message& msg) const override;
};
*/
