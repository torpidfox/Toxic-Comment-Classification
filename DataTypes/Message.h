#pragma once

#include <vector>


/**
 Пример структуры данных. Лучше конечно использовать json.
 Либо сделать через интерфейсы эту структуру данных
 и тогда можно будет легко подключать различные структуры.  
 */
class Message {
private:
	std::vector<char> _lable;
	std::vector<char> _message;

	float _first_class;
	float _second_class;

public:
	Message(std::vector<char> lable, std::vector<char> message,
		float first_class = 0, float second_class = 0)
		: _lable(lable), _message(message), _first_class(first_class), _second_class(second_class)
	{};

	std::vector<char> get_lable();
	std::vector<char> get_massage();
	void get_massage(std::vector<char> message);
	float get_first_class();
	void set_first_class(float first_class);
	float get_second_class();
	void get_second_class(float second_class);
};