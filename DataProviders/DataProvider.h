#pragma once

#include <vector>
#include <string>

#include "../includes/json.hpp"


using json = nlohmann::json;

/**
namespace tcc
@brief Пространство имен tcc
*/
namespace tcc {
	/**
	@brief Интерфейс для классов считывания/записи данных
	*/
	class DataProvider {
		/**
		@brief Виртуальная функция для считывания данных
		@return Вектор структур данных, содержащих в себе считанные данные
		@throw IOException Исключение возникающее при проблемах с чтением файла
		*/
		virtual std::vector<json> get_data() const = 0;
		/**
		@brief Виртуальная функция для записи данных
		@param msg Структура данных, содержащая в себе данные подлежащие записи
		@return Булевое значение:
			- 0 запись не удаласть
			- 1 запись удалась
		*/
		virtual bool save_data(const json& msg) const = 0;
	};

	/**
	@brief Класс для считывания/записи данных из/в файл(а)
	*/
	class FileDataProvider : public DataProvider {
	private:
		std::string _input_file;
		std::string _output_file;

	public:
		/**
		@brief Конструктор класса
		@param input_file Имя файла для чтения
		@param output_file Имя файла для записи
		*/
		FileDataProvider(std::string input_file, std::string output_file)
			: _input_file(input_file), _output_file(output_file)
		{};

		/**
		@brief Функция для считывания данных из файла
		@return Вектор структур данных, содержащих в себе считанные данные
		@throw IOException Исключение возникающее при проблемах с чтением файла
		*/
		std::vector<json> get_data() const override;

		/**
		@brief Функция для записи данных в файл
		@param msg Структура данных, содержащая в себе данные подлежащие записи
		@return Булевое значение:
			- 0 запись не удаласть
			- 1 запись удалась
		*/
		bool save_data(const json& msg) const override;
	};

	/*
	class SQLProvider : public DataProvider {
		Message get_data() const override;
		bool save_data(const Message& msg) const override;
	};
	*/
}
