#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include "../includes/json.hpp"


using json = nlohmann::json;

/**
namespace tcc
@brief Пространство имен tcc
*/
namespace tcc {
	/**
	@brief Шаблон интерфейса, позволяющего записывать результат работы в произвольном формате
	*/
	template <T>
	class DataConsumer {
		/**
		@brief Виртуальная функция для записи данных
		@return void
		@throw IOException Исключение, возникающее при проблемах с чтением файла
		*/
		virtual void flush() const = 0;
		/**
		@brief Виртуальная функция для добавления элемента к буферу уже ожидающих записи
		@param result - элемент, который нужно записать
		@return void
		*/

		virtual void buff(T&& result) const = 0;
	};

	/**
	@brief Шаблон класса для буферизации результатов работы в проивзольном формате и последующей записи в файл
	*/
	template<T>
	class FileDataConsumer : public DataConsumer<T> {
	private:
		std::string _input_file;
		std::vector<T> _buffered_data;
	public:
		/**
		@brief Конструктор класса
		@param input_file Имя файла для записи
		*/
		FileDataConsumer(std::string input_file)
			: _input_file(input_file), _buffered_data() {};

		/**
		@brief Функция для добавления элемента к вектору уже ожидающих записи
		@param result элемент, который нужно записать 
		@return void
		*/
		void buff(T&& result) const override { _buffered_data.push_back(result); }

		/**
		@brief Функция для записи данных в файл
		@throw IOException При ошибке открытия или записи в поток
		*/
		void flush() const override {
			std::ofstream dst;
			dst.open(_input_file);

			for (el : _buffered_data) dst << el << endl;

			dst.close()
		}
	}