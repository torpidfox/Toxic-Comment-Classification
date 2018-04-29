#pragma once

#include "../includes/json.hpp"


using json = nlohmann::json;

/**
namespace tcc
@brief Пространство имен tcc
*/
namespace tcc {
	/**
	@brief Интерфейс для классов предобработки текста
	*/
	class DataPreprocessing {
		/**
		@brief Виртуальная функция для предобработки текста
		@param msg Структура данных, содержащая в себе текст подлежащий предобработке
		*/
		virtual void run(const json& msg) const = 0;
	};
}
