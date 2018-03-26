#include<vector>
#include "BSTNode.h"



namespace tcc {

	/**
	@brief Интерфейс контейнера для хранения словаря
	*/
	class Vocab {
	public:
		/**
		@brief Поиск информации о слове
		@param word_hash хэш искомого слова
		*/
		virtual double FindWordFreq(int word_hash) const = 0;
	};

	/**
	@brief Словарь, хранящийся в виде AVL-дерева для более быстрого поиска
	*/
	class VocabImpl {
	public:
		VocabImpl(std::vector<Word>& raw_vocab) { _avl(std::forward<std::vector<Word>>(raw_vocab)); }
		double FindWordFreq(int word_hash) { return root->_find_value(word_hash); }

		~VocabImpl() { if (root) { root->_release(); delete root; } }
	private:
		void _avl(std::vector<Word>& raw_vocab); /**< Создание дерева из вектора данных */	
		BSTNode* root = nullptr;	/**< Указатель на корень дерева */
	};
}
