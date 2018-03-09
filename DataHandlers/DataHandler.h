#pragma once

#include "../DataTypes/Message.h"

/**
@brief Интерфейс для классов предобработки текста
*/
class DataProcessing {
	/**
	@brief Виртуальная функция для предобработки текста
	@param msg Структура данных, содержащая в себе текст подлежащий предобработке
	*/
	virtual void run(const Message& msg) const = 0;
};
