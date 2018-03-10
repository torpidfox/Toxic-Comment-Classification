#pragma once

#include "../DataTypes/Message.h"


/**
namespace tcc
@brief Пространство имен tcc
*/
namespace tcc {
	/**
	@brief Интерфейс классов ядра для классификации "недоброжелательности" текста
	 */
	class Core {
		/**
		@brief Виртуальная функция классификации "недоброжелательности" текста
		@param msg Структура данных, содержащая в себе текст подлежащий анализу
		*/
		virtual void run(const Message& msg) const = 0;
	};

	/**
	@brief Класс - ядро для классификации "недоброжелательности" текста
	*/
	class RandomCore : public Core {
		/**
		@brief Функция классификации "недоброжелательности" текста
		@param msg Структура данных, содержащая в себе текст подлежащий анализу
		*/
		void run(const Message& msg) const override;
	};
}
