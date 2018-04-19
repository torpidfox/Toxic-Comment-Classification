#pragma once

#include <iostream>
#include <string>
#include "includes/json.hpp"


using json = nlohmann::json;
/**
namespace tcc
@brief Пространство имен tcc
*/
namespace tcc
{
	//перечисление "специальной" етеинформации о слове 
	enum word_info{ LOWERCASE, UPPERCASE, QUOTES};
	//структура, описывающая слово (требует доработки)
	typedef struct word {
		std::string str;
		word_info info;
	}word_t;

	class Stemmer {
		/**
		@brief Виртуальная функция для стемминга
		@return Вектор векторов со словами, приведенными к начальной форме
		*/

		virtual std::vector<std::vector<tcc::word_t>> stem(std::vector<json> text) = 0;
		//virtual void trim(std::string& word);
	};

	class PorterStemming: public Stemmer {
	public:
		std::vector<std::vector<tcc::word_t>> stem(std::vector<json> text);

	private:
		void trim(tcc::word_t& word);
		void stem_word(std::string& word);
		size_t firstNonVowelAfterVowel(const std::string& word, size_t start);
		size_t getStartR1(const std::string& word);
		size_t getStartR2(const std::string& word, size_t startR1);
		void changeY(std::string& word);
		void step0(std::string& word);
		bool step1A(std::string& word);
		void step1B(std::string& word, size_t startR1);
		void step1C(std::string& word);
		void step2(std::string& word, size_t startR1);
		void step3(std::string& word, size_t startR1, size_t startR2);
		void step4(std::string& word, size_t startR2);
		void step5(std::string& word, size_t startR1, size_t startR2);
		inline bool isShort(const std::string& word);
		bool special(std::string& word);
		bool isVowel(char ch);
		bool isVowelY(char ch);
		bool endsWith(const std::string& word, const std::string& str);
		bool endsInDouble(const std::string& word);
		bool replaceIfExists(std::string& word, const std::string& suffix,
		const std::string& replacement, size_t start);
		bool isValidLIEnding(char ch);
		bool containsVowel(const std::string& word, size_t start, size_t end);
	};
}