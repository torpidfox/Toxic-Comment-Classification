#pragma once
#include <vector>
#include <string>
#include <fstream>
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
	};

	/**
	@brief Класс для считывания тренировочных образцов с сайта Kaggle
	*/
	class KaggleDataProvider : public DataProvider {
	private:
		std::string _input_file;

		//разделители в файле
		static const char s_delim;
		static const char* s_quot;

		//перевод строк с информацией о тексте в json
		json _sample_to_json(std::vector<std::string>& text, std::vector<bool>& ratings) const;
		//чтение id
		std::string _parse_id(std::string& s) const;
		//чтение комментария
		bool _parse_text(std::string& line, std::string& dst) const;
		//чтение оценки
		std::vector<bool> _parse_rating(std::string& line) const;

	public:
		/**
		@brief Конструктор класса
		@param input_file Имя файла для чтения
		*/
		KaggleDataProvider(std::string& input_file)
			: _input_file(input_file) {};

		KaggleDataProvider(const KaggleDataProvider& rv)
			: _input_file(rv._input_file) {};

		KaggleDataProvider() : _input_file() {};

		/**
		@brief Функция для считывания данных из файла
		@return Вектор структур данных, содержащих в себе считанные данные
		@throw IOException Исключение возникающее при проблемах с чтением файла
		*/
		std::vector<json> get_data() const override;
	};

	/*
	class SQLProvider : public DataProvider {
		Message get_data() const override;
		bool save_data(const Message& msg) const override;
	};
	*/
}

