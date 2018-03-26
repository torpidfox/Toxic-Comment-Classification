#include<vector>

namespace tcc {
	using uint = unsigned int;
	/**
	@brief Интерфейс контейнера для хранения словаря
	*/
	class Vocab {
	public:
		/**
		@brief Поиск информации о слове
		*/
		virtual uint getWordCounts(const std::string& w) const = 0;
		/**
		@brief Добавление слова
		*/
		virtual void addWord(const std::string& w) = 0;

		/**
		@brief Информация о тексте на основе используемых в нем слов
		*/
		virtual void textFeatures(std::vector<std::string>& t) const = 0;
	};

	/**
	@brief Массив слов, где индекс слова - его хэш
	*/
	class VocabImpl : Vocab {
		/**
		@brief Информация о слове
		*/
		struct Word {
			uint freq;	/**< Встречаемость в тексте*/

			Word() : freq(0) {};
		};


	public:
		VocabImpl() : _vocab(_dim, Word()) {};
		uint getWordCounts(const std::string& w) const override { return _vocab[hash(w)].freq; };
		void addWord(const std::string& w) override { _vocab[hash(w)].freq++; };
	private:
		uint hash(const std::string& w) const;

		std::vector<Word> _vocab;
		static const uint _dim;
	};

	uint VocabImpl::hash(const std::string& w) const {
		uint h = 5381;

		for (auto el : w)
			h = ((h << 5 + h) + el) % _dim;

		return h;
	}
}
