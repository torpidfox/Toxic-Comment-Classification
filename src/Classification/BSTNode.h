#pragma once

#include<vector>
#include<algorithm>
#include<stack>

#define RIGHT_LEFT 2
#define LEFT_RIGHT -2


/**
@brief ���� ��������� ������ ������
*/

namespace tcc {
	/**
	@brief ��������� � ����������� ��� �������������� ����������� � �����
	*/

	struct Word {
		size_t word_hash;	/**< ���������� ��� �����*/
		double freq;	/**< ������������� � ������*/

		Word() {};
		Word(int hash, double f) : word_hash(hash), freq(f) {};
		Word(const Word& r) : word_hash(r.word_hash), freq(r.freq) {};
		void _update_freq() { freq++; }
		const Word& operator= (Word& r) { word_hash = r.word_hash;  freq = r.freq; return r; }
	};

	/**
	@brief ��������� ���� ������ ��������� ������
	*/
	struct BSTNode {
		Word w;
		BSTNode* left;
		BSTNode* right;
		int height;

		BSTNode(Word& r) { w = r; left = right = nullptr; height = 1; }
		BSTNode* _insert(BSTNode* w);
		BSTNode* _balance(BSTNode* pivot);
		BSTNode* _find(int key);
		double _find_value(int word_hash) { return _find(word_hash)->w.freq; }

		void _release();
		static int _height(BSTNode* n) { if (n) return n->height; return 0; }
		static BSTNode* _rotate_left(BSTNode* pivot);
		static BSTNode* _rotate_right(BSTNode* pivot);
		void _calc_height() { height = std::max(_height(left), _height(right)) + 1; };
		static int _rotate_param(BSTNode* n) { return _height(n->right) - _height(n->left); };
	};
}

