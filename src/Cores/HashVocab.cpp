#include "Vocab.h"

namespace tcc {
	uint HashVocab::_hash(const std::string& w) const {
		{
			unsigned int h;
			unsigned char *p;

			h = 0;
			for(auto el : w)
				h = 37 * h + el;
			return h;
		}
	}

	uint HashVocab::_bin_search(uint x) const {
		uint mid = _non_zero_ind.size() / 2;
		uint left = 0;
		uint right = _non_zero_ind.size();

		while (mid < right && mid > left && _non_zero_ind[mid] != x) {
			if (x > _non_zero_ind[mid]) 
				left = mid + 1;
			else 
				right = mid - 1;

			mid = right - left / 2;
		}

		return mid == _non_zero_ind.size() ? mid - 1 : mid;
	}

	void HashVocab::addWord(const std::string& w) {
			auto w_hash = _hash(w);
			auto pos = _bin_search(w_hash);

			if (_non_zero_ind[pos] == w_hash)
				_non_zero_val[pos]++;
			else if (_non_zero_ind[pos] > w_hash) {
				_non_zero_val.insert(_non_zero_val.begin() + pos - 1, 1);
				_non_zero_ind.insert(_non_zero_ind.begin() + pos - 1, w_hash);
			}
			else {
				_non_zero_val.insert(_non_zero_val.begin() + pos, 1);
				_non_zero_ind.insert(_non_zero_ind.begin() + pos, w_hash);
			}

	}
}