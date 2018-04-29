#pragma once

#include "BSTNode.h"

using uint = unsigned int;
using textVec = std::vector<const std::string>;

namespace tcc {
	/**
	@brief Класс для хранения информации о корпусе слов в виде мешка слов
	*/
	class BOW {
	public:
		/**
		@brief Конструктор экземпляра класса
		@param texts - корпус текстов, на основе которых будет составлен мешок слов
		*/
		BOW(textVec& texts);
		/**
		@brief Добавление слова в словарь
		@param s - строка, содержащая слово
		*/
		void add_word(std::string& s);
		/**
		@brief Поиск информации о слове
		@param s - искомое слово
		@returns количество раз, когда слово встретилось в корпусе текстов
		*/
		uint find_word(std::string& s);
	private:
		BSTNode* _root;
	};
}