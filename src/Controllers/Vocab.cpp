#include"Vocab.h"
namespace tcc {
	void VocabImpl::_avl(std::vector<Word>& raw_vocab)
	{
		if (raw_vocab.empty())
			return;
		root = new BSTNode(raw_vocab[0]);

		for (auto el : raw_vocab) {
			root = root->_insert(new BSTNode(el));
		}
	}

}