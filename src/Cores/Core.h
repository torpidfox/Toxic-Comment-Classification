#pragma once

#include "../includes/json.hpp"


using json = nlohmann::json;

/**
namespace tcc
@brief Пространство имен tcc
*/
namespace tcc {
	/**
	@brief Интерфейс классов ядра для классификации "недоброжелательности" текста
	 */
	class Core {
	public:
		/**
		@brief Виртуальная функция классификации "недоброжелательности" текста
		@param msg Структура данных, содержащая в себе текст подлежащий анализу
		*/
		virtual void run(json& msg) const = 0;
	};

	/**
	@brief Класс - ядро для классификации "недоброжелательности" текста
	*/
	class RandomCore : public Core {
	private:
		double MAX_PERCENT;
	public:
		/**
		@brief Конструктор класса
		*/
		RandomCore(double max_percent=100) : MAX_PERCENT(max_percent)
		{};

		/**
		@brief Функция классификации "недоброжелательности" текста
		@param msg Структура данных, содержащая в себе текст подлежащий анализу
		*/
		void run(json& msg) const override;
	};
}
