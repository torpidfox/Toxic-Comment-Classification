#pragma once
#include <memory>
#include <cmath>
#include "Vocab.h"


namespace tcc {
	/**
	@brief Вектор текстов
	*/
	using textVec = std::vector<const std::string>;
	/**
	@brief Вектор текстов с тегами
	*/
	using labeledText = std::vector<std::pair<textVec, bool>>;

	/**
	@brief Интерфейс классификатора текста
	*/
	class Classifyer {
	public:
		/**
		@brief Запуск обучения классификатора
		*/
		virtual void train() = 0;
		/**
		@brief Оценка текста
		@param text - текст, подлежащий оцениванию
		@returns вероятность принадлежности текста категории
		*/
		virtual double run(textVec& text) const = 0;
		virtual ~Classifyer() override = default;
	};
	/**
	@brief Наивный байесовский классификатор
	*/
	class NaiveBayesClassifyer : Classifyer {
	public:
		/**
		@brief Конструктор экземпляра класса
		@param v - информация о словах, встречающихся в корпусе текстов
		*/
		NaiveBayesClassifyer(std::shared_ptr<Features>& v) : bow(v) {};
		~NaiveBayesClassifyer() override = default;

		void train() override {};
		double run(textVec& text) const override;
	private:
		double _logLike(std::string& word) const;
		std::shared_ptr<Features> bow = nullptr;
	};


	double NaiveBayesClassifyer::_logLike(std::string& word) const {
		return bow->extract_feature(word, [](double x)
		{
			return std::log((x + 1) / (x + 1));
		}
		);
	}

	double NaiveBayesClassifyer::run(textVec& text) const {
		double labelProb = 0.5;

		for (auto word : text) {
			labelProb += _logLike(word);
		}

		return std::exp(labelProb) / std::exp(labelProb + 1);
	}

}