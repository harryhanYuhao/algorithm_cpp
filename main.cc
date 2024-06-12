#include <iostream>

#include "util.h"
#include "sort/sort.h"

int main() {
	std::vector<int> input = util::shuffled_vec_int(10000000);
	util::print_vec(input);

	std::vector<int> output = sort::merge_sort(input);
	util::print_vec(output);

    return 0;
}
