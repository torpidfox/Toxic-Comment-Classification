#include "TestTree.h"


void TestTree::test_null_data_provided() {
	std::vector<tcc::Word> raw_vocab;
	tcc::VocabImpl tested = tcc::VocabImpl(raw_vocab);
}

bool TestTree::assert_bstness(tcc::BSTNode* n) {
	if (!n)
		return true;

	if (n->left) {
		if ((n->left)->w.word_hash > n->w.word_hash)
			return false;
		return assert_bstness(n->left);
	}

	if (n->right) {
		if ((n->right)->w.word_hash < n->w.word_hash)
			return false;
		return assert_bstness(n->right);
	}

	return true;
}

void TestTree::test_consistency() {
	tcc::BSTNode* root = new tcc::BSTNode(tcc::Word(1, 1));
	std::vector<tcc::Word> raw_vocab;
	auto count = 10;

	for (auto i = 0; i < count; i++)
		root = root->_insert(new tcc::BSTNode(tcc::Word(std::rand(), i)));

	QCOMPARE(assert_bstness(root), true);

	root->_release();
}

void TestTree::test_benchmark() {
	tcc::BSTNode* root = new tcc::BSTNode(tcc::Word(1, 1));
	std::vector<tcc::Word> raw_vocab;
	//std::map<int, int> cmp;
	//QMap<int, int> qcmp;

	auto count = 1000;

	for (auto i = 0; i < count; i++) {
		root = root->_insert(new tcc::BSTNode(tcc::Word(std::rand(), i)));
		//cmp.emplace(std::rand(), i);
		//qcmp.insert(std::rand(), i);
	}

	QBENCHMARK(root->_find(std::rand()));
	//QBENCHMARK(qcmp.find(std::rand()));

	root->_release();
}