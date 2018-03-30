#pragma once

#include<vector>
#include<list>
#include<memory>
#include<algorithm>
#include "BOW.h"

namespace tcc {
	using uint = unsigned int;
	using vec = std::vector<uint>;
	using text = std::vector<std::string>;

	/**
	@brief Интерфейс класса, преобразующего текст в вектор
	*/
	class Features {
	public:
		/**
		@brief Оценка выраженности признака, задаваемого одним словом
		@param t текст
		@param f функция, с помощью которой оценивается выраженность признака
		*/		
		virtual uint extract_feature(std::string& s, std::function<double(double)> f) const = 0;
		/**
		@brief Оценка выраженности признака, задаваемого несколькими словами
		@param t текст
		@param f функция, с помощью которой оценивается выраженность признака
		*/
		virtual uint extract_feature(text& s, std::function<double(double)> f) const = 0;
		/**
		@brief Сжатие размерности 
		@param t текст
		@param f функция, с помощью которой производится сжатие
		*/
		virtual uint reduce_dimensions(uint dim, text& s, std::function<double(double)> f) const = 0;
		/**
		@brief Оценка расстояния между двумя текстами
		@param l, r тексты
		*/
		double metric(Features& l, Features& r);
		virtual ~Features() {};
	};


	/**
	@brief Преобразование на основе bag-of-words
	*/
	class BOWFeatures : public Features {
	private:
		std::shared_ptr<BOW> _global;
		std::vector<uint> _non_zero_hash;
		std::vector<uint> _non_zero_val;
		
	public:
		BOWFeatures(std::shared_ptr<BOW> global): _global(global) {};
		~BOWFeatures() override {};
	};
}

