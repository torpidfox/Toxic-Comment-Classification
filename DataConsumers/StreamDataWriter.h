#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include "includes/json.hpp"


using json = nlohmann::json;

namespace tcc {
	class StreamDataWriter {
	public:
		/**
		@brief Перечисление, хранящее информацию о текущем состоянии потока
		*/
		enum State {
			GOOD,	///<Ошибки не зарегистрированы 
			FORMAT_FAIL, ///<Не удалось преобразовать переменную для записи 
			WRITING_FAIL, ///<Не удалось записать в поток
			OPENING_FAIL, ///<Не удалось открыть файл
		};
		/**
		@brief Конструкторы класса
		@param input_file Имя файла для записи. При отсутсвии запись ведется в консоль
		*/
		StreamDataWriter(std::string& file_name) {
			_output = new std::ofstream(file_name);
			if (!_output->is_open())
				_cur_state = OPENING_FAIL;
		}
		StreamDataWriter() {};
		StreamDataWriter(const char* file_name) : StreamDataWriter(std::string(file_name)) {};

		/**
		@brief Информация о текущем состоянии потока
		@relatesalso StreamDataWriter::State
		*/
		State state() { return _cur_state; }

		/**
		@brief Запись в поток вектора элементов произвольного типа (один элемент - одна строка)
		@tparam T тип записываемых элементов
		@param el ссылка на запсываемый вектор
		*/
		template<typename T>
		State operator<<(std::vector<T>& vec_el);

		/**
		@brief Запись в поток элемента произвольного типа
		@tparam T тип записываемого эелемента
		@param el ссылка на запсиываемый элемент
		*/
		template<typename T>
		State operator<<(T& el);
	private:
		std::ofstream* _output = nullptr;
		State _cur_state = GOOD;
	};
};

template<typename T>
tcc::StreamDataWriter::State tcc::StreamDataWriter::operator<<(T& el) {
	if (_output) {
		*(_output) << el;
		_output->flush();
	}
	else
		std::cout << el;

	if (_output->rdstate() == std::ios::badbit) {
		_cur_state = State::FORMAT_FAIL;
	}

	if (_output->rdstate() == std::ios::failbit) {
		_cur_state = State::WRITING_FAIL;
	}
	return _cur_state;

};


template<typename T>
tcc::StreamDataWriter::State tcc::StreamDataWriter::operator<<(std::vector<T>& vec_el) {
	for (auto el : vec_el) {
		if (_output) {
			*(_output) << el;
			*(_output) << '\n';
			_output->flush();
		}
		else
			std::cout << el << std::endl;

		if (_output->rdstate() == std::ios::badbit) {
			_cur_state = State::FORMAT_FAIL;
			return _cur_state;
		}

		if (_output->rdstate() == std::ios::failbit) {
			_cur_state = State::WRITING_FAIL;
			return _cur_state;
		}
	}
	return _cur_state;
};
