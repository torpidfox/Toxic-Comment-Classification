#pragma once

#include "BSTNode.h"

using uint = unsigned int;
using textVec = std::vector<std::string>;

namespace tcc {
	class BOW {
	public:
		BOW(textVec& texts);
		void add_word(std::string& s);
		uint find_word(std::string& s);
	private:
		BSTNode * _root;
	};
}