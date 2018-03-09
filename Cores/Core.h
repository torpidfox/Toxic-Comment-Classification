#pragma once

#include "../DataTypes/Message.h"

/**
@brief Интерфейс классов ядра для определения "недоброжелательности" текста
 */
class Core {
	/**
	@brief Виртуальная функция для определения "недоброжелательности" текста
	@param msg Структура данных, содержащая в себе текст подлежащий анализу
	*/
	virtual void run(const Message& msg) const = 0;
};