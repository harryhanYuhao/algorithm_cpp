#ifndef LIBALGORITHM_GUARD
#define LIBALGORITHM_GUARD 
#include <vector>

namespace util {
	int random_int();
	std::vector<int> shuffled_vec_int(long unsigned int length);
	bool validate_ascend(std::vector<int>&);
	void print_vec(std::vector<int>&);
} // namespace libalgorithm

#endif
