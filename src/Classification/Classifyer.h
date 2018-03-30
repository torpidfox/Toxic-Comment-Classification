#pragma once
#include <memory>
#include <cmath>
#include "Vocab.h"


namespace tcc {
	using textVec = std::vector<std::string>;
	using labeledText = std::vector<std::pair<textVec, bool>>;

	class Classifyer {
	public:
		virtual void train() = 0;
		virtual double run(textVec& text) = 0;
		virtual ~Classifyer() = 0;
	};

	class NaiveBayesClassifyer : Classifyer {
	public:
		NaiveBayesClassifyer() {};
		NaiveBayesClassifyer(std::shared_ptr<Features>& v) : bow(v) {};
		~NaiveBayesClassifyer() override {};
		void train() override {};
		double run(textVec& text) override;
	private:
		double _logLike(std::string& word);
		std::shared_ptr<Features> bow = nullptr;
	};


	double NaiveBayesClassifyer::_logLike(std::string& word) {
		return bow->extract_feature(word, [](double x)
		{
			return std::log((x + 1) / (x + 1));
		}
		);
	}

	double NaiveBayesClassifyer::run(textVec& text) {
		double labelProb = 0.5;

		for (auto word : text) {
			labelProb += _logLike(word);
		}

		return std::exp(labelProb) / std::exp(labelProb + 1);
	}

}